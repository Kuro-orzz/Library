---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"String/Trie/Trie.h\"\n\n\
    struct Node {\n    Node *child[26];\n    bool isEnd;\n\n    Node() {\n       \
    \ memset(child, 0, sizeof child);\n        isEnd = false;\n    }\n};\n\nclass\
    \ Trie {\npublic:\n    Node *r = new Node();\n\n    Trie() {}\n\n    void add(const\
    \ string &s) {\n        Node *u = r;\n        for (size_t i = 0; i < s.size();\
    \ i++) {\n            int k = s[i] - 'a';\n            if (!u->child[k]) {\n \
    \               u->child[k] = new Node();\n            }\n            u = u->child[k];\n\
    \        }\n        u->isEnd = true;\n    }\n\n    bool search(const string &s)\
    \ {\n        Node *u = r;\n        for (size_t i = 0; i < s.size(); i++) {\n \
    \           int k = s[i] - 'a';\n            if (!u->child[k]) {\n           \
    \     return false;\n            }\n            u = u->child[k];\n        }\n\
    \        return u->isEnd;\n    }\n};\n"
  code: "#include \"../../template.h\"\n\nstruct Node {\n    Node *child[26];\n  \
    \  bool isEnd;\n\n    Node() {\n        memset(child, 0, sizeof child);\n    \
    \    isEnd = false;\n    }\n};\n\nclass Trie {\npublic:\n    Node *r = new Node();\n\
    \n    Trie() {}\n\n    void add(const string &s) {\n        Node *u = r;\n   \
    \     for (size_t i = 0; i < s.size(); i++) {\n            int k = s[i] - 'a';\n\
    \            if (!u->child[k]) {\n                u->child[k] = new Node();\n\
    \            }\n            u = u->child[k];\n        }\n        u->isEnd = true;\n\
    \    }\n\n    bool search(const string &s) {\n        Node *u = r;\n        for\
    \ (size_t i = 0; i < s.size(); i++) {\n            int k = s[i] - 'a';\n     \
    \       if (!u->child[k]) {\n                return false;\n            }\n  \
    \          u = u->child[k];\n        }\n        return u->isEnd;\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: String/Trie/Trie.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Trie/Trie.h
layout: document
redirect_from:
- /library/String/Trie/Trie.h
- /library/String/Trie/Trie.h.html
title: String/Trie/Trie.h
---
