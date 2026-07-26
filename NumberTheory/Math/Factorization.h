#include "../../template.h"


// 360 -> [2, 2, 2, 3, 3, 5]
vector<ll> primeFactor(ll n) {
    vector<ll> factor;
    for (int i : {2, 3, 5}) {
        while (n % i == 0) {
            n /= i;
            factor.push_back(i);
        }
    }
    int inc[] = {4, 2, 4, 2, 4, 6, 2, 6};
    int j = 0;
    ll lim = sqrtl(n);
    while (lim > 0 && lim > n / lim) lim--;
    for (ll i = 7; i <= lim; i += inc[j%8], j++) {
        if (n % i) continue;
        while(n % i == 0) {
            n /= i;
            factor.push_back(i);
        }
        lim = sqrtl(n);
        while (lim > 0 && lim > n / lim) lim--;
    }
    if (n > 1) factor.push_back(n);
    return factor;
}

// [2, 2, 2, 3, 3, 5] -> [(2,3), (3,2), (5,1)]
vector<pll> primeFactorPow(ll n) {
    vector<pll> res;
    for (ll p : primeFactor(n))
        if (!res.empty() && res.back().fi == p) res.back().se++;
        else res.push_back({p, 1});
    return res;
}