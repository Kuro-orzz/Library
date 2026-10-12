---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Tree/Yosupo/Lowest_common_ancestor.test.cpp
    title: Tree/Yosupo/Lowest_common_ancestor.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"Tree/Tree/Lca.h\"\n\nstruct\
    \ Lca {\n    vector<vector<int>> tree, up;\n    vector<int> h;\n\n    Lca() {}\n\
    \    Lca(int n): tree(n+1), up(n+1, vector<int>(20)), h(n+1, 0) {}\n\n    void\
    \ dfs(int u, int p) {\n        for(int v : tree[u]) {\n            if(v == p)\
    \ continue;\n            up[v][0] = u;\n            h[v] = h[u] + 1;\n       \
    \     for(int j = 1; j < 20; j++) {\n                up[v][j] = up[up[v][j-1]][j-1];\n\
    \            }\n            dfs(v, u);\n        }\n    }\n\n    void addEdge(int\
    \ u, int v) {\n        tree[u].emplace_back(v);\n        tree[v].emplace_back(u);\n\
    \    }\n\n    int query(int u, int v) {\n        if(h[u] < h[v]) swap(u, v);\n\
    \        int k = h[u]-h[v];\n        u = ancestor_k(u, k);\n        if(u == v)\
    \ return u;\n\n        k = __lg(h[u]);\n        for(int j = k; j >= 0; j--) {\n\
    \            if(up[u][j] != up[v][j]) {\n                u = up[u][j];\n     \
    \           v = up[v][j];\n            }\n        }\n        return up[u][0];\n\
    \    }\n\n    int dist(int u, int v) {\n        int node = query(u, v);\n    \
    \    return h[u] + h[v] - 2 * h[node];\n    }\n\n    int ancestor_k(int u, int\
    \ k) {\n        for(int j = 0; (1 << j) <= k; j++) {\n            if(k >> j &\
    \ 1)\n                u = up[u][j];\n        }\n        return u;\n    }\n};\n"
  code: "#include \"../../template.h\"\n\nstruct Lca {\n    vector<vector<int>> tree,\
    \ up;\n    vector<int> h;\n\n    Lca() {}\n    Lca(int n): tree(n+1), up(n+1,\
    \ vector<int>(20)), h(n+1, 0) {}\n\n    void dfs(int u, int p) {\n        for(int\
    \ v : tree[u]) {\n            if(v == p) continue;\n            up[v][0] = u;\n\
    \            h[v] = h[u] + 1;\n            for(int j = 1; j < 20; j++) {\n   \
    \             up[v][j] = up[up[v][j-1]][j-1];\n            }\n            dfs(v,\
    \ u);\n        }\n    }\n\n    void addEdge(int u, int v) {\n        tree[u].emplace_back(v);\n\
    \        tree[v].emplace_back(u);\n    }\n\n    int query(int u, int v) {\n  \
    \      if(h[u] < h[v]) swap(u, v);\n        int k = h[u]-h[v];\n        u = ancestor_k(u,\
    \ k);\n        if(u == v) return u;\n\n        k = __lg(h[u]);\n        for(int\
    \ j = k; j >= 0; j--) {\n            if(up[u][j] != up[v][j]) {\n            \
    \    u = up[u][j];\n                v = up[v][j];\n            }\n        }\n\
    \        return up[u][0];\n    }\n\n    int dist(int u, int v) {\n        int\
    \ node = query(u, v);\n        return h[u] + h[v] - 2 * h[node];\n    }\n\n  \
    \  int ancestor_k(int u, int k) {\n        for(int j = 0; (1 << j) <= k; j++)\
    \ {\n            if(k >> j & 1)\n                u = up[u][j];\n        }\n  \
    \      return u;\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Tree/Tree/Lca.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Tree/Yosupo/Lowest_common_ancestor.test.cpp
documentation_of: Tree/Tree/Lca.h
layout: document
redirect_from:
- /library/Tree/Tree/Lca.h
- /library/Tree/Tree/Lca.h.html
title: Tree/Tree/Lca.h
---
