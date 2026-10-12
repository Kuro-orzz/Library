---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree/Affline.h
    title: DataStructure/SegTree/Affline.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"DataStructure/Yosupo/Range_affine_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n\
    #line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \n \r\n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\
    \n#define unique(x) x.erase(unique(all(x)), x.end())\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main() {\r\n  \
    \  // if (FILE* f = fopen(TASK \".inp\", \"r\")) {\r\n    //     fclose(f);\r\n\
    \    //     freopen(TASK \".inp\", \"r\", stdin);\r\n    //     freopen(TASK \"\
    .out\", \"w\", stdout);\r\n    // }\r\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\r\
    \n    // cin.exceptions(cin.failbit);\r\n    // int t; cin >> t;\r\n    // while(t--)\r\
    \n        solve();\r\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"DataStructure/SegTree/Affline.h\"\
    \n\ntemplate <typename T>\nstruct AfflineSegTree {\n    vector<T> st;\n    vector<pll>\
    \ lazy;\n\n    AfflineSegTree() {}\n    AfflineSegTree(int n): st(n*4), lazy(n*4)\
    \ {}\n\n    void build(int id, int l, int r, const vector<ll> &a) {\n        lazy[id]\
    \ = {1, 0};\n        if (l == r) {\n            st[id] = a[l] % mod;\n       \
    \     return;\n        }\n        int m = (l + r) >> 1;\n        build(id*2, l,\
    \ m, a);\n        build(id*2+1, m+1, r, a);\n        st[id] = (st[id*2] + st[id*2+1])\
    \ % mod;\n    }\n\n    void push(int id, int l, int r) {\n        int m = (l +\
    \ r) >> 1;\n        apply(id*2, l, m, lazy[id]);\n        apply(id*2+1, m+1, r,\
    \ lazy[id]);\n        lazy[id] = {1, 0};\n    }\n\n    void apply(int id, int\
    \ l, int r, pll val) {\n        int len = r-l+1;\n        st[id] = (st[id] * val.fi\
    \ % mod + val.se * len % mod) % mod;\n        lazy[id].fi = lazy[id].fi * val.fi\
    \ % mod;\n        lazy[id].se = (lazy[id].se * val.fi % mod + val.se) % mod;\n\
    \    }\n\n    void update(int id, int l, int r, int u, int v, pll val) {\n   \
    \     if (v < l || u > r)\n            return;\n        if (u <= l && v >= r)\
    \ {\n            apply(id, l, r, val);\n            return;\n        }\n     \
    \   push(id, l, r);\n        int mid = (l + r) >> 1;\n        update(id*2, l,\
    \ mid, u, v, val);\n        update(id*2+1, mid+1, r, u, v, val);\n        st[id]\
    \ = (st[id*2] + st[id*2+1]) % mod;\n    }\n\n    T getSumMod(int id, int l, int\
    \ r, int u, int v) {\n        if (l > v || r < u) return 0;\n        if (l >=\
    \ u && r <= v) return st[id];\n        int mid = (l + r) >> 1;\n        push(id,\
    \ l, r);\n        T t1 = getSumMod(id*2, l, mid, u, v) % mod;\n        T t2 =\
    \ getSumMod(id*2+1, mid+1, r, u, v) % mod;\n        return (t1 + t2) % mod;\n\
    \    }\n};\n#line 5 \"DataStructure/Yosupo/Range_affine_range_sum.test.cpp\"\n\
    \nvoid solve() {\n    int n, q; cin >> n >> q;\n    vector<ll> a(n+1);\n    for\
    \ (int i = 1; i <= n; i++) {\n        cin >> a[i];\n    }\n    AfflineSegTree<ll>\
    \ st(n);\n    st.build(1, 1, n, a);\n    while (q--) {\n        int tv, l, r;\
    \ cin >> tv >> l >> r;\n        if (tv == 0) {\n            ll b, c; cin >> b\
    \ >> c;\n            st.update(1, 1, n, l+1, r, make_pair(b, c));\n        } else\
    \ if (tv == 1) {\n            cout << st.getSumMod(1, 1, n, l+1, r) << '\\n';\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../template.h\"\n#include \"../SegTree/Affline.h\"\n\nvoid solve()\
    \ {\n    int n, q; cin >> n >> q;\n    vector<ll> a(n+1);\n    for (int i = 1;\
    \ i <= n; i++) {\n        cin >> a[i];\n    }\n    AfflineSegTree<ll> st(n);\n\
    \    st.build(1, 1, n, a);\n    while (q--) {\n        int tv, l, r; cin >> tv\
    \ >> l >> r;\n        if (tv == 0) {\n            ll b, c; cin >> b >> c;\n  \
    \          st.update(1, 1, n, l+1, r, make_pair(b, c));\n        } else if (tv\
    \ == 1) {\n            cout << st.getSumMod(1, 1, n, l+1, r) << '\\n';\n     \
    \   }\n    }\n}"
  dependsOn:
  - template.h
  - DataStructure/SegTree/Affline.h
  isVerificationFile: true
  path: DataStructure/Yosupo/Range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Yosupo/Range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Yosupo/Range_affine_range_sum.test.cpp
- /verify/DataStructure/Yosupo/Range_affine_range_sum.test.cpp.html
title: DataStructure/Yosupo/Range_affine_range_sum.test.cpp
---
