---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Tree/Tree/BinaryLifting.h
    title: Tree/Tree/BinaryLifting.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/jump_on_tree
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
  bundledCode: "#line 1 \"Tree/Yosupo/Jump_on_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#line 2 \"template.h\"\n\r\n\
    #include <bits/stdc++.h>\r\nusing namespace std;\r\n \r\n#define ll long long\r\
    \n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\n#define unique(x)\
    \ x.erase(unique(all(x)), x.end())\r\n#define INF32 ((1ull<<31)-1)\r\n#define\
    \ INF64 ((1ull<<63)-1)\r\n#define inf (ll)1e18\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main(){\r\n   \
    \ ios_base::sync_with_stdio(false);cin.tie(NULL);\r\n    // cin.exceptions(cin.failbit);\r\
    \n    // int t; cin >> t;\r\n    // while(t--)\r\n        solve();\r\n    cerr\
    \ << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\r\
    \n    return 0;\r\n}\n#line 2 \"Tree/Tree/BinaryLifting.h\"\n\nclass BinLift {\n\
    public:\n    int n;\n    vector<vector<int>> tree, up;\n    vector<int> lg, h;\n\
    \n    BinLift() {}\n    BinLift(int n): n(n), tree(n), up(n, vector<int>(20)),\
    \ lg(20), h(n) {}\n\n    void dfs(int u, int p) {\n        for(int v : tree[u])\
    \ {\n            if(v == p) continue;\n            up[v][0] = u;\n           \
    \ h[v] = h[u] + 1;\n            for(int j = 1; j < 20; j++)\n            up[v][j]\
    \ = up[up[v][j-1]][j-1];\n            dfs(v, u);\n        }\n    }\n\n    void\
    \ addEdge(int u, int v) {\n        tree[u].emplace_back(v);\n        tree[v].emplace_back(u);\n\
    \    }\n\n    int jump(int u, int v, int i) {\n        int t = lca(u, v);\n  \
    \      int diff1 = h[u]-h[t];\n        int diff2 = h[v]-h[t];\n        if (i >\
    \ diff1 + diff2) return -1;\n        if (i <= diff1) return ancestor_k(u, i);\n\
    \        else {\n            int step = i-diff1;\n            return ancestor_k(v,\
    \ diff2-step);\n        }\n    }\n\n    int lca(int u, int v) {\n        if(h[u]\
    \ < h[v]) swap(u, v);\n        int k = h[u]-h[v];\n        u = ancestor_k(u, k);\n\
    \        if(u == v) return u;\n\n        k = __lg(h[u]);\n        for(int j =\
    \ k; j >= 0; j--) {\n            if(up[u][j] != up[v][j]) {\n                u\
    \ = up[u][j];\n                v = up[v][j];\n            }\n        }\n     \
    \   return up[u][0];\n    }\n\n    int ancestor_k(int u, int k) {\n        for(int\
    \ j = 0; (1 << j) <= k; j++) {\n            if(k >> j & 1)\n                u\
    \ = up[u][j];\n        }\n        return u;\n    }\n};\n#line 5 \"Tree/Yosupo/Jump_on_tree.test.cpp\"\
    \n\nvoid solve() {\n    int n, q; cin >> n >> q;\n    BinLift binLift(n);\n  \
    \  for (int i = 0; i < n-1; i++) {\n        int u, v; cin >> u >> v;\n       \
    \ binLift.addEdge(u, v);\n    }\n    binLift.dfs(0, -1);\n    while (q--) {\n\
    \        int s, t, i; cin >> s >> t >> i;\n        cout << binLift.jump(s, t,\
    \ i) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#include\
    \ \"../../template.h\"\n#include \"../Tree/BinaryLifting.h\"\n\nvoid solve() {\n\
    \    int n, q; cin >> n >> q;\n    BinLift binLift(n);\n    for (int i = 0; i\
    \ < n-1; i++) {\n        int u, v; cin >> u >> v;\n        binLift.addEdge(u,\
    \ v);\n    }\n    binLift.dfs(0, -1);\n    while (q--) {\n        int s, t, i;\
    \ cin >> s >> t >> i;\n        cout << binLift.jump(s, t, i) << '\\n';\n    }\n\
    }"
  dependsOn:
  - template.h
  - Tree/Tree/BinaryLifting.h
  isVerificationFile: true
  path: Tree/Yosupo/Jump_on_tree.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Tree/Yosupo/Jump_on_tree.test.cpp
layout: document
redirect_from:
- /verify/Tree/Yosupo/Jump_on_tree.test.cpp
- /verify/Tree/Yosupo/Jump_on_tree.test.cpp.html
title: Tree/Yosupo/Jump_on_tree.test.cpp
---
