#include "../../template.h"
#include "../../Misc/ModInt.h"
#include "Binary_exponentiation.h"
#include "Extended_euclid.h"

// This modint only work for MOD is prime cuz using modulo inverse
using mint = ModInt<MOD>;

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


// Using for n * k <= 1e7 or n,k <= 5000, O(1) per operation
vector<vector<int>> preprocess(int n, int k, int m) {
    vector<vector<int>> C(n+1, vector<int>(k+1));
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= min(i, k); j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % m;
        }
    }
    return C;
}

// Using for n, k <= 1e6, MOD is prime
const int N = 1e6 + 6;
vector<ll> fact(N), inv(N), invFact(N);

void preprocess() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    // slow version
    invFact[0] = invFact[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < N; i++) {
        inv[i] = MOD - (ll)(MOD/i) * inv[MOD%i] % MOD;
        invFact[i] = invFact[i-1] * inv[i] % MOD;
    }
    // Optimize version
    // invFact[N-1] = binPow(fact[N-1], MOD-2, MOD);
    // for (int i = N-2; i >= 0; i--) {
    //     invFact[i] = invFact[i+1] * (i + 1) % MOD;
    // }
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

ll comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    // ll t = binMul(fact[k], fact[n-k], MOD);
    // return fact[n] * inverse2(t, MOD) % MOD;
    return fact[n] * invFact[k] % MOD * invFact[n-k] % MOD;
}