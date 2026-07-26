---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DataStructure/SegTree/SegTreeBeats1.h
    title: DataStructure/SegTree/SegTreeBeats1.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/438/D
  bundledCode: "#line 1 \"DataStructure/Problem/SegTreeBeats1.cpp\"\n// https://codeforces.com/problemset/problem/438/D\n\
    \n#line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
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
    \n    return 0;\r\n}\n#line 2 \"DataStructure/SegTree/SegTreeBeats1.h\"\n\n\n\
    struct Node {\n    ll Max, sum;\n\n    Node() {}\n\n    Node(int val) {\n    \
    \    Max = val;\n        sum = val;\n    }\n\n    Node operator+(const Node &b)\
    \ {\n        Node res;\n        res.Max = max(Max, b.Max);\n        res.sum =\
    \ sum + b.sum;\n        return res;\n    }\n};\n\n// range mod, sum query\n//\
    \ point assign query\nclass SegTreeBeats {\npublic:\n    vector<Node> tree;\n\n\
    \    SegTreeBeats(int n): tree(4*n) {}\n\n    void build(int id, int l, int r,\
    \ int u, int v, int val) {\n        if (l > v || r < u) return;\n        if (u\
    \ <= l && r <= v) {\n            tree[id] = Node(val);\n            return;\n\
    \        }\n        int mid = (l + r) >> 1;\n        build(id*2, l, mid, u, v,\
    \ val);\n        build(id*2+1, mid+1, r, u, v, val);\n        tree[id] = tree[id*2]\
    \ + tree[id*2+1];\n    }   \n\n    void updateMod(int id, int l, int r, int u,\
    \ int v, int x) {\n        if (l > v || r < u) return;\n        if (tree[id].Max\
    \ < x) return;\n        if (l == r) {\n            tree[id].Max %= x;\n      \
    \      tree[id].sum = tree[id].Max;\n            return;\n        }\n        int\
    \ mid = (l + r) >> 1;\n        updateMod(id*2, l, mid, u, v, x);\n        updateMod(id*2+1,\
    \ mid+1, r, u, v, x);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    }\n\n\
    \    ll getSum(int id, int l, int r, int u, int v) {\n        if (l > v || r <\
    \ u) return 0;\n        if (u <= l && r <= v) return tree[id].sum;\n        int\
    \ mid = (l + r) >> 1;\n        ll t1 = getSum(id*2, l, mid, u, v);\n        ll\
    \ t2 = getSum(id*2+1, mid+1, r, u, v);\n        return t1 + t2;\n    }\n};\n#line\
    \ 5 \"DataStructure/Problem/SegTreeBeats1.cpp\"\n\nvoid solve() {\n    int n,\
    \ m; cin >> n >> m;\n    SegTreeBeats st(n);\n    for (int i = 1; i <= n; i++)\
    \ {\n        int x; cin >> x;\n        st.build(1, 1, n, i, i, x);\n    }\n  \
    \  while (m--) {\n        int type; cin >> type;\n        if (type == 1) {\n \
    \           int l, r; cin >> l >> r;\n            cout << st.getSum(1, 1, n, l,\
    \ r) << '\\n';\n        } else if (type == 2) {\n            int l, r, x; cin\
    \ >> l >> r >> x;\n            st.updateMod(1, 1, n, l, r, x);\n        } else\
    \ if (type == 3) {\n            int k, x; cin >> k >> x;\n            st.build(1,\
    \ 1, n, k, k, x);\n        }\n    }\n}\n"
  code: "// https://codeforces.com/problemset/problem/438/D\n\n#include \"../../template.h\"\
    \n#include \"../SegTree/SegTreeBeats1.h\"\n\nvoid solve() {\n    int n, m; cin\
    \ >> n >> m;\n    SegTreeBeats st(n);\n    for (int i = 1; i <= n; i++) {\n  \
    \      int x; cin >> x;\n        st.build(1, 1, n, i, i, x);\n    }\n    while\
    \ (m--) {\n        int type; cin >> type;\n        if (type == 1) {\n        \
    \    int l, r; cin >> l >> r;\n            cout << st.getSum(1, 1, n, l, r) <<\
    \ '\\n';\n        } else if (type == 2) {\n            int l, r, x; cin >> l >>\
    \ r >> x;\n            st.updateMod(1, 1, n, l, r, x);\n        } else if (type\
    \ == 3) {\n            int k, x; cin >> k >> x;\n            st.build(1, 1, n,\
    \ k, k, x);\n        }\n    }\n}"
  dependsOn:
  - template.h
  - DataStructure/SegTree/SegTreeBeats1.h
  isVerificationFile: false
  path: DataStructure/Problem/SegTreeBeats1.cpp
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Problem/SegTreeBeats1.cpp
layout: document
redirect_from:
- /library/DataStructure/Problem/SegTreeBeats1.cpp
- /library/DataStructure/Problem/SegTreeBeats1.cpp.html
title: DataStructure/Problem/SegTreeBeats1.cpp
---
