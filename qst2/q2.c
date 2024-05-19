#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Calculates the probability of a given number of events occurring in a fixed interval
 * of time or space, according to the Poisson distribution.
 */
double poisson_probability(double l, int k) {
    return (pow(l, k) * exp(-l)) / tgamma(k + 1);
}


int main(int argc, char *argv[]) {
    // Check if the number of arguments is exactly 3 (program name + 2 arguments)
    if (argc != 3) {
        printf("Error\n");
        return 1;
    }

    // Convert the first argument to a double (lambda)
    double l = atof(argv[1]);
    // Convert the second argument to an integer (k)
    int k = atoi(argv[2]);

    // Check if the arguments are valid (both should be non-negative)
    if (l < 0 || k < 0) {
        printf("Error\n");
        return 1;
    }

    // Calculate the Poisson probability
    double probability = poisson_probability(l, k);
    // Print the result
    printf("%f\n", probability);

    return 0;
}
