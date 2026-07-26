---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Yosupo/Point_add_range_sum.test.cpp
    title: DataStructure/Yosupo/Point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n \r\n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x)\
    \ (x).begin(),(x).end()\r\n#define unique(x) x.erase(unique(all(x)), x.end())\r\
    \n#define INF32 ((1ull<<31)-1)\r\n#define INF64 ((1ull<<63)-1)\r\n#define inf\
    \ (ll)1e18\r\n\r\n#define vi vector<int>\r\n#define pii pair<int, int>\r\n#define\
    \ pll pair<ll, ll>\r\n#define fi first\r\n#define se second\r\n\r\nmt19937_64\
    \ rng(chrono::steady_clock::now().time_since_epoch().count());\r\nll get_rand(ll\
    \ r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\r\nconst int\
    \ mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main(){\r\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\r\
    \n    // cin.exceptions(cin.failbit);\r\n    // int t; cin >> t;\r\n    // while(t--)\r\
    \n        solve();\r\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"DataStructure/SegTree/SegTree.h\"\
    \n\ntemplate <typename T>\nstruct SegTree {\n    int n;\n    vector<T> tree;\n\
    \n    SegTree() {}\n    SegTree(int _n): n(_n), tree(_n*4) {}\n\n    void update(int\
    \ pos, T val) {\n        update(1, 1, n, pos, val);\n    }\n\n    T getSum(int\
    \ u, int v) {\n        return getSum(1, 1, n, u, v);\n    }\n\n    void update(int\
    \ id, int l, int r, int pos, T val) {\n        if (pos < l || pos > r) return;\n\
    \        if (l == r) {\n            tree[id] += val;\n            return;\n  \
    \      }\n        int mid = (l + r) >> 1;\n        update(id*2, l, mid, pos, val);\n\
    \        update(id*2+1, mid+1, r, pos, val);\n        tree[id] = tree[id*2] +\
    \ tree[id*2+1];\n    }\n\n    T getSum(int id, int l, int r, int u, int v) {\n\
    \        if (l > v || r < u) return 0;\n        if (l >= u && r <= v) return tree[id];\n\
    \        int mid = (l + r) >> 1;\n        T t1 = getSum(id*2, l, mid, u, v);\n\
    \        T t2 = getSum(id*2+1, mid+1, r, u, v);\n        return t1 + t2;\n   \
    \ }\n};\n"
  code: "#include \"../../template.h\"\n\ntemplate <typename T>\nstruct SegTree {\n\
    \    int n;\n    vector<T> tree;\n\n    SegTree() {}\n    SegTree(int _n): n(_n),\
    \ tree(_n*4) {}\n\n    void update(int pos, T val) {\n        update(1, 1, n,\
    \ pos, val);\n    }\n\n    T getSum(int u, int v) {\n        return getSum(1,\
    \ 1, n, u, v);\n    }\n\n    void update(int id, int l, int r, int pos, T val)\
    \ {\n        if (pos < l || pos > r) return;\n        if (l == r) {\n        \
    \    tree[id] += val;\n            return;\n        }\n        int mid = (l +\
    \ r) >> 1;\n        update(id*2, l, mid, pos, val);\n        update(id*2+1, mid+1,\
    \ r, pos, val);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    }\n\n    T\
    \ getSum(int id, int l, int r, int u, int v) {\n        if (l > v || r < u) return\
    \ 0;\n        if (l >= u && r <= v) return tree[id];\n        int mid = (l + r)\
    \ >> 1;\n        T t1 = getSum(id*2, l, mid, u, v);\n        T t2 = getSum(id*2+1,\
    \ mid+1, r, u, v);\n        return t1 + t2;\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SegTree/SegTree.h
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/Yosupo/Point_add_range_sum.test.cpp
documentation_of: DataStructure/SegTree/SegTree.h
layout: document
redirect_from:
- /library/DataStructure/SegTree/SegTree.h
- /library/DataStructure/SegTree/SegTree.h.html
title: DataStructure/SegTree/SegTree.h
---
