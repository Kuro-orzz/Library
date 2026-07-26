#include "../../template.h"
#include "Pollard_rho.h"

// smallest primitive root of a PRIME p, that is g with order exactly p-1
// g works iff g^((p-1)/q) != 1 for every distinct prime q of p-1
// O(n^(1/4)) to factor p-1, then a few binPow per candidate
ll primitiveRoot(ll p) {
    if (p == 2) return 1;
    vector<ll> q = primeFactorFast(p - 1);
    unique(q);
    for (ll g = 2; ; g++) {
        bool ok = true;
        for (ll x : q) {
            if (binPow(g, (p-1) / x, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}