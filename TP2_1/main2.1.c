#include <stdio.h>
#include <stdlib.h>
#include "exchange.h"

int main(int argc, char *argv[]) {
    float x1, x2;
    if (argc == 3) {
        x1 = atof(argv[1]);
        x2 = atof(argv[2]);
    } else {
        printf("Enter the values of x1 and x2:\n");
        scanf("%f %f", &x1, &x2);
    }
    printf("Before exchanging: x1=%f, x2=%f\n", x1, x2);
    exchange(&x1, &x2);
    printf("After exchanging: x1=%f, x2=%f\n", x1, x2);
    return 0;
}

