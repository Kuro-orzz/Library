---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Combination.h
    title: NumberTheory/Math/Combination.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Aizu/aizu_ntl_1_e_extended_euclid.test.cpp
    title: NumberTheory/Aizu/aizu_ntl_1_e_extended_euclid.test.cpp
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Yosupo/Binomial_coefficient_prime_mod.test.cpp
    title: NumberTheory/Yosupo/Binomial_coefficient_prime_mod.test.cpp
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"NumberTheory/Math/Extended_euclid.h\"\
    \n\r\n\r\nll extended1(ll a, ll b, ll &x, ll &y) {\r\n    if (b == 0) {\r\n  \
    \      x = 1, y = 0;\r\n        return a;\r\n    }\r\n    ll x1, y1;\r\n    ll\
    \ d = extended1(b, a%b, x1, y1);\r\n    x = y1;\r\n    y = x1-y1*(a/b);\r\n  \
    \  return d;\r\n}\r\n\r\n// Iterative version\r\nll extended2(ll a, ll b, ll &x,\
    \ ll &y) {\r\n    x = 1, y = 0;\r\n    ll x1 = 0, y1 = 1;\r\n    ll a1 = a, b1\
    \ = b;\r\n    while (b1) {\r\n        ll q = a1 / b1;\r\n        tie(x, x1) =\
    \ make_tuple(x1, x - q * x1);\r\n        tie(y, y1) = make_tuple(y1, y - q * y1);\r\
    \n        tie(a1, b1) = make_tuple(b1, a1 - q * b1);\r\n    }\r\n    return a1;\r\
    \n}\n"
  code: "#include \"../../template.h\"\r\n\r\n\r\nll extended1(ll a, ll b, ll &x,\
    \ ll &y) {\r\n    if (b == 0) {\r\n        x = 1, y = 0;\r\n        return a;\r\
    \n    }\r\n    ll x1, y1;\r\n    ll d = extended1(b, a%b, x1, y1);\r\n    x =\
    \ y1;\r\n    y = x1-y1*(a/b);\r\n    return d;\r\n}\r\n\r\n// Iterative version\r\
    \nll extended2(ll a, ll b, ll &x, ll &y) {\r\n    x = 1, y = 0;\r\n    ll x1 =\
    \ 0, y1 = 1;\r\n    ll a1 = a, b1 = b;\r\n    while (b1) {\r\n        ll q = a1\
    \ / b1;\r\n        tie(x, x1) = make_tuple(x1, x - q * x1);\r\n        tie(y,\
    \ y1) = make_tuple(y1, y - q * y1);\r\n        tie(a1, b1) = make_tuple(b1, a1\
    \ - q * b1);\r\n    }\r\n    return a1;\r\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/Extended_euclid.h
  requiredBy:
  - NumberTheory/Math/Combination.h
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - NumberTheory/Aizu/aizu_ntl_1_e_extended_euclid.test.cpp
  - NumberTheory/Yosupo/Binomial_coefficient_prime_mod.test.cpp
documentation_of: NumberTheory/Math/Extended_euclid.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Extended_euclid.h
- /library/NumberTheory/Math/Extended_euclid.h.html
title: NumberTheory/Math/Extended_euclid.h
---
