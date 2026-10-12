---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"Dp/Knapsack.h\"\n\n// 1\
    \ <= N <= 100, 1 <= W <= 1e5\n// 1 <= wi <= W, 1 <= vi <= 1e9\nvoid knapsack01()\
    \ {\n    int n, W; cin >> n >> W;\n    vector<int> w(n+1), v(n+1);\n    for (int\
    \ i = 1; i <= n; i++) {\n        cin >> w[i] >> v[i];\n    }\n    vector<vector<ll>>\
    \ dp(n+1, vector<ll>(W+1));\n    for (int i = 1; i <= n; i++) {\n        for (int\
    \ j = 1; j <= W; j++) {\n            dp[i][j] = dp[i-1][j];\n            if (j-w[i]\
    \ < 0) continue;\n            dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);\n\
    \        }\n    }\n    cout << dp[n][W];\n}\n\n// 1 <= N <= 100, 1 <= W <= 1e9\n\
    // 1 <= wi <= W, 1 <= vi <= 1e3\nvoid knapsack02() {\n    int n, W; cin >> n >>\
    \ W;\n    vector<int> w(n+1), v(n+1);\n    for (int i = 1; i <= n; i++) {\n  \
    \      cin >> w[i] >> v[i];\n    }\n    vector<vector<ll>> dp(n+1, vector<ll>(1e5+1,\
    \ 1e18));\n    for (int i = 0; i <= n; i++) {\n        dp[i][0] = 0;\n    }\n\
    \    for (int i = 1; i <= n; i++) {\n        for (int j = 0; j <= 1e5; j++) {\n\
    \            dp[i][j] = dp[i-1][j];\n            if (j-v[i] < 0) continue;\n \
    \           if (dp[i-1][j-v[i]] + w[i] <= W) {\n                dp[i][j] = min(dp[i][j],\
    \ dp[i-1][j-v[i]] + w[i]);\n            }\n        }\n    }\n    for (int i =\
    \ 1e5; i >= 0; i--) {\n        if (dp[n][i] <= W) {\n            cout << i;\n\
    \            return;\n        }\n    }\n}\n"
  code: "#include \"../template.h\"\n\n// 1 <= N <= 100, 1 <= W <= 1e5\n// 1 <= wi\
    \ <= W, 1 <= vi <= 1e9\nvoid knapsack01() {\n    int n, W; cin >> n >> W;\n  \
    \  vector<int> w(n+1), v(n+1);\n    for (int i = 1; i <= n; i++) {\n        cin\
    \ >> w[i] >> v[i];\n    }\n    vector<vector<ll>> dp(n+1, vector<ll>(W+1));\n\
    \    for (int i = 1; i <= n; i++) {\n        for (int j = 1; j <= W; j++) {\n\
    \            dp[i][j] = dp[i-1][j];\n            if (j-w[i] < 0) continue;\n \
    \           dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);\n        }\n   \
    \ }\n    cout << dp[n][W];\n}\n\n// 1 <= N <= 100, 1 <= W <= 1e9\n// 1 <= wi <=\
    \ W, 1 <= vi <= 1e3\nvoid knapsack02() {\n    int n, W; cin >> n >> W;\n    vector<int>\
    \ w(n+1), v(n+1);\n    for (int i = 1; i <= n; i++) {\n        cin >> w[i] >>\
    \ v[i];\n    }\n    vector<vector<ll>> dp(n+1, vector<ll>(1e5+1, 1e18));\n   \
    \ for (int i = 0; i <= n; i++) {\n        dp[i][0] = 0;\n    }\n    for (int i\
    \ = 1; i <= n; i++) {\n        for (int j = 0; j <= 1e5; j++) {\n            dp[i][j]\
    \ = dp[i-1][j];\n            if (j-v[i] < 0) continue;\n            if (dp[i-1][j-v[i]]\
    \ + w[i] <= W) {\n                dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]] + w[i]);\n\
    \            }\n        }\n    }\n    for (int i = 1e5; i >= 0; i--) {\n     \
    \   if (dp[n][i] <= W) {\n            cout << i;\n            return;\n      \
    \  }\n    }\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Dp/Knapsack.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dp/Knapsack.h
layout: document
redirect_from:
- /library/Dp/Knapsack.h
- /library/Dp/Knapsack.h.html
title: Dp/Knapsack.h
---
