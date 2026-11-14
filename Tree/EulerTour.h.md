---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Tree/Yosupo/Vertex_add_subtree_sum.test.cpp
    title: Tree/Yosupo/Vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"Tree/EulerTour.h\"\n\n\
    vector<int> EulerTour(vector<int> &st, vector<int> &en, \n                vector<vector<int>>\
    \ &adj, int root = 0, int type = 0) {\n    int n = adj.size();\n    st.assign(n,\
    \ 0);\n    en.assign(n, 0);\n    vector<int> tour;\n    if (type == 0) tour.reserve(n);\n\
    \    else if (type == 1) tour.reserve(2 * n);\n    int pos = 0;\n    function<void(int,\
    \ int)> dfs = [&] (int u, int par) {\n        tour.push_back(u);\n        st[u]\
    \ = ++pos;\n        for (int v : adj[u]) {\n            if (v == par) continue;\n\
    \            dfs(v, u);\n        }\n        if (type == 1) {\n            tour.push_back(u);\n\
    \            pos++;\n        }\n        en[u] = pos;\n    };\n    dfs(root, -1);\n\
    \    return tour;\n}\n"
  code: "#include \"../template.h\"\n\nvector<int> EulerTour(vector<int> &st, vector<int>\
    \ &en, \n                vector<vector<int>> &adj, int root = 0, int type = 0)\
    \ {\n    int n = adj.size();\n    st.assign(n, 0);\n    en.assign(n, 0);\n   \
    \ vector<int> tour;\n    if (type == 0) tour.reserve(n);\n    else if (type ==\
    \ 1) tour.reserve(2 * n);\n    int pos = 0;\n    function<void(int, int)> dfs\
    \ = [&] (int u, int par) {\n        tour.push_back(u);\n        st[u] = ++pos;\n\
    \        for (int v : adj[u]) {\n            if (v == par) continue;\n       \
    \     dfs(v, u);\n        }\n        if (type == 1) {\n            tour.push_back(u);\n\
    \            pos++;\n        }\n        en[u] = pos;\n    };\n    dfs(root, -1);\n\
    \    return tour;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Tree/EulerTour.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Tree/Yosupo/Vertex_add_subtree_sum.test.cpp
documentation_of: Tree/EulerTour.h
layout: document
redirect_from:
- /library/Tree/EulerTour.h
- /library/Tree/EulerTour.h.html
title: Tree/EulerTour.h
---
