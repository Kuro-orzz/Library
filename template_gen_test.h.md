---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template_gen_test.h\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\n\r\n#define TASK \"test\"\r\n#define ll long long\r\n#define\
    \ MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define fi first\r\n#define se second\r\n\r\n\
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\nll\
    \ rnd(ll l, ll r) { return l + rng() % (r - l + 1); }\r\n\r\nvoid gen() {\r\n\
    \    ofstream f(TASK \".inp\");\r\n    // int n = rnd(1, 10);\r\n    // f << n\
    \ << \"\\n\";\r\n    // for (int i = 0; i < n; i++) f << rnd(1, 100) << \" \\\
    n\"[i == n - 1];\r\n}\r\n\r\nvector<ll> solve1(istream& cin) { vector<ll> ans;\
    \ return ans; } // optimize solution\r\nvector<ll> solve2(istream& cin) { vector<ll>\
    \ ans; return ans; } // bruteforce solution\r\n\r\nint main(){\r\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\r\
    \n    for (int t = 1; t <= 100; t++) {\r\n        gen();\r\n\r\n        ifstream\
    \ i1(TASK \".inp\"), i2(TASK \".inp\");\r\n        vector<ll> a = solve1(i1),\
    \ b = solve2(i2);\r\n        \r\n        if (a.empty() && b.empty()) {\r\n   \
    \         cout << \"Rong, kiem tra gen/solve\\n\";\r\n            return 0;\r\n\
    \        }\r\n        if (a != b) {\r\n            cout << \"WRONG at test \"\
    \ << t << \" (xem \" TASK \".inp)\\n\";\r\n            cout << \"sol  :\"; for\
    \ (ll x : a) cout << ' ' << x; cout << '\\n';\r\n            cout << \"brute:\"\
    ; for (ll x : b) cout << ' ' << x; cout << '\\n';\r\n            return 0;\r\n\
    \        }\r\n    }\r\n    cout << \"AC\\n\";\r\n    cerr << \"\\nTime run: \"\
    \ << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\r\n    return 0;\r\n\
    }\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define TASK \"test\"\
    \r\n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\
    \n\r\n#define vi vector<int>\r\n#define pii pair<int, int>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll rnd(ll l, ll r) { return l + rng() % (r - l + 1); }\r\n\r\nvoid gen() {\r\
    \n    ofstream f(TASK \".inp\");\r\n    // int n = rnd(1, 10);\r\n    // f <<\
    \ n << \"\\n\";\r\n    // for (int i = 0; i < n; i++) f << rnd(1, 100) << \" \\\
    n\"[i == n - 1];\r\n}\r\n\r\nvector<ll> solve1(istream& cin) { vector<ll> ans;\
    \ return ans; } // optimize solution\r\nvector<ll> solve2(istream& cin) { vector<ll>\
    \ ans; return ans; } // bruteforce solution\r\n\r\nint main(){\r\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\r\
    \n    for (int t = 1; t <= 100; t++) {\r\n        gen();\r\n\r\n        ifstream\
    \ i1(TASK \".inp\"), i2(TASK \".inp\");\r\n        vector<ll> a = solve1(i1),\
    \ b = solve2(i2);\r\n        \r\n        if (a.empty() && b.empty()) {\r\n   \
    \         cout << \"Rong, kiem tra gen/solve\\n\";\r\n            return 0;\r\n\
    \        }\r\n        if (a != b) {\r\n            cout << \"WRONG at test \"\
    \ << t << \" (xem \" TASK \".inp)\\n\";\r\n            cout << \"sol  :\"; for\
    \ (ll x : a) cout << ' ' << x; cout << '\\n';\r\n            cout << \"brute:\"\
    ; for (ll x : b) cout << ' ' << x; cout << '\\n';\r\n            return 0;\r\n\
    \        }\r\n    }\r\n    cout << \"AC\\n\";\r\n    cerr << \"\\nTime run: \"\
    \ << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: template_gen_test.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template_gen_test.h
layout: document
redirect_from:
- /library/template_gen_test.h
- /library/template_gen_test.h.html
title: template_gen_test.h
---
