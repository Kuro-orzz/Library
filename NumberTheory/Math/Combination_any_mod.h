#include "../../template.h"
#include "Binary_exponentiation.h"
#include "Factorization.h"


// https://codeforces.com/blog/entry/116681
// https://wiki.vnoi.info/translate/he/Lucas-theorem
// Extended Lucas (granville theorem)
// C(n, k) % m when m is NOT prime
//
// Step 1: cut m into prime powers
//    m = p1^e1 * p2^e2 * ...
// => solve C(n, k) % p^e for each one, then glue them back by CRT
// CRT works here because p1^e1, p2^e2, ... are pairwise coprime
//
// Step 2: solve one p^e
// write each factorial as n! = p^t * a with gcd(a, p) = 1
// => t counts how many times p divides n!, a is everything else
// a holds no factor p, so a is ALWAYS invertible mod p^e
//    C(n, k) = p^E * a(n) / (a(k) * a(n-k))
//    E = t(n) - t(k) - t(n-k)
// => E >= e means p^e divides C(n, k), so the answer is 0
//
// Step 3: how to get t (legendre formula)
//    t = n/p + n/p^2 + n/p^3 + ...     (integer division, stop when it hits 0)
//
// Step 4: how to get a
// split off the multiples of p first
//    n! = p^(n/p) * (n/p)! * n!_p
// with n!_p = product of j in [1, n] that p does not divide
// => repeat on (n/p)! until it becomes 0, that is log_p(n) rounds
//
// n!_p is easy because the units repeat with period p^e
//    n!_p = ((p^e - 1)!_p)^(n / p^e) * (n % p^e)!_p
// (p^e - 1)!_p is the product of every unit mod p^e
// by wilson theorem it is -1 when p is odd or p^e = 2 or 4, and +1 otherwise
// => it is always +1 or -1, so only the parity of n / p^e matters, no binPow needed
//
// Example m = 10 = 2 * 5, C(4, 2) = 6
//    p = 2: t(4) = 3, t(2) = 1, t(2) = 1 => E = 1 >= e = 1 => 0
//    p = 5: t are all 0 => E = 0
//           a(4) = 4, a(2) = 2 => 4 * 2^-1 * 2^-1 = 4 * 3 * 3 = 1 (mod 5)
//    CRT: x = 0 (mod 2), x = 1 (mod 5) => x = 6, and 6 % 10 = 6


// C(n, k) % p^e
// O(p^e) build and memory, O(log n) per query, require p^e <= 1e7
struct CombPrimePower {
    ll p, e, pe, phi, unit;
    vector<ll> f, pw;   // f[i] = prod of j in [1, i] with p not dividing j, % pe
                        // pw[i] = p^i % pe
    // every value here is < pe <= 1e7 so products stay under 1e14, plain ll is enough

    CombPrimePower() {}
    CombPrimePower(ll _p, ll _e) : p(_p), e(_e) {
        pe = 1;
        for (ll i = 0; i < e; i++) pe *= p;
        phi = pe - pe / p;                  // a^-1 = binPow(a, phi-1, pe)
        f.resize(pe);
        f[0] = 1 % pe;
        for (ll i = 1; i < pe; i++) f[i] = (i % p == 0) ? f[i-1] : f[i-1] * i % pe;
        unit = f[pe-1];                     // +1 or -1, so only parity matters in fact()
        pw.resize(e+1);
        pw[0] = 1 % pe;
        for (ll i = 1; i <= e; i++) pw[i] = pw[i-1] * p % pe;
    }

    // kept apart from fact() on purpose: it is the cheap half, and letting comb()
    // bail out on it first skips 3 fact() calls, worth 3x on m with many factors
    ll expo(ll n) {
        ll t = 0;
        while (n > 0) {
            n /= p;
            t += n;
        }
        return t;
    }

    // same as factmod() in Factorial.h but for p^e instead of p
    ll fact(ll n) {
        ll a = 1 % pe;
        while (n > 0) {
            if ((n / pe) & 1) a = a * unit % pe;
            a = a * f[n % pe] % pe;
            n /= p;
        }
        return a;
    }

    ll comb(ll n, ll k) {
        if (k < 0 || k > n) return 0;
        ll E = expo(n) - expo(k) - expo(n-k);
        if (E >= e) return 0;
        ll d = fact(k) * fact(n-k) % pe;    // multiply first, one inverse instead of two
        return fact(n) * binPow(d, phi-1, pe) % pe * pw[E] % pe;
    }
};

// C(n, k) % m for any m
// O(m) build and memory, O(log^2 n) per query, require every p^e <= 1e7
struct CombAnyMod {
    ll m;
    vector<CombPrimePower> pp;
    vector<ll> w;   // CRT weight, w[i] = M_i * (M_i^-1 % pe_i) % m with M_i = m / pe_i

    CombAnyMod() {}
    CombAnyMod(ll _m) : m(_m) {
        for (pll pe : primeFactorPow(m)) pp.push_back(CombPrimePower(pe.fi, pe.se));
        for (CombPrimePower &c : pp) {      // w does not depend on n, k
            ll M = m / c.pe;
            w.push_back((i128)M * binPow(M % c.pe, c.phi - 1, c.pe) % m);
        }
    }

    ll comb(ll n, ll k) {
        ll res = 0;
        for (int i = 0; i < (int)pp.size(); i++) {
            ll a = pp[i].comb(n, k);
            if (a) res = (res + (i128)a * w[i] % m) % m;
        }
        return res;
    }
};