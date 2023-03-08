#include <stdio.h>

int main() {
    int a, b;
    // Logical AND table
    printf("Logical AND table:\n");
    printf("a\tb\ta&&b\n");
    printf("--------------------\n");

    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            int c;
            c = a&&b;
            printf("%d\t%d\t%d\n",a, b, c);
        }
    }
    // Logical OR table
    printf("Logical OR table:\n");
    printf("a\tb\ta||b\n");
    printf("--------------------\n");

    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            int c;
            c = a||b;
            printf("%d\t%d\t%d\n",a, b, c);
        }
    }
    // Logical XOR table
    printf("Logical XOR table:\n");
    printf("a\tb\ta^b\n");
    printf("--------------------\n");

    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            int c;
            c = a^b;
            printf("%d\t%d\t%d\n",a, b, c);
        }
    }
    return 0;
}