---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Tree/Yosupo/Diameter_tree.test.cpp
    title: Tree/Yosupo/Diameter_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"Tree/Tree_diameter.h\"\n\
    \npair<ll, vector<int>> tree_diameter(const vector<vector<pii>>& g) {\n    int\
    \ n = g.size();\n    vector<ll> d(n); // dist\n    vector<int> p(n); // par\n\n\
    \    function<void(int, int, ll)> dfs = [&] (int u, int par, ll cur_d) {\n   \
    \     d[u] = cur_d;\n        p[u] = par;\n        for (auto [v, w] : g[u]) {\n\
    \            if (v == par) continue;\n            dfs(v, u, cur_d + w);\n    \
    \    }\n    };\n    dfs(0, -1, 0);\n    // r = furthest node from root\n    int\
    \ r = max_element(d.begin(), d.end()) - d.begin();\n    dfs(r, -1, 0);\n    //\
    \ r->s = longest path\n    int s = max_element(d.begin(), d.end()) - d.begin();\n\
    \n    vector<int> path;\n    for (int x = s; x >= 0; x = p[x]) { \n        path.push_back(x);\n\
    \    }\n    return {d[s], path};\n}\n"
  code: "#include \"../template.h\"\n\npair<ll, vector<int>> tree_diameter(const vector<vector<pii>>&\
    \ g) {\n    int n = g.size();\n    vector<ll> d(n); // dist\n    vector<int> p(n);\
    \ // par\n\n    function<void(int, int, ll)> dfs = [&] (int u, int par, ll cur_d)\
    \ {\n        d[u] = cur_d;\n        p[u] = par;\n        for (auto [v, w] : g[u])\
    \ {\n            if (v == par) continue;\n            dfs(v, u, cur_d + w);\n\
    \        }\n    };\n    dfs(0, -1, 0);\n    // r = furthest node from root\n \
    \   int r = max_element(d.begin(), d.end()) - d.begin();\n    dfs(r, -1, 0);\n\
    \    // r->s = longest path\n    int s = max_element(d.begin(), d.end()) - d.begin();\n\
    \n    vector<int> path;\n    for (int x = s; x >= 0; x = p[x]) { \n        path.push_back(x);\n\
    \    }\n    return {d[s], path};\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Tree/Tree_diameter.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Tree/Yosupo/Diameter_tree.test.cpp
documentation_of: Tree/Tree_diameter.h
layout: document
redirect_from:
- /library/Tree/Tree_diameter.h
- /library/Tree/Tree_diameter.h.html
title: Tree/Tree_diameter.h
---
