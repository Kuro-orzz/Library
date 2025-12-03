#include "../template.h"


// Still slow ver, need optimize
// This template only work for base <= 10

const int BASE_DIGITS = 9;
const int BASE = 1000000000;

class BigInt {
public:
    int sign;
    vector<uint32_t> digit;

    BigInt(): sign(1) {}

    BigInt(const string &s) { *this = s; }

    BigInt(int64_t val) { *this = val; }

    BigInt &operator = (const BigInt &b) {
        sign = b.sign;
        digit = b.digit;
        return *this;
    }

    BigInt &operator = (const string &s) {
        read(s);
        return *this;
    }

    BigInt &operator = (int64_t val) {
        sign = val >= 0 ? 1 : -1;
        val = llabs(val);
        digit.clear();
        for (; val; val /= BASE) {
            digit.push_back(val % BASE);
        }
        trim();
        return *this;
    }

    BigInt &operator += (const BigInt &b) {
        if (sign != b.sign) {
            BigInt t = b;
            t.sign *= -1;
            return *this -= t;
        }
        int carry = 0, len = (int)max(size(), b.size());
        for (int i = 0; i < len; i++) {
            int sum = carry;
            if (i < (int)size()) sum += digit[i];
            if (i < (int)b.size()) sum += b[i];
            if (i < (int)size()) digit[i] = sum % BASE;
            else digit.push_back(sum % BASE);
            carry = sum / BASE;
        }
        if (carry) digit.push_back(carry);
        trim();
        return *this;
    }

    BigInt &operator -= (const BigInt &b) {
        if (sign != b.sign) {
            return *this += (-b);
        }
        if (__compare_abs(b) == -1) {
            BigInt t = b;
            t -= *this;
            t.sign *= -1;
            return *this = t;
        }
        int borrow = 0, len = (int)max(size(), b.size());
        for (int i = 0; i < len; i++) {
            int sub = -borrow;
            if (i < (int)size()) sub += digit[i];
            if (i < (int)b.size()) sub -= b[i];
            if (sub < 0) sub += BASE, borrow = 1;
            else borrow = 0;
            digit[i] = sub;
        }
        trim();
        return *this;
    }

    BigInt &operator *= (const BigInt &b) {
        return *this = karatsuba(*this, b);
    }

    BigInt &operator /= (const BigInt &b) {
        *this = divmod(*this, b).first;
        return *this;
    }

    BigInt &operator %= (const BigInt &b) {
        *this = divmod(*this, b).second;
        return *this;
    }

    // ------------------------ Operator ------------------------
    // BigInt += Int
    BigInt &operator += (int64_t t) { return *this += BigInt(t); }
    BigInt &operator -= (int64_t t) { return *this -= BigInt(t); }
    BigInt &operator *= (int64_t t) { return *this *= BigInt(t); }
    BigInt &operator /= (int64_t t) { 
        assert(t != 0); // not divided for 0
        int64_t rem = 0;
        for (int i = (int)size() - 1; i >= 0; i--) {
            int64_t cur = rem * BASE + (*this)[i];
            (*this)[i] = uint32_t(cur / t);
            rem = cur % t;
        } 
        trim();
        sign = sign * (t < 0 ? -1 : 1);
        return *this;
    }
    BigInt &operator %= (int64_t t) {
        assert(t != 0);
        int64_t rem = 0;
        for (int i = (int)size() - 1; i >= 0; i--) {
            int64_t cur = rem * BASE + (*this)[i];
            rem = cur % t;
        }
        if (rem < 0) rem += llabs(t);
        int s = sign;
        *this = rem;
        sign = s;
        return *this;
    }

    BigInt operator - () const { BigInt res = *this; res *= -1; return res; } // -a;
    BigInt operator + () const { return BigInt(*this); } // +a;
    BigInt &operator ++ () { *this += 1; return *this; } // ++a;
    BigInt &operator -- () { *this -= 1; return *this; } // --a;
    BigInt operator ++ (int) { BigInt res = *this; *this += 1; return res; } // a++;
    BigInt operator -- (int) { BigInt res = *this; *this -= 1; return res; } // a--;

    // BigInt = BigInt + BigInt
    BigInt operator + (const BigInt &b) const { return BigInt(*this) += b; }
    BigInt operator - (const BigInt &b) const { return BigInt(*this) -= b; }
    BigInt operator * (const BigInt &b) const { return BigInt(*this) *= b; }
    BigInt operator / (const BigInt &b) const { return BigInt(*this) /= b; }
    BigInt operator % (const BigInt &b) const { return BigInt(*this) %= b; }

    // BigInt = BigInt + Int
    BigInt operator + (int64_t t) const { return BigInt(*this) += t; }
    BigInt operator - (int64_t t) const { return BigInt(*this) -= t; }
    BigInt operator * (int64_t t) const { return BigInt(*this) *= t; }
    BigInt operator / (int64_t t) const { return BigInt(*this) /= t; }
    BigInt operator % (int64_t t) const { return BigInt(*this) %= t; }

    // BigInt = Int + BigInt
    friend BigInt operator + (int64_t t, const BigInt &b) { BigInt res(t); res += b; return res; }
    friend BigInt operator - (int64_t t, const BigInt &b) { BigInt res(t); res -= b; return res; }
    friend BigInt operator * (int64_t t, const BigInt &b) { BigInt res(t); res *= b; return res; }
    friend BigInt operator / (int64_t t, const BigInt &b) { BigInt res(t); res /= b; return res; }
    friend BigInt operator % (int64_t t, const BigInt &b) { BigInt res(t); res %= b; return res; }

    uint32_t operator [] (const int i) const { assert(i >= 0 && i < (int)size()); return digit[i]; }
    uint32_t &operator [] (const int i) { assert(i >= 0 && i < (int)size()); return digit[i]; }

    // ------------------------- Comparison ---------------------
    bool operator < (const BigInt &b) const {
        if (sign != b.sign) {
            return sign < b.sign;
        }
        if (size() != b.size()) {
            return size() * sign < b.size() * b.sign;
        }
        for (int i = (int)size() - 1; i >= 0; i--) {
            if ((*this)[i] != b[i]) {
                return (*this)[i] * sign < b[i] * sign;
            }
        }
        return false;
    }

    bool operator > (const BigInt &b) const { return b < *this; }
    bool operator <= (const BigInt &b) const { return !(b < *this); }
    bool operator >= (const BigInt &b) const { return !(*this < b); }
    bool operator == (const BigInt &b) const { return !(*this < b) && !(b < *this); }
    bool operator != (const BigInt &b) const { return *this < b || b < *this; }

    bool operator == (int64_t t) const { return *this == BigInt(t); }
    bool operator != (int64_t t) const { return *this != BigInt(t); }
    bool operator < (int64_t t) const { return *this < BigInt(t); }
    bool operator <= (int64_t t) const { return *this <= BigInt(t); }
    bool operator > (int64_t t) const { return *this > BigInt(t); }
    bool operator >= (int64_t t) const { return *this >= BigInt(t); }

    // 0 if |a| == |b|
    // -1 if |a| < |b|
    // 1 if |a| > |b|
    int __compare_abs(const BigInt &b) const {
        if (size() != b.size()) {
            return size() < b.size() ? -1 : 1;
        }
        for (int i = (int)size() - 1; i >= 0; i--) {
            if ((*this)[i] != b[i]) {
                return (*this)[i] < b[i] ? -1 : 1;
            }
        }
        return 0;
    }

    // -------------------- karatsuba ---------------------
    BigInt mul_simple(const BigInt &a, const BigInt &b) {
        BigInt x = a, y = b;
        BigInt res;
        res.sign = x.sign * y.sign;
        res.digit.resize(x.size() + y.size());
        for (int i = 0; i < (int)x.size(); i++) {
            uint64_t carry = 0;
            for (int j = 0; j < (int)y.size(); j++) {
                uint64_t cur = res[i+j] + carry;
                cur += 1ull * x[i] * y[j];
                res[i+j] = cur % BASE;
                carry = cur / BASE;
            }
            if (carry) res[i+(int)y.size()] += carry;
        }
        res.trim();
        if (res.isZero()) res.sign = 1;
        return res;
    }

    BigInt shifted(int k) const {
        if (isZero()) return *this;
        BigInt r = *this;
        r.digit.insert(r.digit.begin(), k, 0);
        return r;
    }

    BigInt karatsuba(const BigInt &a, const BigInt &b) {
        if (a.size() < 32 || b.size() < 32) {
            return mul_simple(a, b);
        }
        size_t n = max(a.size(), b.size());
        size_t k = n / 2;

        BigInt a_low, a_high, b_low, b_high;
        int m1 = min(k, a.size()), m2 = min(k, b.size());
        a_low.digit.assign(a.digit.begin(), a.digit.begin() + m1);
        a_high.digit.assign(a.digit.begin() + m1, a.digit.end());
        b_low.digit.assign(b.digit.begin(), b.digit.begin() + m2);
        b_high.digit.assign(b.digit.begin() + m2, b.digit.end());
        a_low.sign = a_high.sign = b_low.sign = b_high.sign = 1;
        a_low.trim(); a_high.trim();
        b_low.trim(); b_high.trim();

        BigInt z0 = karatsuba(a_low, b_low);
        BigInt z1 = karatsuba(a_high, b_high);
        BigInt z2 = karatsuba(a_low + a_high, b_low + b_high) - z1 - z0;
        BigInt res = z1.shifted(2 * k) + z2.shifted(k) + z0;
        res.trim();
        res.sign = (a.sign != b.sign ? -1 : 1);
        return res;
    }

    // ------------------------ Div / Mod -----------------------
    pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1) {
        assert(b1 != 0); // not divided for 0
        ll norm = BASE / (b1.digit.back() + 1);
        BigInt a = a1.abs() * norm;
        BigInt b = b1.abs() * norm;
        BigInt q = 0, r = 0;
        q.digit.resize(a.size());

        for (int i = a.size() - 1; i >= 0; i--) {
            r *= BASE;
            r += a[i];
            int64_t s1 = r.size() <= b.size() ? 0 : r[b.size()];
            int64_t s2 = r.size() <= b.size() - 1 ? 0 : r[b.size() - 1];
            int64_t d = (BASE * s1 + s2) / b.digit.back();
            if (d >= BASE) {
                d = BASE - 1;
            }
            r -= b * d;
            while (r < 0) {
                r += b, --d;
            }
            q[i] = d;
        }
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim(); r.trim();

        BigInt remainder;
        remainder.digit.resize(r.size());
        int64_t carry = 0;
        for (int i = (int)r.size() - 1; i >= 0; i--) {
            int64_t cur = r[i] + carry * BASE;
            remainder[i] = cur / norm;
            carry = cur % norm;
        }
        remainder.trim();
        auto res = make_pair(q, remainder);
        if (res.second < 0) {
            res.second += b1.abs();
        }
        return res;
    }

    // ------------------------- Misc ---------------------------
    size_t size() const { return digit.size(); }

    bool isZero() const { return digit.empty(); }

    void trim() {
        while (!digit.empty() && !digit.back()) {
            digit.pop_back();
        }
        if (digit.empty()) sign = 1;
    }

    BigInt abs() const { BigInt res = *this; res.sign = 1; return res; }

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    // only support b >= 0, if b < 0 need to implement modulo inverse
    friend BigInt pow(const BigInt &a, const BigInt &b, ll mod) { return pow(a, b, BigInt(mod)); }
    friend BigInt pow(const BigInt &a, const BigInt &b, const BigInt &mod) {
        BigInt x(a), y(b), res(1);
        while (y != 0) {
            if (y[0] % 2 == 1) res = res * x % mod;
            x = x * x % mod;
            y /= 2;
        }
        return res;
    }
    friend BigInt pow(const BigInt &a, const BigInt &b) {
        BigInt x(a), y(b), res(1);
        while (y != 0) {
            if (y[0] % 2 == 1) res = res * x;
            x = x * x;
            y /= 2;
        }
        return res;
    }

    friend BigInt __gcd(const BigInt &a, const BigInt &b) {
        if (b == 0) return a;
        return __gcd(b, a % b);
    }

    friend BigInt __lcm(const BigInt &a, const BigInt &b) {
        return a / __gcd(a, b) * b;
    }

    // safe sqrt for long long and BigInt
    friend BigInt sqrt(const BigInt &a1) {
        BigInt a = a1;
        while (a.digit.empty() || a.size() % 2 == 1) {
            a.digit.push_back(0);
        }

        int n = a.size();
        int firstDigit = (int) sqrt((double) a[n - 1] * BASE + a[n - 2]);
        int norm = BASE / (firstDigit + 1);
        a = a * norm * norm;
        while (a.digit.empty() || a.size() % 2 == 1) {
            a.digit.push_back(0);
        }

        BigInt r = 1ll * a[n - 1] * BASE + a[n - 2];
        firstDigit = (int) sqrt((double) a[n - 1] * BASE + a[n - 2]);
        int q = firstDigit;
        BigInt res;

        for (int j = n / 2 - 1; j >= 0; j--) {
            for (; ; --q) {
                BigInt r1 = (r - (res * 2 * BigInt(BASE) + q) * q) * BigInt(BASE) * BigInt(BASE);
                r1 += (j > 0 ? 1ll * a[2 * j - 1] * BASE + a[2 * j - 2] : 0);
                if (r1 >= 0) {
                    r = r1;
                    break;
                }
            }
            res *= BASE;
            res += q;

            if (j > 0) {
                int d1 = res.size() + 2 < r.size() ? r[res.size() + 2] : 0;
                int d2 = res.size() + 1 < r.size() ? r[res.size() + 1] : 0;
                int d3 = res.size() < r.size() ? r[res.size()] : 0;
                q = (1ll * d1 * BASE * BASE + 1ll * d2 * BASE + d3) / (firstDigit * 2);
            }
        }

        res.trim();
        return res / norm;
    }

    // ---------------------- Input Output ---------------------
    /* only use for decimal number */
    void read(const string &s) {
        sign = (s[0] == '-' ? -1 : 1);
        digit.clear();
        int pos = (s[0] == '-' ? 1 : 0);
        for (int i = (int)s.size() - 1; i >= pos; i -= BASE_DIGITS) {
            int x = 0;
            int k = max(pos, i - BASE_DIGITS + 1);
            for (int j = k; j <= i; j++) {
                x = x * 10 + (s[j] - '0');
            }
            digit.push_back(x);
        }
        trim();
    }

    friend istream &operator >> (istream &in, BigInt &a) {
        string s; in >> s;
        a.read(s);
        return in;
    }

    friend ostream &operator << (ostream &out, const BigInt &a) {
        if (a.sign == -1 && !a.isZero()) out << '-';
        out << (a.digit.empty() ? 0 : a.digit.back());
        for (int i = (int)a.size() - 2; i >= 0; i--)
            out << setw(BASE_DIGITS) << setfill('0') << a[i];
        return out;
    }
};