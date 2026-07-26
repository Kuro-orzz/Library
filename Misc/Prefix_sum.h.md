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
    links: []
  bundledCode: "#line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n \r\n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x)\
    \ (x).begin(),(x).end()\r\n#define unique(x) x.erase(unique(all(x)), x.end())\r\
    \n#define INF32 ((1ull<<31)-1)\r\n#define INF64 ((1ull<<63)-1)\r\n#define inf\
    \ (ll)1e18\r\n\r\n#define vi vector<int>\r\n#define pii pair<int, int>\r\n#define\
    \ pll pair<ll, ll>\r\n#define fi first\r\n#define se second\r\n\r\nmt19937_64\
    \ rng(chrono::steady_clock::now().time_since_epoch().count());\r\nll get_rand(ll\
    \ r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\r\nconst int\
    \ mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main(){\r\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\r\
    \n    // cin.exceptions(cin.failbit);\r\n    // int t; cin >> t;\r\n    // while(t--)\r\
    \n        solve();\r\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"Misc/Prefix_sum.h\"\n\n\
    vector<vector<ll>> prefix_2d_init(int n, int m, const vector<vector<int>> &a)\
    \ {\n    vector<vector<ll>> pref(n+1, vector<ll>(m+1));\n    for (int i = 1; i\
    \ <= n; i++) {\n        for (int j = 1; j <= m; j++) {\n            pref[i][j]\
    \ = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i-1][j-1];\n        }\n \
    \   }\n    return pref;\n}\n\nll get(const vector<vector<ll>> &pref, int a, int\
    \ b, int c, int d) {\n    return pref[c][d]-pref[c][b-1]-pref[a-1][d]+pref[a-1][b-1];\n\
    }\n"
  code: "#include \"../template.h\"\n\nvector<vector<ll>> prefix_2d_init(int n, int\
    \ m, const vector<vector<int>> &a) {\n    vector<vector<ll>> pref(n+1, vector<ll>(m+1));\n\
    \    for (int i = 1; i <= n; i++) {\n        for (int j = 1; j <= m; j++) {\n\
    \            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i-1][j-1];\n\
    \        }\n    }\n    return pref;\n}\n\nll get(const vector<vector<ll>> &pref,\
    \ int a, int b, int c, int d) {\n    return pref[c][d]-pref[c][b-1]-pref[a-1][d]+pref[a-1][b-1];\n\
    }"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/Prefix_sum.h
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Prefix_sum.h
layout: document
redirect_from:
- /library/Misc/Prefix_sum.h
- /library/Misc/Prefix_sum.h.html
title: Misc/Prefix_sum.h
---
