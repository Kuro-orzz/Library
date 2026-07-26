#include "../../template.h"


// for both negative + positive val
ll GCD(ll a, ll b) {
    a = llabs(a), b = llabs(b);
    return (!b ? a : GCD(b, a % b));
}
ll LCM(ll a, ll b) { return (!a || !b) ? 0 : llabs(a / GCD(a, b) * b); }

// Only positive
// ll GCD(ll a, ll b) { return (!b ? a : GCD(b, a % b)); }
// ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }

// logb(a)
double log_base(ll a, ll b) { return log(a) / log(b); }

// use for 2 <= BASE <= 36
string decimal_to_base(ll n, int BASE) {
    if (!n) return "0";
    bool neg = (n < 0 ? 1 : 0);
    n = llabs(n);
    string num = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res;
    while(n) {
        res.push_back(num[n % BASE]);
        n /= BASE;
    }
    if (neg) res += '-';
    reverse(all(res));
    return res;
}

// any BASE to decimal
// use ctype lib
ll convert_decimal(string s, int BASE) {
    auto val = [&](char c) { c = toupper(c); return (isdigit(c) ? c-'0' : c-'A'+10); };
    ll n = s.size(), p = 1, res = 0;
    for (int i = n-1; i >= 0; i--) {
        res += val(s[i]) * p;
        p = p * BASE;
    }
    return res;
}