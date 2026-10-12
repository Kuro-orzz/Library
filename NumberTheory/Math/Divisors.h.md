---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Binary_exponentiation.h
    title: NumberTheory/Math/Binary_exponentiation.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/MillerRabin.h
    title: NumberTheory/Math/MillerRabin.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Sieve.h
    title: NumberTheory/Math/Sieve.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Yosupo/Unit_test_math.test.cpp
    title: NumberTheory/Yosupo/Unit_test_math.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/gym/100753
    - https://usaco.guide/problems/cses-1082-sum-of-divisors/solution
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
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"NumberTheory/Math/Binary_exponentiation.h\"\
    \n\r\nusing u128 = __uint128_t;\r\nusing i128 = __int128;\r\n\r\nll binMul(ll\
    \ a, ll b, ll M) { return (i128)a * b % M; }\r\n\r\n// long double trick\r\n//\
    \ require: mantissa 64 bit, x86 gcc/clang\r\nll binMul2(ll a, ll b, ll M) {\r\n\
    \    ll q = (ll)((long double)a * b / M);\r\n    ll r = (ll)((unsigned ll)a *\
    \ b - (unsigned ll)q * M);\r\n    return r < 0 ? r + M : (r >= M ? r - M : r);\r\
    \n}\r\n\r\nll binMul3(ll a, ll b, ll M) {\r\n    unsigned long long ua = a % M,\
    \ um = M, res = 0;\r\n    while (b) {\r\n        if (b & 1) { res += ua; if (res\
    \ >= um) res -= um; }\r\n        ua <<= 1; if (ua >= um) ua -= um;\r\n       \
    \ b >>= 1;\r\n    }\r\n    return res;\r\n}\r\n\r\nll binPow(ll a, ll b, ll M)\
    \ {\r\n    a %= M;\r\n    ll res = 1 % M;\r\n    while (b) {\r\n        if (b\
    \ & 1) res = (i128)res * a % M;\r\n        a = (i128)a * a % M;\r\n        b /=\
    \ 2;\r\n    }\r\n    return res;\r\n}\n#line 3 \"NumberTheory/Math/MillerRabin.h\"\
    \n\r\n\r\nbool millerTest(ll a, ll n, ll k, ll m) {\r\n    ll mod = binPow(a,\
    \ m, n);\r\n    if (mod == 1 || mod == n - 1) return true;\r\n    for (int l =\
    \ 1; l < k; l++) {\r\n        mod = (u128)mod * mod % n;\r\n        if (mod ==\
    \ n - 1) return true;\r\n    }\r\n    return false;\r\n}\r\n\r\n// Miller rabin\r\
    \nbool MillerRabin0(ll n) {\r\n    if (n < 4) return n == 2 || n == 3;\r\n   \
    \ if (n % 2 == 0) return false;\r\n    ll k = 0, m = n - 1;\r\n    while(m % 2\
    \ == 0) {\r\n        m /= 2;\r\n        k++;\r\n    }\r\n    for (int i = 0; i\
    \ < 5; i++) {\r\n        ll a = get_rand(n-3) + 2;\r\n        if (!millerTest(a,\
    \ n, k, m)) return false;\r\n    }\r\n    return true;\r\n}\r\n\r\n// Miller Rabin\
    \ deterministic version\r\nbool MillerRabin(ll n) {\r\n    if (n <= 1) return\
    \ false;\r\n    ll k = 0, m = n-1;\r\n    while (m % 2 == 0) {\r\n        m /=\
    \ 2;\r\n        k++;\r\n    }\r\n    for (int a : {2, 3, 5, 7, 11, 13, 17, 19,\
    \ 23, 29, 31, 37}) {\r\n        if (n == a) return true;\r\n        if (!millerTest(a,\
    \ n, k, m)) return false;\r\n    }\r\n    return true;\r\n}\n#line 2 \"NumberTheory/Math/Sieve.h\"\
    \n\r\nvector<int> sieve(int n) {\r\n    vector<int> nt(n+1, 1);\r\n    nt[0] =\
    \ nt[1] = 0;\r\n    for (int i = 2; i * i <= n; i++) {\r\n        if (!nt[i])\
    \ continue;\r\n        for (int j = i * i; j <= n; j += i)\r\n            nt[j]\
    \ = 0;\r\n    }\r\n    return nt;\r\n}\r\n\r\nvector<int> segmentSieve(ll l, ll\
    \ r){\r\n    ll sq = sqrtl(r);\r\n    while (sq * sq > r) sq--;\r\n    while (sq+1\
    \ <= r/(sq+1)) sq++;\r\n    vector<int> small(sq+1, 1);\r\n    for (ll i = 2;\
    \ i*i <= sq; i++) {\r\n        if (!small[i]) continue;\r\n        for (ll j =\
    \ i*i; j <= sq; j += i) {\r\n            small[j] = 0;\r\n        }\r\n    }\r\
    \n    vector<int> prime(r-l+1, 1);\r\n    for(ll p = 2; p <= sq; p++){\r\n   \
    \     if (!small[p]) continue;\r\n        ll lim = max(p*p, (l+p-1)/p*p);\r\n\
    \        for(ll j = lim; j <= r; j += p) {\r\n            prime[j-l] = 0;\r\n\
    \        }\r\n    }\r\n    if (l == 0) prime[0] = 0;\r\n    if (l == 0 && r >\
    \ l) prime[1] = 0;\r\n    if (l == 1) prime[1-l] = 0;\r\n    return prime;\r\n\
    }\r\n\r\nvector<int> listPrime(int l, int r) {\r\n    vector<int> prime = segmentSieve(l,\
    \ r);\r\n    vector<int> listPi;\r\n    for (int i = l; i <= r; i++) {\r\n   \
    \     if (prime[i-l]) listPi.push_back(i);\r\n    }\r\n    return listPi;\r\n\
    }\r\n\r\nvector<int> sieve_count_divisors(int n) {\r\n    vector<int> divisors(n+1,\
    \ 0);\r\n    for (ll i = 1; i*i <= n; i++) {\r\n        for (ll j = i*i; j <=\
    \ n; j += i) {\r\n            divisors[j] += 2;\r\n        }\r\n        divisors[i*i]--;\r\
    \n    }\r\n    return divisors;\r\n}\r\n\r\nvector<int> sieve_sum_divisors(int\
    \ n) {\r\n    vector<int> sumDiv(n+1, 0);\r\n    for (int i = 1; i*i <= n; i++)\
    \ {\r\n        for (int j = i*i; j <= n; j += i) {\r\n            sumDiv[j] +=\
    \ i;\r\n            if (i*i != j) sumDiv[j] += j/i;\r\n        }\r\n    }\r\n\
    \    return sumDiv;\r\n}\r\n\r\nvector<int> segmentSieveDivisors(int l, int r){\r\
    \n    vector<int> div(r-l+1, 0);\r\n    for(ll i = 1; i*i <= r; i++){\r\n    \
    \    ll lim = max(i*i, (l+i-1)/i*i);\r\n        for(ll j = lim; j <= r; j += i)\
    \ {\r\n            div[j-l] += 2;\r\n        }\r\n        if (i * i >= l) div[i*i-l]--;\r\
    \n    }\r\n    if (l == 0) div[0] = 0;\r\n    return div;\r\n}\r\n\r\nvector<vector<int>>\
    \ sieve_prime_divisors(int n) {\r\n    vector<int> prime = sieve(n);\r\n    vector<vector<int>>\
    \ div(n+1);\r\n    for (int i = 2; i <= n; i++) {\r\n        if (!prime[i]) continue;\r\
    \n        for (int j = i; j <= n; j += i) {\r\n            div[j].push_back(i);\r\
    \n        }\r\n    }\r\n    return div;\r\n}\n#line 4 \"NumberTheory/Math/Divisors.h\"\
    \n\r\nusing u128 = __uint128_t;\r\n\r\n// sum of all divisor [1, n]\r\n// https://usaco.guide/problems/cses-1082-sum-of-divisors/solution\r\
    \nll sum_of_divisor(ll n) {\r\n    ll res = 0, i = 1;\r\n    while (i <= n) {\r\
    \n        ll l = i;\r\n        ll r = n / (n / i);\r\n        ll val = n / l;\r\
    \n        ll csc = (u128)(r - l + 1) * (l + r) / 2 % MOD;\r\n        res = (res\
    \ + csc * val) % MOD;\r\n        i = r + 1;\r\n    }\r\n    return res;\r\n}\r\
    \n\r\n// count number of divisor up to n <= 1e18\r\n// AC: https://codeforces.com/gym/100753\
    \ (Probblem F)\r\nint count_divisor(ll n) {\r\n    if (n == 1) return 1;\r\n \
    \   static vector<int> prime = listPrime(1, 1e6+5);\r\n    int ans = 1;\r\n  \
    \  for (int p : prime) {\r\n        if (1ll * p * p * p > n) break;\r\n      \
    \  int cnt = 0;\r\n        while (n % p == 0) {\r\n            n /= p;\r\n   \
    \         cnt++;\r\n        }\r\n        ans *= cnt + 1;\r\n    }\r\n    auto\
    \ isSqrt = [&](ll n)->bool {\r\n        ll c = sqrtl(n);\r\n        return c *\
    \ c == n;\r\n    };\r\n    if (n == 1) return ans;\r\n    if (MillerRabin(n))\
    \ ans *= 2;\r\n    else if (isSqrt(n)) ans *= 3;\r\n    else ans *= 4;\r\n   \
    \ return ans;\r\n}\n"
  code: "#include \"../../template.h\"\r\n#include \"MillerRabin.h\"\r\n#include \"\
    Sieve.h\"\r\n\r\nusing u128 = __uint128_t;\r\n\r\n// sum of all divisor [1, n]\r\
    \n// https://usaco.guide/problems/cses-1082-sum-of-divisors/solution\r\nll sum_of_divisor(ll\
    \ n) {\r\n    ll res = 0, i = 1;\r\n    while (i <= n) {\r\n        ll l = i;\r\
    \n        ll r = n / (n / i);\r\n        ll val = n / l;\r\n        ll csc = (u128)(r\
    \ - l + 1) * (l + r) / 2 % MOD;\r\n        res = (res + csc * val) % MOD;\r\n\
    \        i = r + 1;\r\n    }\r\n    return res;\r\n}\r\n\r\n// count number of\
    \ divisor up to n <= 1e18\r\n// AC: https://codeforces.com/gym/100753 (Probblem\
    \ F)\r\nint count_divisor(ll n) {\r\n    if (n == 1) return 1;\r\n    static vector<int>\
    \ prime = listPrime(1, 1e6+5);\r\n    int ans = 1;\r\n    for (int p : prime)\
    \ {\r\n        if (1ll * p * p * p > n) break;\r\n        int cnt = 0;\r\n   \
    \     while (n % p == 0) {\r\n            n /= p;\r\n            cnt++;\r\n  \
    \      }\r\n        ans *= cnt + 1;\r\n    }\r\n    auto isSqrt = [&](ll n)->bool\
    \ {\r\n        ll c = sqrtl(n);\r\n        return c * c == n;\r\n    };\r\n  \
    \  if (n == 1) return ans;\r\n    if (MillerRabin(n)) ans *= 2;\r\n    else if\
    \ (isSqrt(n)) ans *= 3;\r\n    else ans *= 4;\r\n    return ans;\r\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/MillerRabin.h
  - NumberTheory/Math/Binary_exponentiation.h
  - NumberTheory/Math/Sieve.h
  isVerificationFile: false
  path: NumberTheory/Math/Divisors.h
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - NumberTheory/Yosupo/Unit_test_math.test.cpp
documentation_of: NumberTheory/Math/Divisors.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Divisors.h
- /library/NumberTheory/Math/Divisors.h.html
title: NumberTheory/Math/Divisors.h
---
