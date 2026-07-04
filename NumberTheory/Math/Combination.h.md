---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Misc/ModInt.h
    title: Misc/ModInt.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Binary_exponentiation.h
    title: NumberTheory/Math/Binary_exponentiation.h
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
    \ 0;\n}\n#line 2 \"Misc/ModInt.h\"\n\ntemplate <int32_t mod>\nstruct ModInt {\n\
    \    int32_t x;\n\n    ModInt(): x(0) {}\n    ModInt(int32_t _x): x(_x % mod)\
    \ { x = x < 0 ? x + mod : x; }\n\n    ModInt &operator += (const ModInt &p) {\n\
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
    \ x; }\n    static constexpr int32_t get_mod() { return mod; }\n};\n#line 2 \"\
    NumberTheory/Math/Binary_exponentiation.h\"\n\nusing u128 = __uint128_t;\nusing\
    \ i128 = __int128;\n\nll binMul(ll a, ll b, ll M) {\n    a = a % M;\n    ll res\
    \ = 0;\n    while (b) {\n        if (b & 1) res = (res + a) % M;\n        a =\
    \ a * 2 % M;\n        b /= 2;\n    }\n    return res;\n}\n\nll binPow(ll a, ll\
    \ b, ll M) {\n    a %= M;\n    ll res = 1;\n    while (b) {\n        if (b & 1)\
    \ res = (i128)res * a % M;\n        a = (i128)a * a % M;\n        b /= 2;\n  \
    \  }\n    return res;\n}\n#line 4 \"NumberTheory/Math/Combination.h\"\n\n// This\
    \ modint only work for MOD is prime cuz using modulo inverse\nusing mint = ModInt<MOD>;\n\
    \n// vector<mint> fact;\n\n// void preprocess() {\n//     fact[0] = 1;\n//   \
    \  for (int i = 1; i < (int)fact.size(); i++) {\n//         fact[i] = fact[i-1]\
    \ * i;\n//     }\n// }\n\n// mint comb(int n, int k) {\n//     if (k < 0 || k\
    \ > n) return 0; \n//     return fact[n] / (fact[n-k] * fact[k]);\n// }\n\n\n\
    // Using for n * k <= 1e7 or n,k <= 5000, O(1) per operation\nvector<vector<int>>\
    \ preprocess(int n, int k, int m) {\n    vector<vector<int>> C(n+1, vector<int>(k+1));\n\
    \    for (int i = 0; i <= n; i++) {\n        C[i][0] = 1;\n        for (int j\
    \ = 1; j <= min(i, k); j++) {\n            C[i][j] = (C[i-1][j-1] + C[i-1][j])\
    \ % m;\n        }\n    }\n    return C;\n}\n\n// Using for n, k <= 1e6, MOD is\
    \ prime\nconst int N = 1e6 + 6;\nvector<ll> fact(N), inv(N), invFact(N);\n\nvoid\
    \ preprocess() {\n    fact[0] = 1;\n    for (int i = 1; i < N; i++) {\n      \
    \  fact[i] = fact[i-1] * i % MOD;\n    }\n    invFact[0] = invFact[1] = 1;\n \
    \   inv[1] = 1;\n    for(int i = 2; i < N; i++) {\n        inv[i] = MOD - (ll)(MOD/i)\
    \ * inv[MOD%i] % MOD;\n        invFact[i] = invFact[i-1] * inv[i] % MOD;\n   \
    \ }\n    // Optional\n    // invFact[N-1] = binPow(fact[N-1], MOD-2, MOD);\n \
    \   // for (int i = N-2; i >= 0; i--) {\n    //     invFact[i] = invFact[i+1]\
    \ * (i + 1) % MOD;\n    // }\n}\n\n// m must be prime\n// fermat's little theorem\
    \ a^(m-2) \u2261 a^(-1)\nll inverse1(ll a, ll m) { return binPow(a, m-2, m); }\n\
    // m coprime to a, gcd(a, m) = 1\n// base on extended euclid trick\nll inverse2(ll\
    \ a, ll m) { return a <= 1 ? a : m-m/a * inverse2(m % a, m) % m; }\n\nll comb(int\
    \ n, int k) {\n    if (k < 0 || k > n) return 0;\n    // ll t = binMul(fact[k],\
    \ fact[n-k], MOD);\n    // return fact[n] * inverse2(t, MOD) % MOD;\n    return\
    \ fact[n] * invFact[k] % MOD * invFact[n-k] % MOD;\n}\n"
  code: "#include \"../../template.h\"\n#include \"../../Misc/ModInt.h\"\n#include\
    \ \"Binary_exponentiation.h\"\n\n// This modint only work for MOD is prime cuz\
    \ using modulo inverse\nusing mint = ModInt<MOD>;\n\n// vector<mint> fact;\n\n\
    // void preprocess() {\n//     fact[0] = 1;\n//     for (int i = 1; i < (int)fact.size();\
    \ i++) {\n//         fact[i] = fact[i-1] * i;\n//     }\n// }\n\n// mint comb(int\
    \ n, int k) {\n//     if (k < 0 || k > n) return 0; \n//     return fact[n] /\
    \ (fact[n-k] * fact[k]);\n// }\n\n\n// Using for n * k <= 1e7 or n,k <= 5000,\
    \ O(1) per operation\nvector<vector<int>> preprocess(int n, int k, int m) {\n\
    \    vector<vector<int>> C(n+1, vector<int>(k+1));\n    for (int i = 0; i <= n;\
    \ i++) {\n        C[i][0] = 1;\n        for (int j = 1; j <= min(i, k); j++) {\n\
    \            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % m;\n        }\n    }\n    return\
    \ C;\n}\n\n// Using for n, k <= 1e6, MOD is prime\nconst int N = 1e6 + 6;\nvector<ll>\
    \ fact(N), inv(N), invFact(N);\n\nvoid preprocess() {\n    fact[0] = 1;\n    for\
    \ (int i = 1; i < N; i++) {\n        fact[i] = fact[i-1] * i % MOD;\n    }\n \
    \   invFact[0] = invFact[1] = 1;\n    inv[1] = 1;\n    for(int i = 2; i < N; i++)\
    \ {\n        inv[i] = MOD - (ll)(MOD/i) * inv[MOD%i] % MOD;\n        invFact[i]\
    \ = invFact[i-1] * inv[i] % MOD;\n    }\n    // Optional\n    // invFact[N-1]\
    \ = binPow(fact[N-1], MOD-2, MOD);\n    // for (int i = N-2; i >= 0; i--) {\n\
    \    //     invFact[i] = invFact[i+1] * (i + 1) % MOD;\n    // }\n}\n\n// m must\
    \ be prime\n// fermat's little theorem a^(m-2) \u2261 a^(-1)\nll inverse1(ll a,\
    \ ll m) { return binPow(a, m-2, m); }\n// m coprime to a, gcd(a, m) = 1\n// base\
    \ on extended euclid trick\nll inverse2(ll a, ll m) { return a <= 1 ? a : m-m/a\
    \ * inverse2(m % a, m) % m; }\n\nll comb(int n, int k) {\n    if (k < 0 || k >\
    \ n) return 0;\n    // ll t = binMul(fact[k], fact[n-k], MOD);\n    // return\
    \ fact[n] * inverse2(t, MOD) % MOD;\n    return fact[n] * invFact[k] % MOD * invFact[n-k]\
    \ % MOD;\n}"
  dependsOn:
  - template.h
  - Misc/ModInt.h
  - NumberTheory/Math/Binary_exponentiation.h
  isVerificationFile: false
  path: NumberTheory/Math/Combination.h
  requiredBy: []
  timestamp: '2026-07-04 22:16:55+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NumberTheory/Math/Combination.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Combination.h
- /library/NumberTheory/Math/Combination.h.html
title: NumberTheory/Math/Combination.h
---
