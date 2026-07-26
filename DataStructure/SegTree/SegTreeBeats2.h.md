---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: DataStructure/Problem/SegTreeBeats2.cpp
    title: DataStructure/Problem/SegTreeBeats2.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n \r\n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x)\
    \ (x).begin(),(x).end()\r\n#define unique(x) x.erase(unique(all(x)), x.end())\r\
    \n#define INF32 ((1ull<<31)-1)\r\n#define INF64 ((1ull<<63)-1)\r\n#define inf\
    \ (ll)1e18\r\n\r\n#define vi vector<int>\r\n#define pii pair<int, int>\r\n#define\
    \ pll pair<ll, ll>\r\n#define fi first\r\n#define se second\r\n\r\nmt19937_64\
    \ rng(chrono::steady_clock::now().time_since_epoch().count());\r\nll get_rand(ll\
    \ r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\r\nconst int\
    \ mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main(){\r\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\r\
    \n    // cin.exceptions(cin.failbit);\r\n    // int t; cin >> t;\r\n    // while(t--)\r\
    \n        solve();\r\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"DataStructure/SegTree/SegTreeBeats2.h\"\
    \n\n\nstruct Node {\n    ll max1, max2, cntMax, sum, lazy;\n\n    Node() {}\n\n\
    \    Node(int val) {\n        max1 = val;\n        max2 = -1;\n        cntMax\
    \ = 1;\n        sum = val;\n        lazy = -1;\n    }\n\n    Node operator+(const\
    \ Node &b) {\n        Node res;\n        res.max1 = max(max1, b.max1);\n     \
    \   res.max2 = max(max2, b.max2);\n        if (res.max1 != max1) res.max2 = max(res.max2,\
    \ max1);\n        if (res.max1 != b.max1) res.max2 = max(res.max2, b.max1); \n\
    \        res.cntMax = 0;\n        if (res.max1 == max1) res.cntMax += cntMax;\n\
    \        if (res.max1 == b.max1) res.cntMax += b.cntMax;\n        res.sum = sum\
    \ + b.sum;\n        res.lazy = -1;\n        return res;\n    }\n\n    void setMin(int\
    \ val) {\n        if (val > max1) return;\n        sum -= (max1 - val) * cntMax;\n\
    \        max1 = val;\n        lazy = val;\n    }\n};\n\n// range chmin, sum\n\
    class SegTreeBeats {\npublic:\n    vector<Node> tree;\n\n    SegTreeBeats(int\
    \ n): tree(4*n) {}\n\n    void build(int id, int l, int r, int u, int v, int val)\
    \ {\n        if (l > v || r < u) return;\n        if (u <= l && r <= v) {\n  \
    \          tree[id] = Node(val);\n            return;\n        }\n        int\
    \ mid = (l + r) >> 1;\n        build(id*2, l, mid, u, v, val);\n        build(id*2+1,\
    \ mid+1, r, u, v, val);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    }\
    \   \n\n    void push(int id) {\n        if (tree[id].lazy < 0) return;\n    \
    \    tree[id*2].setMin(tree[id].lazy);\n        tree[id*2+1].setMin(tree[id].lazy);\n\
    \        tree[id].lazy = -1;\n    }\n\n    void updateChmin(int id, int l, int\
    \ r, int u, int v, int x) {\n        if (l > v || r < u) return;\n        if (tree[id].max1\
    \ <= x) return;\n        if (u <= l && r <= v && tree[id].max2 < x) {\n      \
    \      tree[id].setMin(x);\n            return;\n        }\n        push(id);\n\
    \        int mid = (l + r) >> 1;\n        updateChmin(id*2, l, mid, u, v, x);\n\
    \        updateChmin(id*2+1, mid+1, r, u, v, x);\n        tree[id] = tree[id*2]\
    \ + tree[id*2+1];\n    }\n\n    ll getSum(int id, int l, int r, int u, int v)\
    \ {\n        if (l > v || r < u) return 0;\n        if (u <= l && r <= v) return\
    \ tree[id].sum;\n        push(id);\n        int mid = (l + r) >> 1;\n        ll\
    \ t1 = getSum(id*2, l, mid, u, v);\n        ll t2 = getSum(id*2+1, mid+1, r, u,\
    \ v);\n        return t1 + t2;\n    }\n};\n"
  code: "#include \"../../template.h\"\n\n\nstruct Node {\n    ll max1, max2, cntMax,\
    \ sum, lazy;\n\n    Node() {}\n\n    Node(int val) {\n        max1 = val;\n  \
    \      max2 = -1;\n        cntMax = 1;\n        sum = val;\n        lazy = -1;\n\
    \    }\n\n    Node operator+(const Node &b) {\n        Node res;\n        res.max1\
    \ = max(max1, b.max1);\n        res.max2 = max(max2, b.max2);\n        if (res.max1\
    \ != max1) res.max2 = max(res.max2, max1);\n        if (res.max1 != b.max1) res.max2\
    \ = max(res.max2, b.max1); \n        res.cntMax = 0;\n        if (res.max1 ==\
    \ max1) res.cntMax += cntMax;\n        if (res.max1 == b.max1) res.cntMax += b.cntMax;\n\
    \        res.sum = sum + b.sum;\n        res.lazy = -1;\n        return res;\n\
    \    }\n\n    void setMin(int val) {\n        if (val > max1) return;\n      \
    \  sum -= (max1 - val) * cntMax;\n        max1 = val;\n        lazy = val;\n \
    \   }\n};\n\n// range chmin, sum\nclass SegTreeBeats {\npublic:\n    vector<Node>\
    \ tree;\n\n    SegTreeBeats(int n): tree(4*n) {}\n\n    void build(int id, int\
    \ l, int r, int u, int v, int val) {\n        if (l > v || r < u) return;\n  \
    \      if (u <= l && r <= v) {\n            tree[id] = Node(val);\n          \
    \  return;\n        }\n        int mid = (l + r) >> 1;\n        build(id*2, l,\
    \ mid, u, v, val);\n        build(id*2+1, mid+1, r, u, v, val);\n        tree[id]\
    \ = tree[id*2] + tree[id*2+1];\n    }   \n\n    void push(int id) {\n        if\
    \ (tree[id].lazy < 0) return;\n        tree[id*2].setMin(tree[id].lazy);\n   \
    \     tree[id*2+1].setMin(tree[id].lazy);\n        tree[id].lazy = -1;\n    }\n\
    \n    void updateChmin(int id, int l, int r, int u, int v, int x) {\n        if\
    \ (l > v || r < u) return;\n        if (tree[id].max1 <= x) return;\n        if\
    \ (u <= l && r <= v && tree[id].max2 < x) {\n            tree[id].setMin(x);\n\
    \            return;\n        }\n        push(id);\n        int mid = (l + r)\
    \ >> 1;\n        updateChmin(id*2, l, mid, u, v, x);\n        updateChmin(id*2+1,\
    \ mid+1, r, u, v, x);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    }\n\n\
    \    ll getSum(int id, int l, int r, int u, int v) {\n        if (l > v || r <\
    \ u) return 0;\n        if (u <= l && r <= v) return tree[id].sum;\n        push(id);\n\
    \        int mid = (l + r) >> 1;\n        ll t1 = getSum(id*2, l, mid, u, v);\n\
    \        ll t2 = getSum(id*2+1, mid+1, r, u, v);\n        return t1 + t2;\n  \
    \  }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SegTree/SegTreeBeats2.h
  requiredBy:
  - DataStructure/Problem/SegTreeBeats2.cpp
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegTree/SegTreeBeats2.h
layout: document
redirect_from:
- /library/DataStructure/SegTree/SegTreeBeats2.h
- /library/DataStructure/SegTree/SegTreeBeats2.h.html
title: DataStructure/SegTree/SegTreeBeats2.h
---
