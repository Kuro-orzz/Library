---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Graph/Flow/MaxFlowEdmondsKarp.h
    title: Graph/Flow/MaxFlowEdmondsKarp.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"Graph/Aizu/aizu_grl_6_a_maximum_flow2.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\r\n\r\n\
    #line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \n \r\n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\
    \n#define unique(x) x.erase(unique(all(x)), x.end())\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main() {\r\n  \
    \  // if (FILE* f = fopen(TASK \".inp\", \"r\")) {\r\n    //     fclose(f);\r\n\
    \    //     freopen(TASK \".inp\", \"r\", stdin);\r\n    //     freopen(TASK \"\
    .out\", \"w\", stdout);\r\n    // }\r\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\r\
    \n    // cin.exceptions(cin.failbit);\r\n    // int t; cin >> t;\r\n    // while(t--)\r\
    \n        solve();\r\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 1 \"Graph/Flow/MaxFlowEdmondsKarp.h\"\
    \n// // vnoi version\r\n// struct EdmondsKarp {\r\n//     int n;\r\n//     vector<vector<int>>\
    \ adj;\r\n//     vector<vector<ll>> c, f;\r\n//     vector<int> trace;\r\n\r\n\
    //     EdmondsKarp(int n) : n(n), adj(n + 1), c(n + 1, vector<ll>(n + 1, 0)),\
    \ f(n + 1, vector<ll>(n + 1, 0)) {}\r\n\r\n//     void addEdge(int u, int v, ll\
    \ w) {\r\n//         adj[u].push_back(v);\r\n//         adj[v].push_back(u);\r\
    \n//         c[u][v] += w;\r\n//     }\r\n\r\n//     bool bfs(int s, int t) {\r\
    \n//         trace.assign(n + 1, 0);\r\n//         queue<int> q;\r\n//       \
    \  q.push(s);\r\n//         trace[s] = -1;\r\n//         while (!q.empty()) {\r\
    \n//             int u = q.front(); q.pop();\r\n//             for (int v : adj[u])\
    \ {\r\n//                 if (trace[v] || c[u][v] - f[u][v] == 0) continue;\r\n\
    //                 trace[v] = u;\r\n//                 q.push(v);\r\n//      \
    \       }\r\n//         }\r\n//         return trace[t] != 0;\r\n//     }\r\n\r\
    \n//     ll maxFlow(int s, int t) {\r\n//         ll res = 0;\r\n//         while\
    \ (bfs(s, t)) {\r\n//             ll delta = LLONG_MAX;\r\n//             for\
    \ (int v = t; v != s; v = trace[v]) {\r\n//                 int u = trace[v];\r\
    \n//                 delta = min(delta, c[u][v] - f[u][v]);\r\n//            \
    \ }\r\n//             for (int v = t; v != s; v = trace[v]) {\r\n//          \
    \       int u = trace[v];\r\n//                 f[u][v] += delta;\r\n//      \
    \           f[v][u] -= delta;\r\n//             }\r\n//             res += delta;\r\
    \n//         }\r\n//         return res;\r\n//     }\r\n\r\n//     bool inA(int\
    \ u) { return trace[u] != 0; }\r\n// };\r\n\r\n// optimize memory version\r\n\
    struct EdmondsKarp {\r\n    struct Edge {\r\n        int v, rev;\r\n        ll\
    \ cap, flow;\r\n    };\r\n    int n;\r\n    vector<vector<Edge>> g;\r\n    vector<int>\
    \ trace, id;\r\n\r\n    EdmondsKarp(int n) : n(n), g(n + 1) {}\r\n\r\n    void\
    \ addEdge(int u, int v, ll c) {\r\n        int iu = g[u].size(), iv = g[v].size()\
    \ + (u == v);\r\n        g[u].push_back({v, iv, c, 0});\r\n        g[v].push_back({u,\
    \ iu, 0, 0});\r\n    }\r\n\r\n    bool bfs(int s, int t) {\r\n        trace.assign(n\
    \ + 1, -1);\r\n        id.assign(n + 1, -1);\r\n        trace[s] = s;\r\n    \
    \    queue<int> q; q.push(s);\r\n        while (!q.empty()) {\r\n            int\
    \ u = q.front(); q.pop();\r\n            for (int i = 0; i < (int)g[u].size();\
    \ i++) {\r\n                Edge &e = g[u][i];\r\n                if (trace[e.v]\
    \ != -1 || e.cap - e.flow == 0) continue;\r\n                trace[e.v] = u;\r\
    \n                id[e.v] = i;\r\n                q.push(e.v);\r\n           \
    \     if (e.v == t) return true;\r\n            }\r\n        }\r\n        return\
    \ trace[t] != -1;\r\n    }\r\n\r\n    ll maxFlow(int s, int t) {\r\n        ll\
    \ res = 0;\r\n        while (bfs(s, t)) {\r\n            ll delta = LLONG_MAX;\r\
    \n            for (int v = t; v != s; v = trace[v]) {\r\n                Edge\
    \ &e = g[trace[v]][id[v]];\r\n                delta = min(delta, e.cap - e.flow);\r\
    \n            }\r\n            for (int v = t; v != s; v = trace[v]) {\r\n   \
    \             Edge &e = g[trace[v]][id[v]];\r\n                e.flow += delta;\r\
    \n                g[v][e.rev].flow -= delta;\r\n            }\r\n            res\
    \ += delta;\r\n        }\r\n        return res;\r\n    }\r\n\r\n    bool inA(int\
    \ u) { return trace[u] != -1; }\r\n};\r\n#line 5 \"Graph/Aizu/aizu_grl_6_a_maximum_flow2.cpp\"\
    \n\r\nvoid solve() {\r\n    int n, m; cin >> n >> m;\r\n    EdmondsKarp mxFlow(n);\r\
    \n    for (int i = 0; i < m; i++) {\r\n        int u, v, w; cin >> u >> v >> w;\r\
    \n        mxFlow.addEdge(u, v, w);\r\n    }\r\n    cout << mxFlow.maxFlow(0, n-1)\
    \ << '\\n';\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \r\n\r\n#include \"../../template.h\"\r\n#include \"../Flow/MaxFlowEdmondsKarp.h\"\
    \r\n\r\nvoid solve() {\r\n    int n, m; cin >> n >> m;\r\n    EdmondsKarp mxFlow(n);\r\
    \n    for (int i = 0; i < m; i++) {\r\n        int u, v, w; cin >> u >> v >> w;\r\
    \n        mxFlow.addEdge(u, v, w);\r\n    }\r\n    cout << mxFlow.maxFlow(0, n-1)\
    \ << '\\n';\r\n}"
  dependsOn:
  - template.h
  - Graph/Flow/MaxFlowEdmondsKarp.h
  isVerificationFile: false
  path: Graph/Aizu/aizu_grl_6_a_maximum_flow2.cpp
  requiredBy: []
  timestamp: '2026-10-16 23:50:27+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Aizu/aizu_grl_6_a_maximum_flow2.cpp
layout: document
redirect_from:
- /library/Graph/Aizu/aizu_grl_6_a_maximum_flow2.cpp
- /library/Graph/Aizu/aizu_grl_6_a_maximum_flow2.cpp.html
title: Graph/Aizu/aizu_grl_6_a_maximum_flow2.cpp
---
