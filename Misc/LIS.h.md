---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://hnoj.edu.vn/contest/hnoi2023v1/all
    - https://marisaoj.com/problem/276
    - https://oj.vnoi.info/problem/lis
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"Misc/LIS.h\"\n\nconst int\
    \ N = 2e5 + 6;\nvector<vector<int>> adj;\nvector<int> a, ans;\nset<int> s[N];\n\
    \n// AC: https://oj.vnoi.info/problem/lis\nint LIS(vector<int> &a) {\n    multiset<int>\
    \ s;\n    for (int x : a) {\n        auto it = s.lower_bound(x);\n        if (it\
    \ != s.end()) {\n            s.erase(it);\n        }\n        s.insert(x);\n \
    \   }\n    return s.size();\n}\n\nint __LIS(vector<int> &a) {\n    vector<int>\
    \ v;\n    for (int x : a) {\n        auto it = lower_bound(all(v), x);\n     \
    \   if (it != v.end()) {\n            (*it) = min((*it), x);\n        } else {\n\
    \            v.push_back(x);\n        }\n    }\n    return v.size();\n}\n\n//\
    \ LIS on tree\n// AC: https://marisaoj.com/problem/276\n// AC: https://hnoj.edu.vn/contest/hnoi2023v1/all\n\
    void dfs(int u, int par) {\n    for (int v : adj[u]) {\n        if (v == par)\
    \ continue;\n        dfs(v, u);\n        if (s[u].size() < s[v].size()) {\n  \
    \          swap(s[u], s[v]);\n        }\n        for (auto it : s[v]) {\n    \
    \        s[u].insert(it);\n        }\n    }\n    auto it = s[u].lower_bound(a[u]);\n\
    \    if (it != s[u].end()) {\n        s[u].erase(it);\n    }\n    s[u].insert(a[u]);\n\
    \    ans[u] = s[u].size();\n}\n"
  code: "#include \"../template.h\"\n\nconst int N = 2e5 + 6;\nvector<vector<int>>\
    \ adj;\nvector<int> a, ans;\nset<int> s[N];\n\n// AC: https://oj.vnoi.info/problem/lis\n\
    int LIS(vector<int> &a) {\n    multiset<int> s;\n    for (int x : a) {\n     \
    \   auto it = s.lower_bound(x);\n        if (it != s.end()) {\n            s.erase(it);\n\
    \        }\n        s.insert(x);\n    }\n    return s.size();\n}\n\nint __LIS(vector<int>\
    \ &a) {\n    vector<int> v;\n    for (int x : a) {\n        auto it = lower_bound(all(v),\
    \ x);\n        if (it != v.end()) {\n            (*it) = min((*it), x);\n    \
    \    } else {\n            v.push_back(x);\n        }\n    }\n    return v.size();\n\
    }\n\n// LIS on tree\n// AC: https://marisaoj.com/problem/276\n// AC: https://hnoj.edu.vn/contest/hnoi2023v1/all\n\
    void dfs(int u, int par) {\n    for (int v : adj[u]) {\n        if (v == par)\
    \ continue;\n        dfs(v, u);\n        if (s[u].size() < s[v].size()) {\n  \
    \          swap(s[u], s[v]);\n        }\n        for (auto it : s[v]) {\n    \
    \        s[u].insert(it);\n        }\n    }\n    auto it = s[u].lower_bound(a[u]);\n\
    \    if (it != s[u].end()) {\n        s[u].erase(it);\n    }\n    s[u].insert(a[u]);\n\
    \    ans[u] = s[u].size();\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/LIS.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/LIS.h
layout: document
redirect_from:
- /library/Misc/LIS.h
- /library/Misc/LIS.h.html
title: Misc/LIS.h
---
