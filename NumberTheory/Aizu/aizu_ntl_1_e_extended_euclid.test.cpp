#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include "../../template.h"
#include "../Math/Extended_euclid.h"

void solve() {
    ll a, b; cin >> a >> b;
    ll x, y;
    ll g = extended2(a, b, x, y);
    cout << x << " " << y << '\n';
}