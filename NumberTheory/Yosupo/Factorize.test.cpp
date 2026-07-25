#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../../template.h"
#include "../Math/Pollard_rho.h"

void solve() {
    int q; cin >> q;
    while (q--) {
        ll a; cin >> a;
        vector<ll> f = primeFactorFast(a);
        cout << f.size();
        for (ll p : f) cout << ' ' << p;
        cout << '\n';
    }
}