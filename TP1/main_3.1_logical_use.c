#include <stdio.h>

int main() {
    int a, b;
    // Logical AND table
    printf("Logical AND table:\n");
    printf("=============\n");
    // Nested loop that prints the result of a logical AND operation
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            int c;
            c = a&&b;
            printf("%d AND %d = %d\n",a, b, c);
        }
    }
    printf("\n");
    // Logical OR table
    printf("Logical OR table:\n");
    printf("=============\n");
    // Nested loop that prints the result of a logical OR operation
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            int c;
            c = a||b;
            printf("%d OR %d = %d\n",a, b, c);
        }
    }
    printf("\n");
    // Logical XOR table
    printf("Logical XOR table:\n");
    printf("=============\n");
    // Nested loop that prints the result of a logical XOR operation
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            int c;
            c = a^b;
            printf("%d XOR %d = %d\n",a, b, c);
        }
    }
    printf("\n");
    return 0;
}