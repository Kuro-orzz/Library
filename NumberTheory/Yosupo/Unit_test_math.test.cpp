#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template.h"
#include "../Math/Divisors.h"
#include "../Math/Factorial.h"
#include "../Math/Misc.h"

void solve() {
    const int N = 200000;

    // count_divisor vs sieve_count_divisors
    auto dv = sieve_count_divisors(N);
    for (int n = 1; n <= N; n++) assert(count_divisor(n) == dv[n]);

    // sum_of_divisor vs prefix sum of sieve_sum_divisors
    auto sd = sieve_sum_divisors(N);
    ll acc = 0;
    for (int n = 1; n <= N; n++) {
        acc = (acc + sd[n]) % MOD;
        if (n % 4096 == 0 || n == N) assert(sum_of_divisor(n) == acc);
    }

    // factmod vs brute force
    for (ll p : {2LL, 3LL, 97LL, 9973LL}) {
        ll r = 1;
        for (ll n = 1; n <= 5000; n++) {
            ll x = n;
            while (x % p == 0) x /= p;
            r = r * (x % p) % p;
            assert(factmod(n, p) == r);
        }
    }

    // GCD, LCM
    for (ll a = -60; a <= 60; a++) for (ll b = -60; b <= 60; b++) {
        ll g = GCD(a, b), l = LCM(a, b);
        if (a && b) {
            assert(llabs(a) % g == 0 && llabs(b) % g == 0);
            assert(l == llabs(a * b) / g);
        } else assert(l == 0);
    }

    // base conversion round trip
    for (int base = 2; base <= 36; base++)
        for (ll v = 0; v <= 3000; v++)
            assert(convert_decimal(decimal_to_base(v, base), base) == v);

    ll a, b; cin >> a >> b;
    cout << a + b << '\n';
}