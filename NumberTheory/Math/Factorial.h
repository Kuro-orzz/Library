#include "../../template.h"


// https://wiki.vnoi.info/translate/he/Wilsons-theorem
// Wilson theorem
// n > 1 is prime <=> (n-1)! ≡ -1 (mod n)
//
// Proof:
//    a^(n-2) ≡ a^(-1) (mod n) (Fermat's little theorem)
// => a^(n-2) * a ≡ 1 (mod n)
// Set b = a^(n-2)
// => ab ≡ 1 (mod n)
//
// Have a = b <=> a^2 ≡ 1 (mod n) <=> a = 1 or a = n-1
//
// So if a = 2,3,...,n-2 then a != b
// => we have (n-3)/2 distinct pairs (because with each a, b is unique)
// so we multiple all paris
// => 2.3...(n-2) ≡ 1 (mod n)
// => (n-1)! ≡ n-1 (mod n)

// Proof by contradiction:
// if n is not prime => n have divisors in range [2, n)
//                   => gcd((n-1)!, n) > 1
//                   => gcd(n-1, n) > 1 (contradiction)


// use for small prime p <= 46341
// slow version
int factmod0(int n, int p) {
    vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++) {
        f[i] = f[i-1] * i % p;
    }
    int res = 1;
    while (n > 1) {
        if ((n/p) % 2) res = p - res;
        res = res * f[n % p] % p;
        n /= p;
    }
    return res;
}


// Optimize version using static to cache, can work with multiple calling
ll factmod(ll n, ll p) {
    static ll lastp = -1;
    static vector<ll> f;
    if (p != lastp) {
        lastp = p;
        f.assign(p, 1);
        for (ll i = 1; i < p; i++) f[i] = f[i-1] * i % p;
    }
    ll res = 1;
    while (n > 1) {
        if ((n/p) % 2) res = p - res;
        res = res * f[n % p] % p;
        n /= p;
    }
    return res;
}