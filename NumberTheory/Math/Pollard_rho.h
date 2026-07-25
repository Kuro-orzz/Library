#include "../../template.h"
#include "MillerRabin.h"


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll get_rand(ll r) {
    return uniform_int_distribution<ll>(0, r - 1)(rng);
}

// https://wiki.vnoi.info/algo/math/integer-factorization
// pollard's rho, brent variant
// the polynomial and the start point MUST be random, a fixed one can gets hacked
// return one non trivial divisor, require n composite
// expected O(n^(1/4))
ll pollardRho(ll n) {
    if (n % 2 == 0) return 2;
    while (true) {
        ll c = 1 + get_rand(n-1), x = get_rand(n), prod = 2, step = 30;
        auto f = [&](ll v) { return (ll)(((i128)v * v + c) % n); };
        ll y = f(x);
        while (step % 40 || __gcd(prod, n) == 1) {
            if (x == y) break;
            ll q = binMul(prod, x > y ? x - y : y - x, n);
            if (q) prod = q;
            x = f(x);
            y = f(f(y));
            step++;
        }
        ll d = __gcd(prod, n);
        if (d != 1 && d != n) return d;
    }
}

// same output as primeFactor (sorted, with multiplicity) but O(n^(1/4))
// use for 1 <= n <= 1e18
vector<ll> primeFactorFast(ll n) {
    if (n == 1) return {};
    if (MillerRabin(n)) return {n};
    ll d = pollardRho(n);
    vector<ll> l = primeFactorFast(d), r = primeFactorFast(n / d);
    l.insert(l.end(), all(r));
    sort(all(l));
    return l;
}