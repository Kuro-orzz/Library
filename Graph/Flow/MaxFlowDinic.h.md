---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/Aizu/aizu_grl_6_a_maximum_flow.test.cpp
    title: Graph/Aizu/aizu_grl_6_a_maximum_flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Flow/MaxFlowDinic.h\"\n// // vnoi version\r\n// struct\
    \ Dinic {\r\n//     int n;\r\n//     vector<vector<int>> adj;\r\n//     vector<vector<ll>>\
    \ c, f;\r\n//     vector<int> d, ptr;\r\n\r\n//     Dinic(int n) : n(n), adj(n\
    \ + 1), c(n + 1, vector<ll>(n + 1, 0)), f(n + 1, vector<ll>(n + 1, 0)) {}\r\n\r\
    \n//     void addEdge(int u, int v, ll w) {\r\n//         adj[u].push_back(v);\r\
    \n//         adj[v].push_back(u);\r\n//         c[u][v] += w;\r\n//     }\r\n\r\
    \n//     bool bfs(int s, int t) {\r\n//         d.assign(n + 1, -1);\r\n//   \
    \      d[s] = 0;\r\n//         queue<int> q; q.push(s);\r\n//         while (!q.empty())\
    \ {\r\n//             int u = q.front(); q.pop();\r\n//             for (int v\
    \ : adj[u]) {\r\n//                 if (d[v] != -1 || c[u][v] - f[u][v] == 0)\
    \ continue;\r\n//                 d[v] = d[u] + 1;\r\n//                 q.push(v);\r\
    \n//             }\r\n//         }\r\n//         return d[t] != -1;\r\n//    \
    \ }\r\n\r\n//     ll dfs(int u, int t, ll delta) {\r\n//         if (u == t) return\
    \ delta;\r\n//         for (; ptr[u] < (int)adj[u].size(); ptr[u]++) {\r\n// \
    \            int v = adj[u][ptr[u]];\r\n//             if (d[v] != d[u] + 1 ||\
    \ c[u][v] - f[u][v] == 0) continue;\r\n//             ll got = dfs(v, t, min(delta,\
    \ c[u][v] - f[u][v]));\r\n//             if (got == 0) continue;\r\n//       \
    \      f[u][v] += got;\r\n//             f[v][u] -= got;\r\n//             return\
    \ got;\r\n//         }\r\n//         return 0;\r\n//     }\r\n\r\n//     ll maxFlow(int\
    \ s, int t) {\r\n//         ll res = 0;\r\n//         while (bfs(s, t)) {\r\n\
    //             ptr.assign(n + 1, 0);\r\n//             while (ll delta = dfs(s,\
    \ t, LLONG_MAX)) res += delta;\r\n//         }\r\n//         return res;\r\n//\
    \     }\r\n\r\n//     bool inA(int u) { return d[u] != -1; }\r\n// };\r\n\r\n\
    // optimize memory version\r\nstruct Dinic {\r\n    struct Edge {\r\n        int\
    \ v, rev;\r\n        ll cap, flow;\r\n    };\r\n    int n;\r\n    vector<vector<Edge>>\
    \ g;\r\n    vector<int> d, ptr;\r\n\r\n    Dinic(int n) : n(n), g(n + 1) {}\r\n\
    \r\n    void addEdge(int u, int v, ll c) {\r\n        int iu = g[u].size(), iv\
    \ = g[v].size() + (u == v);\r\n        g[u].push_back({v, iv, c, 0});\r\n    \
    \    g[v].push_back({u, iu, 0, 0});\r\n    }\r\n\r\n    bool bfs(int s, int t)\
    \ {\r\n        d.assign(n + 1, -1);\r\n        d[s] = 0;\r\n        queue<int>\
    \ q; q.push(s);\r\n        while (!q.empty()) {\r\n            int u = q.front();\
    \ q.pop();\r\n            for (Edge &e : g[u]) {\r\n                if (d[e.v]\
    \ != -1 || e.cap - e.flow == 0) continue;\r\n                d[e.v] = d[u] + 1;\r\
    \n                q.push(e.v);\r\n            }\r\n        }\r\n        return\
    \ d[t] != -1;\r\n    }\r\n\r\n    ll dfs(int u, int t, ll delta) {\r\n       \
    \ if (u == t) return delta;\r\n        for (; ptr[u] < (int)g[u].size(); ptr[u]++)\
    \ {\r\n            Edge &e = g[u][ptr[u]];\r\n            if (d[e.v] != d[u] +\
    \ 1 || e.cap - e.flow == 0) continue;\r\n            ll got = dfs(e.v, t, min(delta,\
    \ e.cap - e.flow));\r\n            if (got == 0) continue;\r\n            e.flow\
    \ += got;\r\n            g[e.v][e.rev].flow -= got;\r\n            return got;\r\
    \n        }\r\n        return 0;\r\n    }\r\n\r\n    ll maxFlow(int s, int t)\
    \ {\r\n        ll res = 0;\r\n        while (bfs(s, t)) {\r\n            ptr.assign(n\
    \ + 1, 0);\r\n            while (ll delta = dfs(s, t, LLONG_MAX)) res += delta;\r\
    \n        }\r\n        return res;\r\n    }\r\n\r\n    bool inA(int u) { return\
    \ d[u] != -1; }\r\n};\r\n"
  code: "// // vnoi version\r\n// struct Dinic {\r\n//     int n;\r\n//     vector<vector<int>>\
    \ adj;\r\n//     vector<vector<ll>> c, f;\r\n//     vector<int> d, ptr;\r\n\r\n\
    //     Dinic(int n) : n(n), adj(n + 1), c(n + 1, vector<ll>(n + 1, 0)), f(n +\
    \ 1, vector<ll>(n + 1, 0)) {}\r\n\r\n//     void addEdge(int u, int v, ll w) {\r\
    \n//         adj[u].push_back(v);\r\n//         adj[v].push_back(u);\r\n//   \
    \      c[u][v] += w;\r\n//     }\r\n\r\n//     bool bfs(int s, int t) {\r\n//\
    \         d.assign(n + 1, -1);\r\n//         d[s] = 0;\r\n//         queue<int>\
    \ q; q.push(s);\r\n//         while (!q.empty()) {\r\n//             int u = q.front();\
    \ q.pop();\r\n//             for (int v : adj[u]) {\r\n//                 if (d[v]\
    \ != -1 || c[u][v] - f[u][v] == 0) continue;\r\n//                 d[v] = d[u]\
    \ + 1;\r\n//                 q.push(v);\r\n//             }\r\n//         }\r\n\
    //         return d[t] != -1;\r\n//     }\r\n\r\n//     ll dfs(int u, int t, ll\
    \ delta) {\r\n//         if (u == t) return delta;\r\n//         for (; ptr[u]\
    \ < (int)adj[u].size(); ptr[u]++) {\r\n//             int v = adj[u][ptr[u]];\r\
    \n//             if (d[v] != d[u] + 1 || c[u][v] - f[u][v] == 0) continue;\r\n\
    //             ll got = dfs(v, t, min(delta, c[u][v] - f[u][v]));\r\n//      \
    \       if (got == 0) continue;\r\n//             f[u][v] += got;\r\n//      \
    \       f[v][u] -= got;\r\n//             return got;\r\n//         }\r\n//  \
    \       return 0;\r\n//     }\r\n\r\n//     ll maxFlow(int s, int t) {\r\n// \
    \        ll res = 0;\r\n//         while (bfs(s, t)) {\r\n//             ptr.assign(n\
    \ + 1, 0);\r\n//             while (ll delta = dfs(s, t, LLONG_MAX)) res += delta;\r\
    \n//         }\r\n//         return res;\r\n//     }\r\n\r\n//     bool inA(int\
    \ u) { return d[u] != -1; }\r\n// };\r\n\r\n// optimize memory version\r\nstruct\
    \ Dinic {\r\n    struct Edge {\r\n        int v, rev;\r\n        ll cap, flow;\r\
    \n    };\r\n    int n;\r\n    vector<vector<Edge>> g;\r\n    vector<int> d, ptr;\r\
    \n\r\n    Dinic(int n) : n(n), g(n + 1) {}\r\n\r\n    void addEdge(int u, int\
    \ v, ll c) {\r\n        int iu = g[u].size(), iv = g[v].size() + (u == v);\r\n\
    \        g[u].push_back({v, iv, c, 0});\r\n        g[v].push_back({u, iu, 0, 0});\r\
    \n    }\r\n\r\n    bool bfs(int s, int t) {\r\n        d.assign(n + 1, -1);\r\n\
    \        d[s] = 0;\r\n        queue<int> q; q.push(s);\r\n        while (!q.empty())\
    \ {\r\n            int u = q.front(); q.pop();\r\n            for (Edge &e : g[u])\
    \ {\r\n                if (d[e.v] != -1 || e.cap - e.flow == 0) continue;\r\n\
    \                d[e.v] = d[u] + 1;\r\n                q.push(e.v);\r\n      \
    \      }\r\n        }\r\n        return d[t] != -1;\r\n    }\r\n\r\n    ll dfs(int\
    \ u, int t, ll delta) {\r\n        if (u == t) return delta;\r\n        for (;\
    \ ptr[u] < (int)g[u].size(); ptr[u]++) {\r\n            Edge &e = g[u][ptr[u]];\r\
    \n            if (d[e.v] != d[u] + 1 || e.cap - e.flow == 0) continue;\r\n   \
    \         ll got = dfs(e.v, t, min(delta, e.cap - e.flow));\r\n            if\
    \ (got == 0) continue;\r\n            e.flow += got;\r\n            g[e.v][e.rev].flow\
    \ -= got;\r\n            return got;\r\n        }\r\n        return 0;\r\n   \
    \ }\r\n\r\n    ll maxFlow(int s, int t) {\r\n        ll res = 0;\r\n        while\
    \ (bfs(s, t)) {\r\n            ptr.assign(n + 1, 0);\r\n            while (ll\
    \ delta = dfs(s, t, LLONG_MAX)) res += delta;\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    bool inA(int u) { return d[u] != -1; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Flow/MaxFlowDinic.h
  requiredBy: []
  timestamp: '2026-10-16 23:50:27+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/Aizu/aizu_grl_6_a_maximum_flow.test.cpp
documentation_of: Graph/Flow/MaxFlowDinic.h
layout: document
redirect_from:
- /library/Graph/Flow/MaxFlowDinic.h
- /library/Graph/Flow/MaxFlowDinic.h.html
title: Graph/Flow/MaxFlowDinic.h
---
