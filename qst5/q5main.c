#include "q5.h"

#define SIZE_100 100
#define SIZE_1000 1000
#define SIZE_10000 10000

int maxSubArraySumN3(int arr[], int size);
int maxSubArraySumN2(int arr[], int size);
int maxSubArraySumN(int arr[], int size);
void generateRandomArray(int arr[], int size, unsigned int seed);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <seed> <size>\n", argv[0]);
        return 1;
    }
    unsigned int seed = (unsigned int)atoi(argv[1]);
    int size = atoi(argv[2]);

    if (size != SIZE_100 && size != SIZE_1000 && size != SIZE_10000) {
        fprintf(stderr, "Size must be 100, 1000, or 10000\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    generateRandomArray(arr, size, seed);

    printf("Max subarray sum (O(n^3)): %d\n", maxSubArraySumN3(arr, size));
    printf("Max subarray sum (O(n^2)): %d\n", maxSubArraySumN2(arr, size));
    printf("Max subarray sum (O(n)): %d\n", maxSubArraySumN(arr, size));

    free(arr);
    return 0;
}


