---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"DataStructure/Yosupo/Point_set_range_composite.brute_force.cpp\"\
    \n// #define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 4 \"DataStructure/Yosupo/Point_set_range_composite.brute_force.cpp\"\
    \n\nconst int mod = 998244353;\n\nvector<int> a, b;\n\nint calc(int l, int r,\
    \ int x) {\n    if (l == r) return (1ll * a[l] * x + b[l]) % mod;\n    return\
    \ (1ll * a[r] * calc(l, r-1, x) + b[r]) % mod;\n}\n\nvoid solve() {\n    int n,\
    \ q; cin >> n >> q;\n    a.resize(n);\n    b.resize(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        cin >> a[i] >> b[i];\n    }\n    while (q--) {\n      \
    \  int tv; cin >> tv;\n        if (tv == 0) {\n            int p, c, d; cin >>\
    \ p >> c >> d;\n            a[p] = c;\n            b[p] = d;\n        } else {\n\
    \            int l, r, x; cin >> l >> r >> x;\n            cout << calc(l, r-1,\
    \ x) << '\\n';\n        }\n    }\n}\n"
  code: "// #define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../../template.h\"\n\nconst int mod = 998244353;\n\nvector<int>\
    \ a, b;\n\nint calc(int l, int r, int x) {\n    if (l == r) return (1ll * a[l]\
    \ * x + b[l]) % mod;\n    return (1ll * a[r] * calc(l, r-1, x) + b[r]) % mod;\n\
    }\n\nvoid solve() {\n    int n, q; cin >> n >> q;\n    a.resize(n);\n    b.resize(n);\n\
    \    for (int i = 0; i < n; i++) {\n        cin >> a[i] >> b[i];\n    }\n    while\
    \ (q--) {\n        int tv; cin >> tv;\n        if (tv == 0) {\n            int\
    \ p, c, d; cin >> p >> c >> d;\n            a[p] = c;\n            b[p] = d;\n\
    \        } else {\n            int l, r, x; cin >> l >> r >> x;\n            cout\
    \ << calc(l, r-1, x) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/Yosupo/Point_set_range_composite.brute_force.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Yosupo/Point_set_range_composite.brute_force.cpp
layout: document
redirect_from:
- /library/DataStructure/Yosupo/Point_set_range_composite.brute_force.cpp
- /library/DataStructure/Yosupo/Point_set_range_composite.brute_force.cpp.html
title: DataStructure/Yosupo/Point_set_range_composite.brute_force.cpp
---
