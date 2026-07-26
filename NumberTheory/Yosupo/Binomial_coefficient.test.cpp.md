---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: NumberTheory/Math/Binary_exponentiation.h
    title: NumberTheory/Math/Binary_exponentiation.h
  - icon: ':x:'
    path: NumberTheory/Math/Combination_any_mod.h
    title: NumberTheory/Math/Combination_any_mod.h
  - icon: ':x:'
    path: NumberTheory/Math/Factorization.h
    title: NumberTheory/Math/Factorization.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient
  bundledCode: "#line 1 \"NumberTheory/Yosupo/Binomial_coefficient.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient\"\r\n\r\n#line\
    \ 2 \"template.h\"\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n \r\
    \n#define ll long long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\
    \n#define unique(x) x.erase(unique(all(x)), x.end())\r\n#define INF32 ((1ull<<31)-1)\r\
    \n#define INF64 ((1ull<<63)-1)\r\n#define inf (ll)1e18\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main(){\r\n   \
    \ ios_base::sync_with_stdio(false);cin.tie(NULL);\r\n    // cin.exceptions(cin.failbit);\r\
    \n    // int t; cin >> t;\r\n    // while(t--)\r\n        solve();\r\n    cerr\
    \ << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\r\
    \n    return 0;\r\n}\n#line 2 \"NumberTheory/Math/Binary_exponentiation.h\"\n\r\
    \nusing u128 = __uint128_t;\r\nusing i128 = __int128;\r\n\r\nll binMul(ll a, ll\
    \ b, ll M) { return (i128)a * b % M; }\r\n\r\n// long double trick\r\n// require:\
    \ mantissa 64 bit, x86 gcc/clang\r\nll binMul2(ll a, ll b, ll M) {\r\n    ll q\
    \ = (ll)((long double)a * b / M);\r\n    ll r = (ll)((unsigned ll)a * b - (unsigned\
    \ ll)q * M);\r\n    return r < 0 ? r + M : (r >= M ? r - M : r);\r\n}\r\n\r\n\
    ll binMul3(ll a, ll b, ll M) {\r\n    unsigned long long ua = a % M, um = M, res\
    \ = 0;\r\n    while (b) {\r\n        if (b & 1) { res += ua; if (res >= um) res\
    \ -= um; }\r\n        ua <<= 1; if (ua >= um) ua -= um;\r\n        b >>= 1;\r\n\
    \    }\r\n    return res;\r\n}\r\n\r\nll binPow(ll a, ll b, ll M) {\r\n    a %=\
    \ M;\r\n    ll res = 1 % M;\r\n    while (b) {\r\n        if (b & 1) res = (i128)res\
    \ * a % M;\r\n        a = (i128)a * a % M;\r\n        b /= 2;\r\n    }\r\n   \
    \ return res;\r\n}\n#line 2 \"NumberTheory/Math/Factorization.h\"\n\r\n\r\n//\
    \ 360 -> [2, 2, 2, 3, 3, 5]\r\nvector<ll> primeFactor(ll n) {\r\n    vector<ll>\
    \ factor;\r\n    for (int i : {2, 3, 5}) {\r\n        while (n % i == 0) {\r\n\
    \            n /= i;\r\n            factor.push_back(i);\r\n        }\r\n    }\r\
    \n    int inc[] = {4, 2, 4, 2, 4, 6, 2, 6};\r\n    int j = 0;\r\n    ll lim =\
    \ sqrtl(n);\r\n    while (lim > 0 && lim > n / lim) lim--;\r\n    for (ll i =\
    \ 7; i <= lim; i += inc[j%8], j++) {\r\n        if (n % i) continue;\r\n     \
    \   while(n % i == 0) {\r\n            n /= i;\r\n            factor.push_back(i);\r\
    \n        }\r\n        lim = sqrtl(n);\r\n        while (lim > 0 && lim > n /\
    \ lim) lim--;\r\n    }\r\n    if (n > 1) factor.push_back(n);\r\n    return factor;\r\
    \n}\r\n\r\n// [2, 2, 2, 3, 3, 5] -> [(2,3), (3,2), (5,1)]\r\nvector<pll> primeFactorPow(ll\
    \ n) {\r\n    vector<pll> res;\r\n    for (ll p : primeFactor(n))\r\n        if\
    \ (!res.empty() && res.back().fi == p) res.back().se++;\r\n        else res.push_back({p,\
    \ 1});\r\n    return res;\r\n}\n#line 4 \"NumberTheory/Math/Combination_any_mod.h\"\
    \n\r\n\r\n// https://codeforces.com/blog/entry/116681\r\n// https://wiki.vnoi.info/translate/he/Lucas-theorem\r\
    \n// Extended Lucas (granville theorem)\r\n// C(n, k) % m when m is NOT prime\r\
    \n//\r\n// Step 1: cut m into prime powers\r\n//    m = p1^e1 * p2^e2 * ...\r\n\
    // => solve C(n, k) % p^e for each one, then glue them back by CRT\r\n// CRT works\
    \ here because p1^e1, p2^e2, ... are pairwise coprime\r\n//\r\n// Step 2: solve\
    \ one p^e\r\n// write each factorial as n! = p^t * a with gcd(a, p) = 1\r\n//\
    \ => t counts how many times p divides n!, a is everything else\r\n// a holds\
    \ no factor p, so a is ALWAYS invertible mod p^e\r\n//    C(n, k) = p^E * a(n)\
    \ / (a(k) * a(n-k))\r\n//    E = t(n) - t(k) - t(n-k)\r\n// => E >= e means p^e\
    \ divides C(n, k), so the answer is 0\r\n//\r\n// Step 3: how to get t (legendre\
    \ formula)\r\n//    t = n/p + n/p^2 + n/p^3 + ...     (integer division, stop\
    \ when it hits 0)\r\n//\r\n// Step 4: how to get a\r\n// split off the multiples\
    \ of p first\r\n//    n! = p^(n/p) * (n/p)! * n!_p\r\n// with n!_p = product of\
    \ j in [1, n] that p does not divide\r\n// => repeat on (n/p)! until it becomes\
    \ 0, that is log_p(n) rounds\r\n//\r\n// n!_p is easy because the units repeat\
    \ with period p^e\r\n//    n!_p = ((p^e - 1)!_p)^(n / p^e) * (n % p^e)!_p\r\n\
    // (p^e - 1)!_p is the product of every unit mod p^e\r\n// by wilson theorem it\
    \ is -1 when p is odd or p^e = 2 or 4, and +1 otherwise\r\n// => it is always\
    \ +1 or -1, so only the parity of n / p^e matters, no binPow needed\r\n//\r\n\
    // Example m = 10 = 2 * 5, C(4, 2) = 6\r\n//    p = 2: t(4) = 3, t(2) = 1, t(2)\
    \ = 1 => E = 1 >= e = 1 => 0\r\n//    p = 5: t are all 0 => E = 0\r\n//      \
    \     a(4) = 4, a(2) = 2 => 4 * 2^-1 * 2^-1 = 4 * 3 * 3 = 1 (mod 5)\r\n//    CRT:\
    \ x = 0 (mod 2), x = 1 (mod 5) => x = 6, and 6 % 10 = 6\r\n\r\n\r\n// C(n, k)\
    \ % p^e\r\n// O(p^e) build and memory, O(log n) per query, require p^e <= 1e7\r\
    \nstruct CombPrimePower {\r\n    ll p, e, pe, phi, unit;\r\n    vector<ll> f,\
    \ pw;   // f[i] = prod of j in [1, i] with p not dividing j, % pe\r\n        \
    \                // pw[i] = p^i % pe\r\n    // every value here is < pe <= 1e7\
    \ so products stay under 1e14, plain ll is enough\r\n\r\n    CombPrimePower()\
    \ {}\r\n    CombPrimePower(ll _p, ll _e) : p(_p), e(_e) {\r\n        pe = 1;\r\
    \n        for (ll i = 0; i < e; i++) pe *= p;\r\n        phi = pe - pe / p;  \
    \                // a^-1 = binPow(a, phi-1, pe)\r\n        f.resize(pe);\r\n \
    \       f[0] = 1 % pe;\r\n        for (ll i = 1; i < pe; i++) f[i] = (i % p ==\
    \ 0) ? f[i-1] : f[i-1] * i % pe;\r\n        unit = f[pe-1];                  \
    \   // +1 or -1, so only parity matters in fact()\r\n        pw.resize(e+1);\r\
    \n        pw[0] = 1 % pe;\r\n        for (ll i = 1; i <= e; i++) pw[i] = pw[i-1]\
    \ * p % pe;\r\n    }\r\n\r\n    // kept apart from fact() on purpose: it is the\
    \ cheap half, and letting comb()\r\n    // bail out on it first skips 3 fact()\
    \ calls, worth 3x on m with many factors\r\n    ll expo(ll n) {\r\n        ll\
    \ t = 0;\r\n        while (n > 0) {\r\n            n /= p;\r\n            t +=\
    \ n;\r\n        }\r\n        return t;\r\n    }\r\n\r\n    // same as factmod()\
    \ in Factorial.h but for p^e instead of p\r\n    ll fact(ll n) {\r\n        ll\
    \ a = 1 % pe;\r\n        while (n > 0) {\r\n            if ((n / pe) & 1) a =\
    \ a * unit % pe;\r\n            a = a * f[n % pe] % pe;\r\n            n /= p;\r\
    \n        }\r\n        return a;\r\n    }\r\n\r\n    ll comb(ll n, ll k) {\r\n\
    \        if (k < 0 || k > n) return 0;\r\n        ll E = expo(n) - expo(k) - expo(n-k);\r\
    \n        if (E >= e) return 0;\r\n        ll d = fact(k) * fact(n-k) % pe;  \
    \  // multiply first, one inverse instead of two\r\n        return fact(n) * binPow(d,\
    \ phi-1, pe) % pe * pw[E] % pe;\r\n    }\r\n};\r\n\r\n// C(n, k) % m for any m\r\
    \n// O(m) build and memory, O(log^2 n) per query, require every p^e <= 1e7\r\n\
    struct CombAnyMod {\r\n    ll m;\r\n    vector<CombPrimePower> pp;\r\n    vector<ll>\
    \ w;   // CRT weight, w[i] = M_i * (M_i^-1 % pe_i) % m with M_i = m / pe_i\r\n\
    \r\n    CombAnyMod() {}\r\n    CombAnyMod(ll _m) : m(_m) {\r\n        for (pll\
    \ pe : primeFactorPow(m)) pp.push_back(CombPrimePower(pe.fi, pe.se));\r\n    \
    \    for (CombPrimePower &c : pp) {      // w does not depend on n, k\r\n    \
    \        ll M = m / c.pe;\r\n            w.push_back((i128)M * binPow(M % c.pe,\
    \ c.phi - 1, c.pe) % m);\r\n        }\r\n    }\r\n\r\n    ll comb(ll n, ll k)\
    \ {\r\n        ll res = 0;\r\n        for (int i = 0; i < (int)pp.size(); i++)\
    \ {\r\n            ll a = pp[i].comb(n, k);\r\n            if (a) res = (res +\
    \ (i128)a * w[i] % m) % m;\r\n        }\r\n        return res;\r\n    }\r\n};\n\
    #line 5 \"NumberTheory/Yosupo/Binomial_coefficient.test.cpp\"\n\r\nvoid solve()\
    \ {\r\n    int t; ll m; cin >> t >> m;\r\n    CombAnyMod C(m);\r\n    while (t--)\
    \ {\r\n        ll n, k; cin >> n >> k;\r\n        cout << C.comb(n, k) << '\\\
    n';\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient\"\r\
    \n\r\n#include \"../../template.h\"\r\n#include \"../Math/Combination_any_mod.h\"\
    \r\n\r\nvoid solve() {\r\n    int t; ll m; cin >> t >> m;\r\n    CombAnyMod C(m);\r\
    \n    while (t--) {\r\n        ll n, k; cin >> n >> k;\r\n        cout << C.comb(n,\
    \ k) << '\\n';\r\n    }\r\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/Combination_any_mod.h
  - NumberTheory/Math/Binary_exponentiation.h
  - NumberTheory/Math/Factorization.h
  isVerificationFile: true
  path: NumberTheory/Yosupo/Binomial_coefficient.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 14:40:30+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: NumberTheory/Yosupo/Binomial_coefficient.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Yosupo/Binomial_coefficient.test.cpp
- /verify/NumberTheory/Yosupo/Binomial_coefficient.test.cpp.html
title: NumberTheory/Yosupo/Binomial_coefficient.test.cpp
---
