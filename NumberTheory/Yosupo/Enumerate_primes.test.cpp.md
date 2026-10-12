---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: NumberTheory/Math/CheckPrime.h
    title: NumberTheory/Math/CheckPrime.h
  - icon: ':x:'
    path: NumberTheory/Math/Sieve.h
    title: NumberTheory/Math/Sieve.h
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"NumberTheory/Yosupo/Enumerate_primes.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#line 2 \"template.h\"\
    \n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n \r\n#define ll long\
    \ long\r\n#define MOD (ll)(1e9+7)\r\n#define all(x) (x).begin(),(x).end()\r\n\
    #define unique(x) x.erase(unique(all(x)), x.end())\r\n\r\n#define vi vector<int>\r\
    \n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define fi first\r\
    \n#define se second\r\n\r\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }\r\n\
    \r\nconst int mod = 998244353;\r\n\r\nvoid solve();\r\n\r\nint main() {\r\n  \
    \  // if (FILE* f = fopen(TASK \".inp\", \"r\")) {\r\n    //     fclose(f);\r\n\
    \    //     freopen(TASK \".inp\", \"r\", stdin);\r\n    //     freopen(TASK \"\
    .out\", \"w\", stdout);\r\n    // }\r\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\r\
    \n    // cin.exceptions(cin.failbit);\r\n    // int t; cin >> t;\r\n    // while(t--)\r\
    \n        solve();\r\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\r\n    return 0;\r\n}\n#line 2 \"NumberTheory/Math/CheckPrime.h\"\
    \n\r\n\r\nbool BruteForce(ll n) {\r\n    if (n == 2 || n == 3) return true;\r\n\
    \    if (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;\r\n    ll lim = sqrtl(n);\r\
    \n    while (lim > 0 && lim > n / lim) lim--;\r\n    for (ll i = 5; i <= lim;\
    \ i += 6) {\r\n        if (n % i == 0 || n % (i+2) == 0) return false;\r\n   \
    \ }\r\n    return true;\r\n}\r\n\r\n// https://codeforces.com/blog/entry/91632\r\
    \nll Meissel(ll n) {\r\n    vector<ll> v;\r\n    for (ll i = 1; i*i <= n; i++)\
    \ {\r\n        v.push_back(i);\r\n        v.push_back(n / i);\r\n    }\r\n   \
    \ sort(all(v));\r\n    unique(v);\r\n    ll sq = sqrt(n);\r\n    auto geti = [&](ll\
    \ x) {\r\n        if (x <= sq) return x-1;\r\n        return (int)v.size() - n\
    \ / x;\r\n    };\r\n    vector<ll> dp = v;\r\n    ll a = 0;\r\n    for (ll p =\
    \ 2; p*p <= n; p++) {\r\n        if (dp[geti(p)] == dp[geti(p-1)]) continue;\r\
    \n        a++;\r\n        for (int i = (int)v.size()-1; i >= 0; i--) {\r\n   \
    \         if (v[i] < p * p) break;\r\n            dp[i] -= dp[geti(v[i] / p)]\
    \ - a;\r\n        }\r\n    }\r\n    return dp[geti(n)] - 1;\r\n}\n#line 2 \"NumberTheory/Math/Sieve.h\"\
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
    \n        }\r\n    }\r\n    return div;\r\n}\n#line 6 \"NumberTheory/Yosupo/Enumerate_primes.test.cpp\"\
    \n\nvoid solve() {\n    int n, a, b; cin >> n >> a >> b;\n    ll cnt_pi = Meissel(n);\n\
    \    \n    int lim = 1e6;\n    vector<int> need;\n    int i = 0;\n    while (a*i\
    \ + b <= n && (int)need.size() < lim) {\n        need.push_back(a*i+b);\n    \
    \    i++;\n    }\n\n    vector<int> prime = listPrime(0, lim);\n    vector<int>\
    \ res;\n    int cnt = 0, idx = 0;\n    for (int l = 2; l <= n; l += lim) {\n \
    \       int r = min(l + lim - 1, n);\n        vector<int> isPrime(r - l + 1, 1);\n\
    \        for (int p : prime) {\n            ll low = max(1ll*p*p, 1ll*(l+p-1)/p*p);\n\
    \            for (ll j = low; j <= r; j += p) {\n                if (j-l >= 0)\
    \ isPrime[j-l] = 0;\n            }\n        }\n        // vector<int> isPrime\
    \ = segmentSieve(l, r);\n\n        for (int p = l; p <= min(r, n); p++) {\n  \
    \          if (!isPrime[p-l]) continue;\n            if (cnt == need[idx]) {\n\
    \                res.push_back(p);\n                idx++;\n            }\n  \
    \          cnt++;\n            if (idx == (int)need.size()) break;\n        }\n\
    \n        if (idx == (int)need.size()) break;\n    }\n\n    cout << cnt_pi <<\
    \ ' ' << res.size() << '\\n';\n    for (int x : res) cout << x << ' ';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include \"../../template.h\"\n#include \"../Math/CheckPrime.h\"\n#include \"\
    ../Math/Sieve.h\"\n\nvoid solve() {\n    int n, a, b; cin >> n >> a >> b;\n  \
    \  ll cnt_pi = Meissel(n);\n    \n    int lim = 1e6;\n    vector<int> need;\n\
    \    int i = 0;\n    while (a*i + b <= n && (int)need.size() < lim) {\n      \
    \  need.push_back(a*i+b);\n        i++;\n    }\n\n    vector<int> prime = listPrime(0,\
    \ lim);\n    vector<int> res;\n    int cnt = 0, idx = 0;\n    for (int l = 2;\
    \ l <= n; l += lim) {\n        int r = min(l + lim - 1, n);\n        vector<int>\
    \ isPrime(r - l + 1, 1);\n        for (int p : prime) {\n            ll low =\
    \ max(1ll*p*p, 1ll*(l+p-1)/p*p);\n            for (ll j = low; j <= r; j += p)\
    \ {\n                if (j-l >= 0) isPrime[j-l] = 0;\n            }\n        }\n\
    \        // vector<int> isPrime = segmentSieve(l, r);\n\n        for (int p =\
    \ l; p <= min(r, n); p++) {\n            if (!isPrime[p-l]) continue;\n      \
    \      if (cnt == need[idx]) {\n                res.push_back(p);\n          \
    \      idx++;\n            }\n            cnt++;\n            if (idx == (int)need.size())\
    \ break;\n        }\n\n        if (idx == (int)need.size()) break;\n    }\n\n\
    \    cout << cnt_pi << ' ' << res.size() << '\\n';\n    for (int x : res) cout\
    \ << x << ' ';\n}"
  dependsOn:
  - template.h
  - NumberTheory/Math/CheckPrime.h
  - NumberTheory/Math/Sieve.h
  isVerificationFile: true
  path: NumberTheory/Yosupo/Enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 05:42:39+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: NumberTheory/Yosupo/Enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Yosupo/Enumerate_primes.test.cpp
- /verify/NumberTheory/Yosupo/Enumerate_primes.test.cpp.html
title: NumberTheory/Yosupo/Enumerate_primes.test.cpp
---
