---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Fenwick/Fenwick.h
    title: DataStructure/Fenwick/Fenwick.h
  - icon: ':heavy_check_mark:'
    path: Tree/EulerTour.h
    title: Tree/EulerTour.h
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"Tree/Yosupo/Vertex_add_subtree_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#line 2 \"template.h\"\
    \n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n \r\n#define ll long\
    \ long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\r\n#define INF32 ((1ull<<31)-1)\r\
    \n#define INF64 ((1ull<<63)-1)\r\n#define inf (ll)1e18\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main(){\r\n   \
    \ ios_base::sync_with_stdio(false);cin.tie(NULL);\r\n    // cin.exceptions(cin.failbit);\r\
    \n    // int t; cin >> t;\r\n    // while(t--)\r\n        solve();\r\n    cerr\
    \ << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\r\
    \n    return 0;\r\n}\n#line 2 \"Tree/EulerTour.h\"\n\nvector<int> EulerTour(vector<int>\
    \ &st, vector<int> &en, \n                vector<vector<int>> &adj, int root =\
    \ 0, int type = 0) {\n    int n = adj.size();\n    st.assign(n, 0);\n    en.assign(n,\
    \ 0);\n    vector<int> tour;\n    if (type == 0) tour.reserve(n);\n    else if\
    \ (type == 1) tour.reserve(2 * n);\n    int pos = 0;\n    function<void(int, int)>\
    \ dfs = [&] (int u, int par) {\n        tour.push_back(u);\n        st[u] = ++pos;\n\
    \        for (int v : adj[u]) {\n            if (v == par) continue;\n       \
    \     dfs(v, u);\n        }\n        if (type == 1) {\n            tour.push_back(u);\n\
    \            pos++;\n        }\n        en[u] = pos;\n    };\n    dfs(root, -1);\n\
    \    return tour;\n}\n#line 2 \"DataStructure/Fenwick/Fenwick.h\"\n\ntemplate\
    \ <typename T>\nstruct Fenwick{\n    int n;\n    vector<T> fen;\n\n    Fenwick()\
    \ {}\n    Fenwick(int _n): n(_n), fen(_n+1) {}\n\n    void update(int pos, T val)\
    \ {\n        for (; pos <= n; pos += pos & -pos) {\n            fen[pos] += val;\n\
    \        }\n    }\n\n    T get(int pos) {\n        T ans = 0;\n        for (;\
    \ pos > 0; pos -= pos & -pos) {\n            ans += fen[pos];\n        }\n   \
    \     return ans;\n    }\n\n    T get(int l, int r) {\n        return get(r) -\
    \ get(l - 1);\n    }\n\n    void update_range(int l, int r, T val){\n        update(l,\
    \ val);\n        update(r+1, -val);\n    }\n\n    void reset() {\n        fill(all(fen),\
    \ T(0));\n    }\n};\n#line 6 \"Tree/Yosupo/Vertex_add_subtree_sum.test.cpp\"\n\
    \nvoid solve() {\n    int n, q; cin >> n >> q;\n    int a[n];\n    for (int i\
    \ = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    vector<vector<int>> adj(n);\n\
    \    for (int i = 1; i < n; i++) {\n        int x; cin >> x;\n        adj[i].push_back(x);\n\
    \        adj[x].push_back(i);\n    }\n    vector<int> st, en;\n    vector<int>\
    \ tour = EulerTour(st, en, adj);\n    Fenwick<ll> BIT((int)tour.size() + 1);\n\
    \    for (int i = 0; i < n; i++) BIT.update(st[i], a[i]);\n    while (q--) {\n\
    \        int type; cin >> type;\n        if (type == 0) {\n            int u,\
    \ x; cin >> u >> x;\n            BIT.update(st[u], x);\n        } else if (type\
    \ == 1) {\n            int u; cin >> u;\n            cout << BIT.get(st[u], en[u])\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../template.h\"\n#include \"../EulerTour.h\"\n#include \"../../DataStructure/Fenwick/Fenwick.h\"\
    \n\nvoid solve() {\n    int n, q; cin >> n >> q;\n    int a[n];\n    for (int\
    \ i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    vector<vector<int>> adj(n);\n\
    \    for (int i = 1; i < n; i++) {\n        int x; cin >> x;\n        adj[i].push_back(x);\n\
    \        adj[x].push_back(i);\n    }\n    vector<int> st, en;\n    vector<int>\
    \ tour = EulerTour(st, en, adj);\n    Fenwick<ll> BIT((int)tour.size() + 1);\n\
    \    for (int i = 0; i < n; i++) BIT.update(st[i], a[i]);\n    while (q--) {\n\
    \        int type; cin >> type;\n        if (type == 0) {\n            int u,\
    \ x; cin >> u >> x;\n            BIT.update(st[u], x);\n        } else if (type\
    \ == 1) {\n            int u; cin >> u;\n            cout << BIT.get(st[u], en[u])\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.h
  - Tree/EulerTour.h
  - DataStructure/Fenwick/Fenwick.h
  isVerificationFile: true
  path: Tree/Yosupo/Vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Tree/Yosupo/Vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/Tree/Yosupo/Vertex_add_subtree_sum.test.cpp
- /verify/Tree/Yosupo/Vertex_add_subtree_sum.test.cpp.html
title: Tree/Yosupo/Vertex_add_subtree_sum.test.cpp
---
