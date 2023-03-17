#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "exchange.h"

// Define 2 possible cases
enum Case {LOWER, UPPER};

// Changes the case of the string based on the value of the enum
void change_case(char *str, enum Case c) {
    int i = 0;
    while (str[i]) {
        if (c == UPPER) {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
        i++;
    }
    printf("Here are the text that you gave after changing the case : \n");
    printf("%s\n", str);
}

int main() {
    printf("Please give your text and press enter when you finish.\n");
    //  Reads input from the console and stores it in a dynamically allocated character array
    int capacity = 10;
    char *text = (char *)malloc(sizeof(char) * capacity); //Allocates memory dynamically
    char c = getchar(); // Read character from the console
    int i = 0;
    while (c != '\n') {
        text[i] = c;
        i++;
        // Increase the capacibility of the memory block
        if (i >= capacity) {
            capacity *= 2;
            text = (char *)realloc(text, sizeof(char) * capacity);
        }
        c = getchar();
    }
    text[i] = '\0';

    printf("You gave the following string: %s\n", text);
    printf("Please choose if you want to change your string to lower-case (type 0) or upper-case (type 1).\n");
    int choice;
    scanf("%d", &choice); // Input to choose cases

    change_case(text, choice == UPPER ? UPPER : LOWER);

    char **words = (char **)malloc(sizeof(char *) * capacity);
    char *word = strtok(text, " ,.-"); // Tokenize the character string 
    i = 0;
    while (word) {
        words[i] = word;
        i++;
        if (i >= capacity) {
            capacity *= 2;
            words = (char **)realloc(words, sizeof(char *) * capacity);
        }
        word = strtok(NULL, " ,.-");
    }
    int num_words = i;
    printf("The total number of words is %d and the average number of letters per word is ", num_words);
    int total_letters = 0;
    // Count length of the words
    for (i = 0; i < num_words; i++) {
        total_letters += strlen(words[i]);
    }
    printf("%.6f\n", (float)total_letters / num_words);

    // Free memory
    free(text);
    free(words);
    return 0;
}