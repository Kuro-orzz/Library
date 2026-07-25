#include "../../template.h"
#include "MillerRabin.h"
#include "Sieve.h"

using u128 = __uint128_t;

// sum of all divisor [1, n]
// https://usaco.guide/problems/cses-1082-sum-of-divisors/solution
ll sum_of_divisor(ll n) {
    ll res = 0, i = 1;
    while (i <= n) {
        ll l = i;
        ll r = n / (n / i);
        ll val = n / l;
        ll csc = (u128)(r - l + 1) * (l + r) / 2 % MOD;
        res = (res + csc * val) % MOD;
        i = r + 1;
    }
    return res;
}

// count number of divisor up to n <= 1e18
// AC: https://codeforces.com/gym/100753 (Probblem F)
int count_divisor(ll n) {
    if (n == 1) return 1;
    static vector<int> prime = listPrime(1, 1e6+5);
    int ans = 1;
    for (int p : prime) {
        if (1ll * p * p * p > n) break;
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            cnt++;
        }
        ans *= cnt + 1;
    }
    auto isSqrt = [&](ll n)->bool {
        ll c = sqrtl(n);
        return c * c == n;
    };
    if (n == 1) return ans;
    if (MillerRabin(n)) ans *= 2;
    else if (isSqrt(n)) ans *= 3;
    else ans *= 4;
    return ans;
}