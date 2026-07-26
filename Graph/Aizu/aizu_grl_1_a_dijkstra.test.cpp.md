---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/Shortest_path/Dijkstra.h
    title: Graph/Shortest_path/Dijkstra.h
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"Graph/Aizu/aizu_grl_1_a_dijkstra.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\n\n#line\
    \ 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n \r\
    \n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\
    \n#define unique(x) x.erase(unique(all(x)), x.end())\r\n#define INF32 ((1ull<<31)-1)\r\
    \n#define INF64 ((1ull<<63)-1)\r\n#define inf (ll)1e18\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main(){\r\n   \
    \ ios_base::sync_with_stdio(false);cin.tie(NULL);\r\n    // cin.exceptions(cin.failbit);\r\
    \n    // int t; cin >> t;\r\n    // while(t--)\r\n        solve();\r\n    cerr\
    \ << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\r\
    \n    return 0;\r\n}\n#line 2 \"Graph/Shortest_path/Dijkstra.h\"\n\nvector<ll>\
    \ dijkstra(int s, int n, vector<vector<pii>> &g) {\n    vector<int> vis(n + 1);\n\
    \    vector<ll> d(n + 1, LLONG_MAX);\n    priority_queue<pii, vector<pii>, greater<pii>>\
    \ pq;\n    pq.push({d[s], s});\n    d[s] = 0;\n    while (!pq.empty()) {\n   \
    \     auto [dist, u] = pq.top(); pq.pop();\n        if (vis[u]) continue;\n  \
    \      vis[u] = 1;\n        for (auto [v, w] : g[u]) {\n            if (d[v] >\
    \ d[u] + w) {\n                d[v] = d[u] + w;\n                pq.push({d[v],\
    \ v});\n            }\n        }\n    }\n    return d;\n}\n\n\n\nstruct Oxyz {\n\
    \    int x, y, z;\n\n    Oxyz(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}\n\
    \n    bool operator < (Oxyz other) const {\n        if (x != other.x) return x\
    \ < other.x;\n        if (y != other.y) return y < other.y;\n        return z\
    \ < other.z;\n    }\n};\n\nusing plO = pair<ll, Oxyz>;\n\nint dijkstra(Oxyz s,\
    \ int n, vector<vector<vector<int>>> &a) {\n    vector<vector<vector<int>>> vis(n+1,\
    \ vector<vector<int>>(n+1, vector<int>(n+1, 0)));\n    vector<vector<vector<ll>>>\
    \ d(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1, 1e9)));\n    priority_queue<plO,\
    \ vector<plO>, greater<plO>> pq;\n    d[s.x][s.y][s.z] = 0;\n    pq.push({d[s.x][s.y][s.z],\
    \ s});\n    while (!pq.empty()) {\n        plO u = pq.top(); pq.pop();\n     \
    \   auto [dist, pos] = u;\n        auto [x, y, z] = pos;\n        if (vis[x][y][z])\
    \ continue;\n        vis[x][y][z] = 1;\n        for (int i = -1; i <= 1; i++)\
    \ {\n            for (int j = -1; j <= 1; j++) {\n                for (int k =\
    \ -1; k <= 1; k++) {\n                    Oxyz v(x+i, y+j, z+k);\n           \
    \         if (abs(v.x-x)+abs(v.y-y)+abs(v.z-z) != 1) continue;\n             \
    \       if (v.x < 1 || v.y < 1 || v.z < 1) continue;\n                    if (v.x\
    \ > n || v.y > n || v.z > n) continue;\n                    ll w = a[x+i][y+j][z+k];\n\
    \                    if (d[v.x][v.y][v.z] > dist + w) {\n                    \
    \    d[v.x][v.y][v.z] = dist + w;\n                        pq.push({d[v.x][v.y][v.z],\
    \ v});\n                    }\n                }\n            }\n        }\n \
    \   }\n    return d[n][n][n];\n}\n#line 5 \"Graph/Aizu/aizu_grl_1_a_dijkstra.test.cpp\"\
    \n\nvoid solve() {\n    int n, m, s; cin >> n >> m >> s;\n    vector<vector<pii>>\
    \ adj(n+1);\n    for (int i = 0; i < m; i++) {\n        int u, v, w; cin >> u\
    \ >> v >> w;\n        adj[u].push_back({v, w});\n    }\n    vector<ll> d = dijkstra(s,\
    \ n, adj);\n    for (int i = 0; i < n; i++) {\n        if (d[i] == LLONG_MAX)\
    \ {\n            cout << \"INF\\n\";\n        } else {\n            cout << d[i]\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include \"../../template.h\"\n#include \"../Shortest_path/Dijkstra.h\"\n\n\
    void solve() {\n    int n, m, s; cin >> n >> m >> s;\n    vector<vector<pii>>\
    \ adj(n+1);\n    for (int i = 0; i < m; i++) {\n        int u, v, w; cin >> u\
    \ >> v >> w;\n        adj[u].push_back({v, w});\n    }\n    vector<ll> d = dijkstra(s,\
    \ n, adj);\n    for (int i = 0; i < n; i++) {\n        if (d[i] == LLONG_MAX)\
    \ {\n            cout << \"INF\\n\";\n        } else {\n            cout << d[i]\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.h
  - Graph/Shortest_path/Dijkstra.h
  isVerificationFile: true
  path: Graph/Aizu/aizu_grl_1_a_dijkstra.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Graph/Aizu/aizu_grl_1_a_dijkstra.test.cpp
layout: document
redirect_from:
- /verify/Graph/Aizu/aizu_grl_1_a_dijkstra.test.cpp
- /verify/Graph/Aizu/aizu_grl_1_a_dijkstra.test.cpp.html
title: Graph/Aizu/aizu_grl_1_a_dijkstra.test.cpp
---
