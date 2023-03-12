#include <stdio.h>

void logical_operator_use(char x) {
    int a,b;
    switch (x){
        case 'A':
        // Logical AND table
            printf("Logical AND table:\n");
            printf("=============\n");

            for (a = 0; a <= 1; a++) {
                for (b = 0; b <= 1; b++) {
                    int c;
                    c = a&&b;
                    printf("%d AND %d = %d\n",a, b, c);
                }
            }
            break;
        case 'O':
        // Logical OR table
            printf("Logical OR table:\n");
            printf("=============\n");

            for (a = 0; a <= 1; a++) {
                for (b = 0; b <= 1; b++) {
                    int c;
                    c = a||b;
                    printf("%d OR %d = %d\n",a, b, c);
                }
            }
            break;
        case 'X':
            // Logical XOR table
            printf("Logical XOR table:\n");
            printf("=============\n");

                for (a = 0; a <= 1; a++) {
                for (b = 0; b <= 1; b++) {
                    int c;
                    c = a^b;
                    printf("%d XOR %d = %d\n",a, b, c);
                }
            }
            break;
        default:
            printf("Please make sure you choose the correct character\n");
    }
}