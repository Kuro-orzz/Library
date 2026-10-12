---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/SqrtDecomposition/Split_Rebuild/Simplified_version.h
    title: DataStructure/SqrtDecomposition/Split_Rebuild/Simplified_version.h
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
    - https://oj.vnoi.info/problem/sqrt_b
  bundledCode: "#line 1 \"DataStructure/Problem/Sqrt_split_rebuild2.cpp\"\n/*    AC:\
    \ https://oj.vnoi.info/problem/sqrt_b    */\n\n#line 2 \"template.h\"\n\r\n#include\
    \ <bits/stdc++.h>\r\nusing namespace std;\r\n \r\n#define ll long long\r\n#define\
    \ MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\n#define unique(x)\
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"DataStructure/SqrtDecomposition/Split_Rebuild/Simplified_version.h\"\
    \n\nstruct Block {\n    vector<int> v;\n    int sz = 0, assigned = -1;\n    bool\
    \ rev = false;\n    ll sum = 0;\n\n    Block() {}\n    \n    Block(int _sz, int\
    \ _assign, bool _rev = false) {\n        this->sz = _sz;\n        this->assigned\
    \ = _assign;\n        this->rev = _rev;\n    }\n\n    Block(vector<int> &a, int\
    \ _assign = -1, bool _rev = false) {\n        this->v = a;\n        this->sz =\
    \ a.size();\n        this->assigned = _assign;\n        this->rev = _rev;\n  \
    \      this->sum = accumulate(all(a), 0LL);\n    }\n\n    int size() { return\
    \ sz; }\n\n    ll getSum() { return assigned != -1 ? 1LL * assigned * sz : sum;\
    \ }\n\n    void perform_reverse() {\n        rev ^= true;\n        if (assigned\
    \ != -1) return;\n        reverse(all(v));\n    }\n\n    void truncate(int k)\
    \ {\n        sz = k;\n        if (rev) perform_reverse();\n        if (assigned\
    \ != -1) return;\n        v.resize(k);\n        if (assigned != -1) {\n      \
    \      sum = 1LL * assigned * sz;\n        } else {\n            sum = accumulate(all(v),\
    \ 0ll);\n        }\n    }\n};\n\nstruct Sqrt {\n    int n, cnt, block_sz = 450;\n\
    \    vector<Block> blocks;\n    vector<int> a, blockId;\n\n    Sqrt() {}\n   \
    \ Sqrt(int _n, vector<int> &a) {\n        this->n = _n;\n        this->a = a;\n\
    \        cnt = 0;\n        blocks.assign(4000, {});\n    }\n\n    void rebuild()\
    \ {\n        cnt = 0;\n        blockId.clear();\n        for (int i = 1; i <=\
    \ n; i += block_sz) {\n            int l = i, r = min(i + block_sz - 1, n);\n\
    \            vector<int> v(a.begin() + l, a.begin() + r + 1);\n            blocks[++cnt]\
    \ = Block(v);\n            blockId.push_back(cnt);\n        }\n    }\n\n    int\
    \ split(int i) {\n        if (i > n) return blockId.size();\n        int curPos\
    \ = 1;\n        for (auto it = blockId.begin(); it != blockId.end(); it++) {\n\
    \            int id = *it;\n            int curL = curPos, curR = curPos + blocks[id].size()\
    \ - 1;\n            if (curL <= i && i <= curR) {\n                if (i == curL)\
    \ return it-blockId.begin();\n                \n                if (blocks[id].rev)\
    \ {\n                    blocks[id].perform_reverse();\n                }\n  \
    \              int k = i - curL;\n                int newId = ++cnt;\n       \
    \         if (blocks[id].assigned != -1) {\n                    blocks[newId]\
    \ = Block(curR - curL + 1 - k, blocks[id].assigned);\n                } else {\n\
    \                    vector<int> tail = vector<int>(blocks[id].v.begin() + k,\
    \ blocks[id].v.end());\n                    blocks[newId] = Block(tail);\n   \
    \             }\n                blocks[id].truncate(k);\n                ++it;\n\
    \                it = blockId.insert(it, newId);\n                return it -\
    \ blockId.begin();\n            }\n            curPos = curR + 1;\n        }\n\
    \        return 0;\n    }\n\n    ll sum(int l, int r) {\n        l = split(l),\
    \ r = split(r + 1);\n        ll res = 0;\n        for (int i = l; i < r; i++)\n\
    \            res += blocks[ blockId[i] ].getSum();\n        return res;\n    }\n\
    \n    void Reverse(int l, int r) {\n        l = split(l), r = split(r + 1);\n\
    \        for (int i = l; i < r; i++)\n            blocks[blockId[i]].rev ^= 1;\n\
    \        reverse(blockId.begin() + l, blockId.begin() + r);\n    }\n\n    void\
    \ rebuild_if_need() {\n        a.resize(1);\n        for (auto it : blockId) {\n\
    \            if (blocks[it].rev) {\n                blocks[it].perform_reverse();\n\
    \            }\n            if (blocks[it].assigned == -1) {\n               \
    \ for (auto x : blocks[it].v)\n                    a.push_back(x);\n         \
    \   } else {\n                for (int i = 0; i < blocks[it].sz; i++)\n      \
    \              a.push_back(blocks[it].assigned);\n            }\n        }\n \
    \       n = a.size() - 1;\n        rebuild();\n    }\n};\n#line 5 \"DataStructure/Problem/Sqrt_split_rebuild2.cpp\"\
    \n\nvoid solve() {\n    int n, q; cin >> n >> q;\n    vector<int> a(n + 1);\n\
    \    for (int i = 1; i <= n; i++) {\n        cin >> a[i];\n    }\n    Sqrt sqrt(n,\
    \ a);\n    sqrt.rebuild();\n    while (q--) {\n        if (sqrt.blockId.size()\
    \ > 3000) sqrt.rebuild_if_need();\n        int type, l, r; cin >> type >> l >>\
    \ r;\n        if (type == 1) {\n            sqrt.Reverse(l, r);\n        } else\
    \ if (type == 2) {\n            cout << sqrt.sum(l, r) << '\\n';\n        }\n\
    \    }\n}\n"
  code: "/*    AC: https://oj.vnoi.info/problem/sqrt_b    */\n\n#include \"../../template.h\"\
    \n#include \"../SqrtDecomposition/Split_Rebuild/Simplified_version.h\"\n\nvoid\
    \ solve() {\n    int n, q; cin >> n >> q;\n    vector<int> a(n + 1);\n    for\
    \ (int i = 1; i <= n; i++) {\n        cin >> a[i];\n    }\n    Sqrt sqrt(n, a);\n\
    \    sqrt.rebuild();\n    while (q--) {\n        if (sqrt.blockId.size() > 3000)\
    \ sqrt.rebuild_if_need();\n        int type, l, r; cin >> type >> l >> r;\n  \
    \      if (type == 1) {\n            sqrt.Reverse(l, r);\n        } else if (type\
    \ == 2) {\n            cout << sqrt.sum(l, r) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.h
  - DataStructure/SqrtDecomposition/Split_Rebuild/Simplified_version.h
  isVerificationFile: false
  path: DataStructure/Problem/Sqrt_split_rebuild2.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Problem/Sqrt_split_rebuild2.cpp
layout: document
redirect_from:
- /library/DataStructure/Problem/Sqrt_split_rebuild2.cpp
- /library/DataStructure/Problem/Sqrt_split_rebuild2.cpp.html
title: DataStructure/Problem/Sqrt_split_rebuild2.cpp
---
