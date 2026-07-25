---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Binary_exponentiation.h
    title: NumberTheory/Math/Binary_exponentiation.h
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
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Binary_exponentiation.h\"\n\r\nusing u128\
    \ = __uint128_t;\r\nusing i128 = __int128;\r\n\r\nll binMul(ll a, ll b, ll M)\
    \ { return (i128)a * b % M; }\r\n\r\n// long double trick\r\n// require: mantissa\
    \ 64 bit, x86 gcc/clang\r\nll binMul2(ll a, ll b, ll M) {\r\n    ll q = (ll)((long\
    \ double)a * b / M);\r\n    ll r = (ll)((unsigned ll)a * b - (unsigned ll)q *\
    \ M);\r\n    return r < 0 ? r + M : (r >= M ? r - M : r);\r\n}\r\n\r\nll binMul3(ll\
    \ a, ll b, ll M) {\r\n    unsigned long long ua = a % M, um = M, res = 0;\r\n\
    \    while (b) {\r\n        if (b & 1) { res += ua; if (res >= um) res -= um;\
    \ }\r\n        ua <<= 1; if (ua >= um) ua -= um;\r\n        b >>= 1;\r\n    }\r\
    \n    return res;\r\n}\r\n\r\nll binPow(ll a, ll b, ll M) {\r\n    a %= M;\r\n\
    \    ll res = 1;\r\n    while (b) {\r\n        if (b & 1) res = (i128)res * a\
    \ % M;\r\n        a = (i128)a * a % M;\r\n        b /= 2;\r\n    }\r\n    return\
    \ res;\r\n}\n#line 3 \"NumberTheory/Math/Primality_test.h\"\n\r\n\r\nmt19937_64\
    \ rng(chrono::steady_clock::now().time_since_epoch().count());\r\n\r\n// Fermat's\
    \ little theorem (probabilistic)\r\n// always fails on carmichael numbers a^(n\u2212\
    1) \u2261 1\r\nbool isPrime(ll n) {\r\n    if (n < 7) return n == 2 || n == 3\
    \ || n == 5;\r\n    for (int i = 0; i < 5; i++) {\r\n        ll a = rng() % (n-3)\
    \ + 2;\r\n        if (binPow(a, n-1, n) != 1) \r\n            return false;\r\n\
    \    }\r\n    return true;\r\n}\n"
  code: "#include \"../../template.h\"\r\n#include \"Binary_exponentiation.h\"\r\n\
    \r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n\r\n// Fermat's little theorem (probabilistic)\r\n// always fails on carmichael\
    \ numbers a^(n\u22121) \u2261 1\r\nbool isPrime(ll n) {\r\n    if (n < 7) return\
    \ n == 2 || n == 3 || n == 5;\r\n    for (int i = 0; i < 5; i++) {\r\n       \
    \ ll a = rng() % (n-3) + 2;\r\n        if (binPow(a, n-1, n) != 1) \r\n      \
    \      return false;\r\n    }\r\n    return true;\r\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/Binary_exponentiation.h
  isVerificationFile: false
  path: NumberTheory/Math/Primality_test.h
  requiredBy: []
  timestamp: '2026-07-26 02:09:30+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NumberTheory/Math/Primality_test.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Primality_test.h
- /library/NumberTheory/Math/Primality_test.h.html
title: NumberTheory/Math/Primality_test.h
---
