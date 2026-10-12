---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Misc/ModInt.h
    title: Misc/ModInt.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Binary_exponentiation.h
    title: NumberTheory/Math/Binary_exponentiation.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Extended_euclid.h
    title: NumberTheory/Math/Extended_euclid.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Yosupo/Binomial_coefficient_prime_mod.test.cpp
    title: NumberTheory/Yosupo/Binomial_coefficient_prime_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ x; }\n    static constexpr int32_t get_mod() { return mod; }\n};\n#line 2 \"\
    NumberTheory/Math/Binary_exponentiation.h\"\n\r\nusing u128 = __uint128_t;\r\n\
    using i128 = __int128;\r\n\r\nll binMul(ll a, ll b, ll M) { return (i128)a * b\
    \ % M; }\r\n\r\n// long double trick\r\n// require: mantissa 64 bit, x86 gcc/clang\r\
    \nll binMul2(ll a, ll b, ll M) {\r\n    ll q = (ll)((long double)a * b / M);\r\
    \n    ll r = (ll)((unsigned ll)a * b - (unsigned ll)q * M);\r\n    return r <\
    \ 0 ? r + M : (r >= M ? r - M : r);\r\n}\r\n\r\nll binMul3(ll a, ll b, ll M) {\r\
    \n    unsigned long long ua = a % M, um = M, res = 0;\r\n    while (b) {\r\n \
    \       if (b & 1) { res += ua; if (res >= um) res -= um; }\r\n        ua <<=\
    \ 1; if (ua >= um) ua -= um;\r\n        b >>= 1;\r\n    }\r\n    return res;\r\
    \n}\r\n\r\nll binPow(ll a, ll b, ll M) {\r\n    a %= M;\r\n    ll res = 1 % M;\r\
    \n    while (b) {\r\n        if (b & 1) res = (i128)res * a % M;\r\n        a\
    \ = (i128)a * a % M;\r\n        b /= 2;\r\n    }\r\n    return res;\r\n}\n#line\
    \ 2 \"NumberTheory/Math/Extended_euclid.h\"\n\r\n\r\nll extended1(ll a, ll b,\
    \ ll &x, ll &y) {\r\n    if (b == 0) {\r\n        x = 1, y = 0;\r\n        return\
    \ a;\r\n    }\r\n    ll x1, y1;\r\n    ll d = extended1(b, a%b, x1, y1);\r\n \
    \   x = y1;\r\n    y = x1-y1*(a/b);\r\n    return d;\r\n}\r\n\r\n// Iterative\
    \ version\r\nll extended2(ll a, ll b, ll &x, ll &y) {\r\n    x = 1, y = 0;\r\n\
    \    ll x1 = 0, y1 = 1;\r\n    ll a1 = a, b1 = b;\r\n    while (b1) {\r\n    \
    \    ll q = a1 / b1;\r\n        tie(x, x1) = make_tuple(x1, x - q * x1);\r\n \
    \       tie(y, y1) = make_tuple(y1, y - q * y1);\r\n        tie(a1, b1) = make_tuple(b1,\
    \ a1 - q * b1);\r\n    }\r\n    return a1;\r\n}\n#line 5 \"NumberTheory/Math/Combination.h\"\
    \n\r\n// This modint only work for MOD is prime cuz using modulo inverse\r\n//\
    \ using mint = ModInt<MOD>;\r\n\r\n// vector<mint> fact;\r\n\r\n// void preprocess()\
    \ {\r\n//     fact[0] = 1;\r\n//     for (int i = 1; i < (int)fact.size(); i++)\
    \ {\r\n//         fact[i] = fact[i-1] * i;\r\n//     }\r\n// }\r\n\r\n// mint\
    \ comb(int n, int k) {\r\n//     if (k < 0 || k > n) return 0; \r\n//     return\
    \ fact[n] / (fact[n-k] * fact[k]);\r\n// }\r\n// -----------------------------------------------------\r\
    \n\r\n// Using for n, k <= 1e6, m is prime and n < m < 2^31\r\nstruct Comb {\r\
    \n    ll m;\r\n    vector<int> fact, invFact;\r\n\r\n    Comb() {}\r\n    Comb(int\
    \ maxn, ll _m) : m(_m), fact(maxn+1), invFact(maxn+1) {\r\n        fact[0] = 1;\r\
    \n        for (int i = 1; i <= maxn; i++) fact[i] = (ll)fact[i-1] * i % m;\r\n\
    \        invFact[maxn] = binPow(fact[maxn], m-2, m);\r\n        for (int i = maxn;\
    \ i >= 1; i--) invFact[i-1] = (ll)invFact[i] * i % m;\r\n    }\r\n\r\n    // C(n,\
    \ k) = n! / (k! * (n-k)!)\r\n    ll comb(int n, int k) {\r\n        if (k < 0\
    \ || k > n) return 0;\r\n        return 1ll * fact[n] * invFact[k] % m * invFact[n-k]\
    \ % m;\r\n    }\r\n\r\n    // P(n,k) = n! / (n\u2212k)!\r\n    ll perm(int n,\
    \ int k) {\r\n        if (k < 0 || k > n) return 0;\r\n        return 1ll * fact[n]\
    \ * invFact[n-k] % m;\r\n    }\r\n\r\n    // inv(i) = (i-1)! / i! = 1/i\r\n  \
    \  // modulo inverse of i\r\n    ll inv(int i) { return i <= 0 ? 0 : 1ll * invFact[i]\
    \ * fact[i-1] % m; }\r\n\r\n    // catalan(n) = C(2n, n) / (n+1)\r\n    // require\
    \ 2*n <= maxn\r\n    ll Catalan(int n) { return 1ll * comb(2*n, n) * inv(n+1)\
    \ % m; }\r\n};\r\n\r\n\r\n// Pascal triangle\r\n// Using for n * k <= 1e7 or n,k\
    \ <= 5000, O(1) per operation\r\nvector<vector<int>> preprocess(int n, int k,\
    \ int m) {\r\n    vector<vector<int>> C(n+1, vector<int>(k+1));\r\n    for (int\
    \ i = 0; i <= n; i++) {\r\n        C[i][0] = 1 % m;\r\n        for (int j = 1;\
    \ j <= min(i, k); j++) {\r\n            C[i][j] = (1ll * C[i-1][j-1] + C[i-1][j])\
    \ % m;\r\n        }\r\n    }\r\n    return C;\r\n}\r\n\r\n// m must be prime\r\
    \n// fermat's little theorem a^(m-2) \u2261 a^(-1)\r\nll inverse1(ll a, ll m)\
    \ { return binPow(a, m-2, m); }\r\n// m must be prime\r\n// base on extended euclid\
    \ trick\r\nll inverse2(ll a, ll m) { return a <= 1 ? a : m-m/a * inverse2(m %\
    \ a, m) % m; }\r\n// m coprime to a, gcd(a, m) = 1\r\n// extended euclid trick\r\
    \nll inverse3(ll a, ll m) {\r\n    ll x, y;\r\n    extended2(a, m, x, y);\r\n\
    \    return (x % m + m) % m;\r\n}\n"
  code: "#include \"../../template.h\"\r\n#include \"../../Misc/ModInt.h\"\r\n#include\
    \ \"Binary_exponentiation.h\"\r\n#include \"Extended_euclid.h\"\r\n\r\n// This\
    \ modint only work for MOD is prime cuz using modulo inverse\r\n// using mint\
    \ = ModInt<MOD>;\r\n\r\n// vector<mint> fact;\r\n\r\n// void preprocess() {\r\n\
    //     fact[0] = 1;\r\n//     for (int i = 1; i < (int)fact.size(); i++) {\r\n\
    //         fact[i] = fact[i-1] * i;\r\n//     }\r\n// }\r\n\r\n// mint comb(int\
    \ n, int k) {\r\n//     if (k < 0 || k > n) return 0; \r\n//     return fact[n]\
    \ / (fact[n-k] * fact[k]);\r\n// }\r\n// -----------------------------------------------------\r\
    \n\r\n// Using for n, k <= 1e6, m is prime and n < m < 2^31\r\nstruct Comb {\r\
    \n    ll m;\r\n    vector<int> fact, invFact;\r\n\r\n    Comb() {}\r\n    Comb(int\
    \ maxn, ll _m) : m(_m), fact(maxn+1), invFact(maxn+1) {\r\n        fact[0] = 1;\r\
    \n        for (int i = 1; i <= maxn; i++) fact[i] = (ll)fact[i-1] * i % m;\r\n\
    \        invFact[maxn] = binPow(fact[maxn], m-2, m);\r\n        for (int i = maxn;\
    \ i >= 1; i--) invFact[i-1] = (ll)invFact[i] * i % m;\r\n    }\r\n\r\n    // C(n,\
    \ k) = n! / (k! * (n-k)!)\r\n    ll comb(int n, int k) {\r\n        if (k < 0\
    \ || k > n) return 0;\r\n        return 1ll * fact[n] * invFact[k] % m * invFact[n-k]\
    \ % m;\r\n    }\r\n\r\n    // P(n,k) = n! / (n\u2212k)!\r\n    ll perm(int n,\
    \ int k) {\r\n        if (k < 0 || k > n) return 0;\r\n        return 1ll * fact[n]\
    \ * invFact[n-k] % m;\r\n    }\r\n\r\n    // inv(i) = (i-1)! / i! = 1/i\r\n  \
    \  // modulo inverse of i\r\n    ll inv(int i) { return i <= 0 ? 0 : 1ll * invFact[i]\
    \ * fact[i-1] % m; }\r\n\r\n    // catalan(n) = C(2n, n) / (n+1)\r\n    // require\
    \ 2*n <= maxn\r\n    ll Catalan(int n) { return 1ll * comb(2*n, n) * inv(n+1)\
    \ % m; }\r\n};\r\n\r\n\r\n// Pascal triangle\r\n// Using for n * k <= 1e7 or n,k\
    \ <= 5000, O(1) per operation\r\nvector<vector<int>> preprocess(int n, int k,\
    \ int m) {\r\n    vector<vector<int>> C(n+1, vector<int>(k+1));\r\n    for (int\
    \ i = 0; i <= n; i++) {\r\n        C[i][0] = 1 % m;\r\n        for (int j = 1;\
    \ j <= min(i, k); j++) {\r\n            C[i][j] = (1ll * C[i-1][j-1] + C[i-1][j])\
    \ % m;\r\n        }\r\n    }\r\n    return C;\r\n}\r\n\r\n// m must be prime\r\
    \n// fermat's little theorem a^(m-2) \u2261 a^(-1)\r\nll inverse1(ll a, ll m)\
    \ { return binPow(a, m-2, m); }\r\n// m must be prime\r\n// base on extended euclid\
    \ trick\r\nll inverse2(ll a, ll m) { return a <= 1 ? a : m-m/a * inverse2(m %\
    \ a, m) % m; }\r\n// m coprime to a, gcd(a, m) = 1\r\n// extended euclid trick\r\
    \nll inverse3(ll a, ll m) {\r\n    ll x, y;\r\n    extended2(a, m, x, y);\r\n\
    \    return (x % m + m) % m;\r\n}"
  dependsOn:
  - template.h
  - Misc/ModInt.h
  - NumberTheory/Math/Binary_exponentiation.h
  - NumberTheory/Math/Extended_euclid.h
  isVerificationFile: false
  path: NumberTheory/Math/Combination.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - NumberTheory/Yosupo/Binomial_coefficient_prime_mod.test.cpp
documentation_of: NumberTheory/Math/Combination.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Combination.h
- /library/NumberTheory/Math/Combination.h.html
title: NumberTheory/Math/Combination.h
---
