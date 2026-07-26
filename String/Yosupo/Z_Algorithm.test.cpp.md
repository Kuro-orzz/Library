---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/Z_Function.h
    title: String/Z_Function.h
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"String/Yosupo/Z_Algorithm.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/zalgorithm\"\n\n#line 2 \"template.h\"\n\r\n#include\
    \ <bits/stdc++.h>\r\nusing namespace std;\r\n \r\n#define ll long long\r\n#define\
    \ MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\n#define unique(x)\
    \ x.erase(unique(all(x)), x.end())\r\n#define INF32 ((1ull<<31)-1)\r\n#define\
    \ INF64 ((1ull<<63)-1)\r\n#define inf (ll)1e18\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main(){\r\n   \
    \ ios_base::sync_with_stdio(false);cin.tie(NULL);\r\n    // cin.exceptions(cin.failbit);\r\
    \n    // int t; cin >> t;\r\n    // while(t--)\r\n        solve();\r\n    cerr\
    \ << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\r\
    \n    return 0;\r\n}\n#line 2 \"String/Z_Function.h\"\n\nvector<int> Z_function(const\
    \ string &s) {\n    int n = s.size();\n    vector<int> z(n);\n    z[0] = (int)s.size();\n\
    \    int l = 0, r = 0;\n    for (int i = 1; i < n; i++) {\n        if (i <= r)\
    \ {\n            z[i] = min(r-i+1, z[i-l]);\n        }\n        while (i + z[i]\
    \ < n && s[z[i]] == s[i + z[i]]) {\n            z[i]++;\n        }\n        if\
    \ (i + z[i] - 1 > r) {\n            l = i;\n            r = i + z[i] - 1;\n  \
    \      }\n    }\n    return z;\n}\n#line 5 \"String/Yosupo/Z_Algorithm.test.cpp\"\
    \n\nvoid solve() {\n    string s; cin >> s;\n    vector<int> ans = Z_function(s);\n\
    \    for (int x : ans) cout << x << \" \";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ \"../../template.h\"\n#include \"../Z_Function.h\"\n\nvoid solve() {\n    string\
    \ s; cin >> s;\n    vector<int> ans = Z_function(s);\n    for (int x : ans) cout\
    \ << x << \" \";\n}"
  dependsOn:
  - template.h
  - String/Z_Function.h
  isVerificationFile: true
  path: String/Yosupo/Z_Algorithm.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: String/Yosupo/Z_Algorithm.test.cpp
layout: document
redirect_from:
- /verify/String/Yosupo/Z_Algorithm.test.cpp
- /verify/String/Yosupo/Z_Algorithm.test.cpp.html
title: String/Yosupo/Z_Algorithm.test.cpp
---
