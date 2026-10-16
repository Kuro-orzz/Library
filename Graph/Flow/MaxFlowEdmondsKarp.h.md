---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Graph/Aizu/aizu_grl_6_a_maximum_flow2.cpp
    title: Graph/Aizu/aizu_grl_6_a_maximum_flow2.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Flow/MaxFlowEdmondsKarp.h\"\n// // vnoi version\r\n\
    // struct EdmondsKarp {\r\n//     int n;\r\n//     vector<vector<int>> adj;\r\n\
    //     vector<vector<ll>> c, f;\r\n//     vector<int> trace;\r\n\r\n//     EdmondsKarp(int\
    \ n) : n(n), adj(n + 1), c(n + 1, vector<ll>(n + 1, 0)), f(n + 1, vector<ll>(n\
    \ + 1, 0)) {}\r\n\r\n//     void addEdge(int u, int v, ll w) {\r\n//         adj[u].push_back(v);\r\
    \n//         adj[v].push_back(u);\r\n//         c[u][v] += w;\r\n//     }\r\n\r\
    \n//     bool bfs(int s, int t) {\r\n//         trace.assign(n + 1, 0);\r\n//\
    \         queue<int> q;\r\n//         q.push(s);\r\n//         trace[s] = -1;\r\
    \n//         while (!q.empty()) {\r\n//             int u = q.front(); q.pop();\r\
    \n//             for (int v : adj[u]) {\r\n//                 if (trace[v] ||\
    \ c[u][v] - f[u][v] == 0) continue;\r\n//                 trace[v] = u;\r\n//\
    \                 q.push(v);\r\n//             }\r\n//         }\r\n//       \
    \  return trace[t] != 0;\r\n//     }\r\n\r\n//     ll maxFlow(int s, int t) {\r\
    \n//         ll res = 0;\r\n//         while (bfs(s, t)) {\r\n//             ll\
    \ delta = LLONG_MAX;\r\n//             for (int v = t; v != s; v = trace[v]) {\r\
    \n//                 int u = trace[v];\r\n//                 delta = min(delta,\
    \ c[u][v] - f[u][v]);\r\n//             }\r\n//             for (int v = t; v\
    \ != s; v = trace[v]) {\r\n//                 int u = trace[v];\r\n//        \
    \         f[u][v] += delta;\r\n//                 f[v][u] -= delta;\r\n//    \
    \         }\r\n//             res += delta;\r\n//         }\r\n//         return\
    \ res;\r\n//     }\r\n\r\n//     bool inA(int u) { return trace[u] != 0; }\r\n\
    // };\r\n\r\n// optimize memory version\r\nstruct EdmondsKarp {\r\n    struct\
    \ Edge {\r\n        int v, rev;\r\n        ll cap, flow;\r\n    };\r\n    int\
    \ n;\r\n    vector<vector<Edge>> g;\r\n    vector<int> trace, id;\r\n\r\n    EdmondsKarp(int\
    \ n) : n(n), g(n + 1) {}\r\n\r\n    void addEdge(int u, int v, ll c) {\r\n   \
    \     int iu = g[u].size(), iv = g[v].size() + (u == v);\r\n        g[u].push_back({v,\
    \ iv, c, 0});\r\n        g[v].push_back({u, iu, 0, 0});\r\n    }\r\n\r\n    bool\
    \ bfs(int s, int t) {\r\n        trace.assign(n + 1, -1);\r\n        id.assign(n\
    \ + 1, -1);\r\n        trace[s] = s;\r\n        queue<int> q; q.push(s);\r\n \
    \       while (!q.empty()) {\r\n            int u = q.front(); q.pop();\r\n  \
    \          for (int i = 0; i < (int)g[u].size(); i++) {\r\n                Edge\
    \ &e = g[u][i];\r\n                if (trace[e.v] != -1 || e.cap - e.flow == 0)\
    \ continue;\r\n                trace[e.v] = u;\r\n                id[e.v] = i;\r\
    \n                q.push(e.v);\r\n                if (e.v == t) return true;\r\
    \n            }\r\n        }\r\n        return trace[t] != -1;\r\n    }\r\n\r\n\
    \    ll maxFlow(int s, int t) {\r\n        ll res = 0;\r\n        while (bfs(s,\
    \ t)) {\r\n            ll delta = LLONG_MAX;\r\n            for (int v = t; v\
    \ != s; v = trace[v]) {\r\n                Edge &e = g[trace[v]][id[v]];\r\n \
    \               delta = min(delta, e.cap - e.flow);\r\n            }\r\n     \
    \       for (int v = t; v != s; v = trace[v]) {\r\n                Edge &e = g[trace[v]][id[v]];\r\
    \n                e.flow += delta;\r\n                g[v][e.rev].flow -= delta;\r\
    \n            }\r\n            res += delta;\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    bool inA(int u) { return trace[u] != -1; }\r\n};\r\n"
  code: "// // vnoi version\r\n// struct EdmondsKarp {\r\n//     int n;\r\n//    \
    \ vector<vector<int>> adj;\r\n//     vector<vector<ll>> c, f;\r\n//     vector<int>\
    \ trace;\r\n\r\n//     EdmondsKarp(int n) : n(n), adj(n + 1), c(n + 1, vector<ll>(n\
    \ + 1, 0)), f(n + 1, vector<ll>(n + 1, 0)) {}\r\n\r\n//     void addEdge(int u,\
    \ int v, ll w) {\r\n//         adj[u].push_back(v);\r\n//         adj[v].push_back(u);\r\
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
    \ u) { return trace[u] != -1; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Flow/MaxFlowEdmondsKarp.h
  requiredBy:
  - Graph/Aizu/aizu_grl_6_a_maximum_flow2.cpp
  timestamp: '2026-10-16 23:50:27+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Flow/MaxFlowEdmondsKarp.h
layout: document
redirect_from:
- /library/Graph/Flow/MaxFlowEdmondsKarp.h
- /library/Graph/Flow/MaxFlowEdmondsKarp.h.html
title: Graph/Flow/MaxFlowEdmondsKarp.h
---
