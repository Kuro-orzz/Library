---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: NumberTheory/Math/CheckPrime.h
    title: NumberTheory/Math/CheckPrime.h
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"NumberTheory/Yosupo/Enumerate_primes.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#line 2 \"template.h\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n \n#define ll long long\n\
    #define MOD (ll)(1e9+7)\n#define all(x) (x).begin(),(x).end()\n#define unique(x)\
    \ x.erase(unique(all(x)), x.end())\n#define INF32 ((1ull<<31)-1)\n#define INF64\
    \ ((1ull<<63)-1)\n#define inf (ll)1e18\n\n#define vi vector<int>\n#define pii\
    \ pair<int, int>\n#define pll pair<ll, ll>\n#define fi first\n#define se second\n\
    \nconst int mod = 998244353;\n\nvoid solve();\n\nint main(){\n    ios_base::sync_with_stdio(false);cin.tie(NULL);\n\
    \    // cin.exceptions(cin.failbit);\n    // int t; cin >> t;\n    // while(t--)\n\
    \        solve();\n    cerr << \"\\nTime run: \" << 1000 * clock() / CLOCKS_PER_SEC\
    \ << \"ms\" << '\\n';\n    return 0;\n}\n#line 2 \"NumberTheory/Math/CheckPrime.h\"\
    \n\n\nbool BruteForce(ll n) {\n    if (n == 2 || n == 3) return true;\n    if\
    \ (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;\n    for (ll i = 5; i * i\
    \ <= n; i += 6)\n        if (n % i == 0 || n % (i+2) == 0)\n            return\
    \ false;\n    return true;\n}\n\n// https://codeforces.com/blog/entry/91632\n\
    ll Meissel(ll n) {\n    vector<ll> v;\n    for (ll i = 1; i*i <= n; i++) {\n \
    \       v.push_back(i);\n        v.push_back(n / i);\n    }\n    sort(all(v));\n\
    \    unique(v);\n    ll sq = sqrt(n);\n    auto geti = [&](ll x) {\n        if\
    \ (x <= sq) return x-1;\n        return (int)v.size() - n / x;\n    };\n    vector<ll>\
    \ dp = v;\n    ll a = 0;\n    for (ll p = 2; p*p <= n; p++) {\n        if (dp[geti(p)]\
    \ == dp[geti(p-1)]) continue;\n        a++;\n        for (int i = (int)v.size()-1;\
    \ i >= 0; i--) {\n            if (v[i] < p * p) break;\n            dp[i] -= dp[geti(v[i]\
    \ / p)] - a;\n        }\n    }\n    return dp[geti(n)] - 1;\n}\n#line 2 \"NumberTheory/Math/Sieve.h\"\
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
    \   }\n    }\n    return div;\n}\n#line 6 \"NumberTheory/Yosupo/Enumerate_primes.test.cpp\"\
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
  timestamp: '2025-12-04 02:05:35+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: NumberTheory/Yosupo/Enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/NumberTheory/Yosupo/Enumerate_primes.test.cpp
- /verify/NumberTheory/Yosupo/Enumerate_primes.test.cpp.html
title: NumberTheory/Yosupo/Enumerate_primes.test.cpp
---
