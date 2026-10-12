---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: NumberTheory/Math/Factorization.h
    title: NumberTheory/Math/Factorization.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"NumberTheory/Aizu/aizu_ntl_1_a_prime_factor.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \n \r\n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\
    \n#define unique(x) x.erase(unique(all(x)), x.end())\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main() {\r\n  \
    \  // if (FILE* f = fopen(TASK \".inp\", \"r\")) {\r\n    //     fclose(f);\r\n\
    \    //     freopen(TASK \".inp\", \"r\", stdin);\r\n    //     freopen(TASK \"\
    .out\", \"w\", stdout);\r\n    // }\r\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\r\
    \n    // cin.exceptions(cin.failbit);\r\n    // int t; cin >> t;\r\n    // while(t--)\r\
    \n        solve();\r\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"NumberTheory/Math/Factorization.h\"\
    \n\r\n\r\n// 360 -> [2, 2, 2, 3, 3, 5]\r\nvector<ll> primeFactor(ll n) {\r\n \
    \   vector<ll> factor;\r\n    for (int i : {2, 3, 5}) {\r\n        while (n %\
    \ i == 0) {\r\n            n /= i;\r\n            factor.push_back(i);\r\n   \
    \     }\r\n    }\r\n    int inc[] = {4, 2, 4, 2, 4, 6, 2, 6};\r\n    int j = 0;\r\
    \n    ll lim = sqrtl(n);\r\n    while (lim > 0 && lim > n / lim) lim--;\r\n  \
    \  for (ll i = 7; i <= lim; i += inc[j%8], j++) {\r\n        if (n % i) continue;\r\
    \n        while(n % i == 0) {\r\n            n /= i;\r\n            factor.push_back(i);\r\
    \n        }\r\n        lim = sqrtl(n);\r\n        while (lim > 0 && lim > n /\
    \ lim) lim--;\r\n    }\r\n    if (n > 1) factor.push_back(n);\r\n    return factor;\r\
    \n}\r\n\r\n// [2, 2, 2, 3, 3, 5] -> [(2,3), (3,2), (5,1)]\r\nvector<pll> primeFactorPow(ll\
    \ n) {\r\n    vector<pll> res;\r\n    for (ll p : primeFactor(n))\r\n        if\
    \ (!res.empty() && res.back().fi == p) res.back().se++;\r\n        else res.push_back({p,\
    \ 1});\r\n    return res;\r\n}\n#line 5 \"NumberTheory/Aizu/aizu_ntl_1_a_prime_factor.test.cpp\"\
    \n\nvoid solve() {\n    int n; cin >> n;\n    vector<ll> v = primeFactor(n);\n\
    \    cout << n << \": \";\n    for (int i = 0; i < (int)v.size() - 1; i++) {\n\
    \        cout << v[i] << \" \";\n    }\n    cout << v.back() << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#include \"../../template.h\"\n#include \"../Math/Factorization.h\"\n\nvoid\
    \ solve() {\n    int n; cin >> n;\n    vector<ll> v = primeFactor(n);\n    cout\
    \ << n << \": \";\n    for (int i = 0; i < (int)v.size() - 1; i++) {\n       \
    \ cout << v[i] << \" \";\n    }\n    cout << v.back() << '\\n';\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/Factorization.h
  isVerificationFile: true
  path: NumberTheory/Aizu/aizu_ntl_1_a_prime_factor.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: NumberTheory/Aizu/aizu_ntl_1_a_prime_factor.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Aizu/aizu_ntl_1_a_prime_factor.test.cpp
- /verify/NumberTheory/Aizu/aizu_ntl_1_a_prime_factor.test.cpp.html
title: NumberTheory/Aizu/aizu_ntl_1_a_prime_factor.test.cpp
---
