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
    links:
    - https://wiki.vnoi.info/translate/he/Wilsons-theorem
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Factorial.h\"\n\r\n\r\n// https://wiki.vnoi.info/translate/he/Wilsons-theorem\r\
    \n// Wilson theorem\r\n// n > 1 is prime <=> (n-1)! \u2261 -1 (mod n)\r\n//\r\n\
    // Proof:\r\n//    a^(n-2) \u2261 a^(-1) (mod n) (Fermat's little theorem)\r\n\
    // => a^(n-2) * a \u2261 1 (mod n)\r\n// Set b = a^(n-2)\r\n// => ab \u2261 1\
    \ (mod n)\r\n//\r\n// Have a = b <=> a^2 \u2261 1 (mod n) <=> a = 1 or a = n-1\r\
    \n//\r\n// So if a = 2,3,...,n-2 then a != b\r\n// => we have (n-3)/2 distinct\
    \ pairs (because with each a, b is unique)\r\n// so we multiple all paris\r\n\
    // => 2.3...(n-2) \u2261 1 (mod n)\r\n// => (n-1)! \u2261 n-1 (mod n)\r\n\r\n\
    // Proof by contradiction:\r\n// if n is not prime => n have divisors in range\
    \ [2, n)\r\n//                   => gcd((n-1)!, n) > 1\r\n//                 \
    \  => gcd(n-1, n) > 1 (contradiction)\r\nint factmod(int n, int p) {\r\n    vector<int>\
    \ f(p);\r\n    f[0] = 1;\r\n    for (int i = 1; i < p; i++) {\r\n        f[i]\
    \ = f[i-1] * i % p;\r\n    }\r\n    int res = 1;\r\n    while (n > 1) {\r\n  \
    \      if ((n/p) % 2) res = p - res;\r\n        res = res * f[n % p] % p;\r\n\
    \        n /= p;\r\n    }\r\n    return res;\r\n}\r\n// use for small prime p\r\
    \n\r\n\r\n// Optimize version using static to cache\r\nll factmod(ll n, ll p)\
    \ {\r\n    static ll lastp = -1;\r\n    static vector<ll> f;\r\n    if (p != lastp)\
    \ {\r\n        lastp = p;\r\n        f.assign(p, 1);\r\n        for (ll i = 1;\
    \ i < p; i++) f[i] = f[i-1] * i % p;\r\n    }\r\n    ll res = 1;\r\n    while\
    \ (n > 1) {\r\n        if ((n/p) % 2) res = p - res;\r\n        res = res * f[n\
    \ % p] % p;\r\n        n /= p;\r\n    }\r\n    return res;\r\n}\n"
  code: "#include \"../../template.h\"\r\n\r\n\r\n// https://wiki.vnoi.info/translate/he/Wilsons-theorem\r\
    \n// Wilson theorem\r\n// n > 1 is prime <=> (n-1)! \u2261 -1 (mod n)\r\n//\r\n\
    // Proof:\r\n//    a^(n-2) \u2261 a^(-1) (mod n) (Fermat's little theorem)\r\n\
    // => a^(n-2) * a \u2261 1 (mod n)\r\n// Set b = a^(n-2)\r\n// => ab \u2261 1\
    \ (mod n)\r\n//\r\n// Have a = b <=> a^2 \u2261 1 (mod n) <=> a = 1 or a = n-1\r\
    \n//\r\n// So if a = 2,3,...,n-2 then a != b\r\n// => we have (n-3)/2 distinct\
    \ pairs (because with each a, b is unique)\r\n// so we multiple all paris\r\n\
    // => 2.3...(n-2) \u2261 1 (mod n)\r\n// => (n-1)! \u2261 n-1 (mod n)\r\n\r\n\
    // Proof by contradiction:\r\n// if n is not prime => n have divisors in range\
    \ [2, n)\r\n//                   => gcd((n-1)!, n) > 1\r\n//                 \
    \  => gcd(n-1, n) > 1 (contradiction)\r\nint factmod(int n, int p) {\r\n    vector<int>\
    \ f(p);\r\n    f[0] = 1;\r\n    for (int i = 1; i < p; i++) {\r\n        f[i]\
    \ = f[i-1] * i % p;\r\n    }\r\n    int res = 1;\r\n    while (n > 1) {\r\n  \
    \      if ((n/p) % 2) res = p - res;\r\n        res = res * f[n % p] % p;\r\n\
    \        n /= p;\r\n    }\r\n    return res;\r\n}\r\n// use for small prime p\r\
    \n\r\n\r\n// Optimize version using static to cache\r\nll factmod(ll n, ll p)\
    \ {\r\n    static ll lastp = -1;\r\n    static vector<ll> f;\r\n    if (p != lastp)\
    \ {\r\n        lastp = p;\r\n        f.assign(p, 1);\r\n        for (ll i = 1;\
    \ i < p; i++) f[i] = f[i-1] * i % p;\r\n    }\r\n    ll res = 1;\r\n    while\
    \ (n > 1) {\r\n        if ((n/p) % 2) res = p - res;\r\n        res = res * f[n\
    \ % p] % p;\r\n        n /= p;\r\n    }\r\n    return res;\r\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/Factorial.h
  requiredBy: []
  timestamp: '2026-07-26 02:09:30+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NumberTheory/Math/Factorial.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Factorial.h
- /library/NumberTheory/Math/Factorial.h.html
title: NumberTheory/Math/Factorial.h
---
