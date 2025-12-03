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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/gym/100753
    - https://usaco.guide/problems/cses-1082-sum-of-divisors/solution
  bundledCode: "#line 2 \"template.h\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n \n#define ll long long\n#define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n\
    #define INF64 ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n\
    #define pii pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define\
    \ se second\n\nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n  \
    \  ios_base::sync_with_stdio(false);cin.tie(NULL);\n    // cin.exceptions(cin.failbit);\n\
    \    // int t; cin >> t;\n    // while(t--)\n        solve();\n    cerr << \"\\\
    nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC << \"ms\" << '\\n';\n    return\
    \ 0;\n}\n#line 2 \"NumberTheory/Math/Binary_exponentiation.h\"\n\nusing u128 =\
    \ __uint128_t;\nusing i128 = __int128;\n\nll binMul(ll a, ll b, ll M) {\n    a\
    \ = a % M;\n    ll res = 0;\n    while (b) {\n        if (b & 1) res = (res +\
    \ a) % M;\n        a = a * 2 % M;\n        b /= 2;\n    }\n    return res;\n}\n\
    \nll binPow(ll a, ll b, ll M) {\n    a %= M;\n    ll res = 1;\n    while (b) {\n\
    \        if (b & 1) res = (i128)res * a % M;\n        a = (i128)a * a % M;\n \
    \       b /= 2;\n    }\n    return res;\n}\n#line 3 \"NumberTheory/Math/MillerRabin.h\"\
    \n\nbool test(ll a, ll n, ll k, ll m) {\n    ll mod = binPow(a, m, n);\n    if\
    \ (mod == 1 || mod == n - 1) return true;\n    for (int l = 1; l < k; l++) {\n\
    \        mod = (u128)mod * mod % n;\n        if (mod == n - 1) return true;\n\
    \    }\n    return false;\n}\n\n// Miller rabin\nbool MillerRabin0(ll n) {\n \
    \   if (n == 2) return true;\n    if (n < 2 || n % 2 == 0) return false;\n   \
    \ ll k = 0, m = n - 1;\n    while(m % 2 == 0) {\n        m /= 2;\n        k++;\n\
    \    }\n    for (int i = 0; i < 5; i++) {\n        ll a = rand() % (n - 3) + 2;\n\
    \        if (!test(a, n, k, m)) return false;\n    }\n    return true;\n}\n\n\
    // Miller Rabin deterministic version\nbool MillerRabin(ll n) {\n    if (n <=\
    \ 1) return false;\n    ll k = 0, m = n-1;\n    while (m % 2 == 0) {\n       \
    \ m /= 2;\n        k++;\n    }\n    for (int a : {2, 3, 5, 7, 11, 13, 17, 19,\
    \ 23, 29, 31, 37}) {\n        if (n == a) return true;\n        if (!test(a, n,\
    \ k, m)) return false;\n    }\n    return true;\n}\n#line 2 \"NumberTheory/Math/Sieve.h\"\
    \n\nvector<int> sieve(int n) {\n    vector<int> nt(n+1, 1);\n    nt[0] = nt[1]\
    \ = 0;\n    for (int i = 2; i * i <= n; i++) {\n        if (!nt[i]) continue;\n\
    \        for (int j = i * i; j <= n; j += i)\n            nt[j] = 0;\n    }\n\
    \    return nt;\n}\n\nvector<int> segmentSieve(int l, int r){\n    vector<int>\
    \ prime(r-l+1, 1);\n    for(ll p = 2; p*p <= r; p++){\n        ll lim = max(p*p,\
    \ (l+p-1)/p*p);\n        for(ll j = lim; j <= r; j += p)\n            if (j-l\
    \ >= 0) prime[j-l] = 0;\n    }\n    if (l == 0) prime[0] = 0;\n    if (l == 0\
    \ && r > l) prime[1] = 0;\n    if (l == 1) prime[1-l] = 0;\n    return prime;\n\
    }\n\nvector<int> listPrime(int l, int r) {\n    vector<int> prime = segmentSieve(l,\
    \ r);\n    vector<int> listPi;\n    for (int i = l; i <= r; i++) {\n        if\
    \ (prime[i-l]) listPi.push_back(i);\n    }\n    return listPi;\n}\n\nvector<int>\
    \ sieve_count_divisors(int n) {\n    vector<int> divisors(n+1, 0);\n    for (int\
    \ i = 1; i*i <= n; i++) {\n        for (int j = i; j <= n; j += i) {\n       \
    \     divisors[j]++;\n        }\n        divisors[i*i]--;\n    }\n    return divisors;\n\
    }\n\nvector<int> sieve_sum_divisors(int n) {\n    vector<int> sumDiv(n+1, 0);\n\
    \    for (int i = 1; i*i <= n; i++) {\n        for (int j = i; j <= n; j += i)\
    \ {\n            sumDiv[j] += i;\n            if (i*i != j) sumDiv[j] += j/i;\n\
    \        }\n    }\n    return sumDiv;\n}\n\nvector<vector<int>> sieve__prime_divisors(int\
    \ n) {\n    vector<int> prime = sieve(n);\n    vector<vector<int>> div(n+1);\n\
    \    for (int i = 2; i <= n; i++) {\n        if (!prime[i]) continue;\n      \
    \  for (int j = i; j <= n; j += i) {\n            div[j].push_back(i);\n     \
    \   }\n    }\n    return div;\n}\n#line 4 \"NumberTheory/Math/Divisors.h\"\n\n\
    using u128 = __uint128_t;\n\n// sum of all divisor [1, n]\n// https://usaco.guide/problems/cses-1082-sum-of-divisors/solution\n\
    ll sum_of_divisor(ll n) {\n    ll res = 0, i = 1;\n    while (i <= n) {\n    \
    \    ll l = i;\n        ll r = n / (n / i);\n        ll val = n / l;\n       \
    \ ll csc = (u128)(r - l + 1) * (l + r) / 2 % MOD;\n        res = (res + csc *\
    \ val) % MOD;\n        i = r + 1;\n    }\n    return res;\n}\n\n// count number\
    \ of divisor up to n <= 1e18\n// AC: https://codeforces.com/gym/100753 (Probblem\
    \ F)\nint count_divisor(ll n) {\n    if (n == 1) return 1;\n    vector<int> prime\
    \ = listPrime(1, 1e6+5);\n    int ans = 1;\n    for (int p : prime) {\n      \
    \  if (1ll * p * p * p > n) break;\n        int cnt = 0;\n        while (n % p\
    \ == 0) {\n            n /= p;\n            cnt++;\n        }\n        ans *=\
    \ cnt + 1;\n    }\n    auto isSqrt = [&](ll n)->bool {\n        ll c = sqrtl(n);\n\
    \        return c * c == n;\n    };\n    if (n == 1) return ans;\n    if (MillerRabin(n))\
    \ ans *= 2;\n    else if (isSqrt(n)) ans *= 3;\n    else ans *= 4;\n    return\
    \ ans;\n}\n"
  code: "#include \"../../template.h\"\n#include \"MillerRabin.h\"\n#include \"Sieve.h\"\
    \n\nusing u128 = __uint128_t;\n\n// sum of all divisor [1, n]\n// https://usaco.guide/problems/cses-1082-sum-of-divisors/solution\n\
    ll sum_of_divisor(ll n) {\n    ll res = 0, i = 1;\n    while (i <= n) {\n    \
    \    ll l = i;\n        ll r = n / (n / i);\n        ll val = n / l;\n       \
    \ ll csc = (u128)(r - l + 1) * (l + r) / 2 % MOD;\n        res = (res + csc *\
    \ val) % MOD;\n        i = r + 1;\n    }\n    return res;\n}\n\n// count number\
    \ of divisor up to n <= 1e18\n// AC: https://codeforces.com/gym/100753 (Probblem\
    \ F)\nint count_divisor(ll n) {\n    if (n == 1) return 1;\n    vector<int> prime\
    \ = listPrime(1, 1e6+5);\n    int ans = 1;\n    for (int p : prime) {\n      \
    \  if (1ll * p * p * p > n) break;\n        int cnt = 0;\n        while (n % p\
    \ == 0) {\n            n /= p;\n            cnt++;\n        }\n        ans *=\
    \ cnt + 1;\n    }\n    auto isSqrt = [&](ll n)->bool {\n        ll c = sqrtl(n);\n\
    \        return c * c == n;\n    };\n    if (n == 1) return ans;\n    if (MillerRabin(n))\
    \ ans *= 2;\n    else if (isSqrt(n)) ans *= 3;\n    else ans *= 4;\n    return\
    \ ans;\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/MillerRabin.h
  - NumberTheory/Math/Binary_exponentiation.h
  - NumberTheory/Math/Sieve.h
  isVerificationFile: false
  path: NumberTheory/Math/Divisors.h
  requiredBy: []
  timestamp: '2025-12-04 02:05:35+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: NumberTheory/Math/Divisors.h
layout: document
redirect_from:
- /library/NumberTheory/Math/Divisors.h
- /library/NumberTheory/Math/Divisors.h.html
title: NumberTheory/Math/Divisors.h
---
