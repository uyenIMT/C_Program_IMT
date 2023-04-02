#include <stdio.h>

int main() {
    int arr[5] = {0, -1, -2, -3, -6};
    int max = arr[0]; // Initialize max to first element of array
    for (int i = 1; i < 5; i++) { // Start loop at i = 1
        if (arr[i] > max)
            max = arr[i];
    }
    printf("The largest number in the array is %d\n", max);
    return 0;
}

/*The largest number in the array is 0 */