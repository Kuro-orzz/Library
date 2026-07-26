---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: String/Yosupo/Enumerate_Palindromes.test.cpp
    title: String/Yosupo/Enumerate_Palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"String/Manacher.h\"\n\n\
    // Base = 1\n// s = '$' + s;\n// vector<int> odd = calc_odd(s);\n// vector<int>\
    \ even = calc_even(s);\n// not count center as palindrome\n\nvector<int> calc_odd(string\
    \ &s) {\n    int n = s.size();\n    vector<int> d(n);\n    int l = 1, r = 0;\n\
    \    for (int i = 1; i < n; i++) {\n        if (i > r) d[i] = 0;\n        else\
    \ d[i] = min(r-i, d[l+r-i]);\n        while (i-d[i]-1 > 0 && i+d[i]+1 < n && s[i-d[i]-1]\
    \ == s[i+d[i]+1]) {\n            d[i]++;\n        }\n        if (i + d[i] > r)\
    \ {\n            l = i - d[i];\n            r = i + d[i];\n        }\n    }\n\
    \    return d;\n}\n\nvector<int> calc_even(string &s) {\n    int n = s.size();\n\
    \    vector<int> d(n);\n    int l = 1, r = 0;\n    for (int i = 1; i < n-1; i++)\
    \ {\n        int j = i+1;\n        if (j > r) d[i] = 0;\n        else d[i] = min(r-j+1,\
    \ d[l+r-j]);\n        while (i-d[i] >= 0 && j+d[i] < n && s[i-d[i]] == s[j+d[i]])\
    \ {\n            d[i]++;\n        }\n        if (i + d[i] > r) {\n           \
    \ l = j - d[i];\n            r = i + d[i];\n        }\n    }\n    return d;\n\
    }\n"
  code: "#include \"../template.h\"\n\n// Base = 1\n// s = '$' + s;\n// vector<int>\
    \ odd = calc_odd(s);\n// vector<int> even = calc_even(s);\n// not count center\
    \ as palindrome\n\nvector<int> calc_odd(string &s) {\n    int n = s.size();\n\
    \    vector<int> d(n);\n    int l = 1, r = 0;\n    for (int i = 1; i < n; i++)\
    \ {\n        if (i > r) d[i] = 0;\n        else d[i] = min(r-i, d[l+r-i]);\n \
    \       while (i-d[i]-1 > 0 && i+d[i]+1 < n && s[i-d[i]-1] == s[i+d[i]+1]) {\n\
    \            d[i]++;\n        }\n        if (i + d[i] > r) {\n            l =\
    \ i - d[i];\n            r = i + d[i];\n        }\n    }\n    return d;\n}\n\n\
    vector<int> calc_even(string &s) {\n    int n = s.size();\n    vector<int> d(n);\n\
    \    int l = 1, r = 0;\n    for (int i = 1; i < n-1; i++) {\n        int j = i+1;\n\
    \        if (j > r) d[i] = 0;\n        else d[i] = min(r-j+1, d[l+r-j]);\n   \
    \     while (i-d[i] >= 0 && j+d[i] < n && s[i-d[i]] == s[j+d[i]]) {\n        \
    \    d[i]++;\n        }\n        if (i + d[i] > r) {\n            l = j - d[i];\n\
    \            r = i + d[i];\n        }\n    }\n    return d;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: String/Manacher.h
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - String/Yosupo/Enumerate_Palindromes.test.cpp
documentation_of: String/Manacher.h
layout: document
redirect_from:
- /library/String/Manacher.h
- /library/String/Manacher.h.html
title: String/Manacher.h
---
