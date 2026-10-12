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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"String/Trie/Trie_array_ver.h\"\
    \n\n\nstruct Node {\n    int child[26], isEnd;\n\n    Node() {\n        memset(child,\
    \ 0, sizeof child);\n        isEnd = 0;\n    }\n};\n\nclass Trie {\npublic:\n\
    \    int n, curVertex;\n    vector<Node> tree;\n\n    Trie() {}\n    Trie(int\
    \ _n): n(_n+1), curVertex(0) {\n        tree.assign(n+1, Node());\n    }\n\n \
    \   void add(const string &s) {\n        int u = 0;\n        for (size_t i = 0;\
    \ i < s.size(); i++) {\n            int k = s[i] - 'a';\n            if (!tree[u].child[k])\
    \ {\n                tree[u].child[k] = ++curVertex;\n            }\n        \
    \    u = tree[u].child[k];\n        }\n        tree[u].isEnd++;\n    }\n\n   \
    \ bool search(const string &s) {\n        int u = 0;\n        for (size_t i =\
    \ 0; i < s.size(); i++) {\n            int k = s[i] - 'a';\n            if (!tree[u].child[k])\
    \ {\n                return 0;\n            }\n            u = tree[u].child[k];\n\
    \        }\n        return tree[u].isEnd;\n    }\n\n    void del(const string\
    \ &s) {\n        if (!search(s)) return;\n        int u = 0;\n        for (size_t\
    \ i = 0; i < s.size(); i++) {\n            int k = s[i] - 'a';\n            u\
    \ = tree[u].child[k];\n        }\n        tree[u].isEnd--;\n    }\n\n    // sort\
    \ string\n    void dfs(int pos, string &cur, vector<string> &res) {\n        for\
    \ (int i = 0; i < tree[pos].isEnd; i++) {\n            res.push_back(cur);\n \
    \       }\n        for (int i = 0; i < 26; i++) {\n            if (!tree[pos].child[i])\
    \ continue;\n            cur += char(i + 'a');\n            dfs(tree[pos].child[i],\
    \ cur, res);\n            cur.pop_back();\n        }\n    }\n\n    vector<string>\
    \ sort_string() {\n        vector<int> res;\n        string s = \"\";\n      \
    \  dfs(0, s, res);\n        return res;\n    }\n\n    string find_kth_string(int\
    \ k) {\n        \n    }\n};\n"
  code: "#include \"../../template.h\"\n\n\nstruct Node {\n    int child[26], isEnd;\n\
    \n    Node() {\n        memset(child, 0, sizeof child);\n        isEnd = 0;\n\
    \    }\n};\n\nclass Trie {\npublic:\n    int n, curVertex;\n    vector<Node> tree;\n\
    \n    Trie() {}\n    Trie(int _n): n(_n+1), curVertex(0) {\n        tree.assign(n+1,\
    \ Node());\n    }\n\n    void add(const string &s) {\n        int u = 0;\n   \
    \     for (size_t i = 0; i < s.size(); i++) {\n            int k = s[i] - 'a';\n\
    \            if (!tree[u].child[k]) {\n                tree[u].child[k] = ++curVertex;\n\
    \            }\n            u = tree[u].child[k];\n        }\n        tree[u].isEnd++;\n\
    \    }\n\n    bool search(const string &s) {\n        int u = 0;\n        for\
    \ (size_t i = 0; i < s.size(); i++) {\n            int k = s[i] - 'a';\n     \
    \       if (!tree[u].child[k]) {\n                return 0;\n            }\n \
    \           u = tree[u].child[k];\n        }\n        return tree[u].isEnd;\n\
    \    }\n\n    void del(const string &s) {\n        if (!search(s)) return;\n \
    \       int u = 0;\n        for (size_t i = 0; i < s.size(); i++) {\n        \
    \    int k = s[i] - 'a';\n            u = tree[u].child[k];\n        }\n     \
    \   tree[u].isEnd--;\n    }\n\n    // sort string\n    void dfs(int pos, string\
    \ &cur, vector<string> &res) {\n        for (int i = 0; i < tree[pos].isEnd; i++)\
    \ {\n            res.push_back(cur);\n        }\n        for (int i = 0; i < 26;\
    \ i++) {\n            if (!tree[pos].child[i]) continue;\n            cur += char(i\
    \ + 'a');\n            dfs(tree[pos].child[i], cur, res);\n            cur.pop_back();\n\
    \        }\n    }\n\n    vector<string> sort_string() {\n        vector<int> res;\n\
    \        string s = \"\";\n        dfs(0, s, res);\n        return res;\n    }\n\
    \n    string find_kth_string(int k) {\n        \n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: String/Trie/Trie_array_ver.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Trie/Trie_array_ver.h
layout: document
redirect_from:
- /library/String/Trie/Trie_array_ver.h
- /library/String/Trie/Trie_array_ver.h.html
title: String/Trie/Trie_array_ver.h
---
