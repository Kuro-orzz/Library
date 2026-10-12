---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Yosupo/Static_range_sum.test.cpp
    title: DataStructure/Yosupo/Static_range_sum.test.cpp
  - icon: ':x:'
    path: Tree/Yosupo/Vertex_add_subtree_sum.test.cpp
    title: Tree/Yosupo/Vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n \r\n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x)\
    \ (x).begin(),(x).end()\r\n#define unique(x) x.erase(unique(all(x)), x.end())\r\
    \n\r\n#define vi vector<int>\r\n#define pii pair<int, int>\r\n#define pll pair<ll,\
    \ ll>\r\n#define fi first\r\n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main() {\r\n  \
    \  // if (FILE* f = fopen(TASK \".inp\", \"r\")) {\r\n    //     fclose(f);\r\n\
    \    //     freopen(TASK \".inp\", \"r\", stdin);\r\n    //     freopen(TASK \"\
    .out\", \"w\", stdout);\r\n    // }\r\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\r\
    \n    // cin.exceptions(cin.failbit);\r\n    // int t; cin >> t;\r\n    // while(t--)\r\
    \n        solve();\r\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"DataStructure/Fenwick/Fenwick.h\"\
    \n\ntemplate <typename T>\nstruct Fenwick{\n    int n;\n    vector<T> fen;\n\n\
    \    Fenwick() {}\n    Fenwick(int _n): n(_n), fen(_n+1) {}\n\n    void update(int\
    \ pos, T val) {\n        for (; pos <= n; pos += pos & -pos) {\n            fen[pos]\
    \ += val;\n        }\n    }\n\n    T get(int pos) {\n        T ans = 0;\n    \
    \    for (; pos > 0; pos -= pos & -pos) {\n            ans += fen[pos];\n    \
    \    }\n        return ans;\n    }\n\n    T get(int l, int r) {\n        return\
    \ get(r) - get(l - 1);\n    }\n\n    void update_range(int l, int r, T val){\n\
    \        update(l, val);\n        update(r+1, -val);\n    }\n\n    void reset()\
    \ {\n        fill(all(fen), T(0));\n    }\n};\n"
  code: "#include \"../../template.h\"\n\ntemplate <typename T>\nstruct Fenwick{\n\
    \    int n;\n    vector<T> fen;\n\n    Fenwick() {}\n    Fenwick(int _n): n(_n),\
    \ fen(_n+1) {}\n\n    void update(int pos, T val) {\n        for (; pos <= n;\
    \ pos += pos & -pos) {\n            fen[pos] += val;\n        }\n    }\n\n   \
    \ T get(int pos) {\n        T ans = 0;\n        for (; pos > 0; pos -= pos & -pos)\
    \ {\n            ans += fen[pos];\n        }\n        return ans;\n    }\n\n \
    \   T get(int l, int r) {\n        return get(r) - get(l - 1);\n    }\n\n    void\
    \ update_range(int l, int r, T val){\n        update(l, val);\n        update(r+1,\
    \ -val);\n    }\n\n    void reset() {\n        fill(all(fen), T(0));\n    }\n\
    };"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/Fenwick/Fenwick.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Tree/Yosupo/Vertex_add_subtree_sum.test.cpp
  - DataStructure/Yosupo/Static_range_sum.test.cpp
documentation_of: DataStructure/Fenwick/Fenwick.h
layout: document
redirect_from:
- /library/DataStructure/Fenwick/Fenwick.h
- /library/DataStructure/Fenwick/Fenwick.h.html
title: DataStructure/Fenwick/Fenwick.h
---
