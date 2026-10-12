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
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/ordered_set
    links:
    - https://judge.yosupo.jp/problem/ordered_set
  bundledCode: "#line 1 \"DataStructure/Yosupo/Ordered_set.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/ordered_set\"\n\n#line 2 \"template.h\"\n\r\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n \r\n#define ll long long\r\
    \n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\n#define unique(x)\
    \ x.erase(unique(all(x)), x.end())\r\n\r\n#define vi vector<int>\r\n#define pii\
    \ pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\n#define se\
    \ second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main() {\r\n  \
    \  // if (FILE* f = fopen(TASK \".inp\", \"r\")) {\r\n    //     fclose(f);\r\n\
    \    //     freopen(TASK \".inp\", \"r\", stdin);\r\n    //     freopen(TASK \"\
    .out\", \"w\", stdout);\r\n    // }\r\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\r\
    \n    // cin.exceptions(cin.failbit);\r\n    // int t; cin >> t;\r\n    // while(t--)\r\
    \n        solve();\r\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 4 \"DataStructure/Yosupo/Ordered_set.test.cpp\"\
    \n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    using namespace __gnu_pbds;\nusing ordered_set = tree<int, null_type, less<int>,\
    \ rb_tree_tag, tree_order_statistics_node_update>;\n\nvoid solve() {\n    int\
    \ n, q; cin >> n >> q;\n    ordered_set s;\n    for (int i = 0; i < n; i++) {\n\
    \        int x; cin >> x;\n        s.insert(x);\n    }\n    while (q--) {\n  \
    \      int tv, x; cin >> tv >> x;\n        if (tv == 0) {\n            s.insert(x);\n\
    \        } else if (tv == 1) {\n            s.erase(x);\n        } else if (tv\
    \ == 2) {\n            if (x > (int)s.size()) cout << \"-1\\n\";\n           \
    \ else cout << *s.find_by_order(x-1) << '\\n';\n        } else if (tv == 3) {\n\
    \            cout << s.order_of_key(x+1) << '\\n';\n        } else if (tv == 4)\
    \ {\n            int idx = s.order_of_key(x+1);\n            if (idx == 0) cout\
    \ << \"-1\\n\";\n            else cout << *s.find_by_order(idx-1) << '\\n';\n\
    \        } else if (tv == 5) {\n            int idx = s.order_of_key(x);\n   \
    \         if (idx == (int)s.size()) cout << \"-1\\n\";\n            else cout\
    \ << *s.find_by_order(idx) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/ordered_set\"\n\n#include\
    \ \"../../template.h\"\n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    using namespace __gnu_pbds;\nusing ordered_set = tree<int, null_type, less<int>,\
    \ rb_tree_tag, tree_order_statistics_node_update>;\n\nvoid solve() {\n    int\
    \ n, q; cin >> n >> q;\n    ordered_set s;\n    for (int i = 0; i < n; i++) {\n\
    \        int x; cin >> x;\n        s.insert(x);\n    }\n    while (q--) {\n  \
    \      int tv, x; cin >> tv >> x;\n        if (tv == 0) {\n            s.insert(x);\n\
    \        } else if (tv == 1) {\n            s.erase(x);\n        } else if (tv\
    \ == 2) {\n            if (x > (int)s.size()) cout << \"-1\\n\";\n           \
    \ else cout << *s.find_by_order(x-1) << '\\n';\n        } else if (tv == 3) {\n\
    \            cout << s.order_of_key(x+1) << '\\n';\n        } else if (tv == 4)\
    \ {\n            int idx = s.order_of_key(x+1);\n            if (idx == 0) cout\
    \ << \"-1\\n\";\n            else cout << *s.find_by_order(idx-1) << '\\n';\n\
    \        } else if (tv == 5) {\n            int idx = s.order_of_key(x);\n   \
    \         if (idx == (int)s.size()) cout << \"-1\\n\";\n            else cout\
    \ << *s.find_by_order(idx) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.h
  isVerificationFile: true
  path: DataStructure/Yosupo/Ordered_set.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Yosupo/Ordered_set.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Yosupo/Ordered_set.test.cpp
- /verify/DataStructure/Yosupo/Ordered_set.test.cpp.html
title: DataStructure/Yosupo/Ordered_set.test.cpp
---
