
#include "q5.h"

//O(n^3)
int maxSubArraySumN3(int arr[], int size) {
    int max_sum = -2147483648; // Minimum possible integer value
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int current_sum = 0;
            for (int k = i; k <= j; k++) {
                current_sum += arr[k];
            }
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}

//O(n^2)
int maxSubArraySumN2(int arr[], int size) {
    int max_sum = -2147483648; 
    for (int i = 0; i < size; i++) {
        int current_sum = 0;
        for (int j = i; j < size; j++) {
            current_sum += arr[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}

//O(n)
int maxSubArraySumN(int arr[], int size) {
    int max_sum = arr[0];
    int current_sum = arr[0];
    for (int i = 1; i < size; i++) {
        if(arr[i] > (current_sum + arr[i])) {
        current_sum =  arr[i] ;}
         else
          {
            current_sum = current_sum + arr[i];}
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    return max_sum;
}

void generateRandomArray(int arr[], int size, unsigned int seed) {
    srand(seed);
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) - 25; // Random numbers in the range (-25, 74)
    }
}