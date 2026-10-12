---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Binary_exponentiation.h
    title: NumberTheory/Math/Binary_exponentiation.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Divisors.h
    title: NumberTheory/Math/Divisors.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Factorial.h
    title: NumberTheory/Math/Factorial.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/MillerRabin.h
    title: NumberTheory/Math/MillerRabin.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Misc.h
    title: NumberTheory/Math/Misc.h
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/Sieve.h
    title: NumberTheory/Math/Sieve.h
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"NumberTheory/Yosupo/Unit_test_math.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\r\n\r\n#line 2 \"template.h\"\n\r\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n \r\n#define ll long long\r\
    \n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\n#define unique(x)\
    \ x.erase(unique(all(x)), x.end())\r\n\r\n#define vi vector<int>\r\n#define pii\
    \ pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\n#define se\
    \ second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
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
    \ return ans;\r\n}\n#line 2 \"NumberTheory/Math/Factorial.h\"\n\r\n\r\n// https://wiki.vnoi.info/translate/he/Wilsons-theorem\r\
    \n// Wilson theorem\r\n// n > 1 is prime <=> (n-1)! \u2261 -1 (mod n)\r\n//\r\n\
    // Proof:\r\n//    a^(n-2) \u2261 a^(-1) (mod n) (Fermat's little theorem)\r\n\
    // => a^(n-2) * a \u2261 1 (mod n)\r\n// Set b = a^(n-2)\r\n// => ab \u2261 1\
    \ (mod n)\r\n//\r\n// Have a = b <=> a^2 \u2261 1 (mod n) <=> a = 1 or a = n-1\r\
    \n//\r\n// So if a = 2,3,...,n-2 then a != b\r\n// => we have (n-3)/2 distinct\
    \ pairs (because with each a, b is unique)\r\n// so we multiple all paris\r\n\
    // => 2.3...(n-2) \u2261 1 (mod n)\r\n// => (n-1)! \u2261 n-1 (mod n)\r\n\r\n\
    // Proof by contradiction:\r\n// if n is not prime => n have divisors in range\
    \ [2, n)\r\n//                   => gcd((n-1)!, n) > 1\r\n//                 \
    \  => gcd(n-1, n) > 1 (contradiction)\r\n\r\n\r\n// use for small prime p <= 46341\r\
    \n// slow version\r\nint factmod0(int n, int p) {\r\n    vector<int> f(p);\r\n\
    \    f[0] = 1;\r\n    for (int i = 1; i < p; i++) {\r\n        f[i] = f[i-1] *\
    \ i % p;\r\n    }\r\n    int res = 1;\r\n    while (n > 1) {\r\n        if ((n/p)\
    \ % 2) res = p - res;\r\n        res = res * f[n % p] % p;\r\n        n /= p;\r\
    \n    }\r\n    return res;\r\n}\r\n\r\n\r\n// Optimize version using static to\
    \ cache, can work with multiple calling\r\nll factmod(ll n, ll p) {\r\n    static\
    \ ll lastp = -1;\r\n    static vector<ll> f;\r\n    if (p != lastp) {\r\n    \
    \    lastp = p;\r\n        f.assign(p, 1);\r\n        for (ll i = 1; i < p; i++)\
    \ f[i] = f[i-1] * i % p;\r\n    }\r\n    ll res = 1;\r\n    while (n > 1) {\r\n\
    \        if ((n/p) % 2) res = p - res;\r\n        res = res * f[n % p] % p;\r\n\
    \        n /= p;\r\n    }\r\n    return res;\r\n}\n#line 2 \"NumberTheory/Math/Misc.h\"\
    \n\r\n\r\n// for both negative + positive val\r\nll GCD(ll a, ll b) {\r\n    a\
    \ = llabs(a), b = llabs(b);\r\n    return (!b ? a : GCD(b, a % b));\r\n}\r\nll\
    \ LCM(ll a, ll b) { return (!a || !b) ? 0 : llabs(a / GCD(a, b) * b); }\r\n\r\n\
    // Only positive\r\n// ll GCD(ll a, ll b) { return (!b ? a : GCD(b, a % b)); }\r\
    \n// ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }\r\n\r\n// logb(a)\r\ndouble\
    \ log_base(ll a, ll b) { return log(a) / log(b); }\r\n\r\n// use for 2 <= BASE\
    \ <= 36\r\nstring decimal_to_base(ll n, int BASE) {\r\n    if (!n) return \"0\"\
    ;\r\n    bool neg = (n < 0 ? 1 : 0);\r\n    n = llabs(n);\r\n    string num =\
    \ \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\";\r\n    string res;\r\n    while(n)\
    \ {\r\n        res.push_back(num[n % BASE]);\r\n        n /= BASE;\r\n    }\r\n\
    \    if (neg) res += '-';\r\n    reverse(all(res));\r\n    return res;\r\n}\r\n\
    \r\n// any BASE to decimal\r\n// use ctype lib\r\nll convert_decimal(string s,\
    \ int BASE) {\r\n    auto val = [&](char c) { c = toupper(c); return (isdigit(c)\
    \ ? c-'0' : c-'A'+10); };\r\n    ll n = s.size(), p = 1, res = 0;\r\n    for (int\
    \ i = n-1; i >= 0; i--) {\r\n        res += val(s[i]) * p;\r\n        p = p *\
    \ BASE;\r\n    }\r\n    return res;\r\n}\n#line 7 \"NumberTheory/Yosupo/Unit_test_math.test.cpp\"\
    \n\r\nvoid solve() {\r\n    const int N = 200000;\r\n\r\n    // count_divisor\
    \ vs sieve_count_divisors\r\n    auto dv = sieve_count_divisors(N);\r\n    for\
    \ (int n = 1; n <= N; n++) assert(count_divisor(n) == dv[n]);\r\n\r\n    // sum_of_divisor\
    \ vs prefix sum of sieve_sum_divisors\r\n    auto sd = sieve_sum_divisors(N);\r\
    \n    ll acc = 0;\r\n    for (int n = 1; n <= N; n++) {\r\n        acc = (acc\
    \ + sd[n]) % MOD;\r\n        if (n % 4096 == 0 || n == N) assert(sum_of_divisor(n)\
    \ == acc);\r\n    }\r\n\r\n    // factmod vs brute force\r\n    for (ll p : {2LL,\
    \ 3LL, 97LL, 9973LL}) {\r\n        ll r = 1;\r\n        for (ll n = 1; n <= 5000;\
    \ n++) {\r\n            ll x = n;\r\n            while (x % p == 0) x /= p;\r\n\
    \            r = r * (x % p) % p;\r\n            assert(factmod(n, p) == r);\r\
    \n        }\r\n    }\r\n\r\n    // GCD, LCM\r\n    for (ll a = -60; a <= 60; a++)\
    \ for (ll b = -60; b <= 60; b++) {\r\n        ll g = GCD(a, b), l = LCM(a, b);\r\
    \n        if (a && b) {\r\n            assert(llabs(a) % g == 0 && llabs(b) %\
    \ g == 0);\r\n            assert(l == llabs(a * b) / g);\r\n        } else assert(l\
    \ == 0);\r\n    }\r\n\r\n    // base conversion round trip\r\n    for (int base\
    \ = 2; base <= 36; base++)\r\n        for (ll v = 0; v <= 3000; v++)\r\n     \
    \       assert(convert_decimal(decimal_to_base(v, base), base) == v);\r\n\r\n\
    \    ll a, b; cin >> a >> b;\r\n    cout << a + b << '\\n';\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\r\n\r\n#include\
    \ \"../../template.h\"\r\n#include \"../Math/Divisors.h\"\r\n#include \"../Math/Factorial.h\"\
    \r\n#include \"../Math/Misc.h\"\r\n\r\nvoid solve() {\r\n    const int N = 200000;\r\
    \n\r\n    // count_divisor vs sieve_count_divisors\r\n    auto dv = sieve_count_divisors(N);\r\
    \n    for (int n = 1; n <= N; n++) assert(count_divisor(n) == dv[n]);\r\n\r\n\
    \    // sum_of_divisor vs prefix sum of sieve_sum_divisors\r\n    auto sd = sieve_sum_divisors(N);\r\
    \n    ll acc = 0;\r\n    for (int n = 1; n <= N; n++) {\r\n        acc = (acc\
    \ + sd[n]) % MOD;\r\n        if (n % 4096 == 0 || n == N) assert(sum_of_divisor(n)\
    \ == acc);\r\n    }\r\n\r\n    // factmod vs brute force\r\n    for (ll p : {2LL,\
    \ 3LL, 97LL, 9973LL}) {\r\n        ll r = 1;\r\n        for (ll n = 1; n <= 5000;\
    \ n++) {\r\n            ll x = n;\r\n            while (x % p == 0) x /= p;\r\n\
    \            r = r * (x % p) % p;\r\n            assert(factmod(n, p) == r);\r\
    \n        }\r\n    }\r\n\r\n    // GCD, LCM\r\n    for (ll a = -60; a <= 60; a++)\
    \ for (ll b = -60; b <= 60; b++) {\r\n        ll g = GCD(a, b), l = LCM(a, b);\r\
    \n        if (a && b) {\r\n            assert(llabs(a) % g == 0 && llabs(b) %\
    \ g == 0);\r\n            assert(l == llabs(a * b) / g);\r\n        } else assert(l\
    \ == 0);\r\n    }\r\n\r\n    // base conversion round trip\r\n    for (int base\
    \ = 2; base <= 36; base++)\r\n        for (ll v = 0; v <= 3000; v++)\r\n     \
    \       assert(convert_decimal(decimal_to_base(v, base), base) == v);\r\n\r\n\
    \    ll a, b; cin >> a >> b;\r\n    cout << a + b << '\\n';\r\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/Divisors.h
  - NumberTheory/Math/MillerRabin.h
  - NumberTheory/Math/Binary_exponentiation.h
  - NumberTheory/Math/Sieve.h
  - NumberTheory/Math/Factorial.h
  - NumberTheory/Math/Misc.h
  isVerificationFile: true
  path: NumberTheory/Yosupo/Unit_test_math.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: NumberTheory/Yosupo/Unit_test_math.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Yosupo/Unit_test_math.test.cpp
- /verify/NumberTheory/Yosupo/Unit_test_math.test.cpp.html
title: NumberTheory/Yosupo/Unit_test_math.test.cpp
---
