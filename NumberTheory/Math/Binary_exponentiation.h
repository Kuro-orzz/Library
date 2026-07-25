#include "../../template.h"

using u128 = __uint128_t;
using i128 = __int128;

ll binMul(ll a, ll b, ll M) { return (i128)a * b % M; }

// long double trick
// require: mantissa 64 bit, x86 gcc/clang
ll binMul2(ll a, ll b, ll M) {
    ll q = (ll)((long double)a * b / M);
    ll r = (ll)((unsigned ll)a * b - (unsigned ll)q * M);
    return r < 0 ? r + M : (r >= M ? r - M : r);
}

ll binMul3(ll a, ll b, ll M) {
    unsigned long long ua = a % M, um = M, res = 0;
    while (b) {
        if (b & 1) { res += ua; if (res >= um) res -= um; }
        ua <<= 1; if (ua >= um) ua -= um;
        b >>= 1;
    }
    return res;
}

ll binPow(ll a, ll b, ll M) {
    a %= M;
    ll res = 1;
    while (b) {
        if (b & 1) res = (i128)res * a % M;
        a = (i128)a * a % M;
        b /= 2;
    }
    return res;
}