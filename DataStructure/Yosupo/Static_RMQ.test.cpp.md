---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/RMQ/RMQ.h
    title: DataStructure/RMQ/RMQ.h
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"DataStructure/Yosupo/Static_RMQ.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 2 \"template.h\"\n\r\n\
    #include <bits/stdc++.h>\r\nusing namespace std;\r\n \r\n#define ll long long\r\
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"DataStructure/RMQ/RMQ.h\"\
    \n\ntemplate <typename T>\nstruct RMQ {\n    int n;\n    vector<vector<T>> mn,\
    \ mx, sum;\n\n    RMQ() {}\n    RMQ(int _n): n(_n) {\n        mn = mx = sum =\
    \ vector<vector<T>>(20, vector<T>(_n+1));\n    }\n\n    void preprocess(vector<T>\
    \ &a) {\n        for (int i = 1; i <= n; i++) {\n            mn[0][i] = mx[0][i]\
    \ = sum[0][i] = a[i];\n        }\n        for (int i = 1; i < 20; i++) {\n   \
    \         for (int j = 1; j + (1 << i) - 1 <= n; j++) {\n                mn[i][j]\
    \ = min(mn[i-1][j], mn[i - 1][j + (1 << (i-1))]);\n                mx[i][j] =\
    \ max(mx[i-1][j], mx[i - 1][j + (1 << (i-1))]);\n                sum[i][j] = sum[i-1][j]\
    \ + sum[i - 1][j + (1 << (i-1))];\n            }\n        }\n    }\n\n    T queryMin(int\
    \ l, int r) {\n        int k = __lg(r-l+1);\n        return min(mn[k][l], mn[k][r\
    \ - (1 << k) + 1]);\n    }\n\n    T queryMax(int l, int r) {\n        int k =\
    \ __lg(r-l+1);\n        return max(mx[k][l], mx[k][r - (1 << k) + 1]);\n    }\n\
    \n    T querySum(int l, int r) {\n        int len = r-l+1;\n        T ans = 0;\n\
    \        for (int i = 0; (1 << i) <= len; i++) {\n            if (len >> i & 1)\
    \ {\n                ans += sum[i][l];\n                l += (1 << i);\n     \
    \       }\n        }\n        return ans;\n    }\n};\n#line 5 \"DataStructure/Yosupo/Static_RMQ.test.cpp\"\
    \n\nvoid solve() {\n    int n, q; cin >> n >> q;\n    vector<int> a(n+1);\n  \
    \  for (int i = 1; i <= n; i++) {\n        cin >> a[i];\n    }\n    RMQ<int> rmq(n);\n\
    \    rmq.preprocess(a);\n    while (q--) {\n        int l, r; cin >> l >> r;\n\
    \        cout << rmq.queryMin(l+1, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../template.h\"\n#include \"../RMQ/RMQ.h\"\n\nvoid solve() {\n    int n,\
    \ q; cin >> n >> q;\n    vector<int> a(n+1);\n    for (int i = 1; i <= n; i++)\
    \ {\n        cin >> a[i];\n    }\n    RMQ<int> rmq(n);\n    rmq.preprocess(a);\n\
    \    while (q--) {\n        int l, r; cin >> l >> r;\n        cout << rmq.queryMin(l+1,\
    \ r) << '\\n';\n    }\n}"
  dependsOn:
  - template.h
  - DataStructure/RMQ/RMQ.h
  isVerificationFile: true
  path: DataStructure/Yosupo/Static_RMQ.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: DataStructure/Yosupo/Static_RMQ.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Yosupo/Static_RMQ.test.cpp
- /verify/DataStructure/Yosupo/Static_RMQ.test.cpp.html
title: DataStructure/Yosupo/Static_RMQ.test.cpp
---
