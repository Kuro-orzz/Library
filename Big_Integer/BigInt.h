#include "../template.h"

class BigInt {
public:
    static const int BASE = 10;
    vector<uint32_t> digit;
    bool neg = false;

    BigInt() {}

    BigInt(int64_t val) {*this = val;}

    BigInt(const string &s) {*this = s;}

    uint32_t getDigit(const uint32_t i) const {return digit[i];}

    uint32_t size() const {return digit.size();}

    bool isZero() const {return digit.empty();}

    int compare(const BigInt &b) const {
        if (size() != b.size()) return size() > b.size() ? 1 : -1;
        for (int i = (int)size()-1; i >= 0; i--) {
            if (digit[i] != b.getDigit(i))
                return digit[i] > b.getDigit(i) ? 1 : -1;
        }
        return 0;
    }

    void trim() {
        while (!digit.empty() && digit.back() == 0)
            digit.pop_back();
        if (digit.empty()) neg = false;
    }

    BigInt &operator=(int64_t val) {
        digit.clear();
        if (val < 0) {
            neg = true;
            val = -val;
        } else neg = false;
        while (val) {
            digit.push_back(val % BASE);
            val /= BASE;
        }
        return *this;
    }

    BigInt &operator=(const string &s) {
        digit.clear();
        int32_t pos = 0;
        if (s[0] == '-') {
            neg = true;
            pos = 1;
        } else neg = false;
        for (int i = (int)s.size()-1; i >= pos; i--) {
            digit.push_back(s[i]-'0');
        }
        trim();
        return *this;
    }

    friend ostream &operator<<(ostream &out, const BigInt &b) {
        if (b.isZero()) return out << "0";
        if (b.neg) out << "-";
        for (int i = (int)b.size()-1; i >= 0; i--)
            out << b.getDigit(i);
        return out;
    }

    BigInt operator+(const BigInt &b) const {
        BigInt res;
        if (neg == b.neg) {
            res.neg = neg;
            int carry = 0;
            size_t len = max(size(), b.size());
            for (size_t i = 0; i < len; i++) {
                int sum = carry;
                if (i < size()) sum += digit[i];
                if (i < b.size()) sum += b.getDigit(i);
                res.digit.push_back(sum % BASE);
                carry = sum / BASE;
            }
            if (carry) res.digit.push_back(carry);
            res.trim();
            return res;
        } else {
            return *this - (-b);
        }
    }

    BigInt operator-(const BigInt &b) const {
        if (!neg && b.neg)
            return *this + (-b);
        if (neg && !b.neg)
            return -((-*this) + b);
        if (compare(b) == -1) 
            return -(b - *this);
        BigInt res;
        res.neg = neg;
        int borrow = 0;
        for (size_t i = 0; i < digit.size(); i++) {
            int sub = digit[i]-borrow;
            if (i < b.size()) sub -= b.getDigit(i);
            if (sub < 0) sub += BASE, borrow = 1;
            else borrow = 0;
            res.digit.push_back(sub);
        }
        res.trim();
        return res;
    }

    BigInt operator-() const {
        BigInt res = *this;
        if (!res.isZero())
            res.neg = !neg;
        return res;
    }

    BigInt mul(const BigInt &a, const BigInt &b) const {
        BigInt x = a, y = b;
        x.trim(); y.trim();
        BigInt res;
        if (x.neg != y.neg)
            res.neg = true;
        res.digit.resize(x.size()+y.size());
        for (size_t i = 0; i < x.size(); i++) {
            int carry = 0;
            for (size_t j = 0; j < y.size(); j++) {
                int64_t cur = res.getDigit(i+j) + carry;
                cur += x.digit[i] * y.getDigit(j);
                res.digit[i+j] = cur % BASE;
                carry = cur / BASE;
            }
            if (carry) res.digit[i+y.size()] += carry;
        }
        res.trim();
        if (res.isZero()) res.neg = false;
        return res;
    }

    //---------------------karatsuba----------------------
    BigInt shifted(size_t k) const {
        if (isZero()) return *this;
        BigInt r = *this;
        r.digit.insert(r.digit.begin(), k, 0);
        return r;
    }    

    BigInt karatsuba(const BigInt &a, const BigInt &b) const {
        if (a.size() < 32 || b.size() < 32)
            return mul(a, b);
        size_t n = max(a.size(), b.size());
        uint32_t k = n / 2;

        BigInt a_low, a_high;
        a_low.digit.assign(a.digit.begin(), a.digit.begin() + min(k, a.size()));
        a_high.digit.assign(a.digit.begin() + min(k, a.size()), a.digit.end());
        a_low.neg = a_high.neg = false;
        a_low.trim();
        a_high.trim();

        BigInt b_low, b_high;
        b_low.digit.assign(b.digit.begin(), b.digit.begin() + min(k, b.size()));
        b_high.digit.assign(b.digit.begin() + min(k, b.size()), b.digit.end());
        b_low.neg = b_high.neg = false;
        b_low.trim();
        b_high.trim();

        BigInt z0 = karatsuba(a_low, b_low);
        BigInt z2 = karatsuba(a_high, b_high);
        BigInt z1 = karatsuba(a_low + a_high, b_low + b_high) - z0 - z2;

        BigInt res = z2.shifted(2*k) + z1.shifted(k) + z0;
        res.neg = (a.neg != b.neg);
        res.trim();
        return res;
    }

    BigInt operator*(const BigInt &b) const {
        return karatsuba(*this, b);
    }
};