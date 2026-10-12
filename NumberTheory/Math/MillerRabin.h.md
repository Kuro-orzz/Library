---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Binary_exponentiation.h
    title: NumberTheory/Math/Binary_exponentiation.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Divisors.h
    title: NumberTheory/Math/Divisors.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Pollard_rho.h
    title: NumberTheory/Math/Pollard_rho.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Primitive_root.h
    title: NumberTheory/Math/Primitive_root.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Yosupo/Factorize.test.cpp
    title: NumberTheory/Yosupo/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Yosupo/Primality_test.test.cpp
    title: NumberTheory/Yosupo/Primality_test.test.cpp
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Yosupo/Primitive_root.test.cpp
    title: NumberTheory/Yosupo/Primitive_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Yosupo/Unit_test_math.test.cpp
    title: NumberTheory/Yosupo/Unit_test_math.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"NumberTheory/Math/Binary_exponentiation.h\"\
    \n\r\nusing u128 = __uint128_t;\r\nusing i128 = __int128;\r\n\r\nll binMul(ll\
    \ a, ll b, ll M) { return (i128)a * b % M; }\r\n\r\n// long double trick\r\n//\
    \ require: mantissa 64 bit, x86 gcc/clang\r\nll binMul2(ll a, ll b, ll M) {\r\n\
    \    ll q = (ll)((long double)a * b / M);\r\n    ll r = (ll)((unsigned ll)a *\
    \ b - (unsigned ll)q * M);\r\n    return r < 0 ? r + M : (r >= M ? r - M : r);\r\
    \n}\r\n\r\nll binMul3(ll a, ll b, ll M) {\r\n    unsigned long long ua = a % M,\
    \ um = M, res = 0;\r\n    while (b) {\r\n        if (b & 1) { res += ua; if (res\
    \ >= um) res -= um; }\r\n        ua <<= 1; if (ua >= um) ua -= um;\r\n       \
    \ b >>= 1;\r\n    }\r\n    return res;\r\n}\r\n\r\nll binPow(ll a, ll b, ll M)\
    \ {\r\n    a %= M;\r\n    ll res = 1 % M;\r\n    while (b) {\r\n        if (b\
    \ & 1) res = (i128)res * a % M;\r\n        a = (i128)a * a % M;\r\n        b /=\
    \ 2;\r\n    }\r\n    return res;\r\n}\n#line 3 \"NumberTheory/Math/MillerRabin.h\"\
    \n\r\n\r\nbool millerTest(ll a, ll n, ll k, ll m) {\r\n    ll mod = binPow(a,\
    \ m, n);\r\n    if (mod == 1 || mod == n - 1) return true;\r\n    for (int l =\
    \ 1; l < k; l++) {\r\n        mod = (u128)mod * mod % n;\r\n        if (mod ==\
    \ n - 1) return true;\r\n    }\r\n    return false;\r\n}\r\n\r\n// Miller rabin\r\
    \nbool MillerRabin0(ll n) {\r\n    if (n < 4) return n == 2 || n == 3;\r\n   \
    \ if (n % 2 == 0) return false;\r\n    ll k = 0, m = n - 1;\r\n    while(m % 2\
    \ == 0) {\r\n        m /= 2;\r\n        k++;\r\n    }\r\n    for (int i = 0; i\
    \ < 5; i++) {\r\n        ll a = get_rand(n-3) + 2;\r\n        if (!millerTest(a,\
    \ n, k, m)) return false;\r\n    }\r\n    return true;\r\n}\r\n\r\n// Miller Rabin\
    \ deterministic version\r\nbool MillerRabin(ll n) {\r\n    if (n <= 1) return\
    \ false;\r\n    ll k = 0, m = n-1;\r\n    while (m % 2 == 0) {\r\n        m /=\
    \ 2;\r\n        k++;\r\n    }\r\n    for (int a : {2, 3, 5, 7, 11, 13, 17, 19,\
    \ 23, 29, 31, 37}) {\r\n        if (n == a) return true;\r\n        if (!millerTest(a,\
    \ n, k, m)) return false;\r\n    }\r\n    return true;\r\n}\n"
  code: "#include \"../../template.h\"\r\n#include \"Binary_exponentiation.h\"\r\n\
    \r\n\r\nbool millerTest(ll a, ll n, ll k, ll m) {\r\n    ll mod = binPow(a, m,\
    \ n);\r\n    if (mod == 1 || mod == n - 1) return true;\r\n    for (int l = 1;\
    \ l < k; l++) {\r\n        mod = (u128)mod * mod % n;\r\n        if (mod == n\
    \ - 1) return true;\r\n    }\r\n    return false;\r\n}\r\n\r\n// Miller rabin\r\
    \nbool MillerRabin0(ll n) {\r\n    if (n < 4) return n == 2 || n == 3;\r\n   \
    \ if (n % 2 == 0) return false;\r\n    ll k = 0, m = n - 1;\r\n    while(m % 2\
    \ == 0) {\r\n        m /= 2;\r\n        k++;\r\n    }\r\n    for (int i = 0; i\
    \ < 5; i++) {\r\n        ll a = get_rand(n-3) + 2;\r\n        if (!millerTest(a,\
    \ n, k, m)) return false;\r\n    }\r\n    return true;\r\n}\r\n\r\n// Miller Rabin\
    \ deterministic version\r\nbool MillerRabin(ll n) {\r\n    if (n <= 1) return\
    \ false;\r\n    ll k = 0, m = n-1;\r\n    while (m % 2 == 0) {\r\n        m /=\
    \ 2;\r\n        k++;\r\n    }\r\n    for (int a : {2, 3, 5, 7, 11, 13, 17, 19,\
    \ 23, 29, 31, 37}) {\r\n        if (n == a) return true;\r\n        if (!millerTest(a,\
    \ n, k, m)) return false;\r\n    }\r\n    return true;\r\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/Binary_exponentiation.h
  isVerificationFile: false
  path: NumberTheory/Math/MillerRabin.h
  requiredBy:
  - NumberTheory/Math/Pollard_rho.h
  - NumberTheory/Math/Divisors.h
  - NumberTheory/Math/Primitive_root.h
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - NumberTheory/Yosupo/Unit_test_math.test.cpp
  - NumberTheory/Yosupo/Primitive_root.test.cpp
  - NumberTheory/Yosupo/Factorize.test.cpp
  - NumberTheory/Yosupo/Primality_test.test.cpp
documentation_of: NumberTheory/Math/MillerRabin.h
layout: document
redirect_from:
- /library/NumberTheory/Math/MillerRabin.h
- /library/NumberTheory/Math/MillerRabin.h.html
title: NumberTheory/Math/MillerRabin.h
---
