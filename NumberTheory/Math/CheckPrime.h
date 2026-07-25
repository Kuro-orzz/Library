#include "../../template.h"


bool BruteForce(ll n) {
    if (n == 2 || n == 3) return true;
    if (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;
    ll lim = sqrtl(n);
    while (lim > 0 && lim > n / lim) lim--;
    for (ll i = 5; i <= lim; i += 6) {
        if (n % i == 0 || n % (i+2) == 0) return false;
    }
    return true;
}

// https://codeforces.com/blog/entry/91632
ll Meissel(ll n) {
    vector<ll> v;
    for (ll i = 1; i*i <= n; i++) {
        v.push_back(i);
        v.push_back(n / i);
    }
    sort(all(v));
    unique(v);
    ll sq = sqrt(n);
    auto geti = [&](ll x) {
        if (x <= sq) return x-1;
        return (int)v.size() - n / x;
    };
    vector<ll> dp = v;
    ll a = 0;
    for (ll p = 2; p*p <= n; p++) {
        if (dp[geti(p)] == dp[geti(p-1)]) continue;
        a++;
        for (int i = (int)v.size()-1; i >= 0; i--) {
            if (v[i] < p * p) break;
            dp[i] -= dp[geti(v[i] / p)] - a;
        }
    }
    return dp[geti(n)] - 1;
}