#include <stdio.h>
#include <ctype.h>

int main() {
    int a = 0, b = 0;
    for (int i = 0; i < 1000; i++) {
        if (isprint(i)) {
            putchar(i);
            printf(" %d\n", i);
            a++;
        }
        else {
            b++;
        }
    }
    printf("The total number of printable characters is %d\n", a);
    printf("The total number of NON printable characters is %d\n", b);
    printf("There are 95 printable ASCII characters, numbered 32 to 126 following the ASCII standard (American Standard Code for Information Interchange).\n");
    printf("If we try to print 1000 characters or more, the program will only shows 95 printable ASCII characters because they are fixed and defined well.\n");
    return 0;
}