---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: NumberTheory/Math/Divisors.h
    title: NumberTheory/Math/Divisors.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/MillerRabin.h
    title: NumberTheory/Math/MillerRabin.h
  - icon: ':warning:'
    path: NumberTheory/Math/Primality_test.h
    title: NumberTheory/Math/Primality_test.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp
    title: NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Yosupo/Primality_test.test.cpp
    title: NumberTheory/Yosupo/Primality_test.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Binary_exponentiation.h\"\n\nusing u128 =\
    \ __uint128_t;\nusing i128 = __int128;\n\nll binMul(ll a, ll b, ll M) {\n    a\
    \ = a % M;\n    ll res = 0;\n    while (b) {\n        if (b & 1) res = (res +\
    \ a) % M;\n        a = a * 2 % M;\n        b /= 2;\n    }\n    return res;\n}\n\
    \nll binPow(ll a, ll b, ll M) {\n    a %= M;\n    ll res = 1;\n    while (b) {\n\
    \        if (b & 1) res = (i128)res * a % M;\n        a = (i128)a * a % M;\n \
    \       b /= 2;\n    }\n    return res;\n}\n"
  code: "#include \"../../template.h\"\n\nusing u128 = __uint128_t;\nusing i128 =\
    \ __int128;\n\nll binMul(ll a, ll b, ll M) {\n    a = a % M;\n    ll res = 0;\n\
    \    while (b) {\n        if (b & 1) res = (res + a) % M;\n        a = a * 2 %\
    \ M;\n        b /= 2;\n    }\n    return res;\n}\n\nll binPow(ll a, ll b, ll M)\
    \ {\n    a %= M;\n    ll res = 1;\n    while (b) {\n        if (b & 1) res = (i128)res\
    \ * a % M;\n        a = (i128)a * a % M;\n        b /= 2;\n    }\n    return res;\n\
    }"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/Binary_exponentiation.h
  requiredBy:
  - NumberTheory/Math/Divisors.h
  - NumberTheory/Math/MillerRabin.h
  - NumberTheory/Math/Primality_test.h
  timestamp: '2025-07-18 00:55:12+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp
  - NumberTheory/Yosupo/Primality_test.test.cpp
documentation_of: NumberTheory/Math/Binary_exponentiation.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Binary_exponentiation.h
- /library/NumberTheory/Math/Binary_exponentiation.h.html
title: NumberTheory/Math/Binary_exponentiation.h
---
