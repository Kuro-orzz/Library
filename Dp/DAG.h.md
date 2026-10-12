---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"Dp/DAG.h\"\n\n\n// Longest\
    \ path in graph\n\nint n, m;\nvector<vector<int>> adj;\nvector<int> vis, d;\n\
    stack<int> topo;\n\nvoid topoSort(int u) {\n    vis[u] = 1;\n    for (int v :\
    \ adj[u]) {\n        if (vis[v]) continue;\n        topoSort(v);\n    }\n    topo.push(u);\n\
    }\n\nvoid solve() {\n    cin >> n >> m;\n    adj.resize(n+1);\n    for (int i\
    \ = 0; i < m; i++) {\n        int u, v; cin >> u >> v;\n        adj[u].push_back(v);\n\
    \    }\n    vis.resize(n+1);\n    for (int i = 1; i <= n; i++) {\n        if (vis[i])\
    \ continue;\n        topoSort(i);\n    }\n    fill(all(vis), 0);\n    d.resize(n+1,\
    \ 0);\n    while (!topo.empty()) {\n        int u = topo.top(); topo.pop();\n\
    \        for (int v : adj[u]) {\n            d[v] = max(d[v], d[u] + 1);\n   \
    \     }\n    }\n    cout << *max_element(all(d));\n}\n"
  code: "#include \"../template.h\"\n\n\n// Longest path in graph\n\nint n, m;\nvector<vector<int>>\
    \ adj;\nvector<int> vis, d;\nstack<int> topo;\n\nvoid topoSort(int u) {\n    vis[u]\
    \ = 1;\n    for (int v : adj[u]) {\n        if (vis[v]) continue;\n        topoSort(v);\n\
    \    }\n    topo.push(u);\n}\n\nvoid solve() {\n    cin >> n >> m;\n    adj.resize(n+1);\n\
    \    for (int i = 0; i < m; i++) {\n        int u, v; cin >> u >> v;\n       \
    \ adj[u].push_back(v);\n    }\n    vis.resize(n+1);\n    for (int i = 1; i <=\
    \ n; i++) {\n        if (vis[i]) continue;\n        topoSort(i);\n    }\n    fill(all(vis),\
    \ 0);\n    d.resize(n+1, 0);\n    while (!topo.empty()) {\n        int u = topo.top();\
    \ topo.pop();\n        for (int v : adj[u]) {\n            d[v] = max(d[v], d[u]\
    \ + 1);\n        }\n    }\n    cout << *max_element(all(d));\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Dp/DAG.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dp/DAG.h
layout: document
redirect_from:
- /library/Dp/DAG.h
- /library/Dp/DAG.h.html
title: Dp/DAG.h
---
