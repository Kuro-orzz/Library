---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: String/Problem/Rolling_Hash1.cpp
    title: String/Problem/Rolling_Hash1.cpp
  - icon: ':warning:'
    path: String/Problem/Rolling_Hash2.cpp
    title: String/Problem/Rolling_Hash2.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"String/Rolling_Hash.h\"\n\ntemplate <typename T>\nclass Hash\
    \ {\npublic:\n    static constexpr int base = 331;\n    static constexpr int mod\
    \ = 1'000'000'007;\n    vector<T> h, p;\n\n    Hash() {}\n\n    Hash(const string\
    \ &s) {\n        build(s);\n    }\n\n    void build(const string &s) {\n     \
    \   int n = s.size();\n        h = hashStr(s, n);\n        p = calc_pow(n);\n\
    \    }\n\n    T getHash(int l, int r) const {\n        T x = (h[r] - 1ll * h[l-1]\
    \ * p[r-l+1]) % mod;\n        return T((x + mod) % mod);\n    }\n\nprivate:\n\
    \    vector<T> hashStr(const string &s, int n) {\n        vector<T> hash(n + 1);\n\
    \        for (int i = 1; i <= n; i++) {\n            int c = s[i - 1] - 'a' +\
    \ 1;\n            hash[i] = (1ll * hash[i-1] * base + c) % mod;\n        }\n \
    \       return hash;\n    }\n\n    vector<T> calc_pow(int n) {\n        vector<T>\
    \ P;\n        P.emplace_back(1);\n        for (int i = 1; i <= n; i++) {\n   \
    \         P.emplace_back((1ll * P[i-1] * base) % mod);\n        }\n        return\
    \ P;\n    }\n};\n"
  code: "#include \"../template.h\"\n\ntemplate <typename T>\nclass Hash {\npublic:\n\
    \    static constexpr int base = 331;\n    static constexpr int mod = 1'000'000'007;\n\
    \    vector<T> h, p;\n\n    Hash() {}\n\n    Hash(const string &s) {\n       \
    \ build(s);\n    }\n\n    void build(const string &s) {\n        int n = s.size();\n\
    \        h = hashStr(s, n);\n        p = calc_pow(n);\n    }\n\n    T getHash(int\
    \ l, int r) const {\n        T x = (h[r] - 1ll * h[l-1] * p[r-l+1]) % mod;\n \
    \       return T((x + mod) % mod);\n    }\n\nprivate:\n    vector<T> hashStr(const\
    \ string &s, int n) {\n        vector<T> hash(n + 1);\n        for (int i = 1;\
    \ i <= n; i++) {\n            int c = s[i - 1] - 'a' + 1;\n            hash[i]\
    \ = (1ll * hash[i-1] * base + c) % mod;\n        }\n        return hash;\n   \
    \ }\n\n    vector<T> calc_pow(int n) {\n        vector<T> P;\n        P.emplace_back(1);\n\
    \        for (int i = 1; i <= n; i++) {\n            P.emplace_back((1ll * P[i-1]\
    \ * base) % mod);\n        }\n        return P;\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: String/Rolling_Hash.h
  requiredBy:
  - String/Problem/Rolling_Hash1.cpp
  - String/Problem/Rolling_Hash2.cpp
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Rolling_Hash.h
layout: document
redirect_from:
- /library/String/Rolling_Hash.h
- /library/String/Rolling_Hash.h.html
title: String/Rolling_Hash.h
---
