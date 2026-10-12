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
    - https://codeforces.com/contest/221/problem/D
  bundledCode: "#line 1 \"DataStructure/Problem/Mo1.cpp\"\n// https://codeforces.com/contest/221/problem/D\n\
    \n#line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 4 \"DataStructure/Problem/Mo1.cpp\"\
    \n\nint block_sz;\nvector<int> a;\n \nstruct Query{\n    int l, r, idx;\n};\n\
    \ \nvector<Query> q;\n \nbool cmp(Query a, Query b){\n    if(a.l/block_sz != b.l/block_sz)\n\
    \        return a.l/block_sz < b.l/block_sz;\n    return a.r < b.r;\n}\n\nunordered_map<int,\
    \ int> fre;\nint cnt = 0;\n\nvoid insert(int i){\n    if(fre[a[i]] == a[i]) cnt--;\n\
    \    fre[a[i]]++;\n    if(fre[a[i]] == a[i]) cnt++;\n}\n \nvoid remove(int i){\n\
    \    if(fre[a[i]] == a[i]) cnt--;\n    fre[a[i]]--;\n    if(fre[a[i]] == a[i])\
    \ cnt++;\n}\n \nvector<int> query(){\n    sort(q.begin(), q.end(), cmp);\n   \
    \ int curL = 0, curR = 0;\n    vector<int> ans((int)q.size());\n    for(int i\
    \ = 0; i < (int)q.size(); i++){\n        auto [L, R, idx] = q[i];\n        while(curL\
    \ < L) remove(curL++);\n        while(curL > L) insert(--curL);\n        while(curR\
    \ <= R) insert(curR++);\n        while(curR > R+1) remove(--curR);\n        ans[idx]\
    \ = cnt;\n    }\n    return ans;\n}\n \nvoid solve(){\n    int n, t; cin >> n\
    \ >> t;\n    a.resize(n);\n    for(int i = 0; i < n; i++)\n        cin >> a[i];\n\
    \    for(int i = 0; i < t; i++){\n        int l, r; cin >> l >> r;\n        q.push_back({l-1,\
    \ r-1, i});\n    }\n    block_sz = sqrt(n);\n    vector<int> ans = query();\n\
    \    for(auto it : ans) cout << it << '\\n';\n}\n"
  code: "// https://codeforces.com/contest/221/problem/D\n\n#include \"../../template.h\"\
    \n\nint block_sz;\nvector<int> a;\n \nstruct Query{\n    int l, r, idx;\n};\n\
    \ \nvector<Query> q;\n \nbool cmp(Query a, Query b){\n    if(a.l/block_sz != b.l/block_sz)\n\
    \        return a.l/block_sz < b.l/block_sz;\n    return a.r < b.r;\n}\n\nunordered_map<int,\
    \ int> fre;\nint cnt = 0;\n\nvoid insert(int i){\n    if(fre[a[i]] == a[i]) cnt--;\n\
    \    fre[a[i]]++;\n    if(fre[a[i]] == a[i]) cnt++;\n}\n \nvoid remove(int i){\n\
    \    if(fre[a[i]] == a[i]) cnt--;\n    fre[a[i]]--;\n    if(fre[a[i]] == a[i])\
    \ cnt++;\n}\n \nvector<int> query(){\n    sort(q.begin(), q.end(), cmp);\n   \
    \ int curL = 0, curR = 0;\n    vector<int> ans((int)q.size());\n    for(int i\
    \ = 0; i < (int)q.size(); i++){\n        auto [L, R, idx] = q[i];\n        while(curL\
    \ < L) remove(curL++);\n        while(curL > L) insert(--curL);\n        while(curR\
    \ <= R) insert(curR++);\n        while(curR > R+1) remove(--curR);\n        ans[idx]\
    \ = cnt;\n    }\n    return ans;\n}\n \nvoid solve(){\n    int n, t; cin >> n\
    \ >> t;\n    a.resize(n);\n    for(int i = 0; i < n; i++)\n        cin >> a[i];\n\
    \    for(int i = 0; i < t; i++){\n        int l, r; cin >> l >> r;\n        q.push_back({l-1,\
    \ r-1, i});\n    }\n    block_sz = sqrt(n);\n    vector<int> ans = query();\n\
    \    for(auto it : ans) cout << it << '\\n';\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/Problem/Mo1.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Problem/Mo1.cpp
layout: document
redirect_from:
- /library/DataStructure/Problem/Mo1.cpp
- /library/DataStructure/Problem/Mo1.cpp.html
title: DataStructure/Problem/Mo1.cpp
---
