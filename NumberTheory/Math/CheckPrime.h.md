---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Aizu/aizu_alds1_1_c_check_prime.test.cpp
    title: NumberTheory/Aizu/aizu_alds1_1_c_check_prime.test.cpp
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Yosupo/Counting_primes.test.cpp
    title: NumberTheory/Yosupo/Counting_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Yosupo/Enumerate_primes.test.cpp
    title: NumberTheory/Yosupo/Enumerate_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/91632
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"NumberTheory/Math/CheckPrime.h\"\
    \n\r\n\r\nbool BruteForce(ll n) {\r\n    if (n == 2 || n == 3) return true;\r\n\
    \    if (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;\r\n    ll lim = sqrtl(n);\r\
    \n    while (lim > 0 && lim > n / lim) lim--;\r\n    for (ll i = 5; i <= lim;\
    \ i += 6) {\r\n        if (n % i == 0 || n % (i+2) == 0) return false;\r\n   \
    \ }\r\n    return true;\r\n}\r\n\r\n// https://codeforces.com/blog/entry/91632\r\
    \nll Meissel(ll n) {\r\n    vector<ll> v;\r\n    for (ll i = 1; i*i <= n; i++)\
    \ {\r\n        v.push_back(i);\r\n        v.push_back(n / i);\r\n    }\r\n   \
    \ sort(all(v));\r\n    unique(v);\r\n    ll sq = sqrt(n);\r\n    auto geti = [&](ll\
    \ x) {\r\n        if (x <= sq) return x-1;\r\n        return (int)v.size() - n\
    \ / x;\r\n    };\r\n    vector<ll> dp = v;\r\n    ll a = 0;\r\n    for (ll p =\
    \ 2; p*p <= n; p++) {\r\n        if (dp[geti(p)] == dp[geti(p-1)]) continue;\r\
    \n        a++;\r\n        for (int i = (int)v.size()-1; i >= 0; i--) {\r\n   \
    \         if (v[i] < p * p) break;\r\n            dp[i] -= dp[geti(v[i] / p)]\
    \ - a;\r\n        }\r\n    }\r\n    return dp[geti(n)] - 1;\r\n}\n"
  code: "#include \"../../template.h\"\r\n\r\n\r\nbool BruteForce(ll n) {\r\n    if\
    \ (n == 2 || n == 3) return true;\r\n    if (n <= 1 || n % 2 == 0 || n % 3 ==\
    \ 0) return false;\r\n    ll lim = sqrtl(n);\r\n    while (lim > 0 && lim > n\
    \ / lim) lim--;\r\n    for (ll i = 5; i <= lim; i += 6) {\r\n        if (n % i\
    \ == 0 || n % (i+2) == 0) return false;\r\n    }\r\n    return true;\r\n}\r\n\r\
    \n// https://codeforces.com/blog/entry/91632\r\nll Meissel(ll n) {\r\n    vector<ll>\
    \ v;\r\n    for (ll i = 1; i*i <= n; i++) {\r\n        v.push_back(i);\r\n   \
    \     v.push_back(n / i);\r\n    }\r\n    sort(all(v));\r\n    unique(v);\r\n\
    \    ll sq = sqrt(n);\r\n    auto geti = [&](ll x) {\r\n        if (x <= sq) return\
    \ x-1;\r\n        return (int)v.size() - n / x;\r\n    };\r\n    vector<ll> dp\
    \ = v;\r\n    ll a = 0;\r\n    for (ll p = 2; p*p <= n; p++) {\r\n        if (dp[geti(p)]\
    \ == dp[geti(p-1)]) continue;\r\n        a++;\r\n        for (int i = (int)v.size()-1;\
    \ i >= 0; i--) {\r\n            if (v[i] < p * p) break;\r\n            dp[i]\
    \ -= dp[geti(v[i] / p)] - a;\r\n        }\r\n    }\r\n    return dp[geti(n)] -\
    \ 1;\r\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/CheckPrime.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - NumberTheory/Aizu/aizu_alds1_1_c_check_prime.test.cpp
  - NumberTheory/Yosupo/Enumerate_primes.test.cpp
  - NumberTheory/Yosupo/Counting_primes.test.cpp
documentation_of: NumberTheory/Math/CheckPrime.h
layout: document
redirect_from:
- /library/NumberTheory/Math/CheckPrime.h
- /library/NumberTheory/Math/CheckPrime.h.html
title: NumberTheory/Math/CheckPrime.h
---
