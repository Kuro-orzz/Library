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
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Misc.h\"\n\r\n\r\n// for both negative +\
    \ positive val\r\nll GCD(ll a, ll b) {\r\n    a = llabs(a), b = llabs(b);\r\n\
    \    return (!b ? a : GCD(b, a % b));\r\n}\r\n\r\n// Only positive\r\n// ll GCD(ll\
    \ a, ll b) { return (!b ? a : GCD(b, a % b)); }\r\nll LCM(ll a, ll b) { return\
    \ a / GCD(a, b) * b; }\r\n// logb(a)\r\ndouble log_base(ll a, ll b) { return log(a)\
    \ / log(b); }\r\n\r\n// use for 2 <= BASE <= 36\r\nstring decimal_to_base(ll n,\
    \ int BASE) {\r\n    if (!n) return \"0\";\r\n    bool neg = (n < 0 ? 1 : 0);\r\
    \n    n = llabs(n);\r\n    string num = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\"\
    ;\r\n    string res;\r\n    while(n) {\r\n        res.push_back(num[n % BASE]);\r\
    \n        n /= BASE;\r\n    }\r\n    if (neg) res += '-';\r\n    reverse(all(res));\r\
    \n    return res;\r\n}\r\n\r\n// any BASE to decimal\r\n// use ctype lib\r\nll\
    \ convert_decimal(string s, int BASE) {\r\n    auto val = [&](char c) { c = toupper(c);\
    \ return (isdigit(c) ? c-'0' : c-'A'+10); };\r\n    ll n = s.size(), p = 1, res\
    \ = 0;\r\n    for (int i = n-1; i >= 0; i--) {\r\n        res += val(s[i]) * p;\r\
    \n        p = p * BASE;\r\n    }\r\n    return res;\r\n}\n"
  code: "#include \"../../template.h\"\r\n\r\n\r\n// for both negative + positive\
    \ val\r\nll GCD(ll a, ll b) {\r\n    a = llabs(a), b = llabs(b);\r\n    return\
    \ (!b ? a : GCD(b, a % b));\r\n}\r\n\r\n// Only positive\r\n// ll GCD(ll a, ll\
    \ b) { return (!b ? a : GCD(b, a % b)); }\r\nll LCM(ll a, ll b) { return a / GCD(a,\
    \ b) * b; }\r\n// logb(a)\r\ndouble log_base(ll a, ll b) { return log(a) / log(b);\
    \ }\r\n\r\n// use for 2 <= BASE <= 36\r\nstring decimal_to_base(ll n, int BASE)\
    \ {\r\n    if (!n) return \"0\";\r\n    bool neg = (n < 0 ? 1 : 0);\r\n    n =\
    \ llabs(n);\r\n    string num = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\";\r\n\
    \    string res;\r\n    while(n) {\r\n        res.push_back(num[n % BASE]);\r\n\
    \        n /= BASE;\r\n    }\r\n    if (neg) res += '-';\r\n    reverse(all(res));\r\
    \n    return res;\r\n}\r\n\r\n// any BASE to decimal\r\n// use ctype lib\r\nll\
    \ convert_decimal(string s, int BASE) {\r\n    auto val = [&](char c) { c = toupper(c);\
    \ return (isdigit(c) ? c-'0' : c-'A'+10); };\r\n    ll n = s.size(), p = 1, res\
    \ = 0;\r\n    for (int i = n-1; i >= 0; i--) {\r\n        res += val(s[i]) * p;\r\
    \n        p = p * BASE;\r\n    }\r\n    return res;\r\n}"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: NumberTheory/Math/Misc.h
  requiredBy: []
  timestamp: '2026-07-26 02:09:30+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NumberTheory/Math/Misc.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Misc.h
- /library/NumberTheory/Math/Misc.h.html
title: NumberTheory/Math/Misc.h
---
