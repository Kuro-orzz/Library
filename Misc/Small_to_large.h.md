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
    - https://oj.vnoi.info/src/6109008
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"Misc/Small_to_large.h\"\
    \n\nconst int N = 1e5 + 6;\nvector<vector<int>> adj;\nvector<int> color;\nset<int>\
    \ cnt[N];\nvector<int> ans;\n\n// AC: https://oj.vnoi.info/src/6109008\nvoid dfs(int\
    \ u, int par) {\n    cnt[u].insert(color[u]);\n    for (int v : adj[u]) {\n  \
    \      if (v == par) continue;\n        dfs(v, u);\n        if (cnt[u].size()\
    \ < cnt[v].size()) {\n            cnt[u].swap(cnt[v]);\n        }\n        for\
    \ (int i : cnt[v]) {\n            cnt[u].insert(i);\n        }\n    }\n    ans[u]\
    \ = cnt[u].size();\n}\n"
  code: "#include \"../template.h\"\n\nconst int N = 1e5 + 6;\nvector<vector<int>>\
    \ adj;\nvector<int> color;\nset<int> cnt[N];\nvector<int> ans;\n\n// AC: https://oj.vnoi.info/src/6109008\n\
    void dfs(int u, int par) {\n    cnt[u].insert(color[u]);\n    for (int v : adj[u])\
    \ {\n        if (v == par) continue;\n        dfs(v, u);\n        if (cnt[u].size()\
    \ < cnt[v].size()) {\n            cnt[u].swap(cnt[v]);\n        }\n        for\
    \ (int i : cnt[v]) {\n            cnt[u].insert(i);\n        }\n    }\n    ans[u]\
    \ = cnt[u].size();\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/Small_to_large.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Small_to_large.h
layout: document
redirect_from:
- /library/Misc/Small_to_large.h
- /library/Misc/Small_to_large.h.html
title: Misc/Small_to_large.h
---
