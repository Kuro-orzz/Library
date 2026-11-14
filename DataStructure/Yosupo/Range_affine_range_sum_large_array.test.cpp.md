---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree/SparseSegTree.h
    title: DataStructure/SegTree/SparseSegTree.h
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum_large_array
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum_large_array
  bundledCode: "#line 1 \"DataStructure/Yosupo/Range_affine_range_sum_large_array.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum_large_array\"\
    \n\n#line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"DataStructure/SegTree/SparseSegTree.h\"\
    \n\n\nstruct Node {\n    Node *left = nullptr, *right = nullptr;\n    ll val;\n\
    \    pll lazy = {1, 0};\n    \n    Node(): val(0), lazy({1, 0}) {}\n    \n   \
    \ Node operator+(const Node& b) const {\n        Node res;\n        res.val =\
    \ (val + b.val) % mod;\n        return res;\n    }\n\n    ~Node() {\n        delete\
    \ left;\n        delete right;\n    }\n};\n\nclass SparseSegTree {\nprivate:\n\
    \    Node *r = new Node();\n    int n;\n\n    void push(Node *cur, int l, int\
    \ r) {\n        int m = (l + r) >> 1;\n        if (!cur->left) cur->left = new\
    \ Node();\n        if (!cur->right) cur->right = new Node();\n        apply(cur->left,\
    \ l, m, cur->lazy);\n        apply(cur->right, m+1, r, cur->lazy);\n        cur->lazy\
    \ = {1, 0};\n    }\n\n    void apply(Node *cur, int l, int r, pll x) {\n     \
    \   ll b = x.fi, c = x.se;\n        int len = r-l+1;\n        cur->val = (cur->val\
    \ * b % mod + c * len % mod) % mod;\n        cur->lazy.fi = cur->lazy.fi * b %\
    \ mod;\n        cur->lazy.se = (cur->lazy.se * b % mod + c) % mod;\n    }\n\n\
    \    void update(Node *cur, int l, int r, int u, int v, pll x) {\n        if (l\
    \ > v || r < u) return;\n        if (u <= l && r <= v) {\n            apply(cur,\
    \ l, r, x);\n            return;\n        }\n        push(cur, l, r);\n      \
    \  ll mid = (l + r) >> 1;\n        update(cur->left, l, mid, u, v, x);\n     \
    \   update(cur->right, mid+1, r, u, v, x);\n        cur->val = (cur->left->val\
    \ + cur->right->val) % mod;\n    }\n\n    ll query(Node *cur, int l, int r, int\
    \ u, int v) {\n        if (l > v || r < u) return 0;\n        if (u <= l && r\
    \ <= v) return cur->val;\n        push(cur, l, r);\n        int mid = (l + r)\
    \ >> 1;\n        ll t1 = query(cur->left, l, mid, u, v) % mod;\n        ll t2\
    \ = query(cur->right, mid+1, r, u, v) % mod;\n        return (t1 + t2) % mod;\n\
    \    }\n\npublic:\n    SparseSegTree() {}\n    SparseSegTree(int _n): n(_n) {}\n\
    \n    void update(int u, int v, pll val) { update(r, 1, n, u, v, val); }\n   \
    \ \n    ll query(int u, int v) { return query(r, 1, n, u, v); }\n};\n#line 5 \"\
    DataStructure/Yosupo/Range_affine_range_sum_large_array.test.cpp\"\n\nvoid solve()\
    \ {\n    int n, q; cin >> n >> q;\n    SparseSegTree st(n);\n    while (q--) {\n\
    \        int tv, l, r; cin >> tv >> l >> r;\n        if (tv == 0) {\n        \
    \    ll b, c; cin >> b >> c;\n            st.update(l+1, r, {b, c});\n       \
    \ } else if (tv == 1) {\n            cout << st.query(l+1, r) << '\\n';\n    \
    \    }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum_large_array\"\
    \n\n#include \"../../template.h\"\n#include \"../SegTree/SparseSegTree.h\"\n\n\
    void solve() {\n    int n, q; cin >> n >> q;\n    SparseSegTree st(n);\n    while\
    \ (q--) {\n        int tv, l, r; cin >> tv >> l >> r;\n        if (tv == 0) {\n\
    \            ll b, c; cin >> b >> c;\n            st.update(l+1, r, {b, c});\n\
    \        } else if (tv == 1) {\n            cout << st.query(l+1, r) << '\\n';\n\
    \        }\n    }\n}"
  dependsOn:
  - template.h
  - DataStructure/SegTree/SparseSegTree.h
  isVerificationFile: true
  path: DataStructure/Yosupo/Range_affine_range_sum_large_array.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Yosupo/Range_affine_range_sum_large_array.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Yosupo/Range_affine_range_sum_large_array.test.cpp
- /verify/DataStructure/Yosupo/Range_affine_range_sum_large_array.test.cpp.html
title: DataStructure/Yosupo/Range_affine_range_sum_large_array.test.cpp
---
