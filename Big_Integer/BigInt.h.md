---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Big_Integer/Yosupo/Addition_of_Big_Integers.test.cpp
    title: Big_Integer/Yosupo/Addition_of_Big_Integers.test.cpp
  - icon: ':heavy_check_mark:'
    path: Sample/Many_A_plus_B_128bit.test.cpp
    title: Sample/Many_A_plus_B_128bit.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ 0;\n}\n#line 2 \"Big_Integer/BigInt.h\"\n\nclass BigInt {\npublic:\n    static\
    \ const int BASE = 10;\n    vector<uint32_t> digit;\n    bool neg = false;\n\n\
    \    BigInt() {}\n\n    BigInt(int64_t val) {*this = val;}\n\n    BigInt(const\
    \ string &s) {*this = s;}\n\n    uint32_t getDigit(const uint32_t i) const {return\
    \ digit[i];}\n\n    uint32_t size() const {return digit.size();}\n\n    bool isZero()\
    \ const {return digit.empty();}\n\n    int compare(const BigInt &b) const {\n\
    \        if (size() != b.size())\n            return size() > b.size() ? 1 : -1;\n\
    \        else if (size() < b.size())\n            return -1;\n        for (int\
    \ i = (int)size()-1; i >= 0; i--) {\n            if (digit[i] != b.getDigit(i))\n\
    \                return digit[i] > b.getDigit(i) ? 1 : -1;\n        }\n      \
    \  return 0;\n    }\n\n    void trim() {\n        while (!digit.empty() && digit.back()\
    \ == 0)\n            digit.pop_back();\n        if (digit.empty()) neg = false;\n\
    \    }\n\n    BigInt &operator=(int64_t val) {\n        digit.clear();\n     \
    \   if (val < 0) {\n            neg = true;\n            val = -val;\n       \
    \ }\n        while (val) {\n            digit.push_back(val % BASE);\n       \
    \     val /= BASE;\n        }\n        return *this;\n    }\n\n    BigInt &operator=(const\
    \ string &s) {\n        digit.clear();\n        int32_t pos = 0;\n        if (s[0]\
    \ == '-') {\n            neg = true;\n            pos = 1;\n        }\n      \
    \  for (int i = (int)s.size()-1; i >= pos; i--) {\n            digit.push_back(s[i]-'0');\n\
    \        }\n        trim();\n        return *this;\n    }\n\n    friend ostream\
    \ &operator<<(ostream &out, const BigInt &b) {\n        if (b.isZero()) return\
    \ out << \"0\";\n        if (b.neg) out << \"-\";\n        for (int i = (int)b.size()-1;\
    \ i >= 0; i--)\n            out << b.getDigit(i);\n        return out;\n    }\n\
    \n    BigInt operator+(const BigInt &b) const {\n        BigInt res;\n       \
    \ if (neg == b.neg) {\n            res.neg = neg;\n            int carry = 0;\n\
    \            size_t len = max(size(), b.size());\n            for (size_t i =\
    \ 0; i < len; i++) {\n                int sum = carry;\n                if (i\
    \ < size()) sum += digit[i];\n                if (i < b.size()) sum += b.getDigit(i);\n\
    \                res.digit.push_back(sum % BASE);\n                carry = sum\
    \ / BASE;\n            }\n            if (carry) res.digit.push_back(carry);\n\
    \            res.trim();\n            return res;\n        } else {\n        \
    \    return *this - (-b);\n        }\n    }\n\n    BigInt operator-(const BigInt\
    \ &b) const {\n        if (!neg && b.neg)\n            return *this + (-b);\n\
    \        if (neg && !b.neg)\n            return -((-*this) + b);\n        if (compare(b)\
    \ == -1) \n            return -(b - *this);\n        BigInt res;\n        res.neg\
    \ = neg;\n        int borrow = 0;\n        for (size_t i = 0; i < digit.size();\
    \ i++) {\n            int sub = digit[i]-borrow;\n            if (i < b.size())\
    \ sub -= b.getDigit(i);\n            if (sub < 0) sub += BASE, borrow = 1;\n \
    \           else borrow = 0;\n            res.digit.push_back(sub);\n        }\n\
    \        res.trim();\n        return res;\n    }\n\n    BigInt operator-() const\
    \ {\n        BigInt res = *this;\n        if (!res.isZero())\n            res.neg\
    \ = !neg;\n        return res;\n    }\n\n    BigInt mul(const BigInt &a, const\
    \ BigInt &b) const {\n        BigInt x = a, y = b;\n        x.trim(); y.trim();\n\
    \        BigInt res;\n        if (x.neg != y.neg)\n            res.neg = true;\n\
    \        res.digit.resize(x.size()+y.size());\n        for (size_t i = 0; i <\
    \ x.size(); i++) {\n            int carry = 0;\n            for (size_t j = 0;\
    \ j < y.size(); j++) {\n                int64_t cur = res.getDigit(i+j) + carry;\n\
    \                cur += x.digit[i] * y.getDigit(j);\n                res.digit[i+j]\
    \ = cur % BASE;\n                carry = cur / BASE;\n            }\n        \
    \    if (carry) res.digit[i+y.size()] += carry;\n        }\n        res.trim();\n\
    \        if (res.isZero()) res.neg = false;\n        return res;\n    }\n\n  \
    \  //---------------------karatsuba----------------------\n    BigInt shifted(size_t\
    \ k) const {\n        if (isZero()) return *this;\n        BigInt r = *this;\n\
    \        r.digit.insert(r.digit.begin(), k, 0);\n        return r;\n    }    \n\
    \n    BigInt karatsuba(const BigInt &a, const BigInt &b) const {\n        if (a.size()\
    \ < 32 || b.size() < 32)\n            return mul(a, b);\n        size_t n = max(a.size(),\
    \ b.size());\n        uint32_t k = n / 2;\n\n        BigInt a_low, a_high;\n \
    \       a_low.digit.assign(a.digit.begin(), a.digit.begin() + min(k, a.size()));\n\
    \        a_high.digit.assign(a.digit.begin() + min(k, a.size()), a.digit.end());\n\
    \        a_low.neg = a_high.neg = false;\n        a_low.trim();\n        a_high.trim();\n\
    \n        BigInt b_low, b_high;\n        b_low.digit.assign(b.digit.begin(), b.digit.begin()\
    \ + min(k, b.size()));\n        b_high.digit.assign(b.digit.begin() + min(k, b.size()),\
    \ b.digit.end());\n        b_low.neg = b_high.neg = false;\n        b_low.trim();\n\
    \        b_high.trim();\n\n        BigInt z0 = karatsuba(a_low, b_low);\n    \
    \    BigInt z2 = karatsuba(a_high, b_high);\n        BigInt z1 = karatsuba(a_low\
    \ + a_high, b_low + b_high) - z0 - z2;\n\n        BigInt res = z2.shifted(2*k)\
    \ + z1.shifted(k) + z0;\n        res.neg = (a.neg != b.neg);\n        res.trim();\n\
    \        return res;\n    }\n\n    BigInt operator*(const BigInt &b) const {\n\
    \        return karatsuba(*this, b);\n    }\n};\n"
  code: "#include \"../template.h\"\n\nclass BigInt {\npublic:\n    static const int\
    \ BASE = 10;\n    vector<uint32_t> digit;\n    bool neg = false;\n\n    BigInt()\
    \ {}\n\n    BigInt(int64_t val) {*this = val;}\n\n    BigInt(const string &s)\
    \ {*this = s;}\n\n    uint32_t getDigit(const uint32_t i) const {return digit[i];}\n\
    \n    uint32_t size() const {return digit.size();}\n\n    bool isZero() const\
    \ {return digit.empty();}\n\n    int compare(const BigInt &b) const {\n      \
    \  if (size() != b.size())\n            return size() > b.size() ? 1 : -1;\n \
    \       else if (size() < b.size())\n            return -1;\n        for (int\
    \ i = (int)size()-1; i >= 0; i--) {\n            if (digit[i] != b.getDigit(i))\n\
    \                return digit[i] > b.getDigit(i) ? 1 : -1;\n        }\n      \
    \  return 0;\n    }\n\n    void trim() {\n        while (!digit.empty() && digit.back()\
    \ == 0)\n            digit.pop_back();\n        if (digit.empty()) neg = false;\n\
    \    }\n\n    BigInt &operator=(int64_t val) {\n        digit.clear();\n     \
    \   if (val < 0) {\n            neg = true;\n            val = -val;\n       \
    \ }\n        while (val) {\n            digit.push_back(val % BASE);\n       \
    \     val /= BASE;\n        }\n        return *this;\n    }\n\n    BigInt &operator=(const\
    \ string &s) {\n        digit.clear();\n        int32_t pos = 0;\n        if (s[0]\
    \ == '-') {\n            neg = true;\n            pos = 1;\n        }\n      \
    \  for (int i = (int)s.size()-1; i >= pos; i--) {\n            digit.push_back(s[i]-'0');\n\
    \        }\n        trim();\n        return *this;\n    }\n\n    friend ostream\
    \ &operator<<(ostream &out, const BigInt &b) {\n        if (b.isZero()) return\
    \ out << \"0\";\n        if (b.neg) out << \"-\";\n        for (int i = (int)b.size()-1;\
    \ i >= 0; i--)\n            out << b.getDigit(i);\n        return out;\n    }\n\
    \n    BigInt operator+(const BigInt &b) const {\n        BigInt res;\n       \
    \ if (neg == b.neg) {\n            res.neg = neg;\n            int carry = 0;\n\
    \            size_t len = max(size(), b.size());\n            for (size_t i =\
    \ 0; i < len; i++) {\n                int sum = carry;\n                if (i\
    \ < size()) sum += digit[i];\n                if (i < b.size()) sum += b.getDigit(i);\n\
    \                res.digit.push_back(sum % BASE);\n                carry = sum\
    \ / BASE;\n            }\n            if (carry) res.digit.push_back(carry);\n\
    \            res.trim();\n            return res;\n        } else {\n        \
    \    return *this - (-b);\n        }\n    }\n\n    BigInt operator-(const BigInt\
    \ &b) const {\n        if (!neg && b.neg)\n            return *this + (-b);\n\
    \        if (neg && !b.neg)\n            return -((-*this) + b);\n        if (compare(b)\
    \ == -1) \n            return -(b - *this);\n        BigInt res;\n        res.neg\
    \ = neg;\n        int borrow = 0;\n        for (size_t i = 0; i < digit.size();\
    \ i++) {\n            int sub = digit[i]-borrow;\n            if (i < b.size())\
    \ sub -= b.getDigit(i);\n            if (sub < 0) sub += BASE, borrow = 1;\n \
    \           else borrow = 0;\n            res.digit.push_back(sub);\n        }\n\
    \        res.trim();\n        return res;\n    }\n\n    BigInt operator-() const\
    \ {\n        BigInt res = *this;\n        if (!res.isZero())\n            res.neg\
    \ = !neg;\n        return res;\n    }\n\n    BigInt mul(const BigInt &a, const\
    \ BigInt &b) const {\n        BigInt x = a, y = b;\n        x.trim(); y.trim();\n\
    \        BigInt res;\n        if (x.neg != y.neg)\n            res.neg = true;\n\
    \        res.digit.resize(x.size()+y.size());\n        for (size_t i = 0; i <\
    \ x.size(); i++) {\n            int carry = 0;\n            for (size_t j = 0;\
    \ j < y.size(); j++) {\n                int64_t cur = res.getDigit(i+j) + carry;\n\
    \                cur += x.digit[i] * y.getDigit(j);\n                res.digit[i+j]\
    \ = cur % BASE;\n                carry = cur / BASE;\n            }\n        \
    \    if (carry) res.digit[i+y.size()] += carry;\n        }\n        res.trim();\n\
    \        if (res.isZero()) res.neg = false;\n        return res;\n    }\n\n  \
    \  //---------------------karatsuba----------------------\n    BigInt shifted(size_t\
    \ k) const {\n        if (isZero()) return *this;\n        BigInt r = *this;\n\
    \        r.digit.insert(r.digit.begin(), k, 0);\n        return r;\n    }    \n\
    \n    BigInt karatsuba(const BigInt &a, const BigInt &b) const {\n        if (a.size()\
    \ < 32 || b.size() < 32)\n            return mul(a, b);\n        size_t n = max(a.size(),\
    \ b.size());\n        uint32_t k = n / 2;\n\n        BigInt a_low, a_high;\n \
    \       a_low.digit.assign(a.digit.begin(), a.digit.begin() + min(k, a.size()));\n\
    \        a_high.digit.assign(a.digit.begin() + min(k, a.size()), a.digit.end());\n\
    \        a_low.neg = a_high.neg = false;\n        a_low.trim();\n        a_high.trim();\n\
    \n        BigInt b_low, b_high;\n        b_low.digit.assign(b.digit.begin(), b.digit.begin()\
    \ + min(k, b.size()));\n        b_high.digit.assign(b.digit.begin() + min(k, b.size()),\
    \ b.digit.end());\n        b_low.neg = b_high.neg = false;\n        b_low.trim();\n\
    \        b_high.trim();\n\n        BigInt z0 = karatsuba(a_low, b_low);\n    \
    \    BigInt z2 = karatsuba(a_high, b_high);\n        BigInt z1 = karatsuba(a_low\
    \ + a_high, b_low + b_high) - z0 - z2;\n\n        BigInt res = z2.shifted(2*k)\
    \ + z1.shifted(k) + z0;\n        res.neg = (a.neg != b.neg);\n        res.trim();\n\
    \        return res;\n    }\n\n    BigInt operator*(const BigInt &b) const {\n\
    \        return karatsuba(*this, b);\n    }\n};"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Big_Integer/BigInt.h
  requiredBy: []
  timestamp: '2025-05-25 00:26:18+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Sample/Many_A_plus_B_128bit.test.cpp
  - Big_Integer/Yosupo/Addition_of_Big_Integers.test.cpp
documentation_of: Big_Integer/BigInt.h
layout: document
redirect_from:
- /library/Big_Integer/BigInt.h
- /library/Big_Integer/BigInt.h.html
title: Big_Integer/BigInt.h
---
