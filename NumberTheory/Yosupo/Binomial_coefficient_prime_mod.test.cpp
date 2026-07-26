#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "../../template.h"
#include "../Math/Combination.h"

void solve() {
    int t; ll m; cin >> t >> m;
    Comb C(min(m - 1, (ll)1e7 - 1), m);
    while (t--) {
        int n, k; cin >> n >> k;
        cout << C.comb(n, k) << '\n';
    }
}