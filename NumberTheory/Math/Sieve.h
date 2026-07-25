#include "../../template.h"

vector<int> sieve(int n) {
    vector<int> nt(n+1, 1);
    nt[0] = nt[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (!nt[i]) continue;
        for (int j = i * i; j <= n; j += i)
            nt[j] = 0;
    }
    return nt;
}

vector<int> segmentSieve(ll l, ll r){
    ll sq = sqrtl(r);
    while (sq * sq > r) sq--;
    while (sq+1 <= r/(sq+1)) sq++;
    vector<int> small(sq+1, 1);
    for (ll i = 2; i*i <= sq; i++) {
        if (!small[i]) continue;
        for (ll j = i*i; j <= sq; j += i) {
            small[j] = 0;
        }
    }
    vector<int> prime(r-l+1, 1);
    for(ll p = 2; p <= sq; p++){
        if (!small[p]) continue;
        ll lim = max(p*p, (l+p-1)/p*p);
        for(ll j = lim; j <= r; j += p) {
            prime[j-l] = 0;
        }
    }
    if (l == 0) prime[0] = 0;
    if (l == 0 && r > l) prime[1] = 0;
    if (l == 1) prime[1-l] = 0;
    return prime;
}

vector<int> listPrime(int l, int r) {
    vector<int> prime = segmentSieve(l, r);
    vector<int> listPi;
    for (int i = l; i <= r; i++) {
        if (prime[i-l]) listPi.push_back(i);
    }
    return listPi;
}

vector<int> sieve_count_divisors(int n) {
    vector<int> divisors(n+1, 0);
    for (ll i = 1; i*i <= n; i++) {
        for (ll j = i*i; j <= n; j += i) {
            divisors[j] += 2;
        }
        divisors[i*i]--;
    }
    return divisors;
}

vector<int> sieve_sum_divisors(int n) {
    vector<int> sumDiv(n+1, 0);
    for (int i = 1; i*i <= n; i++) {
        for (int j = i*i; j <= n; j += i) {
            sumDiv[j] += i;
            if (i*i != j) sumDiv[j] += j/i;
        }
    }
    return sumDiv;
}

vector<int> segmentSieveDivisors(int l, int r){
    vector<int> div(r-l+1, 0);
    for(ll i = 1; i*i <= r; i++){
        ll lim = max(i*i, (l+i-1)/i*i);
        for(ll j = lim; j <= r; j += i) {
            div[j-l] += 2;
        }
        if (i * i >= l) div[i*i-l]--;
    }
    if (l == 0) div[0] = 0;
    return div;
}

vector<vector<int>> sieve_prime_divisors(int n) {
    vector<int> prime = sieve(n);
    vector<vector<int>> div(n+1);
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) continue;
        for (int j = i; j <= n; j += i) {
            div[j].push_back(i);
        }
    }
    return div;
}