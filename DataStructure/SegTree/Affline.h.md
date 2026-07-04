---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Yosupo/Range_affine_point_get.test.cpp
    title: DataStructure/Yosupo/Range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/Yosupo/Range_affine_range_sum.test.cpp
    title: DataStructure/Yosupo/Range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/Affline.h\"\n\ntemplate <typename T>\n\
    struct AfflineSegTree {\n    vector<T> st;\n    vector<pll> lazy;\n\n    AfflineSegTree()\
    \ {}\n    AfflineSegTree(int n): st(n*4), lazy(n*4) {}\n\n    void build(int id,\
    \ int l, int r, const vector<ll> &a) {\n        lazy[id] = {1, 0};\n        if\
    \ (l == r) {\n            st[id] = a[l] % mod;\n            return;\n        }\n\
    \        int m = (l + r) >> 1;\n        build(id*2, l, m, a);\n        build(id*2+1,\
    \ m+1, r, a);\n        st[id] = (st[id*2] + st[id*2+1]) % mod;\n    }\n\n    void\
    \ push(int id, int l, int r) {\n        int m = (l + r) >> 1;\n        apply(id*2,\
    \ l, m, lazy[id]);\n        apply(id*2+1, m+1, r, lazy[id]);\n        lazy[id]\
    \ = {1, 0};\n    }\n\n    void apply(int id, int l, int r, pll val) {\n      \
    \  int len = r-l+1;\n        st[id] = (st[id] * val.fi % mod + val.se * len %\
    \ mod) % mod;\n        lazy[id].fi = lazy[id].fi * val.fi % mod;\n        lazy[id].se\
    \ = (lazy[id].se * val.fi % mod + val.se) % mod;\n    }\n\n    void update(int\
    \ id, int l, int r, int u, int v, pll val) {\n        if (v < l || u > r)\n  \
    \          return;\n        if (u <= l && v >= r) {\n            apply(id, l,\
    \ r, val);\n            return;\n        }\n        push(id, l, r);\n        int\
    \ mid = (l + r) >> 1;\n        update(id*2, l, mid, u, v, val);\n        update(id*2+1,\
    \ mid+1, r, u, v, val);\n        st[id] = (st[id*2] + st[id*2+1]) % mod;\n   \
    \ }\n\n    T getSumMod(int id, int l, int r, int u, int v) {\n        if (l >\
    \ v || r < u) return 0;\n        if (l >= u && r <= v) return st[id];\n      \
    \  int mid = (l + r) >> 1;\n        push(id, l, r);\n        T t1 = getSumMod(id*2,\
    \ l, mid, u, v) % mod;\n        T t2 = getSumMod(id*2+1, mid+1, r, u, v) % mod;\n\
    \        return (t1 + t2) % mod;\n    }\n};\n"
  code: "#include \"../../template.h\"\n\ntemplate <typename T>\nstruct AfflineSegTree\
    \ {\n    vector<T> st;\n    vector<pll> lazy;\n\n    AfflineSegTree() {}\n   \
    \ AfflineSegTree(int n): st(n*4), lazy(n*4) {}\n\n    void build(int id, int l,\
    \ int r, const vector<ll> &a) {\n        lazy[id] = {1, 0};\n        if (l ==\
    \ r) {\n            st[id] = a[l] % mod;\n            return;\n        }\n   \
    \     int m = (l + r) >> 1;\n        build(id*2, l, m, a);\n        build(id*2+1,\
    \ m+1, r, a);\n        st[id] = (st[id*2] + st[id*2+1]) % mod;\n    }\n\n    void\
    \ push(int id, int l, int r) {\n        int m = (l + r) >> 1;\n        apply(id*2,\
    \ l, m, lazy[id]);\n        apply(id*2+1, m+1, r, lazy[id]);\n        lazy[id]\
    \ = {1, 0};\n    }\n\n    void apply(int id, int l, int r, pll val) {\n      \
    \  int len = r-l+1;\n        st[id] = (st[id] * val.fi % mod + val.se * len %\
    \ mod) % mod;\n        lazy[id].fi = lazy[id].fi * val.fi % mod;\n        lazy[id].se\
    \ = (lazy[id].se * val.fi % mod + val.se) % mod;\n    }\n\n    void update(int\
    \ id, int l, int r, int u, int v, pll val) {\n        if (v < l || u > r)\n  \
    \          return;\n        if (u <= l && v >= r) {\n            apply(id, l,\
    \ r, val);\n            return;\n        }\n        push(id, l, r);\n        int\
    \ mid = (l + r) >> 1;\n        update(id*2, l, mid, u, v, val);\n        update(id*2+1,\
    \ mid+1, r, u, v, val);\n        st[id] = (st[id*2] + st[id*2+1]) % mod;\n   \
    \ }\n\n    T getSumMod(int id, int l, int r, int u, int v) {\n        if (l >\
    \ v || r < u) return 0;\n        if (l >= u && r <= v) return st[id];\n      \
    \  int mid = (l + r) >> 1;\n        push(id, l, r);\n        T t1 = getSumMod(id*2,\
    \ l, mid, u, v) % mod;\n        T t2 = getSumMod(id*2+1, mid+1, r, u, v) % mod;\n\
    \        return (t1 + t2) % mod;\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SegTree/Affline.h
  requiredBy: []
  timestamp: '2025-05-08 02:01:24+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/Yosupo/Range_affine_range_sum.test.cpp
  - DataStructure/Yosupo/Range_affine_point_get.test.cpp
documentation_of: DataStructure/SegTree/Affline.h
layout: document
redirect_from:
- /library/DataStructure/SegTree/Affline.h
- /library/DataStructure/SegTree/Affline.h.html
title: DataStructure/SegTree/Affline.h
---
