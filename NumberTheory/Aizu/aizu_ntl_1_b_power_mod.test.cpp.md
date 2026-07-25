---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Binary_exponentiation.h
    title: NumberTheory/Math/Binary_exponentiation.h
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
  bundledCode: "#line 1 \"NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Binary_exponentiation.h\"\n\r\nusing u128\
    \ = __uint128_t;\r\nusing i128 = __int128;\r\n\r\nll binMul(ll a, ll b, ll M)\
    \ { return (i128)a * b % M; }\r\n\r\n// long double trick\r\n// require: mantissa\
    \ 64 bit, x86 gcc/clang\r\nll binMul2(ll a, ll b, ll M) {\r\n    ll q = (ll)((long\
    \ double)a * b / M);\r\n    ll r = (ll)((unsigned ll)a * b - (unsigned ll)q *\
    \ M);\r\n    return r < 0 ? r + M : (r >= M ? r - M : r);\r\n}\r\n\r\nll binMul3(ll\
    \ a, ll b, ll M) {\r\n    unsigned long long ua = a % M, um = M, res = 0;\r\n\
    \    while (b) {\r\n        if (b & 1) { res += ua; if (res >= um) res -= um;\
    \ }\r\n        ua <<= 1; if (ua >= um) ua -= um;\r\n        b >>= 1;\r\n    }\r\
    \n    return res;\r\n}\r\n\r\nll binPow(ll a, ll b, ll M) {\r\n    a %= M;\r\n\
    \    ll res = 1;\r\n    while (b) {\r\n        if (b & 1) res = (i128)res * a\
    \ % M;\r\n        a = (i128)a * a % M;\r\n        b /= 2;\r\n    }\r\n    return\
    \ res;\r\n}\n#line 5 \"NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp\"\n\n\
    void solve() {\n    int n, m; cin >> n >> m;\n    cout << binPow(n, m, MOD) <<\
    \ '\\n';\n}\n"
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
  timestamp: '2026-07-26 02:09:30+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp
- /verify/NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp.html
title: NumberTheory/Aizu/aizu_ntl_1_b_power_mod.test.cpp
---
