---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Sample/A_plus_B.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 4 \"Sample/A_plus_B.test.cpp\"\
    \n\nvoid solve(){\n    int a, b; cin >> a >> b;\n    cout << a + b;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../template.h\"\n\nvoid solve(){\n    int a, b; cin >> a >> b;\n    cout << a\
    \ + b;\n}"
  dependsOn:
  - template.h
  isVerificationFile: true
  path: Sample/A_plus_B.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Sample/A_plus_B.test.cpp
layout: document
redirect_from:
- /verify/Sample/A_plus_B.test.cpp
- /verify/Sample/A_plus_B.test.cpp.html
title: Sample/A_plus_B.test.cpp
---
