---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: DataStructure/Problem/PersistentSegTree1.cpp
    title: DataStructure/Problem/PersistentSegTree1.cpp
  - icon: ':warning:'
    path: DataStructure/Problem/PersistentSegTree2.cpp
    title: DataStructure/Problem/PersistentSegTree2.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1737/
    - https://www.spoj.com/problems/PSEGTREE/
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"DataStructure/SegTree/PersistentSegTree.h\"\n\n// Tested:\n\
    // - AC: https://cses.fi/problemset/task/1737/\n// - AC: https://www.spoj.com/problems/PSEGTREE/\n\
    \nstruct Node {\n    Node *left, *right;\n    ll sum;\n    Node() {}\n    Node(ll\
    \ _sum): left(NULL), right(NULL), sum(_sum) {}\n    Node(Node *l, Node *r, ll\
    \ _sum): left(l), right(r), sum(_sum) {}\n    ~Node() {\n        delete left;\n\
    \        delete right;\n    }\n};\n\nclass PersistentSegTree {\npublic:\n    vector<Node*>\
    \ ver;\n\n    PersistentSegTree() {}\n    PersistentSegTree(int n): ver(n+1) {}\n\
    \n    void build(Node *cur, int l, int r, const vector<int> &a) {\n        if\
    \ (l == r) {\n            cur->sum = a[l];\n            return;\n        }\n \
    \       int mid = (l + r) >> 1;\n        cur->left = new Node(NULL, NULL, 0);\n\
    \        cur->right = new Node(NULL, NULL, 0);\n        build(cur->left, l, mid,\
    \ a);\n        build(cur->right, mid+1, r, a);\n        cur->sum = cur->left->sum\
    \ + cur->right->sum;\n    }\n\n    void update(Node *prev, Node *cur, int l, int\
    \ r, int pos, ll x) {\n        if (l == r) {\n            cur->sum = x;\n    \
    \        return;\n        }\n        int mid = (l + r) >> 1;\n        if (pos\
    \ <= mid) {\n            cur->right = prev->right;\n            cur->left = new\
    \ Node(NULL, NULL, 0);\n            update(prev->left, cur->left, l, mid, pos,\
    \ x);\n        } else {\n            cur->left = prev->left;\n            cur->right\
    \ = new Node(NULL, NULL, 0);\n            update(prev->right, cur->right, mid+1,\
    \ r, pos, x);\n        }\n        cur->sum = cur->left->sum + cur->right->sum;\n\
    \    }\n\n    ll getSum(Node *cur, int l, int r, int u, int v) {\n        if (l\
    \ > v || r < u) return 0;\n        if (u <= l && r <= v) return cur->sum;\n  \
    \      int mid = (l + r) >> 1;\n        return getSum(cur->left, l, mid, u, v)\
    \ + getSum(cur->right, mid+1, r, u, v);\n    }\n};\n"
  code: "#include \"../../template.h\"\n\n// Tested:\n// - AC: https://cses.fi/problemset/task/1737/\n\
    // - AC: https://www.spoj.com/problems/PSEGTREE/\n\nstruct Node {\n    Node *left,\
    \ *right;\n    ll sum;\n    Node() {}\n    Node(ll _sum): left(NULL), right(NULL),\
    \ sum(_sum) {}\n    Node(Node *l, Node *r, ll _sum): left(l), right(r), sum(_sum)\
    \ {}\n    ~Node() {\n        delete left;\n        delete right;\n    }\n};\n\n\
    class PersistentSegTree {\npublic:\n    vector<Node*> ver;\n\n    PersistentSegTree()\
    \ {}\n    PersistentSegTree(int n): ver(n+1) {}\n\n    void build(Node *cur, int\
    \ l, int r, const vector<int> &a) {\n        if (l == r) {\n            cur->sum\
    \ = a[l];\n            return;\n        }\n        int mid = (l + r) >> 1;\n \
    \       cur->left = new Node(NULL, NULL, 0);\n        cur->right = new Node(NULL,\
    \ NULL, 0);\n        build(cur->left, l, mid, a);\n        build(cur->right, mid+1,\
    \ r, a);\n        cur->sum = cur->left->sum + cur->right->sum;\n    }\n\n    void\
    \ update(Node *prev, Node *cur, int l, int r, int pos, ll x) {\n        if (l\
    \ == r) {\n            cur->sum = x;\n            return;\n        }\n       \
    \ int mid = (l + r) >> 1;\n        if (pos <= mid) {\n            cur->right =\
    \ prev->right;\n            cur->left = new Node(NULL, NULL, 0);\n           \
    \ update(prev->left, cur->left, l, mid, pos, x);\n        } else {\n         \
    \   cur->left = prev->left;\n            cur->right = new Node(NULL, NULL, 0);\n\
    \            update(prev->right, cur->right, mid+1, r, pos, x);\n        }\n \
    \       cur->sum = cur->left->sum + cur->right->sum;\n    }\n\n    ll getSum(Node\
    \ *cur, int l, int r, int u, int v) {\n        if (l > v || r < u) return 0;\n\
    \        if (u <= l && r <= v) return cur->sum;\n        int mid = (l + r) >>\
    \ 1;\n        return getSum(cur->left, l, mid, u, v) + getSum(cur->right, mid+1,\
    \ r, u, v);\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SegTree/PersistentSegTree.h
  requiredBy:
  - DataStructure/Problem/PersistentSegTree2.cpp
  - DataStructure/Problem/PersistentSegTree1.cpp
  timestamp: '2025-10-07 00:37:04+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegTree/PersistentSegTree.h
layout: document
redirect_from:
- /library/DataStructure/SegTree/PersistentSegTree.h
- /library/DataStructure/SegTree/PersistentSegTree.h.html
title: DataStructure/SegTree/PersistentSegTree.h
---
