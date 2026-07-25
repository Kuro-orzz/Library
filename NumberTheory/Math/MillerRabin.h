#include "../../template.h"
#include "Binary_exponentiation.h"


bool test(ll a, ll n, ll k, ll m) {
    ll mod = binPow(a, m, n);
    if (mod == 1 || mod == n - 1) return true;
    for (int l = 1; l < k; l++) {
        mod = (u128)mod * mod % n;
        if (mod == n - 1) return true;
    }
    return false;
}

// Miller rabin
bool MillerRabin0(ll n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    ll k = 0, m = n - 1;
    while(m % 2 == 0) {
        m /= 2;
        k++;
    }
    for (int i = 0; i < 5; i++) {
        ll a = rand() % (n - 3) + 2;
        if (!test(a, n, k, m)) return false;
    }
    return true;
}

// Miller Rabin deterministic version
bool MillerRabin(ll n) {
    if (n <= 1) return false;
    ll k = 0, m = n-1;
    while (m % 2 == 0) {
        m /= 2;
        k++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (!test(a, n, k, m)) return false;
    }
    return true;
}