---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Big_Integer/BigInt_full.h
    title: Big_Integer/BigInt_full.h
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_F
  bundledCode: "#line 1 \"Big_Integer/Aizu/Multiplication_of_Big_Integers_II.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_F\"\
    \n\n#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"Big_Integer/BigInt_full.h\"\n\n\n// Still slow ver, need optimize\n\
    // This template only work for base <= 10\n\nconst int BASE_DIGITS = 9;\nconst\
    \ int BASE = 1000000000;\n\nclass BigInt {\npublic:\n    int sign;\n    vector<uint32_t>\
    \ digit;\n\n    BigInt(): sign(1) {}\n\n    BigInt(const string &s) { *this =\
    \ s; }\n\n    BigInt(int64_t val) { *this = val; }\n\n    BigInt &operator = (const\
    \ BigInt &b) {\n        sign = b.sign;\n        digit = b.digit;\n        return\
    \ *this;\n    }\n\n    BigInt &operator = (const string &s) {\n        read(s);\n\
    \        return *this;\n    }\n\n    BigInt &operator = (int64_t val) {\n    \
    \    sign = val >= 0 ? 1 : -1;\n        val = llabs(val);\n        digit.clear();\n\
    \        for (; val; val /= BASE) {\n            digit.push_back(val % BASE);\n\
    \        }\n        trim();\n        return *this;\n    }\n\n    BigInt &operator\
    \ += (const BigInt &b) {\n        if (sign != b.sign) {\n            BigInt t\
    \ = b;\n            t.sign *= -1;\n            return *this -= t;\n        }\n\
    \        int carry = 0, len = (int)max(size(), b.size());\n        for (int i\
    \ = 0; i < len; i++) {\n            int sum = carry;\n            if (i < (int)size())\
    \ sum += digit[i];\n            if (i < (int)b.size()) sum += b[i];\n        \
    \    if (i < (int)size()) digit[i] = sum % BASE;\n            else digit.push_back(sum\
    \ % BASE);\n            carry = sum / BASE;\n        }\n        if (carry) digit.push_back(carry);\n\
    \        trim();\n        return *this;\n    }\n\n    BigInt &operator -= (const\
    \ BigInt &b) {\n        if (sign != b.sign) {\n            return *this += (-b);\n\
    \        }\n        if (__compare_abs(b) == -1) {\n            BigInt t = b;\n\
    \            t -= *this;\n            t.sign *= -1;\n            return *this\
    \ = t;\n        }\n        int borrow = 0, len = (int)max(size(), b.size());\n\
    \        for (int i = 0; i < len; i++) {\n            int sub = -borrow;\n   \
    \         if (i < (int)size()) sub += digit[i];\n            if (i < (int)b.size())\
    \ sub -= b[i];\n            if (sub < 0) sub += BASE, borrow = 1;\n          \
    \  else borrow = 0;\n            digit[i] = sub;\n        }\n        trim();\n\
    \        return *this;\n    }\n\n    BigInt &operator *= (const BigInt &b) {\n\
    \        return *this = karatsuba(*this, b);\n    }\n\n    BigInt &operator /=\
    \ (const BigInt &b) {\n        *this = divmod(*this, b).first;\n        return\
    \ *this;\n    }\n\n    BigInt &operator %= (const BigInt &b) {\n        *this\
    \ = divmod(*this, b).second;\n        return *this;\n    }\n\n    // ------------------------\
    \ Operator ------------------------\n    // BigInt += Int\n    BigInt &operator\
    \ += (int64_t t) { return *this += BigInt(t); }\n    BigInt &operator -= (int64_t\
    \ t) { return *this -= BigInt(t); }\n    BigInt &operator *= (int64_t t) { return\
    \ *this *= BigInt(t); }\n    BigInt &operator /= (int64_t t) { \n        assert(t\
    \ != 0); // not divided for 0\n        int64_t rem = 0;\n        for (int i =\
    \ (int)size() - 1; i >= 0; i--) {\n            int64_t cur = rem * BASE + (*this)[i];\n\
    \            (*this)[i] = uint32_t(cur / t);\n            rem = cur % t;\n   \
    \     } \n        trim();\n        sign = sign * (t < 0 ? -1 : 1);\n        return\
    \ *this;\n    }\n    BigInt &operator %= (int64_t t) {\n        assert(t != 0);\n\
    \        int64_t rem = 0;\n        for (int i = (int)size() - 1; i >= 0; i--)\
    \ {\n            int64_t cur = rem * BASE + (*this)[i];\n            rem = cur\
    \ % t;\n        }\n        if (rem < 0) rem += llabs(t);\n        int s = sign;\n\
    \        *this = rem;\n        sign = s;\n        return *this;\n    }\n\n   \
    \ BigInt operator - () const { BigInt res = *this; res *= -1; return res; } //\
    \ -a;\n    BigInt operator + () const { return BigInt(*this); } // +a;\n    BigInt\
    \ &operator ++ () { *this += 1; return *this; } // ++a;\n    BigInt &operator\
    \ -- () { *this -= 1; return *this; } // --a;\n    BigInt operator ++ (int) {\
    \ BigInt res = *this; *this += 1; return res; } // a++;\n    BigInt operator --\
    \ (int) { BigInt res = *this; *this -= 1; return res; } // a--;\n\n    // BigInt\
    \ = BigInt + BigInt\n    BigInt operator + (const BigInt &b) const { return BigInt(*this)\
    \ += b; }\n    BigInt operator - (const BigInt &b) const { return BigInt(*this)\
    \ -= b; }\n    BigInt operator * (const BigInt &b) const { return BigInt(*this)\
    \ *= b; }\n    BigInt operator / (const BigInt &b) const { return BigInt(*this)\
    \ /= b; }\n    BigInt operator % (const BigInt &b) const { return BigInt(*this)\
    \ %= b; }\n\n    // BigInt = BigInt + Int\n    BigInt operator + (int64_t t) const\
    \ { return BigInt(*this) += t; }\n    BigInt operator - (int64_t t) const { return\
    \ BigInt(*this) -= t; }\n    BigInt operator * (int64_t t) const { return BigInt(*this)\
    \ *= t; }\n    BigInt operator / (int64_t t) const { return BigInt(*this) /= t;\
    \ }\n    BigInt operator % (int64_t t) const { return BigInt(*this) %= t; }\n\n\
    \    // BigInt = Int + BigInt\n    friend BigInt operator + (int64_t t, const\
    \ BigInt &b) { BigInt res(t); res += b; return res; }\n    friend BigInt operator\
    \ - (int64_t t, const BigInt &b) { BigInt res(t); res -= b; return res; }\n  \
    \  friend BigInt operator * (int64_t t, const BigInt &b) { BigInt res(t); res\
    \ *= b; return res; }\n    friend BigInt operator / (int64_t t, const BigInt &b)\
    \ { BigInt res(t); res /= b; return res; }\n    friend BigInt operator % (int64_t\
    \ t, const BigInt &b) { BigInt res(t); res %= b; return res; }\n\n    uint32_t\
    \ operator [] (const int i) const { assert(i >= 0 && i < (int)size()); return\
    \ digit[i]; }\n    uint32_t &operator [] (const int i) { assert(i >= 0 && i <\
    \ (int)size()); return digit[i]; }\n\n    // ------------------------- Comparison\
    \ ---------------------\n    bool operator < (const BigInt &b) const {\n     \
    \   if (sign != b.sign) {\n            return sign < b.sign;\n        }\n    \
    \    if (size() != b.size()) {\n            return size() * sign < b.size() *\
    \ b.sign;\n        }\n        for (int i = (int)size() - 1; i >= 0; i--) {\n \
    \           if ((*this)[i] != b[i]) {\n                return (*this)[i] * sign\
    \ < b[i] * sign;\n            }\n        }\n        return false;\n    }\n\n \
    \   bool operator > (const BigInt &b) const { return b < *this; }\n    bool operator\
    \ <= (const BigInt &b) const { return !(b < *this); }\n    bool operator >= (const\
    \ BigInt &b) const { return !(*this < b); }\n    bool operator == (const BigInt\
    \ &b) const { return !(*this < b) && !(b < *this); }\n    bool operator != (const\
    \ BigInt &b) const { return *this < b || b < *this; }\n\n    bool operator ==\
    \ (int64_t t) const { return *this == BigInt(t); }\n    bool operator != (int64_t\
    \ t) const { return *this != BigInt(t); }\n    bool operator < (int64_t t) const\
    \ { return *this < BigInt(t); }\n    bool operator <= (int64_t t) const { return\
    \ *this <= BigInt(t); }\n    bool operator > (int64_t t) const { return *this\
    \ > BigInt(t); }\n    bool operator >= (int64_t t) const { return *this >= BigInt(t);\
    \ }\n\n    // 0 if |a| == |b|\n    // -1 if |a| < |b|\n    // 1 if |a| > |b|\n\
    \    int __compare_abs(const BigInt &b) const {\n        if (size() != b.size())\
    \ {\n            return size() < b.size() ? -1 : 1;\n        }\n        for (int\
    \ i = (int)size() - 1; i >= 0; i--) {\n            if ((*this)[i] != b[i]) {\n\
    \                return (*this)[i] < b[i] ? -1 : 1;\n            }\n        }\n\
    \        return 0;\n    }\n\n    // -------------------- karatsuba ---------------------\n\
    \    BigInt mul_simple(const BigInt &a, const BigInt &b) {\n        BigInt x =\
    \ a, y = b;\n        BigInt res;\n        res.sign = x.sign * y.sign;\n      \
    \  res.digit.resize(x.size() + y.size());\n        for (int i = 0; i < (int)x.size();\
    \ i++) {\n            uint64_t carry = 0;\n            for (int j = 0; j < (int)y.size();\
    \ j++) {\n                uint64_t cur = res[i+j] + carry;\n                cur\
    \ += 1ull * x[i] * y[j];\n                res[i+j] = cur % BASE;\n           \
    \     carry = cur / BASE;\n            }\n            if (carry) res[i+(int)y.size()]\
    \ += carry;\n        }\n        res.trim();\n        if (res.isZero()) res.sign\
    \ = 1;\n        return res;\n    }\n\n    BigInt shifted(int k) const {\n    \
    \    if (isZero()) return *this;\n        BigInt r = *this;\n        r.digit.insert(r.digit.begin(),\
    \ k, 0);\n        return r;\n    }\n\n    BigInt karatsuba(const BigInt &a, const\
    \ BigInt &b) {\n        if (a.size() < 32 || b.size() < 32) {\n            return\
    \ mul_simple(a, b);\n        }\n        size_t n = max(a.size(), b.size());\n\
    \        size_t k = n / 2;\n\n        BigInt a_low, a_high, b_low, b_high;\n \
    \       int m1 = min(k, a.size()), m2 = min(k, b.size());\n        a_low.digit.assign(a.digit.begin(),\
    \ a.digit.begin() + m1);\n        a_high.digit.assign(a.digit.begin() + m1, a.digit.end());\n\
    \        b_low.digit.assign(b.digit.begin(), b.digit.begin() + m2);\n        b_high.digit.assign(b.digit.begin()\
    \ + m2, b.digit.end());\n        a_low.sign = a_high.sign = b_low.sign = b_high.sign\
    \ = 1;\n        a_low.trim(); a_high.trim();\n        b_low.trim(); b_high.trim();\n\
    \n        BigInt z0 = karatsuba(a_low, b_low);\n        BigInt z1 = karatsuba(a_high,\
    \ b_high);\n        BigInt z2 = karatsuba(a_low + a_high, b_low + b_high) - z1\
    \ - z0;\n        BigInt res = z1.shifted(2 * k) + z2.shifted(k) + z0;\n      \
    \  res.trim();\n        res.sign = (a.sign != b.sign ? -1 : 1);\n        return\
    \ res;\n    }\n\n    // ------------------------ Div / Mod -----------------------\n\
    \    pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1) {\n     \
    \   assert(b1 != 0); // not divided for 0\n        ll norm = BASE / (b1.digit.back()\
    \ + 1);\n        BigInt a = a1.abs() * norm;\n        BigInt b = b1.abs() * norm;\n\
    \        BigInt q = 0, r = 0;\n        q.digit.resize(a.size());\n\n        for\
    \ (int i = a.size() - 1; i >= 0; i--) {\n            r *= BASE;\n            r\
    \ += a[i];\n            int64_t s1 = r.size() <= b.size() ? 0 : r[b.size()];\n\
    \            int64_t s2 = r.size() <= b.size() - 1 ? 0 : r[b.size() - 1];\n  \
    \          int64_t d = (BASE * s1 + s2) / b.digit.back();\n            if (d >=\
    \ BASE) {\n                d = BASE - 1;\n            }\n            r -= b *\
    \ d;\n            while (r < 0) {\n                r += b, --d;\n            }\n\
    \            q[i] = d;\n        }\n        q.sign = a1.sign * b1.sign;\n     \
    \   r.sign = a1.sign;\n        q.trim(); r.trim();\n\n        BigInt remainder;\n\
    \        remainder.digit.resize(r.size());\n        int64_t carry = 0;\n     \
    \   for (int i = (int)r.size() - 1; i >= 0; i--) {\n            int64_t cur =\
    \ r[i] + carry * BASE;\n            remainder[i] = cur / norm;\n            carry\
    \ = cur % norm;\n        }\n        remainder.trim();\n        auto res = make_pair(q,\
    \ remainder);\n        if (res.second < 0) {\n            res.second += b1.abs();\n\
    \        }\n        return res;\n    }\n\n    // ------------------------- Misc\
    \ ---------------------------\n    size_t size() const { return digit.size();\
    \ }\n\n    bool isZero() const { return digit.empty(); }\n\n    void trim() {\n\
    \        while (!digit.empty() && !digit.back()) {\n            digit.pop_back();\n\
    \        }\n        if (digit.empty()) sign = 1;\n    }\n\n    BigInt abs() const\
    \ { BigInt res = *this; res.sign = 1; return res; }\n\n    string toString() const\
    \ {\n        ostringstream oss;\n        oss << *this;\n        return oss.str();\n\
    \    }\n\n    // only support b >= 0, if b < 0 need to implement modulo inverse\n\
    \    friend BigInt pow(const BigInt &a, const BigInt &b, ll mod) { return pow(a,\
    \ b, BigInt(mod)); }\n    friend BigInt pow(const BigInt &a, const BigInt &b,\
    \ const BigInt &mod) {\n        BigInt x(a), y(b), res(1);\n        while (y !=\
    \ 0) {\n            if (y[0] % 2 == 1) res = res * x % mod;\n            x = x\
    \ * x % mod;\n            y /= 2;\n        }\n        return res;\n    }\n   \
    \ friend BigInt pow(const BigInt &a, const BigInt &b) {\n        BigInt x(a),\
    \ y(b), res(1);\n        while (y != 0) {\n            if (y[0] % 2 == 1) res\
    \ = res * x;\n            x = x * x;\n            y /= 2;\n        }\n       \
    \ return res;\n    }\n\n    friend BigInt __gcd(const BigInt &a, const BigInt\
    \ &b) {\n        if (b == 0) return a;\n        return __gcd(b, a % b);\n    }\n\
    \n    friend BigInt __lcm(const BigInt &a, const BigInt &b) {\n        return\
    \ a / __gcd(a, b) * b;\n    }\n\n    // safe sqrt for long long and BigInt\n \
    \   friend BigInt sqrt(const BigInt &a1) {\n        BigInt a = a1;\n        while\
    \ (a.digit.empty() || a.size() % 2 == 1) {\n            a.digit.push_back(0);\n\
    \        }\n\n        int n = a.size();\n        int firstDigit = (int) sqrt((double)\
    \ a[n - 1] * BASE + a[n - 2]);\n        int norm = BASE / (firstDigit + 1);\n\
    \        a = a * norm * norm;\n        while (a.digit.empty() || a.size() % 2\
    \ == 1) {\n            a.digit.push_back(0);\n        }\n\n        BigInt r =\
    \ 1ll * a[n - 1] * BASE + a[n - 2];\n        firstDigit = (int) sqrt((double)\
    \ a[n - 1] * BASE + a[n - 2]);\n        int q = firstDigit;\n        BigInt res;\n\
    \n        for (int j = n / 2 - 1; j >= 0; j--) {\n            for (; ; --q) {\n\
    \                BigInt r1 = (r - (res * 2 * BigInt(BASE) + q) * q) * BigInt(BASE)\
    \ * BigInt(BASE);\n                r1 += (j > 0 ? 1ll * a[2 * j - 1] * BASE +\
    \ a[2 * j - 2] : 0);\n                if (r1 >= 0) {\n                    r =\
    \ r1;\n                    break;\n                }\n            }\n        \
    \    res *= BASE;\n            res += q;\n\n            if (j > 0) {\n       \
    \         int d1 = res.size() + 2 < r.size() ? r[res.size() + 2] : 0;\n      \
    \          int d2 = res.size() + 1 < r.size() ? r[res.size() + 1] : 0;\n     \
    \           int d3 = res.size() < r.size() ? r[res.size()] : 0;\n            \
    \    q = (1ll * d1 * BASE * BASE + 1ll * d2 * BASE + d3) / (firstDigit * 2);\n\
    \            }\n        }\n\n        res.trim();\n        return res / norm;\n\
    \    }\n\n    // ---------------------- Input Output ---------------------\n \
    \   /* only use for decimal number */\n    void read(const string &s) {\n    \
    \    sign = (s[0] == '-' ? -1 : 1);\n        digit.clear();\n        int pos =\
    \ (s[0] == '-' ? 1 : 0);\n        for (int i = (int)s.size() - 1; i >= pos; i\
    \ -= BASE_DIGITS) {\n            int x = 0;\n            int k = max(pos, i -\
    \ BASE_DIGITS + 1);\n            for (int j = k; j <= i; j++) {\n            \
    \    x = x * 10 + (s[j] - '0');\n            }\n            digit.push_back(x);\n\
    \        }\n        trim();\n    }\n\n    friend istream &operator >> (istream\
    \ &in, BigInt &a) {\n        string s; in >> s;\n        a.read(s);\n        return\
    \ in;\n    }\n\n    friend ostream &operator << (ostream &out, const BigInt &a)\
    \ {\n        if (a.sign == -1 && !a.isZero()) out << '-';\n        out << (a.digit.empty()\
    \ ? 0 : a.digit.back());\n        for (int i = (int)a.size() - 2; i >= 0; i--)\n\
    \            out << setw(BASE_DIGITS) << setfill('0') << a[i];\n        return\
    \ out;\n    }\n};\n#line 5 \"Big_Integer/Aizu/Multiplication_of_Big_Integers_II.test.cpp\"\
    \n\n// Test karatsuba algo\n\nvoid solve() {\n    BigInt a, b; cin >> a >> b;\n\
    \    cout << a * b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_F\"\
    \n\n#include \"../../template.h\"\n#include \"../BigInt_full.h\"\n\n// Test karatsuba\
    \ algo\n\nvoid solve() {\n    BigInt a, b; cin >> a >> b;\n    cout << a * b <<\
    \ '\\n';\n}"
  dependsOn:
  - template.h
  - Big_Integer/BigInt_full.h
  isVerificationFile: true
  path: Big_Integer/Aizu/Multiplication_of_Big_Integers_II.test.cpp
  requiredBy: []
  timestamp: '2025-12-04 02:05:35+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Big_Integer/Aizu/Multiplication_of_Big_Integers_II.test.cpp
layout: document
redirect_from:
- /verify/Big_Integer/Aizu/Multiplication_of_Big_Integers_II.test.cpp
- /verify/Big_Integer/Aizu/Multiplication_of_Big_Integers_II.test.cpp.html
title: Big_Integer/Aizu/Multiplication_of_Big_Integers_II.test.cpp
---
