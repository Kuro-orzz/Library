#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template.h"
#include "../BigInt_full.h"

using B  = BigInt<>;      // D = 9
using B4 = BigInt<4>;     // cung logic, khac limb -> doi chieu cheo
using B1 = BigInt<1>;

string i128str(__int128 v) {
    if (v == 0) return "0";
    bool neg = v < 0; if (neg) v = -v;
    string s;
    while (v) { s += char('0' + int(v % 10)); v /= 10; }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    return s;
}

// so sanh hai so nguyen dang chuoi, doc lap hoan toan voi BigInt
int refCmp(string x, string y) {
    int sx = 1, sy = 1;
    if (x[0] == '-') { sx = -1; x = x.substr(1); }
    if (y[0] == '-') { sy = -1; y = y.substr(1); }
    x.erase(0, min(x.find_first_not_of('0'), x.size() - 1));
    y.erase(0, min(y.find_first_not_of('0'), y.size() - 1));
    if (x == "0") sx = 0;
    if (y == "0") sy = 0;
    if (sx != sy) return sx < sy ? -1 : 1;
    int c = x.size() != y.size() ? (x.size() < y.size() ? -1 : 1)
                                 : (x == y ? 0 : (x < y ? -1 : 1));
    return sx >= 0 ? c : -c;
}

string rndDigits(int n, mt19937 &g, bool neg = false) {
    string s;
    if (neg) s += '-';
    s += char('1' + g() % 9);
    for (int i = 1; i < n; i++) s += char('0' + g() % 10);
    return s;
}

void solve() {
    mt19937 g(20260726);

    // ---------- 1. khoi tao va in ra ----------
    assert(B().toString() == "0");
    assert(B(0).toString() == "0");
    assert(B("0").toString() == "0");
    assert(B("-0").toString() == "0");
    assert(B("0000123").toString() == "123");
    assert(B("-0000123").toString() == "-123");
    assert(B(LLONG_MAX).toString() == "9223372036854775807");
    assert(B(LLONG_MIN + 1).toString() == "-9223372036854775807");

    for (int t = 0; t < 300; t++) {
        string s = rndDigits(1 + g() % 60, g, g() & 1);
        assert(B(s).toString() == s);
        assert(B4(s).toString() == s);
        assert(B1(s).toString() == s);
    }

    // ---------- 2. so 0 chi co MOT bieu dien ----------
    vector<B> zeros = {B(), B(0), B("0"), B("-0"), B(5) - B(5), B(0) * B(-7)};
    { B t(-10); t %= 5LL; zeros.push_back(t); }
    { B t(-10); t /= 3LL; t /= 4LL; zeros.push_back(t); }
    for (const B &z : zeros) {
        assert(z.isZero() && z.sign == 1 && z.toString() == "0");
        for (const B &w : zeros)
            assert(z == w && !(z < w) && !(z > w) && z <= w && z >= w);
    }

    // ---------- 3. so hoc doi chieu long long ----------
    vector<ll> smalls;
    for (ll x = -40; x <= 40; x++) smalls.push_back(x);
    for (ll x : {999999998LL, 999999999LL, 1000000000LL, 1000000001LL,
                 -1000000000LL, 123456789012345LL, -987654321098765LL}) smalls.push_back(x);
    for (ll a : smalls) for (ll b : smalls) {
        B A(a), B_(b);
        assert((A + B_) == B(a + b));
        assert((A - B_) == B(a - b));
        assert((A * B_).toString() == i128str((__int128)a * b));
        assert((A < B_) == (a < b) && (A > B_) == (a > b) && (A == B_) == (a == b));
        assert((A <= B_) == (a <= b) && (A >= B_) == (a >= b) && (A != B_) == (a != b));
        assert((A < b) == (a < b) && (A == b) == (a == b) && (A >= b) == (a >= b));
        if (b != 0) {
            assert((A / B_) == B(a / b));           // chat ve 0, giong C++
            assert((A % B_) == B(a % b));
            assert(A / B_ * B_ + A % B_ == A);      // bat bien
        }
        if (b != 0 && llabs(b) <= 1000000000LL) {
            B q = A, r = A;
            q /= b; r %= b;
            assert(q == B(a / b) && r == B(a % b));
        }
    }

    // ---------- 3b. so sanh ky: nhieu limb, co limb bang 0 ----------
    {
        vector<string> v = {"0", "-0", "1", "-1", "999999999", "-999999999",
            "1000000000", "-1000000000", "1000000005", "-1000000005",
            "1000000000000000000", "-1000000000000000000",
            "1000000000000000001", "-1000000000000000001",
            "2000000000", "-2000000000", "999999999999999999", "-999999999999999999",
            "1000000000000000000000000000", "-1000000000000000000000000000",
            "1000000000000000000000000001", "-1000000000000000000000000001"};
        for (int t = 0; t < 200; t++) {
            string s;
            int limbs = 1 + g() % 4;
            for (int i = 0; i < limbs; i++) {
                int d = (g() % 3 == 0) ? 0 : (int)(g() % 1000000000);
                string p = to_string(d);
                s += string(9 - p.size(), '0') + p;
            }
            s.erase(0, min(s.find_first_not_of('0'), s.size() - 1));
            v.push_back(s);
            v.push_back("-" + s);
        }
        for (const string &x : v) for (const string &y : v) {
            int c = refCmp(x, y);
            B a(x), b(y);
            assert((a < b) == (c < 0));
            assert((a > b) == (c > 0));
            assert((a == b) == (c == 0));
            assert((a <= b) == (c <= 0));
            assert((a >= b) == (c >= 0));
            assert((a != b) == (c != 0));
        }
    }

    // ---------- 4. don nguyen, tang giam ----------
    for (ll x : {-7LL, -1LL, 0LL, 1LL, 9LL}) {
        B a(x);
        assert((-a) == B(-x) && (+a) == B(x) && (-(-a)) == a);
        B b = a; assert((++b) == B(x + 1) && b == B(x + 1));
        B c = a; assert((c++) == B(x) && c == B(x + 1));
        B d = a; assert((--d) == B(x - 1));
        B e = a; assert((e--) == B(x) && e == B(x - 1));
    }
    assert((-B(0)).sign == 1 && (-B(0)).toString() == "0");

    // ---------- 5. int op BigInt (friend) ----------
    assert((100LL + B(23)) == B(123));
    assert((100LL - B(23)) == B(77));
    assert((100LL * B(23)) == B(2300));
    assert((100LL / B(23)) == B(4));
    assert((100LL % B(23)) == B(8));

    // ---------- 6. so lon: doi chieu cheo D=9 / D=4 / D=1 ----------
    for (int t = 0; t < 40; t++) {
        int la = 50 + g() % 700, lb = 50 + g() % 700;   // vuot nguong karatsuba
        string sa = rndDigits(la, g, g() & 1), sb = rndDigits(lb, g, false);
        B a(sa), b(sb);
        B4 a4(sa), b4(sb);
        B1 a1(sa), b1(sb);
        assert((a + b).toString() == (a4 + b4).toString());
        assert((a - b).toString() == (a4 - b4).toString());
        assert((a * b).toString() == (a4 * b4).toString());
        assert((a / b).toString() == (a4 / b4).toString());
        assert((a % b).toString() == (a4 % b4).toString());
        assert((a * b).toString() == (a1 * b1).toString());
        assert(a / b * b + a % b == a);
    }

    // ---------- 7. dong nhat thuc so lon ----------
    for (int k : {1, 5, 20, 100, 400}) {
        B p = pow(B(10), B(k));
        assert(p.toString() == "1" + string(k, '0'));
        assert((p - 1) * (p + 1) == pow(B(10), B(2 * k)) - 1);
        B a = p - 1, b = p + 7;
        assert((a + b) * (a + b) == a * a + 2 * (a * b) + b * b);
        assert((a - b) * (a + b) == a * a - b * b);
    }
    B f1(1); for (int i = 1; i <= 100; i++) f1 *= i;
    B f2(1); for (int i = 100; i >= 1; i--) f2 = f2 * i;
    assert(f1 == f2);
    assert(f1.toString().size() == 158);        // 100! co 158 chu so
    assert(f1 % 101 == B(100));                 // wilson: 100! = -1 (mod 101)

    // ---------- 8. sqrt ----------
    for (ll x = 0; x <= 400; x++) {
        assert(sqrt(B(x * x)) == B(x));
        if (x) assert(sqrt(B(x * x + x)) == B(x));
        if (x) assert(sqrt(B(x * x - 1)) == B(x - 1));
    }
    for (int t = 0; t < 30; t++) {
        B a(rndDigits(1 + g() % 60, g)), r = sqrt(a);
        assert(r * r <= a && (r + 1) * (r + 1) > a);
    }

    // ---------- 9. pow ----------
    for (ll a = 2; a <= 12; a++) for (ll e = 0; e <= 15; e++) {
        ll p = 1; for (ll i = 0; i < e; i++) p *= a;
        assert(pow(B(a), B(e)) == B(p));
        assert(pow(B(a), B(e), 1000000007LL) == B(p % 1000000007));
    }
    assert(pow(B(7), B(0)) == B(1));
    assert(pow(B(0), B(5)) == B(0));
    for (ll a : {2LL, 3LL, 123456LL})           // fermat
        assert(pow(B(a), B(1000000006LL), 1000000007LL) == B(1));

    // ---------- 10. gcd / lcm ----------
    for (ll a = -30; a <= 30; a++) for (ll b = -30; b <= 30; b++) {
        B G = __gcd(B(a), B(b));
        assert(G == B(__gcd(llabs(a), llabs(b))) && G >= B(0));
        B L = __lcm(B(a), B(b));
        if (a == 0 || b == 0) assert(L == B(0));
        else assert(L == B(llabs(a) / __gcd(llabs(a), llabs(b)) * llabs(b)));
    }
    {
        B gg = pow(B(10), B(30)) + 7;
        assert(__gcd(B(999983) * gg, B(1000003) * gg) == gg);
    }

    // ---------- 11. abs / isZero / size ----------
    assert(B(-123).abs() == B(123) && B(0).abs().sign == 1);
    assert(B(0).isZero() && !B(1).isZero());
    assert(B(0).size() == 0 && B("999999999").size() == 1 && B("1000000000").size() == 2);

    // ---------- 12. stream khong bi ban ----------
    { ostringstream os; os << B("1000000000000000000") << setw(5) << 42;
      assert(os.str() == "1000000000000000000   42"); }
    { istringstream is("-123456789012345678901234567890"); B a; is >> a;
      assert(a.toString() == "-123456789012345678901234567890"); }

    ll a, b; cin >> a >> b;
    cout << a + b << '\n';
}