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
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"DataStructure/Yosupo/Associative_array.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n#line 2 \"\
    template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n \r\n#define\
    \ ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\
    \n#define unique(x) x.erase(unique(all(x)), x.end())\r\n#define INF32 ((1ull<<31)-1)\r\
    \n#define INF64 ((1ull<<63)-1)\r\n#define inf (ll)1e18\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main(){\r\n   \
    \ ios_base::sync_with_stdio(false);cin.tie(NULL);\r\n    // cin.exceptions(cin.failbit);\r\
    \n    // int t; cin >> t;\r\n    // while(t--)\r\n        solve();\r\n    cerr\
    \ << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\r\
    \n    return 0;\r\n}\n#line 4 \"DataStructure/Yosupo/Associative_array.test.cpp\"\
    \n\nvoid solve(){\n    unordered_map<ll, ll> mp;\n    int q; cin >> q;\n    while\
    \ (q--) {\n        int tv; cin >> tv;\n        if (tv == 0) {\n            ll\
    \ k, v; cin >> k >> v;\n            mp[k] = v;\n        }\n        else {\n  \
    \          ll k; cin >> k;\n            cout << mp[k] << '\\n';\n        }\n \
    \   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include \"../../template.h\"\n\nvoid solve(){\n    unordered_map<ll, ll> mp;\n\
    \    int q; cin >> q;\n    while (q--) {\n        int tv; cin >> tv;\n       \
    \ if (tv == 0) {\n            ll k, v; cin >> k >> v;\n            mp[k] = v;\n\
    \        }\n        else {\n            ll k; cin >> k;\n            cout << mp[k]\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.h
  isVerificationFile: true
  path: DataStructure/Yosupo/Associative_array.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Yosupo/Associative_array.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Yosupo/Associative_array.test.cpp
- /verify/DataStructure/Yosupo/Associative_array.test.cpp.html
title: DataStructure/Yosupo/Associative_array.test.cpp
---
