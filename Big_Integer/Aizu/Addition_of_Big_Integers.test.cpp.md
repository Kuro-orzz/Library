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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A
  bundledCode: "#line 1 \"Big_Integer/Aizu/Addition_of_Big_Integers.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A\"\
    \n\n#line 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \n \r\n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\
    \n#define unique(x) x.erase(unique(all(x)), x.end())\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main() {\r\n  \
    \  // if (FILE* f = fopen(TASK \".inp\", \"r\")) {\r\n    //     fclose(f);\r\n\
    \    //     freopen(TASK \".inp\", \"r\", stdin);\r\n    //     freopen(TASK \"\
    .out\", \"w\", stdout);\r\n    // }\r\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\r\
    \n    // cin.exceptions(cin.failbit);\r\n    // int t; cin >> t;\r\n    // while(t--)\r\
    \n        solve();\r\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"Big_Integer/BigInt_full.h\"\
    \n\r\n\r\n// Still slow ver, need optimize by FFT\r\n// This template only work\
    \ for base <= 10\r\nconstexpr int pow10c(int k) { return k ? 10 * pow10c(k - 1)\
    \ : 1; }\r\n\r\ntemplate<int D = 9>\r\nclass BigInt {\r\npublic:\r\n    static\
    \ const int BASE_DIGITS = D;\r\n    static const int BASE = pow10c(D);\r\n   \
    \ int sign;\r\n    vector<uint32_t> digit;\r\n\r\n    BigInt(): sign(1) {}\r\n\
    \r\n    BigInt(const string &s) { *this = s; }\r\n\r\n    BigInt(int64_t val)\
    \ { *this = val; }\r\n\r\n    BigInt &operator = (const string &s) {\r\n     \
    \   read(s);\r\n        return *this;\r\n    }\r\n\r\n    BigInt &operator = (int64_t\
    \ val) {\r\n        sign = val >= 0 ? 1 : -1;\r\n        val = llabs(val);\r\n\
    \        digit.clear();\r\n        for (; val; val /= BASE) {\r\n            digit.push_back(val\
    \ % BASE);\r\n        }\r\n        trim();\r\n        return *this;\r\n    }\r\
    \n\r\n    BigInt &operator += (const BigInt &b) {\r\n        if (sign != b.sign)\
    \ {\r\n            BigInt t = b;\r\n            t.sign *= -1;\r\n            return\
    \ *this -= t;\r\n        }\r\n        int carry = 0, len = (int)max(size(), b.size());\r\
    \n        for (int i = 0; i < len; i++) {\r\n            int sum = carry;\r\n\
    \            if (i < (int)size()) sum += digit[i];\r\n            if (i < (int)b.size())\
    \ sum += b[i];\r\n            if (i < (int)size()) digit[i] = sum % BASE;\r\n\
    \            else digit.push_back(sum % BASE);\r\n            carry = sum / BASE;\r\
    \n        }\r\n        if (carry) digit.push_back(carry);\r\n        trim();\r\
    \n        return *this;\r\n    }\r\n\r\n    BigInt &operator -= (const BigInt\
    \ &b) {\r\n        if (sign != b.sign) {\r\n            return *this += (-b);\r\
    \n        }\r\n        if (__compare_abs(b) == -1) {\r\n            BigInt t =\
    \ b;\r\n            t -= *this;\r\n            t.sign *= -1;\r\n            return\
    \ *this = t;\r\n        }\r\n        int borrow = 0, len = (int)max(size(), b.size());\r\
    \n        for (int i = 0; i < len; i++) {\r\n            int sub = -borrow;\r\n\
    \            if (i < (int)size()) sub += digit[i];\r\n            if (i < (int)b.size())\
    \ sub -= b[i];\r\n            if (sub < 0) sub += BASE, borrow = 1;\r\n      \
    \      else borrow = 0;\r\n            digit[i] = sub;\r\n        }\r\n      \
    \  trim();\r\n        return *this;\r\n    }\r\n\r\n    BigInt &operator *= (const\
    \ BigInt &b) {\r\n        return *this = karatsuba(*this, b);\r\n    }\r\n\r\n\
    \    BigInt &operator /= (const BigInt &b) {\r\n        *this = divmod(*this,\
    \ b).first;\r\n        return *this;\r\n    }\r\n\r\n    BigInt &operator %= (const\
    \ BigInt &b) {\r\n        *this = divmod(*this, b).second;\r\n        return *this;\r\
    \n    }\r\n\r\n    // ------------------------ Operator ------------------------\r\
    \n    // BigInt += Int\r\n    BigInt &operator += (int64_t t) { return *this +=\
    \ BigInt(t); }\r\n    BigInt &operator -= (int64_t t) { return *this -= BigInt(t);\
    \ }\r\n    BigInt &operator *= (int64_t t) { return *this *= BigInt(t); }\r\n\
    \    BigInt &operator /= (int64_t t) { \r\n        assert(t != 0); // not divided\
    \ for 0\r\n        if (t < 0) {\r\n            sign = -sign;\r\n            t\
    \ = -t;\r\n        }\r\n        int64_t rem = 0;\r\n        for (int i = (int)size()\
    \ - 1; i >= 0; i--) {\r\n            int64_t cur = rem * BASE + (*this)[i];\r\n\
    \            (*this)[i] = uint32_t(cur / t);\r\n            rem = cur % t;\r\n\
    \        } \r\n        trim();\r\n        return *this;\r\n    }\r\n    BigInt\
    \ &operator %= (int64_t t) {\r\n        assert(t != 0);\r\n        int64_t rem\
    \ = 0;\r\n        for (int i = (int)size() - 1; i >= 0; i--) {\r\n           \
    \ int64_t cur = rem * BASE + (*this)[i];\r\n            rem = cur % t;\r\n   \
    \     }\r\n        if (rem < 0) rem += llabs(t);\r\n        int s = sign;\r\n\
    \        *this = rem;\r\n        if (!isZero()) sign = s;\r\n        return *this;\r\
    \n    }\r\n\r\n    BigInt operator - () const { BigInt res = *this; res *= -1;\
    \ return res; } // -a;\r\n    BigInt operator + () const { return BigInt(*this);\
    \ } // +a;\r\n    BigInt &operator ++ () { *this += 1; return *this; } // ++a;\r\
    \n    BigInt &operator -- () { *this -= 1; return *this; } // --a;\r\n    BigInt\
    \ operator ++ (int) { BigInt res = *this; *this += 1; return res; } // a++;\r\n\
    \    BigInt operator -- (int) { BigInt res = *this; *this -= 1; return res; }\
    \ // a--;\r\n\r\n    // BigInt = BigInt + BigInt\r\n    BigInt operator + (const\
    \ BigInt &b) const { return BigInt(*this) += b; }\r\n    BigInt operator - (const\
    \ BigInt &b) const { return BigInt(*this) -= b; }\r\n    BigInt operator * (const\
    \ BigInt &b) const { return BigInt(*this) *= b; }\r\n    BigInt operator / (const\
    \ BigInt &b) const { return BigInt(*this) /= b; }\r\n    BigInt operator % (const\
    \ BigInt &b) const { return BigInt(*this) %= b; }\r\n\r\n    // BigInt = BigInt\
    \ + Int\r\n    BigInt operator + (int64_t t) const { return BigInt(*this) += t;\
    \ }\r\n    BigInt operator - (int64_t t) const { return BigInt(*this) -= t; }\r\
    \n    BigInt operator * (int64_t t) const { return BigInt(*this) *= t; }\r\n \
    \   BigInt operator / (int64_t t) const { return BigInt(*this) /= t; }\r\n   \
    \ BigInt operator % (int64_t t) const { return BigInt(*this) %= t; }\r\n\r\n \
    \   // BigInt = Int + BigInt\r\n    friend BigInt operator + (int64_t t, const\
    \ BigInt &b) { BigInt res(t); res += b; return res; }\r\n    friend BigInt operator\
    \ - (int64_t t, const BigInt &b) { BigInt res(t); res -= b; return res; }\r\n\
    \    friend BigInt operator * (int64_t t, const BigInt &b) { BigInt res(t); res\
    \ *= b; return res; }\r\n    friend BigInt operator / (int64_t t, const BigInt\
    \ &b) { BigInt res(t); res /= b; return res; }\r\n    friend BigInt operator %\
    \ (int64_t t, const BigInt &b) { BigInt res(t); res %= b; return res; }\r\n\r\n\
    \    uint32_t operator [] (const int i) const { assert(i >= 0 && i < (int)size());\
    \ return digit[i]; }\r\n    uint32_t &operator [] (const int i) { assert(i >=\
    \ 0 && i < (int)size()); return digit[i]; }\r\n\r\n    // -------------------------\
    \ Comparison ---------------------\r\n    bool operator < (const BigInt &b) const\
    \ {\r\n        if (sign != b.sign) {\r\n            return sign < b.sign;\r\n\
    \        }\r\n        int c = __compare_abs(b);\r\n        return sign == 1 ?\
    \ c < 0 : c > 0;\r\n    }\r\n\r\n    bool operator > (const BigInt &b) const {\
    \ return b < *this; }\r\n    bool operator <= (const BigInt &b) const { return\
    \ !(b < *this); }\r\n    bool operator >= (const BigInt &b) const { return !(*this\
    \ < b); }\r\n    bool operator == (const BigInt &b) const { return !(*this < b)\
    \ && !(b < *this); }\r\n    bool operator != (const BigInt &b) const { return\
    \ *this < b || b < *this; }\r\n\r\n    bool operator == (int64_t t) const { return\
    \ *this == BigInt(t); }\r\n    bool operator != (int64_t t) const { return *this\
    \ != BigInt(t); }\r\n    bool operator < (int64_t t) const { return *this < BigInt(t);\
    \ }\r\n    bool operator <= (int64_t t) const { return *this <= BigInt(t); }\r\
    \n    bool operator > (int64_t t) const { return *this > BigInt(t); }\r\n    bool\
    \ operator >= (int64_t t) const { return *this >= BigInt(t); }\r\n\r\n    // 0\
    \ if |a| == |b|\r\n    // -1 if |a| < |b|\r\n    // 1 if |a| > |b|\r\n    int\
    \ __compare_abs(const BigInt &b) const {\r\n        if (size() != b.size()) {\r\
    \n            return size() < b.size() ? -1 : 1;\r\n        }\r\n        for (int\
    \ i = (int)size() - 1; i >= 0; i--) {\r\n            if ((*this)[i] != b[i]) {\r\
    \n                return (*this)[i] < b[i] ? -1 : 1;\r\n            }\r\n    \
    \    }\r\n        return 0;\r\n    }\r\n\r\n    // -------------------- karatsuba\
    \ ---------------------\r\n    BigInt mul_simple(const BigInt &a, const BigInt\
    \ &b) {\r\n        BigInt res;\r\n        res.sign = a.sign * b.sign;\r\n    \
    \    res.digit.resize(a.size() + b.size());\r\n        for (int i = 0; i < (int)a.size();\
    \ i++) {\r\n            uint64_t carry = 0;\r\n            for (int j = 0; j <\
    \ (int)b.size(); j++) {\r\n                uint64_t cur = res[i+j] + carry;\r\n\
    \                cur += 1ull * a[i] * b[j];\r\n                res[i+j] = cur\
    \ % BASE;\r\n                carry = cur / BASE;\r\n            }\r\n        \
    \    if (carry) res[i+(int)b.size()] += carry;\r\n        }\r\n        res.trim();\r\
    \n        if (res.isZero()) res.sign = 1;\r\n        return res;\r\n    }\r\n\r\
    \n    BigInt shifted(int k) const {\r\n        if (isZero()) return *this;\r\n\
    \        BigInt r = *this;\r\n        r.digit.insert(r.digit.begin(), k, 0);\r\
    \n        return r;\r\n    }\r\n\r\n    BigInt karatsuba(const BigInt &a, const\
    \ BigInt &b) {\r\n        if (a.size() < 32 || b.size() < 32) {\r\n          \
    \  return mul_simple(a, b);\r\n        }\r\n        size_t n = max(a.size(), b.size());\r\
    \n        size_t k = n / 2;\r\n\r\n        BigInt a_low, a_high, b_low, b_high;\r\
    \n        int m1 = min(k, a.size()), m2 = min(k, b.size());\r\n        a_low.digit.assign(a.digit.begin(),\
    \ a.digit.begin() + m1);\r\n        a_high.digit.assign(a.digit.begin() + m1,\
    \ a.digit.end());\r\n        b_low.digit.assign(b.digit.begin(), b.digit.begin()\
    \ + m2);\r\n        b_high.digit.assign(b.digit.begin() + m2, b.digit.end());\r\
    \n        a_low.sign = a_high.sign = b_low.sign = b_high.sign = 1;\r\n       \
    \ a_low.trim(); a_high.trim();\r\n        b_low.trim(); b_high.trim();\r\n\r\n\
    \        BigInt z0 = karatsuba(a_low, b_low);\r\n        BigInt z1 = karatsuba(a_high,\
    \ b_high);\r\n        BigInt z2 = karatsuba(a_low + a_high, b_low + b_high) -\
    \ z1 - z0;\r\n        BigInt res = z1.shifted(2 * k) + z2.shifted(k) + z0;\r\n\
    \        res.trim();\r\n        res.sign = (a.sign != b.sign ? -1 : 1);\r\n  \
    \      return res;\r\n    }\r\n\r\n    // ------------------------ Div / Mod -----------------------\r\
    \n    pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1) {\r\n  \
    \      assert(b1 != 0); // not divided for 0\r\n        ll norm = BASE / (b1.digit.back()\
    \ + 1);\r\n        BigInt a = a1.abs() * norm;\r\n        BigInt b = b1.abs()\
    \ * norm;\r\n        BigInt q = 0, r = 0;\r\n        q.digit.resize(a.size());\r\
    \n\r\n        for (int i = a.size() - 1; i >= 0; i--) {\r\n            r *= BASE;\r\
    \n            r += a[i];\r\n            int64_t s1 = r.size() <= b.size() ? 0\
    \ : r[b.size()];\r\n            int64_t s2 = r.size() <= b.size() - 1 ? 0 : r[b.size()\
    \ - 1];\r\n            int64_t d = (BASE * s1 + s2) / b.digit.back();\r\n    \
    \        if (d >= BASE) {\r\n                d = BASE - 1;\r\n            }\r\n\
    \            r -= b * d;\r\n            while (r < 0) {\r\n                r +=\
    \ b, --d;\r\n            }\r\n            q[i] = d;\r\n        }\r\n        q.sign\
    \ = a1.sign * b1.sign;\r\n        r.sign = a1.sign;\r\n        q.trim(); r.trim();\r\
    \n\r\n        BigInt remainder;\r\n        remainder.digit.resize(r.size());\r\
    \n        int64_t carry = 0;\r\n        for (int i = (int)r.size() - 1; i >= 0;\
    \ i--) {\r\n            int64_t cur = r[i] + carry * BASE;\r\n            remainder[i]\
    \ = cur / norm;\r\n            carry = cur % norm;\r\n        }\r\n        remainder.sign\
    \ = r.sign;\r\n        remainder.trim();\r\n        auto res = make_pair(q, remainder);\r\
    \n        return res;\r\n    }\r\n\r\n    // ------------------------- Misc ---------------------------\r\
    \n    size_t size() const { return digit.size(); }\r\n\r\n    bool isZero() const\
    \ { return digit.empty(); }\r\n\r\n    void trim() {\r\n        while (!digit.empty()\
    \ && !digit.back()) {\r\n            digit.pop_back();\r\n        }\r\n      \
    \  if (digit.empty()) sign = 1;\r\n    }\r\n\r\n    BigInt abs() const { BigInt\
    \ res = *this; res.sign = 1; return res; }\r\n\r\n    string toString() const\
    \ {\r\n        ostringstream oss;\r\n        oss << *this;\r\n        return oss.str();\r\
    \n    }\r\n\r\n    // only support b >= 0, if b < 0 need to implement modulo inverse\r\
    \n    friend BigInt pow(const BigInt &a, const BigInt &b, ll mod) { return pow(a,\
    \ b, BigInt(mod)); }\r\n    friend BigInt pow(const BigInt &a, const BigInt &b,\
    \ const BigInt &mod) {\r\n        BigInt x(a), y(b), res(1);\r\n        while\
    \ (y != 0) {\r\n            if (y[0] % 2 == 1) res = res * x % mod;\r\n      \
    \      x = x * x % mod;\r\n            y /= 2;\r\n        }\r\n        return\
    \ res;\r\n    }\r\n    friend BigInt pow(const BigInt &a, const BigInt &b) {\r\
    \n        BigInt x(a), y(b), res(1);\r\n        while (y != 0) {\r\n         \
    \   if (y[0] % 2 == 1) res = res * x;\r\n            x = x * x;\r\n          \
    \  y /= 2;\r\n        }\r\n        return res;\r\n    }\r\n\r\n    friend BigInt\
    \ __gcd(const BigInt &a, const BigInt &b) {\r\n        if (b == 0) return a.abs();\r\
    \n        return __gcd(b, a % b);\r\n    }\r\n\r\n    friend BigInt __lcm(const\
    \ BigInt &a, const BigInt &b) {\r\n        if (a == 0 || b == 0) return BigInt(0);\r\
    \n        return (a / __gcd(a, b) * b).abs();\r\n    }\r\n\r\n    // safe sqrt\
    \ for long long and BigInt\r\n    friend BigInt sqrt(const BigInt &a1) {\r\n \
    \       BigInt a = a1;\r\n        while (a.digit.empty() || a.size() % 2 == 1)\
    \ {\r\n            a.digit.push_back(0);\r\n        }\r\n\r\n        int n = a.size();\r\
    \n        int firstDigit = (int) sqrt((double) a[n - 1] * BASE + a[n - 2]);\r\n\
    \        int norm = BASE / (firstDigit + 1);\r\n        a = a * norm * norm;\r\
    \n        while (a.digit.empty() || a.size() % 2 == 1) {\r\n            a.digit.push_back(0);\r\
    \n        }\r\n\r\n        BigInt r = 1ll * a[n - 1] * BASE + a[n - 2];\r\n  \
    \      firstDigit = (int) sqrt((double) a[n - 1] * BASE + a[n - 2]);\r\n     \
    \   int q = firstDigit;\r\n        BigInt res;\r\n\r\n        for (int j = n /\
    \ 2 - 1; j >= 0; j--) {\r\n            for (; ; --q) {\r\n                BigInt\
    \ r1 = (r - (res * 2 * BigInt(BASE) + q) * q) * BigInt(BASE) * BigInt(BASE);\r\
    \n                r1 += (j > 0 ? 1ll * a[2 * j - 1] * BASE + a[2 * j - 2] : 0);\r\
    \n                if (r1 >= 0) {\r\n                    r = r1;\r\n          \
    \          break;\r\n                }\r\n            }\r\n            res *=\
    \ BASE;\r\n            res += q;\r\n\r\n            if (j > 0) {\r\n         \
    \       int d1 = res.size() + 2 < r.size() ? r[res.size() + 2] : 0;\r\n      \
    \          int d2 = res.size() + 1 < r.size() ? r[res.size() + 1] : 0;\r\n   \
    \             int d3 = res.size() < r.size() ? r[res.size()] : 0;\r\n        \
    \        q = (1ll * d1 * BASE * BASE + 1ll * d2 * BASE + d3) / (firstDigit * 2);\r\
    \n            }\r\n        }\r\n\r\n        res.trim();\r\n        return res\
    \ / norm;\r\n    }\r\n\r\n    // ---------------------- Input Output ---------------------\r\
    \n    /* only use for decimal number */\r\n    void read(const string &s) {\r\n\
    \        if (s.empty()) { *this = 0; return; }\r\n        sign = (s[0] == '-'\
    \ ? -1 : 1);\r\n        digit.clear();\r\n        int pos = (s[0] == '-' ? 1 :\
    \ 0);\r\n        for (int i = (int)s.size() - 1; i >= pos; i -= BASE_DIGITS) {\r\
    \n            int x = 0;\r\n            int k = max(pos, i - BASE_DIGITS + 1);\r\
    \n            for (int j = k; j <= i; j++) {\r\n                x = x * 10 + (s[j]\
    \ - '0');\r\n            }\r\n            digit.push_back(x);\r\n        }\r\n\
    \        trim();\r\n    }\r\n\r\n    friend istream &operator >> (istream &in,\
    \ BigInt &a) {\r\n        string s; in >> s;\r\n        a.read(s);\r\n       \
    \ return in;\r\n    }\r\n\r\n    friend ostream &operator << (ostream &out, const\
    \ BigInt &a) {\r\n        if (a.sign == -1 && !a.isZero()) out << '-';\r\n   \
    \     out << (a.digit.empty() ? 0 : a.digit.back());\r\n        char old = out.fill('0');\r\
    \n        for (int i = (int)a.size() - 2; i >= 0; i--)\r\n            out << setw(BASE_DIGITS)\
    \ << a[i];\r\n        out.fill(old);\r\n        return out;\r\n    }\r\n};\n#line\
    \ 5 \"Big_Integer/Aizu/Addition_of_Big_Integers.test.cpp\"\n\nvoid solve() {\n\
    \    BigInt a, b; cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A\"\
    \n\n#include \"../../template.h\"\n#include \"../BigInt_full.h\"\n\nvoid solve()\
    \ {\n    BigInt a, b; cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - template.h
  - Big_Integer/BigInt_full.h
  isVerificationFile: true
  path: Big_Integer/Aizu/Addition_of_Big_Integers.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Big_Integer/Aizu/Addition_of_Big_Integers.test.cpp
layout: document
redirect_from:
- /verify/Big_Integer/Aizu/Addition_of_Big_Integers.test.cpp
- /verify/Big_Integer/Aizu/Addition_of_Big_Integers.test.cpp.html
title: Big_Integer/Aizu/Addition_of_Big_Integers.test.cpp
---
