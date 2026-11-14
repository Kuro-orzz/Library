---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/home/runner/.local/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/home/runner/.local/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../NumberTheory/Math/EulerPhi.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\r\n\r\n#include\
    \ \"../../template.h\"\r\n#include \"../BigInt_full.h\"\r\n\r\nusing B  = BigInt<>;\
    \      // D = 9\r\nusing B4 = BigInt<4>;     // cung logic, khac limb -> doi chieu\
    \ cheo\r\nusing B1 = BigInt<1>;\r\n\r\nstring i128str(__int128 v) {\r\n    if\
    \ (v == 0) return \"0\";\r\n    bool neg = v < 0; if (neg) v = -v;\r\n    string\
    \ s;\r\n    while (v) { s += char('0' + int(v % 10)); v /= 10; }\r\n    if (neg)\
    \ s += '-';\r\n    reverse(s.begin(), s.end());\r\n    return s;\r\n}\r\n\r\n\
    // so sanh hai so nguyen dang chuoi, doc lap hoan toan voi BigInt\r\nint refCmp(string\
    \ x, string y) {\r\n    int sx = 1, sy = 1;\r\n    if (x[0] == '-') { sx = -1;\
    \ x = x.substr(1); }\r\n    if (y[0] == '-') { sy = -1; y = y.substr(1); }\r\n\
    \    x.erase(0, min(x.find_first_not_of('0'), x.size() - 1));\r\n    y.erase(0,\
    \ min(y.find_first_not_of('0'), y.size() - 1));\r\n    if (x == \"0\") sx = 0;\r\
    \n    if (y == \"0\") sy = 0;\r\n    if (sx != sy) return sx < sy ? -1 : 1;\r\n\
    \    int c = x.size() != y.size() ? (x.size() < y.size() ? -1 : 1)\r\n       \
    \                          : (x == y ? 0 : (x < y ? -1 : 1));\r\n    return sx\
    \ >= 0 ? c : -c;\r\n}\r\n\r\nstring rndDigits(int n, mt19937 &g, bool neg = false)\
    \ {\r\n    string s;\r\n    if (neg) s += '-';\r\n    s += char('1' + g() % 9);\r\
    \n    for (int i = 1; i < n; i++) s += char('0' + g() % 10);\r\n    return s;\r\
    \n}\r\n\r\nvoid solve() {\r\n    mt19937 g(20260726);\r\n\r\n    // ----------\
    \ 1. khoi tao va in ra ----------\r\n    assert(B().toString() == \"0\");\r\n\
    \    assert(B(0).toString() == \"0\");\r\n    assert(B(\"0\").toString() == \"\
    0\");\r\n    assert(B(\"-0\").toString() == \"0\");\r\n    assert(B(\"0000123\"\
    ).toString() == \"123\");\r\n    assert(B(\"-0000123\").toString() == \"-123\"\
    );\r\n    assert(B(LLONG_MAX).toString() == \"9223372036854775807\");\r\n    assert(B(LLONG_MIN\
    \ + 1).toString() == \"-9223372036854775807\");\r\n\r\n    for (int t = 0; t <\
    \ 300; t++) {\r\n        string s = rndDigits(1 + g() % 60, g, g() & 1);\r\n \
    \       assert(B(s).toString() == s);\r\n        assert(B4(s).toString() == s);\r\
    \n        assert(B1(s).toString() == s);\r\n    }\r\n\r\n    // ---------- 2.\
    \ so 0 chi co MOT bieu dien ----------\r\n    vector<B> zeros = {B(), B(0), B(\"\
    0\"), B(\"-0\"), B(5) - B(5), B(0) * B(-7)};\r\n    { B t(-10); t %= 5LL; zeros.push_back(t);\
    \ }\r\n    { B t(-10); t /= 3LL; t /= 4LL; zeros.push_back(t); }\r\n    for (const\
    \ B &z : zeros) {\r\n        assert(z.isZero() && z.sign == 1 && z.toString()\
    \ == \"0\");\r\n        for (const B &w : zeros)\r\n            assert(z == w\
    \ && !(z < w) && !(z > w) && z <= w && z >= w);\r\n    }\r\n\r\n    // ----------\
    \ 3. so hoc doi chieu long long ----------\r\n    vector<ll> smalls;\r\n    for\
    \ (ll x = -40; x <= 40; x++) smalls.push_back(x);\r\n    for (ll x : {999999998LL,\
    \ 999999999LL, 1000000000LL, 1000000001LL,\r\n                 -1000000000LL,\
    \ 123456789012345LL, -987654321098765LL}) smalls.push_back(x);\r\n    for (ll\
    \ a : smalls) for (ll b : smalls) {\r\n        B A(a), B_(b);\r\n        assert((A\
    \ + B_) == B(a + b));\r\n        assert((A - B_) == B(a - b));\r\n        assert((A\
    \ * B_).toString() == i128str((__int128)a * b));\r\n        assert((A < B_) ==\
    \ (a < b) && (A > B_) == (a > b) && (A == B_) == (a == b));\r\n        assert((A\
    \ <= B_) == (a <= b) && (A >= B_) == (a >= b) && (A != B_) == (a != b));\r\n \
    \       assert((A < b) == (a < b) && (A == b) == (a == b) && (A >= b) == (a >=\
    \ b));\r\n        if (b != 0) {\r\n            assert((A / B_) == B(a / b)); \
    \          // chat ve 0, giong C++\r\n            assert((A % B_) == B(a % b));\r\
    \n            assert(A / B_ * B_ + A % B_ == A);      // bat bien\r\n        }\r\
    \n        if (b != 0 && llabs(b) <= 1000000000LL) {\r\n            B q = A, r\
    \ = A;\r\n            q /= b; r %= b;\r\n            assert(q == B(a / b) && r\
    \ == B(a % b));\r\n        }\r\n    }\r\n\r\n    // ---------- 3b. so sanh ky:\
    \ nhieu limb, co limb bang 0 ----------\r\n    {\r\n        vector<string> v =\
    \ {\"0\", \"-0\", \"1\", \"-1\", \"999999999\", \"-999999999\",\r\n          \
    \  \"1000000000\", \"-1000000000\", \"1000000005\", \"-1000000005\",\r\n     \
    \       \"1000000000000000000\", \"-1000000000000000000\",\r\n            \"1000000000000000001\"\
    , \"-1000000000000000001\",\r\n            \"2000000000\", \"-2000000000\", \"\
    999999999999999999\", \"-999999999999999999\",\r\n            \"1000000000000000000000000000\"\
    , \"-1000000000000000000000000000\",\r\n            \"1000000000000000000000000001\"\
    , \"-1000000000000000000000000001\"};\r\n        for (int t = 0; t < 200; t++)\
    \ {\r\n            string s;\r\n            int limbs = 1 + g() % 4;\r\n     \
    \       for (int i = 0; i < limbs; i++) {\r\n                int d = (g() % 3\
    \ == 0) ? 0 : (int)(g() % 1000000000);\r\n                string p = to_string(d);\r\
    \n                s += string(9 - p.size(), '0') + p;\r\n            }\r\n   \
    \         s.erase(0, min(s.find_first_not_of('0'), s.size() - 1));\r\n       \
    \     v.push_back(s);\r\n            v.push_back(\"-\" + s);\r\n        }\r\n\
    \        for (const string &x : v) for (const string &y : v) {\r\n           \
    \ int c = refCmp(x, y);\r\n            B a(x), b(y);\r\n            assert((a\
    \ < b) == (c < 0));\r\n            assert((a > b) == (c > 0));\r\n           \
    \ assert((a == b) == (c == 0));\r\n            assert((a <= b) == (c <= 0));\r\
    \n            assert((a >= b) == (c >= 0));\r\n            assert((a != b) ==\
    \ (c != 0));\r\n        }\r\n    }\r\n\r\n    // ---------- 4. don nguyen, tang\
    \ giam ----------\r\n    for (ll x : {-7LL, -1LL, 0LL, 1LL, 9LL}) {\r\n      \
    \  B a(x);\r\n        assert((-a) == B(-x) && (+a) == B(x) && (-(-a)) == a);\r\
    \n        B b = a; assert((++b) == B(x + 1) && b == B(x + 1));\r\n        B c\
    \ = a; assert((c++) == B(x) && c == B(x + 1));\r\n        B d = a; assert((--d)\
    \ == B(x - 1));\r\n        B e = a; assert((e--) == B(x) && e == B(x - 1));\r\n\
    \    }\r\n    assert((-B(0)).sign == 1 && (-B(0)).toString() == \"0\");\r\n\r\n\
    \    // ---------- 5. int op BigInt (friend) ----------\r\n    assert((100LL +\
    \ B(23)) == B(123));\r\n    assert((100LL - B(23)) == B(77));\r\n    assert((100LL\
    \ * B(23)) == B(2300));\r\n    assert((100LL / B(23)) == B(4));\r\n    assert((100LL\
    \ % B(23)) == B(8));\r\n\r\n    // ---------- 6. so lon: doi chieu cheo D=9 /\
    \ D=4 / D=1 ----------\r\n    for (int t = 0; t < 40; t++) {\r\n        int la\
    \ = 50 + g() % 700, lb = 50 + g() % 700;   // vuot nguong karatsuba\r\n      \
    \  string sa = rndDigits(la, g, g() & 1), sb = rndDigits(lb, g, false);\r\n  \
    \      B a(sa), b(sb);\r\n        B4 a4(sa), b4(sb);\r\n        B1 a1(sa), b1(sb);\r\
    \n        assert((a + b).toString() == (a4 + b4).toString());\r\n        assert((a\
    \ - b).toString() == (a4 - b4).toString());\r\n        assert((a * b).toString()\
    \ == (a4 * b4).toString());\r\n        assert((a / b).toString() == (a4 / b4).toString());\r\
    \n        assert((a % b).toString() == (a4 % b4).toString());\r\n        assert((a\
    \ * b).toString() == (a1 * b1).toString());\r\n        assert(a / b * b + a %\
    \ b == a);\r\n    }\r\n\r\n    // ---------- 7. dong nhat thuc so lon ----------\r\
    \n    for (int k : {1, 5, 20, 100, 400}) {\r\n        B p = pow(B(10), B(k));\r\
    \n        assert(p.toString() == \"1\" + string(k, '0'));\r\n        assert((p\
    \ - 1) * (p + 1) == pow(B(10), B(2 * k)) - 1);\r\n        B a = p - 1, b = p +\
    \ 7;\r\n        assert((a + b) * (a + b) == a * a + 2 * (a * b) + b * b);\r\n\
    \        assert((a - b) * (a + b) == a * a - b * b);\r\n    }\r\n    B f1(1);\
    \ for (int i = 1; i <= 100; i++) f1 *= i;\r\n    B f2(1); for (int i = 100; i\
    \ >= 1; i--) f2 = f2 * i;\r\n    assert(f1 == f2);\r\n    assert(f1.toString().size()\
    \ == 158);        // 100! co 158 chu so\r\n    assert(f1 % 101 == B(100));   \
    \              // wilson: 100! = -1 (mod 101)\r\n\r\n    // ---------- 8. sqrt\
    \ ----------\r\n    for (ll x = 0; x <= 400; x++) {\r\n        assert(sqrt(B(x\
    \ * x)) == B(x));\r\n        if (x) assert(sqrt(B(x * x + x)) == B(x));\r\n  \
    \      if (x) assert(sqrt(B(x * x - 1)) == B(x - 1));\r\n    }\r\n    for (int\
    \ t = 0; t < 30; t++) {\r\n        B a(rndDigits(1 + g() % 60, g)), r = sqrt(a);\r\
    \n        assert(r * r <= a && (r + 1) * (r + 1) > a);\r\n    }\r\n\r\n    //\
    \ ---------- 9. pow ----------\r\n    for (ll a = 2; a <= 12; a++) for (ll e =\
    \ 0; e <= 15; e++) {\r\n        ll p = 1; for (ll i = 0; i < e; i++) p *= a;\r\
    \n        assert(pow(B(a), B(e)) == B(p));\r\n        assert(pow(B(a), B(e), 1000000007LL)\
    \ == B(p % 1000000007));\r\n    }\r\n    assert(pow(B(7), B(0)) == B(1));\r\n\
    \    assert(pow(B(0), B(5)) == B(0));\r\n    for (ll a : {2LL, 3LL, 123456LL})\
    \           // fermat\r\n        assert(pow(B(a), B(1000000006LL), 1000000007LL)\
    \ == B(1));\r\n\r\n    // ---------- 10. gcd / lcm ----------\r\n    for (ll a\
    \ = -30; a <= 30; a++) for (ll b = -30; b <= 30; b++) {\r\n        B G = __gcd(B(a),\
    \ B(b));\r\n        assert(G == B(__gcd(llabs(a), llabs(b))) && G >= B(0));\r\n\
    \        B L = __lcm(B(a), B(b));\r\n        if (a == 0 || b == 0) assert(L ==\
    \ B(0));\r\n        else assert(L == B(llabs(a) / __gcd(llabs(a), llabs(b)) *\
    \ llabs(b)));\r\n    }\r\n    {\r\n        B gg = pow(B(10), B(30)) + 7;\r\n \
    \       assert(__gcd(B(999983) * gg, B(1000003) * gg) == gg);\r\n    }\r\n\r\n\
    \    // ---------- 11. abs / isZero / size ----------\r\n    assert(B(-123).abs()\
    \ == B(123) && B(0).abs().sign == 1);\r\n    assert(B(0).isZero() && !B(1).isZero());\r\
    \n    assert(B(0).size() == 0 && B(\"999999999\").size() == 1 && B(\"1000000000\"\
    ).size() == 2);\r\n\r\n    // ---------- 12. stream khong bi ban ----------\r\n\
    \    { ostringstream os; os << B(\"1000000000000000000\") << setw(5) << 42;\r\n\
    \      assert(os.str() == \"1000000000000000000   42\"); }\r\n    { istringstream\
    \ is(\"-123456789012345678901234567890\"); B a; is >> a;\r\n      assert(a.toString()\
    \ == \"-123456789012345678901234567890\"); }\r\n\r\n    ll a, b; cin >> a >> b;\r\
    \n    cout << a + b << '\\n';\r\n}"
  dependsOn: []
  isVerificationFile: true
  path: Big_Integer/Yosupo/Unit_test_math.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Big_Integer/Yosupo/Unit_test_math.test.cpp
layout: document
redirect_from:
- /verify/Big_Integer/Yosupo/Unit_test_math.test.cpp
- /verify/Big_Integer/Yosupo/Unit_test_math.test.cpp.html
title: Big_Integer/Yosupo/Unit_test_math.test.cpp
---
