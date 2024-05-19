#include "q2.h"


long double poisson_probability(long double l, int k) {
    return (powl(l, k) * expl(-l)) / tgammal(k + 1);
}

