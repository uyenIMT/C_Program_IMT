#include <arpa/inet.h>
#include <netinet/in.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "chat.h"

#define PORT 12345
#define SERVER_ADDR "127.0.0.1"

void error(const char* msg) {
    perror(msg);
    exit(1);
}

int settingUpClientSocket(uint16_t port) {
    struct sockaddr_in serverAddress = setupServer(port);
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error("Error creating socket");
    }
    
    if (inet_aton(SERVER_ADDR, &serverAddress.sin_addr) == 0) {
        error("Error converting address");
    }

    if (connect(sockfd, (struct sockaddr*)&serverAddress,
            sizeof(struct sockaddr_in))
        != 0) {
        error("Error connecting to server");
    }
    int on;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char*)&on, sizeof(on))
        < 0) {
        error("Error setting reuse option\n");
    }

    return sockfd;
}

int main(int argc, char** argv) {
    uint16_t port = PORT;
    if (argc < 2) { // nickname argument is required, but the port argument is optional
        printf("Usage: %s nickname [port]\n", argv[0]);
        exit(1);
    }
    if (argc >= 3) {
        sscanf(argv[2], "%hu", &port);
    }

    printf("Welcome %s\n", argv[1]);

    struct Message outgoing;
    strcpy(outgoing.nickname, argv[1]);

    int sockfd = settingUpClientSocket(port);

    struct Message incoming;
    struct pollfd fds[MAX_CLIENTS + 1];
    int nfds = 2;
    fds[0].fd = 0;
    fds[0].events = POLLIN;
    fds[1].fd = sockfd;
    fds[1].events = POLLIN;

    while (1) {
        printf("%s> ", outgoing.nickname);
        fflush(stdout);
        int retpoll = poll(fds, 2, -1);

        if (retpoll < 0) {
            perror("poll failed");
            return -1;
        }
        if (retpoll == 0) {
            continue;
        }
        if (fds[0].revents == POLLIN) {
            fgets(outgoing.message, 1023, stdin);
            outgoing.message[strcspn(outgoing.message, "\n")] = 0;
            if (sendMessage(sockfd, &outgoing) < 0) {
                perror("Error sending message");
                break;
            }
        } else if (fds[1].revents == POLLIN) {
            if (readMessage(fds[1].fd, &incoming) < 0) {
                perror("Error reading message");
                break;
            }
            printf("\r%s> %s\n", incoming.nickname, incoming.message);
        } else {
            printf("Unexcepted revent\n");
            break;
        }
    }
    close(sockfd);
    return 0;
}
