---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy:
  - icon: ':x:'
    path: NumberTheory/Math/Combination.h
    title: NumberTheory/Math/Combination.h
  _extendedVerifiedWith:
  - icon: ':x:'
    path: NumberTheory/Yosupo/Binomial_coefficient_prime_mod.test.cpp
    title: NumberTheory/Yosupo/Binomial_coefficient_prime_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"Misc/ModInt.h\"\n\ntemplate\
    \ <int32_t mod>\nstruct ModInt {\n    int32_t x;\n\n    ModInt(): x(0) {}\n  \
    \  ModInt(int32_t _x): x(_x % mod) { x = x < 0 ? x + mod : x; }\n\n    ModInt\
    \ &operator += (const ModInt &p) {\n        x += p.x;\n        if (x >= mod) x\
    \ -= mod;\n        return *this;\n    }\n\n    ModInt &operator -= (const ModInt\
    \ &p) {\n        x -= p.x;\n        if (x < 0) x += mod;\n        return *this;\n\
    \    }\n\n    ModInt &operator *= (const ModInt &p) {\n        x = (int32_t)(1ll\
    \ * x * p.x % mod);\n        return *this; \n    }\n\n    ModInt &operator /=\
    \ (const ModInt &p) {\n        *this *= p.inverse();\n        return *this;\n\
    \    }\n\n    // ModInt += Int\n    ModInt &operator += (int32_t t) { return *this\
    \ += ModInt(t); }\n    ModInt &operator -= (int32_t t) { return *this -= ModInt(t);\
    \ }\n    ModInt &operator *= (int32_t t) { return *this *= ModInt(t); }\n    ModInt\
    \ &operator /= (int32_t t) { return *this /= ModInt(t); }\n\n    ModInt operator\
    \ - () const { return ModInt(-x); } // -a;\n    ModInt operator + () const { return\
    \ ModInt(*this); } // +a;\n    ModInt &operator ++ () { *this += 1; return *this;\
    \ } // ++a;\n    ModInt &operator -- () { *this -= 1; return *this; } // --a;\n\
    \    ModInt operator ++ (int) { ModInt res = *this; *this += 1; return res; }\
    \ // a++;\n    ModInt operator -- (int) { ModInt res = *this; *this -= 1; return\
    \ res; } // a--;\n\n    // ModInt = ModInt + ModInt\n    ModInt operator + (const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n    ModInt operator - (const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n    ModInt operator * (const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n    ModInt operator / (const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n\n    // ModInt = ModInt +\
    \ Int\n    ModInt operator + (int32_t t) const { return ModInt(*this) += t; }\n\
    \    ModInt operator - (int32_t t) const { return ModInt(*this) -= t; }\n    ModInt\
    \ operator * (int32_t t) const { return ModInt(*this) *= t; }\n    ModInt operator\
    \ / (int32_t t) const { return ModInt(*this) /= t; }\n\n    // ModInt = Int +\
    \ ModInt\n    friend ModInt operator + (int32_t t, const ModInt &p) { ModInt res(t);\
    \ res += p; return res; }\n    friend ModInt operator - (int32_t t, const ModInt\
    \ &p) { ModInt res(t); res -= p; return res; }\n    friend ModInt operator * (int32_t\
    \ t, const ModInt &p) { ModInt res(t); res *= p; return res; }\n    friend ModInt\
    \ operator / (int32_t t, const ModInt &p) { ModInt res(t); res /= p; return res;\
    \ }\n\n    bool operator == (const ModInt &p) const { return x == p.x; }\n   \
    \ bool operator != (const ModInt &p) const { return x != p.x; }\n    bool operator\
    \ < (const ModInt &p) const { return x < p.x; }\n    bool operator <= (const ModInt\
    \ &p) const { return x <= p.x; }\n    bool operator > (const ModInt &p) const\
    \ { return x > p.x; }\n    bool operator >= (const ModInt &p) const { return x\
    \ >= p.x; }\n\n    bool operator == (int32_t t) const { return x == t; }\n   \
    \ bool operator != (int32_t t) const { return x != t; }\n    bool operator < (int32_t\
    \ t) const { return x < t; }\n    bool operator <= (int32_t t) const { return\
    \ x <= t; }\n    bool operator > (int32_t t) const { return x > t; }\n    bool\
    \ operator >= (int32_t t) const { return x >= t; }\n\n    ModInt inverse() const\
    \ { return power(mod - 2); }\n\n    ModInt power(int32_t b) const {\n        assert(b\
    \ >= 0);\n        ModInt mul(x), ret(1);\n        while (b) {\n            if\
    \ (b & 1) ret *= mul;\n            mul *= mul;\n            b /= 2;\n        }\n\
    \        return ret;\n    }\n\n    friend istream &operator >> (istream &in, ModInt\
    \ &p) { \n        int32_t t;\n        in >> t;\n        p = ModInt<mod>(t);\n\
    \        return in;\n    }\n    \n    friend ostream &operator << (ostream &out,\
    \ const ModInt &p) { return out << p.x; }\n\n    int32_t get() const { return\
    \ x; }\n    static constexpr int32_t get_mod() { return mod; }\n};\n"
  code: "#include \"../template.h\"\n\ntemplate <int32_t mod>\nstruct ModInt {\n \
    \   int32_t x;\n\n    ModInt(): x(0) {}\n    ModInt(int32_t _x): x(_x % mod) {\
    \ x = x < 0 ? x + mod : x; }\n\n    ModInt &operator += (const ModInt &p) {\n\
    \        x += p.x;\n        if (x >= mod) x -= mod;\n        return *this;\n \
    \   }\n\n    ModInt &operator -= (const ModInt &p) {\n        x -= p.x;\n    \
    \    if (x < 0) x += mod;\n        return *this;\n    }\n\n    ModInt &operator\
    \ *= (const ModInt &p) {\n        x = (int32_t)(1ll * x * p.x % mod);\n      \
    \  return *this; \n    }\n\n    ModInt &operator /= (const ModInt &p) {\n    \
    \    *this *= p.inverse();\n        return *this;\n    }\n\n    // ModInt += Int\n\
    \    ModInt &operator += (int32_t t) { return *this += ModInt(t); }\n    ModInt\
    \ &operator -= (int32_t t) { return *this -= ModInt(t); }\n    ModInt &operator\
    \ *= (int32_t t) { return *this *= ModInt(t); }\n    ModInt &operator /= (int32_t\
    \ t) { return *this /= ModInt(t); }\n\n    ModInt operator - () const { return\
    \ ModInt(-x); } // -a;\n    ModInt operator + () const { return ModInt(*this);\
    \ } // +a;\n    ModInt &operator ++ () { *this += 1; return *this; } // ++a;\n\
    \    ModInt &operator -- () { *this -= 1; return *this; } // --a;\n    ModInt\
    \ operator ++ (int) { ModInt res = *this; *this += 1; return res; } // a++;\n\
    \    ModInt operator -- (int) { ModInt res = *this; *this -= 1; return res; }\
    \ // a--;\n\n    // ModInt = ModInt + ModInt\n    ModInt operator + (const ModInt\
    \ &p) const { return ModInt(*this) += p; }\n    ModInt operator - (const ModInt\
    \ &p) const { return ModInt(*this) -= p; }\n    ModInt operator * (const ModInt\
    \ &p) const { return ModInt(*this) *= p; }\n    ModInt operator / (const ModInt\
    \ &p) const { return ModInt(*this) /= p; }\n\n    // ModInt = ModInt + Int\n \
    \   ModInt operator + (int32_t t) const { return ModInt(*this) += t; }\n    ModInt\
    \ operator - (int32_t t) const { return ModInt(*this) -= t; }\n    ModInt operator\
    \ * (int32_t t) const { return ModInt(*this) *= t; }\n    ModInt operator / (int32_t\
    \ t) const { return ModInt(*this) /= t; }\n\n    // ModInt = Int + ModInt\n  \
    \  friend ModInt operator + (int32_t t, const ModInt &p) { ModInt res(t); res\
    \ += p; return res; }\n    friend ModInt operator - (int32_t t, const ModInt &p)\
    \ { ModInt res(t); res -= p; return res; }\n    friend ModInt operator * (int32_t\
    \ t, const ModInt &p) { ModInt res(t); res *= p; return res; }\n    friend ModInt\
    \ operator / (int32_t t, const ModInt &p) { ModInt res(t); res /= p; return res;\
    \ }\n\n    bool operator == (const ModInt &p) const { return x == p.x; }\n   \
    \ bool operator != (const ModInt &p) const { return x != p.x; }\n    bool operator\
    \ < (const ModInt &p) const { return x < p.x; }\n    bool operator <= (const ModInt\
    \ &p) const { return x <= p.x; }\n    bool operator > (const ModInt &p) const\
    \ { return x > p.x; }\n    bool operator >= (const ModInt &p) const { return x\
    \ >= p.x; }\n\n    bool operator == (int32_t t) const { return x == t; }\n   \
    \ bool operator != (int32_t t) const { return x != t; }\n    bool operator < (int32_t\
    \ t) const { return x < t; }\n    bool operator <= (int32_t t) const { return\
    \ x <= t; }\n    bool operator > (int32_t t) const { return x > t; }\n    bool\
    \ operator >= (int32_t t) const { return x >= t; }\n\n    ModInt inverse() const\
    \ { return power(mod - 2); }\n\n    ModInt power(int32_t b) const {\n        assert(b\
    \ >= 0);\n        ModInt mul(x), ret(1);\n        while (b) {\n            if\
    \ (b & 1) ret *= mul;\n            mul *= mul;\n            b /= 2;\n        }\n\
    \        return ret;\n    }\n\n    friend istream &operator >> (istream &in, ModInt\
    \ &p) { \n        int32_t t;\n        in >> t;\n        p = ModInt<mod>(t);\n\
    \        return in;\n    }\n    \n    friend ostream &operator << (ostream &out,\
    \ const ModInt &p) { return out << p.x; }\n\n    int32_t get() const { return\
    \ x; }\n    static constexpr int32_t get_mod() { return mod; }\n};\n"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: Misc/ModInt.h
  requiredBy:
  - NumberTheory/Math/Combination.h
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - NumberTheory/Yosupo/Binomial_coefficient_prime_mod.test.cpp
documentation_of: Misc/ModInt.h
layout: document
redirect_from:
- /library/Misc/ModInt.h
- /library/Misc/ModInt.h.html
title: Misc/ModInt.h
---
