#include <stdio.h>
#include <stdlib.h>
#include "exchange.h"

int main(int argc, char *argv[]) {
    float x1, x2;
    if (argc == 3) {
        // Convert the arguments from strings to floating point numbers
        x1 = atof(argv[1]);
        x2 = atof(argv[2]);
    } else {
        printf("Please give two floating point numbers, separated by a space:\n");
        scanf("%f %f", &x1, &x2);
    }
    printf("The values of the numbers before exchanging: f1=%f, f2=%f\n", x1, x2);
    exchange(&x1, &x2);
    printf("The values of the numbers after exchanging: f1=%f, f2=%f\n", x1, x2);
    return 0;
}

