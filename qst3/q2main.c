
#include "q2.h"


int main(int argc, char *argv[]) {
    // Lambda (l) values
    long double lambdas[5] = {2, 2, 2, 3, 100};
    // k values
    int k[5] = {1, 10, 2, 3, 3};

    for (int i = 0; i < 5; i++) {
        long double pr = poisson_probability(lambdas[i], k[i]);
        printf("P(%d, %Lf) = %Lf\n", k[i], lambdas[i], pr);
    }

    return 0;
}

