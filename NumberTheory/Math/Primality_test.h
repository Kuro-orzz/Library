#include "../../template.h"
#include "Binary_exponentiation.h"


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// Fermat's little theorem (probabilistic)
// always fails on carmichael numbers a^(n−1) ≡ 1
bool isPrime(ll n) {
    if (n < 7) return n == 2 || n == 3 || n == 5;
    for (int i = 0; i < 5; i++) {
        ll a = rng() % (n-3) + 2;
        if (binPow(a, n-1, n) != 1) 
            return false;
    }
    return true;
}