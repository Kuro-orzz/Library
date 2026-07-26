---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Shortest_path/Floyd_warshall.h
    title: Graph/Shortest_path/Floyd_warshall.h
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"Graph/Aizu/aizu_grl_1_c_floyd_warshall.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \n \r\n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\
    \n#define unique(x) x.erase(unique(all(x)), x.end())\r\n#define INF32 ((1ull<<31)-1)\r\
    \n#define INF64 ((1ull<<63)-1)\r\n#define inf (ll)1e18\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main(){\r\n   \
    \ ios_base::sync_with_stdio(false);cin.tie(NULL);\r\n    // cin.exceptions(cin.failbit);\r\
    \n    // int t; cin >> t;\r\n    // while(t--)\r\n        solve();\r\n    cerr\
    \ << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\r\
    \n    return 0;\r\n}\n#line 2 \"Graph/Shortest_path/Floyd_warshall.h\"\n\nvoid\
    \ initTrace(int n, vector<vector<int>> &trace) {\n    for (int u = 1; u <= n;\
    \ ++u) {\n        for (int v = 1; v <= n; ++v) {\n            trace[u][v] = u;\n\
    \        }\n    }\n}\n\nvoid floyd_warshall(int n, vector<vector<ll>> &dist, vector<vector<int>>\
    \ &trace) {\n    initTrace(n, trace);\n    for (int k = 1; k <= n; ++k) {\n  \
    \      for (int u = 1; u <= n; ++u) {\n            for (int v = 1; v <= n; ++v)\
    \ {\n                if (dist[u][k] != 1e18 && dist[k][v] != 1e18 && dist[u][v]\
    \ > dist[u][k] + dist[k][v]) {\n                    dist[u][v] = dist[u][k] +\
    \ dist[k][v];\n                    trace[u][v] = trace[k][v];\n              \
    \  }\n            }\n        }\n    }\n}\n#line 5 \"Graph/Aizu/aizu_grl_1_c_floyd_warshall.test.cpp\"\
    \n\nvoid solve() {\n    int n, m; cin >> n >> m;\n    vector<vector<ll>> d(n+1,\
    \ vector<ll>(n+1, 1e18));\n    vector<vector<int>> trace(n+1, vector<int>(n+1));\n\
    \    for (int i = 1; i <= n; i++) {\n        d[i][i] = 0;\n    }\n    for (int\
    \ i = 0; i < m; i++) {\n        ll u, v, w; cin >> u >> v >> w;\n        d[u+1][v+1]\
    \ = min(d[u+1][v+1], w);\n    }\n    floyd_warshall(n, d, trace);\n    for (int\
    \ i = 1; i <= n; i++) {\n        if (d[i][i] < 0) {\n            cout << \"NEGATIVE\
    \ CYCLE\\n\";\n            return;\n        }\n    }\n    for (int i = 0; i <\
    \ n; i++) {\n        for (int j = 0; j < n; j++) {\n            if (d[i+1][j+1]\
    \ == 1e18) {\n                cout << \"INF\";\n            } else {\n       \
    \         cout << d[i+1][j+1];\n            }\n            cout << (j == n - 1\
    \ ? '\\n' : ' ');\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include \"../../template.h\"\n#include \"../Shortest_path/Floyd_warshall.h\"\
    \n\nvoid solve() {\n    int n, m; cin >> n >> m;\n    vector<vector<ll>> d(n+1,\
    \ vector<ll>(n+1, 1e18));\n    vector<vector<int>> trace(n+1, vector<int>(n+1));\n\
    \    for (int i = 1; i <= n; i++) {\n        d[i][i] = 0;\n    }\n    for (int\
    \ i = 0; i < m; i++) {\n        ll u, v, w; cin >> u >> v >> w;\n        d[u+1][v+1]\
    \ = min(d[u+1][v+1], w);\n    }\n    floyd_warshall(n, d, trace);\n    for (int\
    \ i = 1; i <= n; i++) {\n        if (d[i][i] < 0) {\n            cout << \"NEGATIVE\
    \ CYCLE\\n\";\n            return;\n        }\n    }\n    for (int i = 0; i <\
    \ n; i++) {\n        for (int j = 0; j < n; j++) {\n            if (d[i+1][j+1]\
    \ == 1e18) {\n                cout << \"INF\";\n            } else {\n       \
    \         cout << d[i+1][j+1];\n            }\n            cout << (j == n - 1\
    \ ? '\\n' : ' ');\n        }\n    }\n}"
  dependsOn:
  - template.h
  - Graph/Shortest_path/Floyd_warshall.h
  isVerificationFile: true
  path: Graph/Aizu/aizu_grl_1_c_floyd_warshall.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/Aizu/aizu_grl_1_c_floyd_warshall.test.cpp
layout: document
redirect_from:
- /verify/Graph/Aizu/aizu_grl_1_c_floyd_warshall.test.cpp
- /verify/Graph/Aizu/aizu_grl_1_c_floyd_warshall.test.cpp.html
title: Graph/Aizu/aizu_grl_1_c_floyd_warshall.test.cpp
---
