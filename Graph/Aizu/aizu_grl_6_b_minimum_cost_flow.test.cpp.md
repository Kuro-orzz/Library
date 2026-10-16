---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Flow/MinCostFlow.h
    title: Graph/Flow/MinCostFlow.h
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
  bundledCode: "#line 1 \"Graph/Aizu/aizu_grl_6_b_minimum_cost_flow.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \r\n\r\n#line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace\
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 1 \"Graph/Flow/MinCostFlow.h\"\
    \n// // spfa version\r\n// struct MinCostFlow {\r\n//     struct Edge {\r\n//\
    \         int v, rev;\r\n//         ll cap, flow, cost;\r\n//     };\r\n//   \
    \  const ll INF = LLONG_MAX / 4;\r\n//     int n;\r\n//     vector<vector<Edge>>\
    \ g;\r\n//     vector<ll> d;\r\n//     vector<int> trace, id;\r\n//     vector<bool>\
    \ inq;\r\n\r\n//     MinCostFlow(int n) : n(n), g(n + 1) {}\r\n\r\n//     void\
    \ addEdge(int u, int v, ll cap, ll cost) {\r\n//         int iu = g[u].size(),\
    \ iv = g[v].size() + (u == v);\r\n//         g[u].push_back({v, iv, cap, 0, cost});\r\
    \n//         g[v].push_back({u, iu, 0, 0, -cost});\r\n//     }\r\n\r\n//     bool\
    \ spfa(int s, int t) {\r\n//         d.assign(n + 1, INF);\r\n//         trace.assign(n\
    \ + 1, -1), id.assign(n + 1, -1), inq.assign(n + 1, false);\r\n//         queue<int>\
    \ q;\r\n//         d[s] = 0, q.push(s), inq[s] = true;\r\n//         while (!q.empty())\
    \ {\r\n//             int u = q.front(); q.pop();\r\n//             inq[u] = false;\r\
    \n//             for (int i = 0; i < (int)g[u].size(); i++) {\r\n//          \
    \       Edge &e = g[u][i];\r\n//                 if (e.cap - e.flow == 0 || d[u]\
    \ + e.cost >= d[e.v]) continue;\r\n//                 d[e.v] = d[u] + e.cost;\r\
    \n//                 trace[e.v] = u, id[e.v] = i;\r\n//                 if (!inq[e.v])\
    \ inq[e.v] = true, q.push(e.v);\r\n//             }\r\n//         }\r\n//    \
    \     return d[t] < INF;\r\n//     }\r\n\r\n//     pair<ll, ll> minCostFlow(int\
    \ s, int t, ll k = LLONG_MAX) {\r\n//         ll flow = 0, cost = 0;\r\n//   \
    \      while (flow < k && spfa(s, t)) {\r\n//             ll delta = k - flow;\r\
    \n//             for (int v = t; v != s; v = trace[v]) {\r\n//               \
    \  Edge &e = g[trace[v]][id[v]];\r\n//                 delta = min(delta, e.cap\
    \ - e.flow);\r\n//             }\r\n//             for (int v = t; v != s; v =\
    \ trace[v]) {\r\n//                 Edge &e = g[trace[v]][id[v]];\r\n//      \
    \           e.flow += delta;\r\n//                 g[v][e.rev].flow -= delta;\r\
    \n//             }\r\n//             flow += delta;\r\n//             cost +=\
    \ delta * d[t];\r\n//         }\r\n//         return {flow, cost};\r\n//     }\r\
    \n// };\r\n\r\n// vnoi version (dijkstra + potential)\r\nstruct MinCostFlow {\r\
    \n    struct Edge {\r\n        int v, rev;\r\n        ll cap, flow, cost;\r\n\
    \    };\r\n    const ll INF = LLONG_MAX / 4;\r\n    int n;\r\n    bool negCost\
    \ = false;\r\n    vector<vector<Edge>> g;\r\n    vector<ll> pi, d;\r\n    vector<int>\
    \ trace, id;\r\n\r\n    MinCostFlow(int n) : n(n), g(n + 1) {}\r\n\r\n    void\
    \ addEdge(int u, int v, ll cap, ll cost) {\r\n        int iu = g[u].size(), iv\
    \ = g[v].size() + (u == v);\r\n        g[u].push_back({v, iv, cap, 0, cost});\r\
    \n        g[v].push_back({u, iu, 0, 0, -cost});\r\n        negCost |= cost < 0;\r\
    \n    }\r\n\r\n    void bellmanFord(int s) {\r\n        pi.assign(n + 1, INF);\r\
    \n        pi[s] = 0;\r\n        for (int it = 0; it < n; it++) {\r\n         \
    \   bool upd = false;\r\n            for (int u = 0; u <= n; u++) {\r\n      \
    \          if (pi[u] == INF) continue;\r\n                for (Edge &e : g[u])\r\
    \n                    if (e.cap - e.flow > 0 && pi[u] + e.cost < pi[e.v]) pi[e.v]\
    \ = pi[u] + e.cost, upd = true;\r\n            }\r\n            if (!upd) break;\r\
    \n        }\r\n    }\r\n\r\n    bool dijkstra(int s, int t) {\r\n        d.assign(n\
    \ + 1, INF);\r\n        trace.assign(n + 1, -1), id.assign(n + 1, -1);\r\n   \
    \     priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>\
    \ pq;\r\n        d[s] = 0, pq.push({0, s});\r\n        while (!pq.empty()) {\r\
    \n            auto [du, u] = pq.top(); pq.pop();\r\n            if (du != d[u])\
    \ continue;\r\n            for (int i = 0; i < (int)g[u].size(); i++) {\r\n  \
    \              Edge &e = g[u][i];\r\n                if (e.cap - e.flow == 0)\
    \ continue;\r\n                ll w = e.cost + pi[u] - pi[e.v];\r\n          \
    \      if (d[u] + w >= d[e.v]) continue;\r\n                d[e.v] = d[u] + w;\r\
    \n                trace[e.v] = u, id[e.v] = i;\r\n                pq.push({d[e.v],\
    \ e.v});\r\n            }\r\n        }\r\n        for (int u = 0; u <= n; u++)\r\
    \n            if (d[u] < INF) pi[u] += d[u];\r\n        return d[t] < INF;\r\n\
    \    }\r\n\r\n    pair<ll, ll> minCostFlow(int s, int t, ll k = LLONG_MAX) {\r\
    \n        pi.assign(n + 1, 0);\r\n        if (negCost) bellmanFord(s);\r\n   \
    \     ll flow = 0, cost = 0;\r\n        while (flow < k && dijkstra(s, t)) {\r\
    \n            ll delta = k - flow, pathCost = 0;\r\n            for (int v = t;\
    \ v != s; v = trace[v]) {\r\n                Edge &e = g[trace[v]][id[v]];\r\n\
    \                delta = min(delta, e.cap - e.flow);\r\n                pathCost\
    \ += e.cost;\r\n            }\r\n            for (int v = t; v != s; v = trace[v])\
    \ {\r\n                Edge &e = g[trace[v]][id[v]];\r\n                e.flow\
    \ += delta;\r\n                g[v][e.rev].flow -= delta;\r\n            }\r\n\
    \            flow += delta;\r\n            cost += delta * pathCost;\r\n     \
    \   }\r\n        return {flow, cost};\r\n    }\r\n};\r\n#line 5 \"Graph/Aizu/aizu_grl_6_b_minimum_cost_flow.test.cpp\"\
    \n\r\nvoid solve() {\r\n    int n, m; ll F; cin >> n >> m >> F;\r\n    MinCostFlow\
    \ mcf(n);\r\n    for (int i = 0; i < m; i++) {\r\n        int u, v; ll c, d; cin\
    \ >> u >> v >> c >> d;\r\n        mcf.addEdge(u, v, c, d);\r\n    }\r\n    auto\
    \ [flow, cost] = mcf.minCostFlow(0, n-1, F);\r\n    cout << (flow < F ? -1 : cost)\
    \ << '\\n';\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \r\n\r\n#include \"../../template.h\"\r\n#include \"../Flow/MinCostFlow.h\"\r\n\
    \r\nvoid solve() {\r\n    int n, m; ll F; cin >> n >> m >> F;\r\n    MinCostFlow\
    \ mcf(n);\r\n    for (int i = 0; i < m; i++) {\r\n        int u, v; ll c, d; cin\
    \ >> u >> v >> c >> d;\r\n        mcf.addEdge(u, v, c, d);\r\n    }\r\n    auto\
    \ [flow, cost] = mcf.minCostFlow(0, n-1, F);\r\n    cout << (flow < F ? -1 : cost)\
    \ << '\\n';\r\n}"
  dependsOn:
  - template.h
  - Graph/Flow/MinCostFlow.h
  isVerificationFile: true
  path: Graph/Aizu/aizu_grl_6_b_minimum_cost_flow.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 00:46:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/Aizu/aizu_grl_6_b_minimum_cost_flow.test.cpp
layout: document
redirect_from:
- /verify/Graph/Aizu/aizu_grl_6_b_minimum_cost_flow.test.cpp
- /verify/Graph/Aizu/aizu_grl_6_b_minimum_cost_flow.test.cpp.html
title: Graph/Aizu/aizu_grl_6_b_minimum_cost_flow.test.cpp
---
