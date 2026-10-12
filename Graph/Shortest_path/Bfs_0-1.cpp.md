---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"Graph/Shortest_path/Bfs_0-1.cpp\"\
    \n\r\n// Graph\r\nint bfs01(int s, int n, vector<vector<pii>> &g) {\r\n    vector<int>\
    \ d(n+1, INT_MAX);\r\n    deque<int> q; \r\n    q.push_front(s); \r\n    d[s]\
    \ = 0;\r\n    while (!q.empty()){\r\n        int u = q.front(); q.pop_front();\r\
    \n        for (pii edge : g[u]){\r\n            int v = edge.fi;\r\n         \
    \   int w = edge.se;\r\n            if (w + d[u] < d[v]){\r\n                d[v]\
    \ = w + d[u];\r\n                if (!w) {\r\n                    q.push_front(v);\r\
    \n                } else {\r\n                    q.push_back(v);\r\n        \
    \        }\r\n            }\r\n        }\r\n    }\r\n    return d[n];\r\n}\r\n\
    \r\n\r\n// Matrix 0-1\r\nint dx[4] = {-1, 0, 0, 1};\r\nint dy[4] = {0, -1, 1,\
    \ 0};\r\n\r\nbool isValid(pii u, int n, int m) { return u.fi >= 0 && u.fi < n\
    \ && u.se >= 0 && u.se < m; }\r\n\r\nint bfs01(vector<vector<int>> &grid, int\
    \ n, int m) {\r\n    vector<vector<int>> d(n, vector<int>(m, INT_MAX));\r\n  \
    \  deque<pii> q;\r\n    q.push_front({0, 0});\r\n    d[0][0] = grid[0][0];\r\n\
    \    while (!q.empty()) {\r\n        pii u = q.front(); q.pop_front();\r\n   \
    \     for (int i = 0; i < 4; i++) {\r\n            pii v = {u.fi + dx[i] ,u.se\
    \ + dy[i]};\r\n            if (!isValid(v, n, m)) continue;\r\n            int\
    \ w = grid[v.fi][v.se];\r\n            if (w + d[u.fi][u.se] < d[v.fi][v.se])\
    \ {\r\n                d[v.fi][v.se] = w + d[u.fi][u.se];\r\n                if\
    \ (!w) q.push_front(v);\r\n                else q.push_back(v);\r\n          \
    \  }\r\n        }\r\n    }\r\n    return d[n-1][m-1];\r\n}\n"
  code: "#include \"../../template.h\"\r\n\r\n// Graph\r\nint bfs01(int s, int n,\
    \ vector<vector<pii>> &g) {\r\n    vector<int> d(n+1, INT_MAX);\r\n    deque<int>\
    \ q; \r\n    q.push_front(s); \r\n    d[s] = 0;\r\n    while (!q.empty()){\r\n\
    \        int u = q.front(); q.pop_front();\r\n        for (pii edge : g[u]){\r\
    \n            int v = edge.fi;\r\n            int w = edge.se;\r\n           \
    \ if (w + d[u] < d[v]){\r\n                d[v] = w + d[u];\r\n              \
    \  if (!w) {\r\n                    q.push_front(v);\r\n                } else\
    \ {\r\n                    q.push_back(v);\r\n                }\r\n          \
    \  }\r\n        }\r\n    }\r\n    return d[n];\r\n}\r\n\r\n\r\n// Matrix 0-1\r\
    \nint dx[4] = {-1, 0, 0, 1};\r\nint dy[4] = {0, -1, 1, 0};\r\n\r\nbool isValid(pii\
    \ u, int n, int m) { return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m; }\r\
    \n\r\nint bfs01(vector<vector<int>> &grid, int n, int m) {\r\n    vector<vector<int>>\
    \ d(n, vector<int>(m, INT_MAX));\r\n    deque<pii> q;\r\n    q.push_front({0,\
    \ 0});\r\n    d[0][0] = grid[0][0];\r\n    while (!q.empty()) {\r\n        pii\
    \ u = q.front(); q.pop_front();\r\n        for (int i = 0; i < 4; i++) {\r\n \
    \           pii v = {u.fi + dx[i] ,u.se + dy[i]};\r\n            if (!isValid(v,\
    \ n, m)) continue;\r\n            int w = grid[v.fi][v.se];\r\n            if\
    \ (w + d[u.fi][u.se] < d[v.fi][v.se]) {\r\n                d[v.fi][v.se] = w +\
    \ d[u.fi][u.se];\r\n                if (!w) q.push_front(v);\r\n             \
    \   else q.push_back(v);\r\n            }\r\n        }\r\n    }\r\n    return\
    \ d[n-1][m-1];\r\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Graph/Shortest_path/Bfs_0-1.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Shortest_path/Bfs_0-1.cpp
layout: document
redirect_from:
- /library/Graph/Shortest_path/Bfs_0-1.cpp
- /library/Graph/Shortest_path/Bfs_0-1.cpp.html
title: Graph/Shortest_path/Bfs_0-1.cpp
---
