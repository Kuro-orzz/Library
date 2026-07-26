#include "../../template.h"
#include "../../Misc/ModInt.h"
#include "Binary_exponentiation.h"
#include "Extended_euclid.h"

// This modint only work for MOD is prime cuz using modulo inverse
// using mint = ModInt<MOD>;

// vector<mint> fact;

// void preprocess() {
//     fact[0] = 1;
//     for (int i = 1; i < (int)fact.size(); i++) {
//         fact[i] = fact[i-1] * i;
//     }
// }

// mint comb(int n, int k) {
//     if (k < 0 || k > n) return 0; 
//     return fact[n] / (fact[n-k] * fact[k]);
// }
// -----------------------------------------------------

// Using for n, k <= 1e6, m is prime and n < m < 2^31
struct Comb {
    ll m;
    vector<int> fact, invFact;

    Comb() {}
    Comb(int maxn, ll _m) : m(_m), fact(maxn+1), invFact(maxn+1) {
        fact[0] = 1;
        for (int i = 1; i <= maxn; i++) fact[i] = (ll)fact[i-1] * i % m;
        invFact[maxn] = binPow(fact[maxn], m-2, m);
        for (int i = maxn; i >= 1; i--) invFact[i-1] = (ll)invFact[i] * i % m;
    }

    // C(n, k) = n! / (k! * (n-k)!)
    ll comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return 1ll * fact[n] * invFact[k] % m * invFact[n-k] % m;
    }

    // P(n,k) = n! / (n−k)!
    ll perm(int n, int k) {
        if (k < 0 || k > n) return 0;
        return 1ll * fact[n] * invFact[n-k] % m;
    }

    // inv(i) = (i-1)! / i! = 1/i
    // modulo inverse of i
    ll inv(int i) { return i <= 0 ? 0 : 1ll * invFact[i] * fact[i-1] % m; }

    // catalan(n) = C(2n, n) / (n+1)
    // require 2*n <= maxn
    ll Catalan(int n) { return 1ll * comb(2*n, n) * inv(n+1) % m; }
};


// Pascal triangle
// Using for n * k <= 1e7 or n,k <= 5000, O(1) per operation
vector<vector<int>> preprocess(int n, int k, int m) {
    vector<vector<int>> C(n+1, vector<int>(k+1));
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1 % m;
        for (int j = 1; j <= min(i, k); j++) {
            C[i][j] = (1ll * C[i-1][j-1] + C[i-1][j]) % m;
        }
    }
    return C;
}

// m must be prime
// fermat's little theorem a^(m-2) ≡ a^(-1)
ll inverse1(ll a, ll m) { return binPow(a, m-2, m); }
// m must be prime
// base on extended euclid trick
ll inverse2(ll a, ll m) { return a <= 1 ? a : m-m/a * inverse2(m % a, m) % m; }
// m coprime to a, gcd(a, m) = 1
// extended euclid trick
ll inverse3(ll a, ll m) {
    ll x, y;
    extended2(a, m, x, y);
    return (x % m + m) % m;
}