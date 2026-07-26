---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: DataStructure/Problem/SegTreeBeats3.cpp
    title: DataStructure/Problem/SegTreeBeats3.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Yosupo/Range_chmin_chmax_add_range_sum.test.cpp
    title: DataStructure/Yosupo/Range_chmin_chmax_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"DataStructure/SegTree/SegTreeBeats3.h\"\
    \n\n\nstruct Node {\n    ll max1, max2, cntMax, min1, min2, cntMin, sum, lazy,\
    \ sz;\n\n    Node() {\n        max1 = max2 = -inf;\n        min1 = min2 = inf;\n\
    \        cntMax = cntMin = 0;\n        sum = lazy = sz = 0;\n    }\n\n    Node(ll\
    \ val) {\n        max1 = min1 = val;\n        max2 = -inf;\n        min2 = inf;\n\
    \        cntMax = cntMin = 1;\n        sum = val;\n        lazy = 0;\n       \
    \ sz = 1;\n    }\n\n    Node operator+(const Node &b) {\n        Node res;\n\n\
    \        res.max1 = max(max1, b.max1);\n        res.max2 = max(max2, b.max2);\n\
    \        if (res.max1 != max1) res.max2 = max(res.max2, max1);\n        if (res.max1\
    \ != b.max1) res.max2 = max(res.max2, b.max1); \n        res.cntMax = 0;\n   \
    \     if (res.max1 == max1) res.cntMax += cntMax;\n        if (res.max1 == b.max1)\
    \ res.cntMax += b.cntMax;\n\n        res.min1 = min(min1, b.min1);\n        res.min2\
    \ = min(min2, b.min2);\n        if (res.min1 != min1) res.min2 = min(res.min2,\
    \ min1);\n        if (res.min1 != b.min1) res.min2 = min(res.min2, b.min1);\n\
    \        res.cntMin = 0;\n        if (res.min1 == min1) res.cntMin += cntMin;\n\
    \        if (res.min1 == b.min1) res.cntMin += b.cntMin;\n\n        res.sum =\
    \ sum + b.sum;\n        res.lazy = 0;\n        res.sz = sz + b.sz;\n\n       \
    \ return res;\n    }\n\n    void setMin(ll x) {\n        if (x >= max1) return;\n\
    \        sum -= (max1 - x) * cntMax;\n        max1 = x;\n        min1 = min(min1,\
    \ x);\n        if (min2 != inf) min2 = min(min2, x);\n    }\n\n    void setMax(ll\
    \ x) {\n        if (x <= min1) return;\n        sum += (x-min1) * cntMin;\n  \
    \      min1 = x;\n        max1 = max(max1, x);\n        if (max2 != -inf) max2\
    \ = max(max2, x);\n    }\n\n    void add(ll x) {\n        max1 += x;\n       \
    \ min1 += x;\n        if (max2 != -inf) max2 += x;\n        if (min2 != inf) min2\
    \ += x;\n        sum += x * sz;\n        lazy += x;\n    }\n};\n\n// range chmin,\
    \ chmax, update range, sum\nclass SegTreeBeats {\npublic:\n    vector<Node> tree;\n\
    \n    SegTreeBeats(int n): tree(4*n+6) {}\n\n    void build(int id, int l, int\
    \ r, int pos, ll val) {\n        if (pos < l || pos > r) return;\n        if (l\
    \ == r) {\n            tree[id] = Node(val);\n            return;\n        }\n\
    \        int mid = (l + r) >> 1;\n        build(id*2, l, mid, pos, val);\n   \
    \     build(id*2+1, mid+1, r, pos, val);\n        tree[id] = tree[id*2] + tree[id*2+1];\n\
    \    }   \n\n    void push(int id) {\n        tree[id*2].add(tree[id].lazy);\n\
    \        tree[id*2+1].add(tree[id].lazy);\n        tree[id].lazy = 0;\n\n    \
    \    tree[id*2].setMax(tree[id].min1);\n        tree[id*2+1].setMax(tree[id].min1);\n\
    \n        tree[id*2].setMin(tree[id].max1);\n        tree[id*2+1].setMin(tree[id].max1);\n\
    \    }\n\n    void updateChmax(int id, int l, int r, int u, int v, ll x) {\n \
    \       if (l > v || r < u) return;\n        if (tree[id].min1 >= x) return;\n\
    \        if (u <= l && r <= v && tree[id].min2 > x) {\n            tree[id].setMax(x);\n\
    \            return;\n        }\n        push(id);\n        int mid = (l + r)\
    \ >> 1;\n        updateChmax(id*2, l, mid, u, v, x);\n        updateChmax(id*2+1,\
    \ mid+1, r, u, v, x);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    }\n\n\
    \    void updateChmin(int id, int l, int r, int u, int v, ll x) {\n        if\
    \ (l > v || r < u) return;\n        if (tree[id].max1 <= x) return;\n        if\
    \ (u <= l && r <= v && tree[id].max2 < x) {\n            tree[id].setMin(x);\n\
    \            return;\n        }\n        push(id);\n        int mid = (l + r)\
    \ >> 1;\n        updateChmin(id*2, l, mid, u, v, x);\n        updateChmin(id*2+1,\
    \ mid+1, r, u, v, x);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    }\n\n\
    \    void updateRange(int id, int l, int r, int u, int v, ll x) {\n        if\
    \ (l > v || r < u) return;\n        if (u <= l && r <= v) {\n            tree[id].add(x);\n\
    \            return;\n        }\n        push(id);\n        int mid = (l + r)\
    \ >> 1;\n        updateRange(id*2, l, mid, u, v, x);\n        updateRange(id*2+1,\
    \ mid+1, r, u, v, x);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    }\n\n\
    \    ll getSum(int id, int l, int r, int u, int v) {\n        if (l > v || r <\
    \ u) return 0;\n        if (u <= l && r <= v) return tree[id].sum;\n        push(id);\n\
    \        int mid = (l + r) >> 1;\n        ll t1 = getSum(id*2, l, mid, u, v);\n\
    \        ll t2 = getSum(id*2+1, mid+1, r, u, v);\n        return t1 + t2;\n  \
    \  }\n};\n"
  code: "#include \"../../template.h\"\n\n\nstruct Node {\n    ll max1, max2, cntMax,\
    \ min1, min2, cntMin, sum, lazy, sz;\n\n    Node() {\n        max1 = max2 = -inf;\n\
    \        min1 = min2 = inf;\n        cntMax = cntMin = 0;\n        sum = lazy\
    \ = sz = 0;\n    }\n\n    Node(ll val) {\n        max1 = min1 = val;\n       \
    \ max2 = -inf;\n        min2 = inf;\n        cntMax = cntMin = 1;\n        sum\
    \ = val;\n        lazy = 0;\n        sz = 1;\n    }\n\n    Node operator+(const\
    \ Node &b) {\n        Node res;\n\n        res.max1 = max(max1, b.max1);\n   \
    \     res.max2 = max(max2, b.max2);\n        if (res.max1 != max1) res.max2 =\
    \ max(res.max2, max1);\n        if (res.max1 != b.max1) res.max2 = max(res.max2,\
    \ b.max1); \n        res.cntMax = 0;\n        if (res.max1 == max1) res.cntMax\
    \ += cntMax;\n        if (res.max1 == b.max1) res.cntMax += b.cntMax;\n\n    \
    \    res.min1 = min(min1, b.min1);\n        res.min2 = min(min2, b.min2);\n  \
    \      if (res.min1 != min1) res.min2 = min(res.min2, min1);\n        if (res.min1\
    \ != b.min1) res.min2 = min(res.min2, b.min1);\n        res.cntMin = 0;\n    \
    \    if (res.min1 == min1) res.cntMin += cntMin;\n        if (res.min1 == b.min1)\
    \ res.cntMin += b.cntMin;\n\n        res.sum = sum + b.sum;\n        res.lazy\
    \ = 0;\n        res.sz = sz + b.sz;\n\n        return res;\n    }\n\n    void\
    \ setMin(ll x) {\n        if (x >= max1) return;\n        sum -= (max1 - x) *\
    \ cntMax;\n        max1 = x;\n        min1 = min(min1, x);\n        if (min2 !=\
    \ inf) min2 = min(min2, x);\n    }\n\n    void setMax(ll x) {\n        if (x <=\
    \ min1) return;\n        sum += (x-min1) * cntMin;\n        min1 = x;\n      \
    \  max1 = max(max1, x);\n        if (max2 != -inf) max2 = max(max2, x);\n    }\n\
    \n    void add(ll x) {\n        max1 += x;\n        min1 += x;\n        if (max2\
    \ != -inf) max2 += x;\n        if (min2 != inf) min2 += x;\n        sum += x *\
    \ sz;\n        lazy += x;\n    }\n};\n\n// range chmin, chmax, update range, sum\n\
    class SegTreeBeats {\npublic:\n    vector<Node> tree;\n\n    SegTreeBeats(int\
    \ n): tree(4*n+6) {}\n\n    void build(int id, int l, int r, int pos, ll val)\
    \ {\n        if (pos < l || pos > r) return;\n        if (l == r) {\n        \
    \    tree[id] = Node(val);\n            return;\n        }\n        int mid =\
    \ (l + r) >> 1;\n        build(id*2, l, mid, pos, val);\n        build(id*2+1,\
    \ mid+1, r, pos, val);\n        tree[id] = tree[id*2] + tree[id*2+1];\n    } \
    \  \n\n    void push(int id) {\n        tree[id*2].add(tree[id].lazy);\n     \
    \   tree[id*2+1].add(tree[id].lazy);\n        tree[id].lazy = 0;\n\n        tree[id*2].setMax(tree[id].min1);\n\
    \        tree[id*2+1].setMax(tree[id].min1);\n\n        tree[id*2].setMin(tree[id].max1);\n\
    \        tree[id*2+1].setMin(tree[id].max1);\n    }\n\n    void updateChmax(int\
    \ id, int l, int r, int u, int v, ll x) {\n        if (l > v || r < u) return;\n\
    \        if (tree[id].min1 >= x) return;\n        if (u <= l && r <= v && tree[id].min2\
    \ > x) {\n            tree[id].setMax(x);\n            return;\n        }\n  \
    \      push(id);\n        int mid = (l + r) >> 1;\n        updateChmax(id*2, l,\
    \ mid, u, v, x);\n        updateChmax(id*2+1, mid+1, r, u, v, x);\n        tree[id]\
    \ = tree[id*2] + tree[id*2+1];\n    }\n\n    void updateChmin(int id, int l, int\
    \ r, int u, int v, ll x) {\n        if (l > v || r < u) return;\n        if (tree[id].max1\
    \ <= x) return;\n        if (u <= l && r <= v && tree[id].max2 < x) {\n      \
    \      tree[id].setMin(x);\n            return;\n        }\n        push(id);\n\
    \        int mid = (l + r) >> 1;\n        updateChmin(id*2, l, mid, u, v, x);\n\
    \        updateChmin(id*2+1, mid+1, r, u, v, x);\n        tree[id] = tree[id*2]\
    \ + tree[id*2+1];\n    }\n\n    void updateRange(int id, int l, int r, int u,\
    \ int v, ll x) {\n        if (l > v || r < u) return;\n        if (u <= l && r\
    \ <= v) {\n            tree[id].add(x);\n            return;\n        }\n    \
    \    push(id);\n        int mid = (l + r) >> 1;\n        updateRange(id*2, l,\
    \ mid, u, v, x);\n        updateRange(id*2+1, mid+1, r, u, v, x);\n        tree[id]\
    \ = tree[id*2] + tree[id*2+1];\n    }\n\n    ll getSum(int id, int l, int r, int\
    \ u, int v) {\n        if (l > v || r < u) return 0;\n        if (u <= l && r\
    \ <= v) return tree[id].sum;\n        push(id);\n        int mid = (l + r) >>\
    \ 1;\n        ll t1 = getSum(id*2, l, mid, u, v);\n        ll t2 = getSum(id*2+1,\
    \ mid+1, r, u, v);\n        return t1 + t2;\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SegTree/SegTreeBeats3.h
  requiredBy:
  - DataStructure/Problem/SegTreeBeats3.cpp
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/Yosupo/Range_chmin_chmax_add_range_sum.test.cpp
documentation_of: DataStructure/SegTree/SegTreeBeats3.h
layout: document
redirect_from:
- /library/DataStructure/SegTree/SegTreeBeats3.h
- /library/DataStructure/SegTree/SegTreeBeats3.h.html
title: DataStructure/SegTree/SegTreeBeats3.h
---
