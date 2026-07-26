---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Divisors.h
    title: NumberTheory/Math/Divisors.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Yosupo/Enumerate_primes.test.cpp
    title: NumberTheory/Yosupo/Enumerate_primes.test.cpp
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
    \n#define INF32 ((1ull<<31)-1)\r\n#define INF64 ((1ull<<63)-1)\r\n#define inf\
    \ (ll)1e18\r\n\r\n#define vi vector<int>\r\n#define pii pair<int, int>\r\n#define\
    \ pll pair<ll, ll>\r\n#define fi first\r\n#define se second\r\n\r\nmt19937_64\
    \ rng(chrono::steady_clock::now().time_since_epoch().count());\r\nll get_rand(ll\
    \ r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\r\nconst int\
    \ mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main(){\r\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\r\
    \n    // cin.exceptions(cin.failbit);\r\n    // int t; cin >> t;\r\n    // while(t--)\r\
    \n        solve();\r\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"NumberTheory/Math/Sieve.h\"\
    \n\r\nvector<int> sieve(int n) {\r\n    vector<int> nt(n+1, 1);\r\n    nt[0] =\
    \ nt[1] = 0;\r\n    for (int i = 2; i * i <= n; i++) {\r\n        if (!nt[i])\
    \ continue;\r\n        for (int j = i * i; j <= n; j += i)\r\n            nt[j]\
    \ = 0;\r\n    }\r\n    return nt;\r\n}\r\n\r\nvector<int> segmentSieve(ll l, ll\
    \ r){\r\n    ll sq = sqrtl(r);\r\n    while (sq * sq > r) sq--;\r\n    while (sq+1\
    \ <= r/(sq+1)) sq++;\r\n    vector<int> small(sq+1, 1);\r\n    for (ll i = 2;\
    \ i*i <= sq; i++) {\r\n        if (!small[i]) continue;\r\n        for (ll j =\
    \ i*i; j <= sq; j += i) {\r\n            small[j] = 0;\r\n        }\r\n    }\r\
    \n    vector<int> prime(r-l+1, 1);\r\n    for(ll p = 2; p <= sq; p++){\r\n   \
    \     if (!small[p]) continue;\r\n        ll lim = max(p*p, (l+p-1)/p*p);\r\n\
    \        for(ll j = lim; j <= r; j += p) {\r\n            prime[j-l] = 0;\r\n\
    \        }\r\n    }\r\n    if (l == 0) prime[0] = 0;\r\n    if (l == 0 && r >\
    \ l) prime[1] = 0;\r\n    if (l == 1) prime[1-l] = 0;\r\n    return prime;\r\n\
    }\r\n\r\nvector<int> listPrime(int l, int r) {\r\n    vector<int> prime = segmentSieve(l,\
    \ r);\r\n    vector<int> listPi;\r\n    for (int i = l; i <= r; i++) {\r\n   \
    \     if (prime[i-l]) listPi.push_back(i);\r\n    }\r\n    return listPi;\r\n\
    }\r\n\r\nvector<int> sieve_count_divisors(int n) {\r\n    vector<int> divisors(n+1,\
    \ 0);\r\n    for (ll i = 1; i*i <= n; i++) {\r\n        for (ll j = i*i; j <=\
    \ n; j += i) {\r\n            divisors[j] += 2;\r\n        }\r\n        divisors[i*i]--;\r\
    \n    }\r\n    return divisors;\r\n}\r\n\r\nvector<int> sieve_sum_divisors(int\
    \ n) {\r\n    vector<int> sumDiv(n+1, 0);\r\n    for (int i = 1; i*i <= n; i++)\
    \ {\r\n        for (int j = i*i; j <= n; j += i) {\r\n            sumDiv[j] +=\
    \ i;\r\n            if (i*i != j) sumDiv[j] += j/i;\r\n        }\r\n    }\r\n\
    \    return sumDiv;\r\n}\r\n\r\nvector<int> segmentSieveDivisors(int l, int r){\r\
    \n    vector<int> div(r-l+1, 0);\r\n    for(ll i = 1; i*i <= r; i++){\r\n    \
    \    ll lim = max(i*i, (l+i-1)/i*i);\r\n        for(ll j = lim; j <= r; j += i)\
    \ {\r\n            div[j-l] += 2;\r\n        }\r\n        if (i * i >= l) div[i*i-l]--;\r\
    \n    }\r\n    if (l == 0) div[0] = 0;\r\n    return div;\r\n}\r\n\r\nvector<vector<int>>\
    \ sieve_prime_divisors(int n) {\r\n    vector<int> prime = sieve(n);\r\n    vector<vector<int>>\
    \ div(n+1);\r\n    for (int i = 2; i <= n; i++) {\r\n        if (!prime[i]) continue;\r\
    \n        for (int j = i; j <= n; j += i) {\r\n            div[j].push_back(i);\r\
    \n        }\r\n    }\r\n    return div;\r\n}\n"
  code: "#include \"../../template.h\"\r\n\r\nvector<int> sieve(int n) {\r\n    vector<int>\
    \ nt(n+1, 1);\r\n    nt[0] = nt[1] = 0;\r\n    for (int i = 2; i * i <= n; i++)\
    \ {\r\n        if (!nt[i]) continue;\r\n        for (int j = i * i; j <= n; j\
    \ += i)\r\n            nt[j] = 0;\r\n    }\r\n    return nt;\r\n}\r\n\r\nvector<int>\
    \ segmentSieve(ll l, ll r){\r\n    ll sq = sqrtl(r);\r\n    while (sq * sq > r)\
    \ sq--;\r\n    while (sq+1 <= r/(sq+1)) sq++;\r\n    vector<int> small(sq+1, 1);\r\
    \n    for (ll i = 2; i*i <= sq; i++) {\r\n        if (!small[i]) continue;\r\n\
    \        for (ll j = i*i; j <= sq; j += i) {\r\n            small[j] = 0;\r\n\
    \        }\r\n    }\r\n    vector<int> prime(r-l+1, 1);\r\n    for(ll p = 2; p\
    \ <= sq; p++){\r\n        if (!small[p]) continue;\r\n        ll lim = max(p*p,\
    \ (l+p-1)/p*p);\r\n        for(ll j = lim; j <= r; j += p) {\r\n            prime[j-l]\
    \ = 0;\r\n        }\r\n    }\r\n    if (l == 0) prime[0] = 0;\r\n    if (l ==\
    \ 0 && r > l) prime[1] = 0;\r\n    if (l == 1) prime[1-l] = 0;\r\n    return prime;\r\
    \n}\r\n\r\nvector<int> listPrime(int l, int r) {\r\n    vector<int> prime = segmentSieve(l,\
    \ r);\r\n    vector<int> listPi;\r\n    for (int i = l; i <= r; i++) {\r\n   \
    \     if (prime[i-l]) listPi.push_back(i);\r\n    }\r\n    return listPi;\r\n\
    }\r\n\r\nvector<int> sieve_count_divisors(int n) {\r\n    vector<int> divisors(n+1,\
    \ 0);\r\n    for (ll i = 1; i*i <= n; i++) {\r\n        for (ll j = i*i; j <=\
    \ n; j += i) {\r\n            divisors[j] += 2;\r\n        }\r\n        divisors[i*i]--;\r\
    \n    }\r\n    return divisors;\r\n}\r\n\r\nvector<int> sieve_sum_divisors(int\
    \ n) {\r\n    vector<int> sumDiv(n+1, 0);\r\n    for (int i = 1; i*i <= n; i++)\
    \ {\r\n        for (int j = i*i; j <= n; j += i) {\r\n            sumDiv[j] +=\
    \ i;\r\n            if (i*i != j) sumDiv[j] += j/i;\r\n        }\r\n    }\r\n\
    \    return sumDiv;\r\n}\r\n\r\nvector<int> segmentSieveDivisors(int l, int r){\r\
    \n    vector<int> div(r-l+1, 0);\r\n    for(ll i = 1; i*i <= r; i++){\r\n    \
    \    ll lim = max(i*i, (l+i-1)/i*i);\r\n        for(ll j = lim; j <= r; j += i)\
    \ {\r\n            div[j-l] += 2;\r\n        }\r\n        if (i * i >= l) div[i*i-l]--;\r\
    \n    }\r\n    if (l == 0) div[0] = 0;\r\n    return div;\r\n}\r\n\r\nvector<vector<int>>\
    \ sieve_prime_divisors(int n) {\r\n    vector<int> prime = sieve(n);\r\n    vector<vector<int>>\
    \ div(n+1);\r\n    for (int i = 2; i <= n; i++) {\r\n        if (!prime[i]) continue;\r\
    \n        for (int j = i; j <= n; j += i) {\r\n            div[j].push_back(i);\r\
    \n        }\r\n    }\r\n    return div;\r\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/Sieve.h
  requiredBy:
  - NumberTheory/Math/Divisors.h
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - NumberTheory/Yosupo/Unit_test_math.test.cpp
  - NumberTheory/Yosupo/Enumerate_primes.test.cpp
documentation_of: NumberTheory/Math/Sieve.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Sieve.h
- /library/NumberTheory/Math/Sieve.h.html
title: NumberTheory/Math/Sieve.h
---
