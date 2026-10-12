---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Aizu/aizu_ntl_1_d_euler_phi.test.cpp
    title: NumberTheory/Aizu/aizu_ntl_1_d_euler_phi.test.cpp
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"NumberTheory/Math/EulerPhi.h\"\
    \n\r\nll eulerPhi(ll n) {\r\n    if (n == 0) return 0;\r\n    ll ans = n;\r\n\
    \    for (ll i = 2; i*i <= n; i++) {\r\n        if (n % i == 0) {\r\n        \
    \    ans -= ans / i;\r\n            while (n % i == 0) n /= i;\r\n        }\r\n\
    \    }\r\n    if (n > 1) ans -= ans / n;\r\n    return ans;\r\n}\r\n\r\n// optimize\
    \ version using wheel 6k+1\r\nll eulerPhi2(ll n) {\r\n    if (n == 0) return 0;\r\
    \n    ll ans = n;\r\n    for (ll p : {2, 3}) {\r\n        if (n % p == 0) { \r\
    \n            ans -= ans/p;\r\n            while (n % p == 0) n /= p;\r\n    \
    \    }\r\n    }\r\n    for (ll i = 5; i*i <= n; i += 6) {\r\n        if (n % i\
    \ == 0) { \r\n            ans -= ans/i; \r\n            while (n % i == 0) n /=\
    \ i;\r\n        }\r\n        if (n % (i+2)==0) {\r\n            ans -= ans/(i+2);\r\
    \n            while (n % (i+2) == 0) n /= (i+2);\r\n        }\r\n    }\r\n   \
    \ if (n > 1) ans -= ans/n;\r\n    return ans;\r\n}\r\n\r\nvector<int> phi_from_1_to_n(int\
    \ n) {\r\n    vector<int> phi(n + 1);\r\n    iota(all(phi), 0);\r\n    \r\n  \
    \  for (int i = 2; i <= n; i++) {\r\n        if (phi[i] == i) {\r\n          \
    \  for (int j = i; j <= n; j += i) {\r\n                phi[j] -= phi[j] / i;\r\
    \n            }\r\n        }\r\n    }\r\n    return phi;\r\n}\r\n\r\n// phi(a\
    \ * b) = phi(a) * phi(b) / phi(gcd(a, b)) * gcd(a, b)\r\n// int gcd = __gcd(a,\
    \ b);\r\n// int phi[a*b] = (1ull * phi[a] * phi[b] / phi[gcd] * gcd) % mod;\n"
  code: "#include \"../../template.h\"\r\n\r\nll eulerPhi(ll n) {\r\n    if (n ==\
    \ 0) return 0;\r\n    ll ans = n;\r\n    for (ll i = 2; i*i <= n; i++) {\r\n \
    \       if (n % i == 0) {\r\n            ans -= ans / i;\r\n            while\
    \ (n % i == 0) n /= i;\r\n        }\r\n    }\r\n    if (n > 1) ans -= ans / n;\r\
    \n    return ans;\r\n}\r\n\r\n// optimize version using wheel 6k+1\r\nll eulerPhi2(ll\
    \ n) {\r\n    if (n == 0) return 0;\r\n    ll ans = n;\r\n    for (ll p : {2,\
    \ 3}) {\r\n        if (n % p == 0) { \r\n            ans -= ans/p;\r\n       \
    \     while (n % p == 0) n /= p;\r\n        }\r\n    }\r\n    for (ll i = 5; i*i\
    \ <= n; i += 6) {\r\n        if (n % i == 0) { \r\n            ans -= ans/i; \r\
    \n            while (n % i == 0) n /= i;\r\n        }\r\n        if (n % (i+2)==0)\
    \ {\r\n            ans -= ans/(i+2);\r\n            while (n % (i+2) == 0) n /=\
    \ (i+2);\r\n        }\r\n    }\r\n    if (n > 1) ans -= ans/n;\r\n    return ans;\r\
    \n}\r\n\r\nvector<int> phi_from_1_to_n(int n) {\r\n    vector<int> phi(n + 1);\r\
    \n    iota(all(phi), 0);\r\n    \r\n    for (int i = 2; i <= n; i++) {\r\n   \
    \     if (phi[i] == i) {\r\n            for (int j = i; j <= n; j += i) {\r\n\
    \                phi[j] -= phi[j] / i;\r\n            }\r\n        }\r\n    }\r\
    \n    return phi;\r\n}\r\n\r\n// phi(a * b) = phi(a) * phi(b) / phi(gcd(a, b))\
    \ * gcd(a, b)\r\n// int gcd = __gcd(a, b);\r\n// int phi[a*b] = (1ull * phi[a]\
    \ * phi[b] / phi[gcd] * gcd) % mod;"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/EulerPhi.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - NumberTheory/Aizu/aizu_ntl_1_d_euler_phi.test.cpp
documentation_of: NumberTheory/Math/EulerPhi.h
layout: document
redirect_from:
- /library/NumberTheory/Math/EulerPhi.h
- /library/NumberTheory/Math/EulerPhi.h.html
title: NumberTheory/Math/EulerPhi.h
---
