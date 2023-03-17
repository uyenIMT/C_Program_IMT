#include <stdio.h>
#include <stdlib.h>
#include "exchange.h"
#include <time.h>

void exchange(float *x1, float *x2);
void transposition_square_matrix(float **M, int n);

int main() {
    int n;
    printf("Please give the dimension of the matrix M: ");
    scanf("%d", &n);

    // Allocate memory for the matrix
    float **M = (float **) malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        M[i] = (float *) malloc(n * sizeof(float));
    }

    // Fill the matrix with random numbers in the range [0, 10]
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = (float) rand() / RAND_MAX * 10;
        }
    }

    // Print the initial matrix
    printf("Initial matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", M[i][j]);
        }
        printf("\n");
    }

    // Transpose the matrix
    transposition_square_matrix(M, n);

    // Free the memory
    for (int i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);

    return 0;
}


void transposition_square_matrix(float **M, int n) {
    // Transpose the matrix M in place
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            exchange(&M[i][j], &M[j][i]);
        }
    }

    // Print the transposed matrix
    printf("Transposed matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", M[i][j]);
        }
        printf("\n");
    }
}
