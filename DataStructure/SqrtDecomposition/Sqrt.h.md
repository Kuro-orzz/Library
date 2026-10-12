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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"DataStructure/SqrtDecomposition/Sqrt.h\"\
    \n\nclass SimpleSqrt {\npublic:\n    int n, block_sz;\n    vector<ll> a, block;\n\
    \n    SimpleSqrt() {}\n\n    SimpleSqrt(int _n): n(_n), a(_n, 0) {\n        block_sz\
    \ = sqrt(_n);\n        block.resize(n / block_sz + 1);\n    }\n\n    SimpleSqrt(int\
    \ _n, vector<ll> &arr): n(_n), a(arr) {\n        block_sz = sqrt(n);\n       \
    \ block.resize(n / block_sz + 1);\n        int cnt = -1;\n        for(int i =\
    \ 0; i < n; i++) {\n            if(i % block_sz == 0) cnt++;\n            block[cnt]\
    \ += arr[i];\n        }\n    }\n\n    ll query(int l, int r) {\n        ll sum\
    \ = 0;\n        for(int i = l; i <= r;) {\n            if(i % block_sz == 0 &&\
    \ i+block_sz-1 <= r) {\n                sum += block[i/block_sz];\n          \
    \      i += block_sz;\n            } else {\n                sum += a[i];\n  \
    \              i++;\n            }\n        }\n        return sum;\n    }\n\n\
    \    void add(int pos, int val) {\n        int idx = pos / block_sz;\n       \
    \ block[idx] += val;\n        a[pos] += val;\n    }\n};\n"
  code: "#include \"../../template.h\"\n\nclass SimpleSqrt {\npublic:\n    int n,\
    \ block_sz;\n    vector<ll> a, block;\n\n    SimpleSqrt() {}\n\n    SimpleSqrt(int\
    \ _n): n(_n), a(_n, 0) {\n        block_sz = sqrt(_n);\n        block.resize(n\
    \ / block_sz + 1);\n    }\n\n    SimpleSqrt(int _n, vector<ll> &arr): n(_n), a(arr)\
    \ {\n        block_sz = sqrt(n);\n        block.resize(n / block_sz + 1);\n  \
    \      int cnt = -1;\n        for(int i = 0; i < n; i++) {\n            if(i %\
    \ block_sz == 0) cnt++;\n            block[cnt] += arr[i];\n        }\n    }\n\
    \n    ll query(int l, int r) {\n        ll sum = 0;\n        for(int i = l; i\
    \ <= r;) {\n            if(i % block_sz == 0 && i+block_sz-1 <= r) {\n       \
    \         sum += block[i/block_sz];\n                i += block_sz;\n        \
    \    } else {\n                sum += a[i];\n                i++;\n          \
    \  }\n        }\n        return sum;\n    }\n\n    void add(int pos, int val)\
    \ {\n        int idx = pos / block_sz;\n        block[idx] += val;\n        a[pos]\
    \ += val;\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DataStructure/SqrtDecomposition/Sqrt.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SqrtDecomposition/Sqrt.h
layout: document
redirect_from:
- /library/DataStructure/SqrtDecomposition/Sqrt.h
- /library/DataStructure/SqrtDecomposition/Sqrt.h.html
title: DataStructure/SqrtDecomposition/Sqrt.h
---
