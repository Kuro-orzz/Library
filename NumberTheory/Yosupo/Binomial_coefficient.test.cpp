#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient"

#include "../../template.h"
#include "../Math/Combination_any_mod.h"

void solve() {
    int t; ll m; cin >> t >> m;
    CombAnyMod C(m);
    while (t--) {
        ll n, k; cin >> n >> k;
        cout << C.comb(n, k) << '\n';
    }
}