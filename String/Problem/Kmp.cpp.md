---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: String/Kmp.h
    title: String/Kmp.h
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
    - https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"String/Kmp.h\"\n\nvector<int>\
    \ lps(const string &s) {\n    int n = s.size();\n    vector<int> pi(n);\n    for\
    \ (int i = 1; i < n; i++) {\n        int j = pi[i-1];\n        while (j > 0 &&\
    \ s[i] != s[j]) {\n            j = pi[j - 1];\n        }\n        if (s[i] ==\
    \ s[j]) j++;\n        pi[i] = j;\n    }\n    return pi;\n}\n\nvector<int> __KMP(const\
    \ string &s, const string &t) {\n    int n = s.size(), m = t.size();\n    if (n\
    \ == 0) return {};\n    vector<int> pi = lps(s);\n    int j = 0;\n    vector<int>\
    \ ans(m);\n    for (int i = 0; i < m; i++) {\n        while (j > 0 && t[i] !=\
    \ s[j]) {\n            j = pi[j - 1];\n        }\n        if (t[i] == s[j]) j++;\n\
    \        ans[i] = j;\n        if (j == n) {\n            j = pi[j - 1];\n    \
    \    }\n    }\n    return ans;\n}\n#line 3 \"String/Problem/Kmp.cpp\"\n\n// AC:\
    \ https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/\n\
    \nclass Solution {\npublic:\n    int strStr(string haystack, string needle) {\n\
    \        int n = haystack.size(), m = needle.size();\n        vector<int> res\
    \ = __KMP(needle, haystack);\n        for (size_t i = 0; i < n; i++) {\n     \
    \       if (res[i] == m) return i - m + 1;\n        }\n        return -1;\n  \
    \  }\n};\n"
  code: "#include \"../../template.h\"\n#include \"../Kmp.h\"\n\n// AC: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/\n\
    \nclass Solution {\npublic:\n    int strStr(string haystack, string needle) {\n\
    \        int n = haystack.size(), m = needle.size();\n        vector<int> res\
    \ = __KMP(needle, haystack);\n        for (size_t i = 0; i < n; i++) {\n     \
    \       if (res[i] == m) return i - m + 1;\n        }\n        return -1;\n  \
    \  }\n};"
  dependsOn:
  - template.h
  - String/Kmp.h
  isVerificationFile: false
  path: String/Problem/Kmp.cpp
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Problem/Kmp.cpp
layout: document
redirect_from:
- /library/String/Problem/Kmp.cpp
- /library/String/Problem/Kmp.cpp.html
title: String/Problem/Kmp.cpp
---
