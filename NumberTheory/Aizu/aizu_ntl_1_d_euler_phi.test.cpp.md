---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/EulerPhi.h
    title: NumberTheory/Math/EulerPhi.h
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
  bundledCode: "#line 1 \"NumberTheory/Aizu/aizu_ntl_1_d_euler_phi.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"NumberTheory/Math/EulerPhi.h\"\n\r\nll eulerPhi(ll n) {\r\n\
    \    if (n == 0) return 0;\r\n    ll ans = n;\r\n    for (ll i = 2; i*i <= n;\
    \ i++) {\r\n        if (n % i == 0) {\r\n            ans -= ans / i;\r\n     \
    \       while (n % i == 0) n /= i;\r\n        }\r\n    }\r\n    if (n > 1) ans\
    \ -= ans / n;\r\n    return ans;\r\n}\r\n\r\n// optimize version using wheel 6k+1\r\
    \nll eulerPhi2(ll n) {\r\n    if (n == 0) return 0;\r\n    ll ans = n;\r\n   \
    \ for (ll p : {2, 3}) {\r\n        if (n % p == 0) { \r\n            ans -= ans/p;\r\
    \n            while (n % p == 0) n /= p;\r\n        }\r\n    }\r\n    for (ll\
    \ i = 5; i*i <= n; i += 6) {\r\n        if (n % i == 0) { \r\n            ans\
    \ -= ans/i; \r\n            while (n % i == 0) n /= i;\r\n        }\r\n      \
    \  if (n % (i+2)==0) {\r\n            ans -= ans/(i+2);\r\n            while (n\
    \ % (i+2) == 0) n /= (i+2);\r\n        }\r\n    }\r\n    if (n > 1) ans -= ans/n;\r\
    \n    return ans;\r\n}\r\n\r\nvector<int> phi_from_1_to_n(int n) {\r\n    vector<int>\
    \ phi(n + 1);\r\n    iota(all(phi), 0);\r\n    \r\n    for (int i = 2; i <= n;\
    \ i++) {\r\n        if (phi[i] == i) {\r\n            for (int j = i; j <= n;\
    \ j += i) {\r\n                phi[j] -= phi[j] / i;\r\n            }\r\n    \
    \    }\r\n    }\r\n    return phi;\r\n}\r\n\r\n// phi(a * b) = phi(a) * phi(b)\
    \ / phi(gcd(a, b)) * gcd(a, b)\r\n// int gcd = __gcd(a, b);\r\n// int phi[a*b]\
    \ = (1ull * phi[a] * phi[b] / phi[gcd] * gcd) % mod;\n#line 5 \"NumberTheory/Aizu/aizu_ntl_1_d_euler_phi.test.cpp\"\
    \n\nvoid solve() {\n    ll n; cin >> n;\n    cout << eulerPhi(n) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n\n#include \"../../template.h\"\n#include \"../Math/EulerPhi.h\"\n\nvoid solve()\
    \ {\n    ll n; cin >> n;\n    cout << eulerPhi(n) << '\\n';\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/EulerPhi.h
  isVerificationFile: true
  path: NumberTheory/Aizu/aizu_ntl_1_d_euler_phi.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 02:09:30+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: NumberTheory/Aizu/aizu_ntl_1_d_euler_phi.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Aizu/aizu_ntl_1_d_euler_phi.test.cpp
- /verify/NumberTheory/Aizu/aizu_ntl_1_d_euler_phi.test.cpp.html
title: NumberTheory/Aizu/aizu_ntl_1_d_euler_phi.test.cpp
---
