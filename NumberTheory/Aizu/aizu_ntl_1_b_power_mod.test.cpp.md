---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: NumberTheory/Math/Binary_exponentiation.h
    title: NumberTheory/Math/Binary_exponentiation.h
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
  bundledCode: "#line 1 \"NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \n \r\n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\
    \n#define unique(x) x.erase(unique(all(x)), x.end())\r\n#define INF32 ((1ull<<31)-1)\r\
    \n#define INF64 ((1ull<<63)-1)\r\n#define inf (ll)1e18\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main(){\r\n   \
    \ ios_base::sync_with_stdio(false);cin.tie(NULL);\r\n    // cin.exceptions(cin.failbit);\r\
    \n    // int t; cin >> t;\r\n    // while(t--)\r\n        solve();\r\n    cerr\
    \ << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\r\
    \n    return 0;\r\n}\n#line 2 \"NumberTheory/Math/Binary_exponentiation.h\"\n\r\
    \nusing u128 = __uint128_t;\r\nusing i128 = __int128;\r\n\r\nll binMul(ll a, ll\
    \ b, ll M) { return (i128)a * b % M; }\r\n\r\n// long double trick\r\n// require:\
    \ mantissa 64 bit, x86 gcc/clang\r\nll binMul2(ll a, ll b, ll M) {\r\n    ll q\
    \ = (ll)((long double)a * b / M);\r\n    ll r = (ll)((unsigned ll)a * b - (unsigned\
    \ ll)q * M);\r\n    return r < 0 ? r + M : (r >= M ? r - M : r);\r\n}\r\n\r\n\
    ll binMul3(ll a, ll b, ll M) {\r\n    unsigned long long ua = a % M, um = M, res\
    \ = 0;\r\n    while (b) {\r\n        if (b & 1) { res += ua; if (res >= um) res\
    \ -= um; }\r\n        ua <<= 1; if (ua >= um) ua -= um;\r\n        b >>= 1;\r\n\
    \    }\r\n    return res;\r\n}\r\n\r\nll binPow(ll a, ll b, ll M) {\r\n    a %=\
    \ M;\r\n    ll res = 1 % M;\r\n    while (b) {\r\n        if (b & 1) res = (i128)res\
    \ * a % M;\r\n        a = (i128)a * a % M;\r\n        b /= 2;\r\n    }\r\n   \
    \ return res;\r\n}\n#line 5 \"NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp\"\
    \n\nvoid solve() {\n    int n, m; cin >> n >> m;\n    cout << binPow(n, m, MOD)\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#include \"../../template.h\"\n#include \"../Math/Binary_exponentiation.h\"\
    \n\nvoid solve() {\n    int n, m; cin >> n >> m;\n    cout << binPow(n, m, MOD)\
    \ << '\\n';\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/Binary_exponentiation.h
  isVerificationFile: true
  path: NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp
- /verify/NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp.html
title: NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp
---
