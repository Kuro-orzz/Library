---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/Shortest_path/Bellman_ford.h
    title: Graph/Shortest_path/Bellman_ford.h
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
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
    \n    return 0;\r\n}\n#line 2 \"Graph/Shortest_path/Bellman_ford.h\"\n\n// if\
    \ exist negative cycle d[S] = 1e18\n// else return shortest path\nvector<ll> negativeCycle(int\
    \ S, int n, vector<vector<pii>> &g){\n    vector<ll> d(n+1, 1e18);\n    d[S] =\
    \ 0;\n    for (int i = 0; i < n - 1; i++) {\n        for (int u = 0; u < n; u++)\
    \ {\n            for (auto [v, w] : g[u]) {\n                if (d[u] != 1e18)\
    \ {\n                    d[v] = min(d[v], d[u]+w);\n                }\n      \
    \      }\n        }\n    }\n    for (int i = 0; i < n; i++) {\n        for (int\
    \ u = 0; u < n; u++) {\n            for (auto [v, w] : g[u]) {\n             \
    \   if (d[u] != 1e18 && d[v] > d[u] + w) {\n                    d[S] = 1e18;\n\
    \                    return d;\n                }\n            }\n        }\n\
    \    }\n    return d;\n}\n#line 5 \"Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp\"\
    \n\nvoid solve() {\n    int n, m, s; cin >> n >> m >> s;\n    vector<vector<pii>>\
    \ adj(n+1);\n    for (int i = 0; i < m; i++) {\n        int u, v, w; cin >> u\
    \ >> v >> w;\n        adj[u].push_back({v, w});\n    }\n    vector<ll> d = negativeCycle(s,\
    \ n, adj);\n    if (d[s] == 1e18) {\n        cout << \"NEGATIVE CYCLE\\n\";\n\
    \        return;\n    }\n    for (int i = 0; i < n; i++) {\n        if (d[i] ==\
    \ 1e18) {\n            cout << \"INF\\n\";\n        } else {\n            cout\
    \ << d[i] << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include \"../../template.h\"\n#include \"../Shortest_path/Bellman_ford.h\"\
    \n\nvoid solve() {\n    int n, m, s; cin >> n >> m >> s;\n    vector<vector<pii>>\
    \ adj(n+1);\n    for (int i = 0; i < m; i++) {\n        int u, v, w; cin >> u\
    \ >> v >> w;\n        adj[u].push_back({v, w});\n    }\n    vector<ll> d = negativeCycle(s,\
    \ n, adj);\n    if (d[s] == 1e18) {\n        cout << \"NEGATIVE CYCLE\\n\";\n\
    \        return;\n    }\n    for (int i = 0; i < n; i++) {\n        if (d[i] ==\
    \ 1e18) {\n            cout << \"INF\\n\";\n        } else {\n            cout\
    \ << d[i] << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.h
  - Graph/Shortest_path/Bellman_ford.h
  isVerificationFile: true
  path: Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp
layout: document
redirect_from:
- /verify/Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp
- /verify/Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp.html
title: Graph/Aizu/aizu_grl_1_b_negative_cycle.test.cpp
---
