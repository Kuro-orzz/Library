---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DSU/Dsu.h
    title: DataStructure/DSU/Dsu.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"DataStructure/Yosupo/Union_find.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 2 \"template.h\"\n\r\n\
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"DataStructure/DSU/Dsu.h\"\
    \n\n/* Diff: different between a[u] and a[par[u]] */\n\nstruct Dsu {\n    vector<int>\
    \ par, sz;\n    vector<ll> diff;\n\n    Dsu() {}\n    Dsu(int n): par(n+1), sz(n+1,\
    \ 1), diff(n+1) {\n        iota(all(par), 0);\n    }\n\n    int find(int v) {\n\
    \        if (v == par[v]) return v;\n        return par[v] = find(par[v]);\n \
    \   }\n    \n    void merge(int a, int b) {\n        a = find(a);\n        b =\
    \ find(b);\n        if (a == b) return;\n        if (sz[a] < sz[b]) swap(a, b);\n\
    \        par[b] = a;\n        sz[a] += sz[b];\n    }\n\n    bool same_component(int\
    \ u, int v) {\n        return find(u) == find(v);\n    }\n\n    int component_size(int\
    \ u) {\n        u = find(u);\n        return sz[u];\n    }\n\n    /* https://judge.yosupo.jp/problem/unionfind_with_potential\
    \ */\n    int findPotential(int v, int mod) {\n        if (v == par[v]) return\
    \ v;\n        int p = par[v];\n        int root = findPotential(p, mod);\n   \
    \     diff[v] = (diff[v] + diff[p]) % mod;\n        return par[v] = root;\n  \
    \  }\n\n    bool mergePotential(int u, int v, int x, int mod) {\n        int pu\
    \ = findPotential(u, mod);\n        int pv = findPotential(v, mod);\n        if\
    \ (pu == pv) {\n            return (diff[u] - diff[v] + mod) % mod == x;\n   \
    \     }\n        if(sz[pu] < sz[pv]) {\n            swap(u, v);\n            swap(pu,\
    \ pv);\n            x = (mod - x) % mod;\n        }\n        par[pv] = pu;\n \
    \       sz[pu] += sz[pv];\n        diff[pv] = ((diff[u] - diff[v] - x) % mod +\
    \ mod) % mod;\n        return true;\n    }\n\n    int getDiff(int u, int v, int\
    \ mod) {\n        int pu = findPotential(u, mod);\n        int pv = findPotential(v,\
    \ mod);\n        if (pu != pv) return -1;\n        return (diff[u] - diff[v] +\
    \ mod) % mod;\n    }\n};\n#line 5 \"DataStructure/Yosupo/Union_find.test.cpp\"\
    \n\nvoid solve(){\n    int n, q; cin >> n >> q;\n    Dsu g(n);\n    while (q--)\
    \ {\n        int tv, u, v; cin >> tv >> u >> v;\n        if (tv == 0) g.merge(u,\
    \ v);\n        else if (g.find(u) == g.find(v))\n            cout << \"1\\n\"\
    ;\n        else cout << \"0\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../template.h\"\n#include \"../DSU/Dsu.h\"\n\nvoid solve(){\n    int n,\
    \ q; cin >> n >> q;\n    Dsu g(n);\n    while (q--) {\n        int tv, u, v; cin\
    \ >> tv >> u >> v;\n        if (tv == 0) g.merge(u, v);\n        else if (g.find(u)\
    \ == g.find(v))\n            cout << \"1\\n\";\n        else cout << \"0\\n\"\
    ;\n    }\n}"
  dependsOn:
  - template.h
  - DataStructure/DSU/Dsu.h
  isVerificationFile: true
  path: DataStructure/Yosupo/Union_find.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/Yosupo/Union_find.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/Yosupo/Union_find.test.cpp
- /verify/DataStructure/Yosupo/Union_find.test.cpp.html
title: DataStructure/Yosupo/Union_find.test.cpp
---
