---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DataStructure/DSU/Dsu_2D.h
    title: DataStructure/DSU/Dsu_2D.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://leetcode.com/problems/making-a-large-island/description/
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"DataStructure/DSU/Dsu_2D.h\"\
    \n\ntemplate <typename T>\nstruct Dsu_2D {\n    int n, m;\n    vector<vector<pii>>\
    \ par;\n    vector<vector<int>> sz;\n\n    Dsu_2D() {}\n    Dsu_2D(int _n, int\
    \ _m): n(_n), m(_m) {\n        par.resize(n+1, vector<pii>(m+1));\n        sz.resize(n+1,\
    \ vector<int>(m+1, 1));\n        for (int i = 0; i <= n; i++) {\n            for\
    \ (int j = 0; j <= m; j++) {\n                par[i][j] = {i, j};\n          \
    \  }\n        }\n    }\n\n    pii find(pii v) {\n        if (v == par[v.fi][v.se])\
    \ {\n            return v;\n        }\n        return par[v.fi][v.se] = find(par[v.fi][v.se]);\n\
    \    }\n\n    void merge(pii a, pii b) {\n        a = find(a);\n        b = find(b);\n\
    \        if (a == b) return;\n        if (sz[a.fi][a.se] < sz[b.fi][b.se]) {\n\
    \            swap(a, b);\n        }\n        par[b.fi][b.se] = a;\n        sz[a.fi][a.se]\
    \ += sz[b.fi][b.se];\n    }\n\n    bool same_component(pii u, pii v) {\n     \
    \   return find(u) == find(v);\n    }\n\n    int component_size(pii u) {\n   \
    \     u = find(u);\n        return sz[u.fi][u.se];\n    }\n\n    int max_component()\
    \ {\n        int res = 0;\n        for (int i = 0; i < n; i++) {\n           \
    \ for (int j = 0; j < m; j++) {\n                res = max(res, sz[i][j]);\n \
    \           }\n        }\n        return res;\n    }\n\n    bool isValid(int n,\
    \ int m, pii u) {\n        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se <\
    \ m;\n    }\n\n    /*----------- Paint cell and check maximum component ---------*/\n\
    \    int Try_all_cell (vector<vector<T>> &a) {\n        int dx[4] = {-1, 0, 0,\
    \ 1};\n        int dy[4] = {0, -1, 1, 0};\n        int ans = max_component();\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++)\
    \ {\n                if (a[i][j]) continue;\n                int t = 1;\n    \
    \            set<pii> s;\n                for (int k = 0; k < 4; k++) {\n    \
    \                pii u = {i + dx[k], j + dy[k]};\n                    if (isValid(n,\
    \ m, u) && a[u.fi][u.se]) {\n                        pii v = find(u);\n      \
    \                  if (s.count(v)) continue;\n                        t += sz[v.fi][v.se];\n\
    \                        s.insert(v);\n                    }\n               \
    \ }\n                ans = max(ans, t);\n            }\n        }\n        return\
    \ ans;\n    }\n    /*------------------------------------------------------------*/\n\
    \n    /*-------------------- Paint all row or col ------------------*/\n    int\
    \ Try_Row(int k, vector<vector<T>> &a) {\n        int dx[2] = {-1, 1};\n     \
    \   int dy[2] = {0, 0};\n        int res = 0;\n        set<pii> s;\n        for\
    \ (int i = 0; i < m; i++) {\n            if (a[k][i] == '.') res++;\n        \
    \    if (a[k][i] == '#') {\n                pii x = find({k, i});\n          \
    \      if (s.find(x) == s.end()) {\n                    res += sz[x.fi][x.se];\n\
    \                    s.insert({x.fi, x.se});\n                }\n            }\
    \ \n            for (int j = 0; j < 2; j++) {\n                pii u = {k + dx[j],\
    \ i + dy[j]};\n                if (isValid(n, m, u) && a[u.fi][u.se] == '#') {\n\
    \                    pii v = find(u);\n                    if (s.find(v) == s.end())\
    \ {\n                        s.insert(v);\n                        res += sz[v.fi][v.se];\n\
    \                    }   \n                }\n            }\n        }\n     \
    \   return res;\n    }\n\n    int Try_Col(int k, vector<vector<T>> &a) {\n   \
    \     int dx[2] = {0, 0};\n        int dy[2] = {-1, 1};\n        int res = 0;\n\
    \        set<pii> s;\n        for (int i = 0; i < n; i++) {\n            if (a[i][k]\
    \ == '.') res++;\n            if (a[i][k] == '#') {\n                pii x = find({i,\
    \ k});\n                if (s.find(x) == s.end()) {\n                    res +=\
    \ sz[x.fi][x.se];\n                    s.insert({x.fi, x.se});\n             \
    \   }\n            } \n            for (int j = 0; j < 2; j++) {\n           \
    \     pii u = {i+dx[j], k+dy[j]};\n                if (isValid(n, m, u) && a[u.fi][u.se]\
    \ == '#') {\n                    pii v = find(u);\n                    if (s.find(v)\
    \ == s.end()) {\n                        s.insert(v);\n                      \
    \  res += sz[v.fi][v.se];\n                    }   \n                }\n     \
    \       }\n        }\n        return res;\n    }\n    /*------------------------------------------------------------*/\n\
    };\n#line 3 \"DataStructure/Aizu/test_dsu_2d_2.cpp\"\n\n// AC: https://leetcode.com/problems/making-a-large-island/description/\n\
    \nclass Solution {\npublic:\n    int dx[4] = {-1, 0, 0, 1};\n    int dy[4] = {0,\
    \ -1, 1, 0};\n\n    int largestIsland(vector<vector<int>>& grid) {\n        int\
    \ n = grid.size();\n        Dsu_2D<int> g(n, n);    \n        for (int i = 0;\
    \ i < n; i++) {\n            for (int j = 0; j < n; j++) {\n                if\
    \ (!grid[i][j]) continue;\n                for (int k = 0; k < 4; k++) {\n   \
    \                 pii u = {i+dx[k], j+dy[k]};\n                    if (g.isValid(n,\
    \ n, u) && grid[u.fi][u.se]) {\n                        g.merge({i, j}, u);\n\
    \                    }\n                }\n            }\n        }\n        return\
    \ g.Try_all_cell(grid);\n    }\n};\n"
  code: "#include \"../../template.h\"\n#include \"../DSU/Dsu_2D.h\"\n\n// AC: https://leetcode.com/problems/making-a-large-island/description/\n\
    \nclass Solution {\npublic:\n    int dx[4] = {-1, 0, 0, 1};\n    int dy[4] = {0,\
    \ -1, 1, 0};\n\n    int largestIsland(vector<vector<int>>& grid) {\n        int\
    \ n = grid.size();\n        Dsu_2D<int> g(n, n);    \n        for (int i = 0;\
    \ i < n; i++) {\n            for (int j = 0; j < n; j++) {\n                if\
    \ (!grid[i][j]) continue;\n                for (int k = 0; k < 4; k++) {\n   \
    \                 pii u = {i+dx[k], j+dy[k]};\n                    if (g.isValid(n,\
    \ n, u) && grid[u.fi][u.se]) {\n                        g.merge({i, j}, u);\n\
    \                    }\n                }\n            }\n        }\n        return\
    \ g.Try_all_cell(grid);\n    }\n};"
  dependsOn:
  - template.h
  - DataStructure/DSU/Dsu_2D.h
  isVerificationFile: false
  path: DataStructure/Aizu/test_dsu_2d_2.cpp
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Aizu/test_dsu_2d_2.cpp
layout: document
redirect_from:
- /library/DataStructure/Aizu/test_dsu_2d_2.cpp
- /library/DataStructure/Aizu/test_dsu_2d_2.cpp.html
title: DataStructure/Aizu/test_dsu_2d_2.cpp
---
