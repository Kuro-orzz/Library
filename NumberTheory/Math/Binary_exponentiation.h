#include "../../template.h"

using u128 = __uint128_t;
using i128 = __int128;

// require: gcc/clang 64-bit, M < 10^18
// a, b âm thì kết quả có thể âm
ll binMul(ll a, ll b, ll M) { return (i128)a * b % M; }

// long double trick
// require: mantissa 64 bit, x86 gcc/clang, M < 10^18
// dùng khi cần tốc độ
ll binMul2(ll a, ll b, ll M) {
    ll q = (ll)((long double)a * b / M);
    ll r = (ll)((unsigned ll)a * b - (unsigned ll)q * M);
    return r < 0 ? r + M : (r >= M ? r - M : r);
}

// nhân Ấn Độ
// require: M < 10^18, b >= 0
ll binMul3(ll a, ll b, ll M) {
    unsigned ll ua = ((a % M) + M) % M, ub = b, um = M, res = 0;
    while (ub) {
        if (ub & 1) { res += ua; if (res >= um) res -= um; }
        ua <<= 1; if (ua >= um) ua -= um;
        ub >>= 1;
    }
    return res;
}

// nhân Ấn Độ đệ quy
// require: M < 10^18
ll binMul4(ll a, ll b, ll M) {
    if (!b) return 0;
    ll x = binMul4(a, b / 2, M);
    if (b & 1) return (2 * x + a) % M;
    return 2 * x % M;
}

ll binPow(ll a, ll b, ll M) {
    a %= M;
    ll res = 1 % M;
    while (b) {
        if (b & 1) res = (i128)res * a % M;
        a = (i128)a * a % M;
        b /= 2;
    }
    return res;
}