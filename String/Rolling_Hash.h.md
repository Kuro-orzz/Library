---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"String/Rolling_Hash.h\"\
    \n\ntemplate <typename T>\nclass Hash {\npublic:\n    static constexpr int base\
    \ = 331;\n    static constexpr int mod = 1'000'000'007;\n    vector<T> h, p;\n\
    \n    Hash() {}\n\n    Hash(const string &s) {\n        build(s);\n    }\n\n \
    \   void build(const string &s) {\n        int n = s.size();\n        h = hashStr(s,\
    \ n);\n        p = calc_pow(n);\n    }\n\n    T getHash(int l, int r) const {\n\
    \        T x = (h[r] - 1ll * h[l-1] * p[r-l+1]) % mod;\n        return T((x +\
    \ mod) % mod);\n    }\n\nprivate:\n    vector<T> hashStr(const string &s, int\
    \ n) {\n        vector<T> hash(n + 1);\n        for (int i = 1; i <= n; i++) {\n\
    \            int c = s[i - 1] - 'a' + 1;\n            hash[i] = (1ll * hash[i-1]\
    \ * base + c) % mod;\n        }\n        return hash;\n    }\n\n    vector<T>\
    \ calc_pow(int n) {\n        vector<T> P;\n        P.emplace_back(1);\n      \
    \  for (int i = 1; i <= n; i++) {\n            P.emplace_back((1ll * P[i-1] *\
    \ base) % mod);\n        }\n        return P;\n    }\n};\n"
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
  - String/Problem/Rolling_Hash2.cpp
  - String/Problem/Rolling_Hash1.cpp
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Rolling_Hash.h
layout: document
redirect_from:
- /library/String/Rolling_Hash.h
- /library/String/Rolling_Hash.h.html
title: String/Rolling_Hash.h
---
