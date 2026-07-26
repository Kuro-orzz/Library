---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Big_Integer/BigInt.h
    title: Big_Integer/BigInt.h
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
    PROBLEM: https://judge.yosupo.jp/problem/addition_of_big_integers
    links:
    - https://judge.yosupo.jp/problem/addition_of_big_integers
  bundledCode: "#line 1 \"Big_Integer/Yosupo/Addition_of_Big_Integers.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/addition_of_big_integers\"\n\
    \n#line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \n \r\n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\
    \n#define unique(x) x.erase(unique(all(x)), x.end())\r\n#define INF32 ((1ull<<31)-1)\r\
    \n#define INF64 ((1ull<<63)-1)\r\n#define inf (ll)1e18\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main(){\r\n   \
    \ ios_base::sync_with_stdio(false);cin.tie(NULL);\r\n    // cin.exceptions(cin.failbit);\r\
    \n    // int t; cin >> t;\r\n    // while(t--)\r\n        solve();\r\n    cerr\
    \ << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\r\
    \n    return 0;\r\n}\n#line 2 \"Big_Integer/BigInt.h\"\n\r\nclass BigInt {\r\n\
    public:\r\n    static const int BASE = 10;\r\n    vector<uint32_t> digit;\r\n\
    \    bool neg = false;\r\n\r\n    BigInt() {}\r\n\r\n    BigInt(int64_t val) {*this\
    \ = val;}\r\n\r\n    BigInt(const string &s) {*this = s;}\r\n\r\n    uint32_t\
    \ getDigit(const uint32_t i) const {return digit[i];}\r\n\r\n    uint32_t size()\
    \ const {return digit.size();}\r\n\r\n    bool isZero() const {return digit.empty();}\r\
    \n\r\n    int compare(const BigInt &b) const {\r\n        if (size() != b.size())\
    \ return size() > b.size() ? 1 : -1;\r\n        for (int i = (int)size()-1; i\
    \ >= 0; i--) {\r\n            if (digit[i] != b.getDigit(i))\r\n             \
    \   return digit[i] > b.getDigit(i) ? 1 : -1;\r\n        }\r\n        return 0;\r\
    \n    }\r\n\r\n    void trim() {\r\n        while (!digit.empty() && digit.back()\
    \ == 0)\r\n            digit.pop_back();\r\n        if (digit.empty()) neg = false;\r\
    \n    }\r\n\r\n    BigInt &operator=(int64_t val) {\r\n        digit.clear();\r\
    \n        if (val < 0) {\r\n            neg = true;\r\n            val = -val;\r\
    \n        } else neg = false;\r\n        while (val) {\r\n            digit.push_back(val\
    \ % BASE);\r\n            val /= BASE;\r\n        }\r\n        return *this;\r\
    \n    }\r\n\r\n    BigInt &operator=(const string &s) {\r\n        digit.clear();\r\
    \n        int32_t pos = 0;\r\n        if (s[0] == '-') {\r\n            neg =\
    \ true;\r\n            pos = 1;\r\n        } else neg = false;\r\n        for\
    \ (int i = (int)s.size()-1; i >= pos; i--) {\r\n            digit.push_back(s[i]-'0');\r\
    \n        }\r\n        trim();\r\n        return *this;\r\n    }\r\n\r\n    friend\
    \ ostream &operator<<(ostream &out, const BigInt &b) {\r\n        if (b.isZero())\
    \ return out << \"0\";\r\n        if (b.neg) out << \"-\";\r\n        for (int\
    \ i = (int)b.size()-1; i >= 0; i--)\r\n            out << b.getDigit(i);\r\n \
    \       return out;\r\n    }\r\n\r\n    BigInt operator+(const BigInt &b) const\
    \ {\r\n        BigInt res;\r\n        if (neg == b.neg) {\r\n            res.neg\
    \ = neg;\r\n            int carry = 0;\r\n            size_t len = max(size(),\
    \ b.size());\r\n            for (size_t i = 0; i < len; i++) {\r\n           \
    \     int sum = carry;\r\n                if (i < size()) sum += digit[i];\r\n\
    \                if (i < b.size()) sum += b.getDigit(i);\r\n                res.digit.push_back(sum\
    \ % BASE);\r\n                carry = sum / BASE;\r\n            }\r\n       \
    \     if (carry) res.digit.push_back(carry);\r\n            res.trim();\r\n  \
    \          return res;\r\n        } else {\r\n            return *this - (-b);\r\
    \n        }\r\n    }\r\n\r\n    BigInt operator-(const BigInt &b) const {\r\n\
    \        if (!neg && b.neg)\r\n            return *this + (-b);\r\n        if\
    \ (neg && !b.neg)\r\n            return -((-*this) + b);\r\n        if (compare(b)\
    \ == -1) \r\n            return -(b - *this);\r\n        BigInt res;\r\n     \
    \   res.neg = neg;\r\n        int borrow = 0;\r\n        for (size_t i = 0; i\
    \ < digit.size(); i++) {\r\n            int sub = digit[i]-borrow;\r\n       \
    \     if (i < b.size()) sub -= b.getDigit(i);\r\n            if (sub < 0) sub\
    \ += BASE, borrow = 1;\r\n            else borrow = 0;\r\n            res.digit.push_back(sub);\r\
    \n        }\r\n        res.trim();\r\n        return res;\r\n    }\r\n\r\n   \
    \ BigInt operator-() const {\r\n        BigInt res = *this;\r\n        if (!res.isZero())\r\
    \n            res.neg = !neg;\r\n        return res;\r\n    }\r\n\r\n    BigInt\
    \ mul(const BigInt &a, const BigInt &b) const {\r\n        BigInt x = a, y = b;\r\
    \n        x.trim(); y.trim();\r\n        BigInt res;\r\n        if (x.neg != y.neg)\r\
    \n            res.neg = true;\r\n        res.digit.resize(x.size()+y.size());\r\
    \n        for (size_t i = 0; i < x.size(); i++) {\r\n            int carry = 0;\r\
    \n            for (size_t j = 0; j < y.size(); j++) {\r\n                int64_t\
    \ cur = res.getDigit(i+j) + carry;\r\n                cur += x.digit[i] * y.getDigit(j);\r\
    \n                res.digit[i+j] = cur % BASE;\r\n                carry = cur\
    \ / BASE;\r\n            }\r\n            if (carry) res.digit[i+y.size()] +=\
    \ carry;\r\n        }\r\n        res.trim();\r\n        if (res.isZero()) res.neg\
    \ = false;\r\n        return res;\r\n    }\r\n\r\n    //---------------------karatsuba----------------------\r\
    \n    BigInt shifted(size_t k) const {\r\n        if (isZero()) return *this;\r\
    \n        BigInt r = *this;\r\n        r.digit.insert(r.digit.begin(), k, 0);\r\
    \n        return r;\r\n    }    \r\n\r\n    BigInt karatsuba(const BigInt &a,\
    \ const BigInt &b) const {\r\n        if (a.size() < 32 || b.size() < 32)\r\n\
    \            return mul(a, b);\r\n        size_t n = max(a.size(), b.size());\r\
    \n        uint32_t k = n / 2;\r\n\r\n        BigInt a_low, a_high;\r\n       \
    \ a_low.digit.assign(a.digit.begin(), a.digit.begin() + min(k, a.size()));\r\n\
    \        a_high.digit.assign(a.digit.begin() + min(k, a.size()), a.digit.end());\r\
    \n        a_low.neg = a_high.neg = false;\r\n        a_low.trim();\r\n       \
    \ a_high.trim();\r\n\r\n        BigInt b_low, b_high;\r\n        b_low.digit.assign(b.digit.begin(),\
    \ b.digit.begin() + min(k, b.size()));\r\n        b_high.digit.assign(b.digit.begin()\
    \ + min(k, b.size()), b.digit.end());\r\n        b_low.neg = b_high.neg = false;\r\
    \n        b_low.trim();\r\n        b_high.trim();\r\n\r\n        BigInt z0 = karatsuba(a_low,\
    \ b_low);\r\n        BigInt z2 = karatsuba(a_high, b_high);\r\n        BigInt\
    \ z1 = karatsuba(a_low + a_high, b_low + b_high) - z0 - z2;\r\n\r\n        BigInt\
    \ res = z2.shifted(2*k) + z1.shifted(k) + z0;\r\n        res.neg = (a.neg != b.neg);\r\
    \n        res.trim();\r\n        return res;\r\n    }\r\n\r\n    BigInt operator*(const\
    \ BigInt &b) const {\r\n        return karatsuba(*this, b);\r\n    }\r\n};\n#line\
    \ 5 \"Big_Integer/Yosupo/Addition_of_Big_Integers.test.cpp\"\n\nvoid solve(){\n\
    \    int t; cin >> t;\n    while (t--) {\n        string s1, s2; cin >> s1 >>\
    \ s2;\n        BigInt a(s1), b(s2);\n        cout << a + b << '\\n';\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/addition_of_big_integers\"\
    \n\n#include \"../../template.h\"\n#include \"../BigInt.h\"\n\nvoid solve(){\n\
    \    int t; cin >> t;\n    while (t--) {\n        string s1, s2; cin >> s1 >>\
    \ s2;\n        BigInt a(s1), b(s2);\n        cout << a + b << '\\n';\n    }\n}"
  dependsOn:
  - template.h
  - Big_Integer/BigInt.h
  isVerificationFile: true
  path: Big_Integer/Yosupo/Addition_of_Big_Integers.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 19:50:18+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Big_Integer/Yosupo/Addition_of_Big_Integers.test.cpp
layout: document
redirect_from:
- /verify/Big_Integer/Yosupo/Addition_of_Big_Integers.test.cpp
- /verify/Big_Integer/Yosupo/Addition_of_Big_Integers.test.cpp.html
title: Big_Integer/Yosupo/Addition_of_Big_Integers.test.cpp
---
