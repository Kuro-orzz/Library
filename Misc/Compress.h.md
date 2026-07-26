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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"Misc/Compress.h\"\n\ntemplate\
    \ <typename T>\nstruct Compress {\n    int cnt = 1;\n    map<T, int> compressed;\n\
    \    vector<T> decompress;\n\n    Compress(const vector<T> &a) {\n        decompress.push_back(T(0));\n\
    \        vector<T> b = a;\n        sort(all(b));\n        unique(b);\n       \
    \ for (T x : b) {\n            compressed[x] = cnt++;\n            decompress.push_back(x);\n\
    \        }\n    }\n\n    int operator[] (const T &x) const { assert(compressed.count(x));\
    \ return compressed[x]; }\n\n    T getDecomp(int i) const { return decompress[i];\
    \ }\n};\n"
  code: "#include \"../template.h\"\n\ntemplate <typename T>\nstruct Compress {\n\
    \    int cnt = 1;\n    map<T, int> compressed;\n    vector<T> decompress;\n\n\
    \    Compress(const vector<T> &a) {\n        decompress.push_back(T(0));\n   \
    \     vector<T> b = a;\n        sort(all(b));\n        unique(b);\n        for\
    \ (T x : b) {\n            compressed[x] = cnt++;\n            decompress.push_back(x);\n\
    \        }\n    }\n\n    int operator[] (const T &x) const { assert(compressed.count(x));\
    \ return compressed[x]; }\n\n    T getDecomp(int i) const { return decompress[i];\
    \ }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/Compress.h
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Compress.h
layout: document
redirect_from:
- /library/Misc/Compress.h
- /library/Misc/Compress.h.html
title: Misc/Compress.h
---
