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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Yosupo/Enumerate_primes.test.cpp
    title: NumberTheory/Yosupo/Enumerate_primes.test.cpp
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
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Sieve.h\"\n\nvector<int> sieve(int n) {\n\
    \    vector<int> nt(n+1, 1);\n    nt[0] = nt[1] = 0;\n    for (int i = 2; i *\
    \ i <= n; i++) {\n        if (!nt[i]) continue;\n        for (int j = i * i; j\
    \ <= n; j += i)\n            nt[j] = 0;\n    }\n    return nt;\n}\n\nvector<int>\
    \ segmentSieve(int l, int r){\n    vector<int> prime(r-l+1, 1);\n    for(ll p\
    \ = 2; p*p <= r; p++){\n        ll lim = max(p*p, (l+p-1)/p*p);\n        for(ll\
    \ j = lim; j <= r; j += p)\n            if (j-l >= 0) prime[j-l] = 0;\n    }\n\
    \    if (l == 0) prime[0] = 0;\n    if (l == 0 && r > l) prime[1] = 0;\n    if\
    \ (l == 1) prime[1-l] = 0;\n    return prime;\n}\n\nvector<int> listPrime(int\
    \ l, int r) {\n    vector<int> prime = segmentSieve(l, r);\n    vector<int> listPi;\n\
    \    for (int i = l; i <= r; i++) {\n        if (prime[i-l]) listPi.push_back(i);\n\
    \    }\n    return listPi;\n}\n\nvector<int> sieve_count_divisors(int n) {\n \
    \   vector<int> divisors(n+1, 0);\n    for (int i = 1; i*i <= n; i++) {\n    \
    \    for (int j = i; j <= n; j += i) {\n            divisors[j]++;\n        }\n\
    \        divisors[i*i]--;\n    }\n    return divisors;\n}\n\nvector<int> sieve_sum_divisors(int\
    \ n) {\n    vector<int> sumDiv(n+1, 0);\n    for (int i = 1; i*i <= n; i++) {\n\
    \        for (int j = i; j <= n; j += i) {\n            sumDiv[j] += i;\n    \
    \        if (i*i != j) sumDiv[j] += j/i;\n        }\n    }\n    return sumDiv;\n\
    }\n\nvector<vector<int>> sieve__prime_divisors(int n) {\n    vector<int> prime\
    \ = sieve(n);\n    vector<vector<int>> div(n+1);\n    for (int i = 2; i <= n;\
    \ i++) {\n        if (!prime[i]) continue;\n        for (int j = i; j <= n; j\
    \ += i) {\n            div[j].push_back(i);\n        }\n    }\n    return div;\n\
    }\n"
  code: "#include \"../../template.h\"\n\nvector<int> sieve(int n) {\n    vector<int>\
    \ nt(n+1, 1);\n    nt[0] = nt[1] = 0;\n    for (int i = 2; i * i <= n; i++) {\n\
    \        if (!nt[i]) continue;\n        for (int j = i * i; j <= n; j += i)\n\
    \            nt[j] = 0;\n    }\n    return nt;\n}\n\nvector<int> segmentSieve(int\
    \ l, int r){\n    vector<int> prime(r-l+1, 1);\n    for(ll p = 2; p*p <= r; p++){\n\
    \        ll lim = max(p*p, (l+p-1)/p*p);\n        for(ll j = lim; j <= r; j +=\
    \ p)\n            if (j-l >= 0) prime[j-l] = 0;\n    }\n    if (l == 0) prime[0]\
    \ = 0;\n    if (l == 0 && r > l) prime[1] = 0;\n    if (l == 1) prime[1-l] = 0;\n\
    \    return prime;\n}\n\nvector<int> listPrime(int l, int r) {\n    vector<int>\
    \ prime = segmentSieve(l, r);\n    vector<int> listPi;\n    for (int i = l; i\
    \ <= r; i++) {\n        if (prime[i-l]) listPi.push_back(i);\n    }\n    return\
    \ listPi;\n}\n\nvector<int> sieve_count_divisors(int n) {\n    vector<int> divisors(n+1,\
    \ 0);\n    for (int i = 1; i*i <= n; i++) {\n        for (int j = i; j <= n; j\
    \ += i) {\n            divisors[j]++;\n        }\n        divisors[i*i]--;\n \
    \   }\n    return divisors;\n}\n\nvector<int> sieve_sum_divisors(int n) {\n  \
    \  vector<int> sumDiv(n+1, 0);\n    for (int i = 1; i*i <= n; i++) {\n       \
    \ for (int j = i; j <= n; j += i) {\n            sumDiv[j] += i;\n           \
    \ if (i*i != j) sumDiv[j] += j/i;\n        }\n    }\n    return sumDiv;\n}\n\n\
    vector<vector<int>> sieve__prime_divisors(int n) {\n    vector<int> prime = sieve(n);\n\
    \    vector<vector<int>> div(n+1);\n    for (int i = 2; i <= n; i++) {\n     \
    \   if (!prime[i]) continue;\n        for (int j = i; j <= n; j += i) {\n    \
    \        div[j].push_back(i);\n        }\n    }\n    return div;\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/Sieve.h
  requiredBy:
  - NumberTheory/Math/Divisors.h
  timestamp: '2025-12-04 02:05:35+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - NumberTheory/Yosupo/Enumerate_primes.test.cpp
documentation_of: NumberTheory/Math/Sieve.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Sieve.h
- /library/NumberTheory/Math/Sieve.h.html
title: NumberTheory/Math/Sieve.h
---
