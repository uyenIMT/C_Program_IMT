#include <stdio.h>
#include <stdlib.h>

void exchange(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}