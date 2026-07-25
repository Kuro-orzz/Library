---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Extended_euclid.h
    title: NumberTheory/Math/Extended_euclid.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"NumberTheory/Aizu/aizu_ntl_1_e_extended_euclid.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \r\n\r\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Extended_euclid.h\"\n\r\n\r\nll extended1(ll\
    \ a, ll b, ll &x, ll &y) {\r\n    if (b == 0) {\r\n        x = 1, y = 0;\r\n \
    \       return a;\r\n    }\r\n    ll x1, y1;\r\n    ll d = extended1(b, a%b, x1,\
    \ y1);\r\n    x = y1;\r\n    y = x1-y1*(a/b);\r\n    return d;\r\n}\r\n\r\n//\
    \ Iterative version\r\nll extended2(ll a, ll b, ll &x, ll &y) {\r\n    x = 1,\
    \ y = 0;\r\n    ll x1 = 0, y1 = 1;\r\n    ll a1 = a, b1 = b;\r\n    while (b1)\
    \ {\r\n        ll q = a1 / b1;\r\n        tie(x, x1) = make_tuple(x1, x - q *\
    \ x1);\r\n        tie(y, y1) = make_tuple(y1, y - q * y1);\r\n        tie(a1,\
    \ b1) = make_tuple(b1, a1 - q * b1);\r\n    }\r\n    return a1;\r\n}\n#line 5\
    \ \"NumberTheory/Aizu/aizu_ntl_1_e_extended_euclid.test.cpp\"\n\r\nvoid solve()\
    \ {\r\n    ll a, b; cin >> a >> b;\r\n    ll x, y;\r\n    ll g = extended2(a,\
    \ b, x, y);\r\n    cout << x << \" \" << y << '\\n';\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \r\n\r\n#include \"../../template.h\"\r\n#include \"../Math/Extended_euclid.h\"\
    \r\n\r\nvoid solve() {\r\n    ll a, b; cin >> a >> b;\r\n    ll x, y;\r\n    ll\
    \ g = extended2(a, b, x, y);\r\n    cout << x << \" \" << y << '\\n';\r\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/Extended_euclid.h
  isVerificationFile: true
  path: NumberTheory/Aizu/aizu_ntl_1_e_extended_euclid.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 02:09:30+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: NumberTheory/Aizu/aizu_ntl_1_e_extended_euclid.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Aizu/aizu_ntl_1_e_extended_euclid.test.cpp
- /verify/NumberTheory/Aizu/aizu_ntl_1_e_extended_euclid.test.cpp.html
title: NumberTheory/Aizu/aizu_ntl_1_e_extended_euclid.test.cpp
---
