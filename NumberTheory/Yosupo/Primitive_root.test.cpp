#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"

#include "../../template.h"
#include "../Math/Primitive_root.h"

void solve() {
    int q; cin >> q;
    while (q--) {
        ll p; cin >> p;
        cout << primitiveRoot(p) << '\n';
    }
}