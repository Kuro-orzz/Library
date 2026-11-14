#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "../../template.h"
#include "../Math/CheckPrime.h"
#include "../Math/Sieve.h"

void solve() {
    int n, a, b; cin >> n >> a >> b;
    ll cnt_pi = Meissel(n);
    
    int lim = 1e6;
    vector<int> need;
    int i = 0;
    while (a*i + b <= n && (int)need.size() < lim) {
        need.push_back(a*i+b);
        i++;
    }

    vector<ll> prime = listPrime(0ll, (ll)lim);
    vector<int> res;
    int cnt = 0, idx = 0;
    for (int l = 2; l <= n; l += lim) {
        int r = min(l + lim - 1, n);
        vector<int> isPrime(r - l + 1, 1);
        for (ll p : prime) {
            ll low = max(p*p, (l+p-1)/p*p);
            for (ll j = low; j <= r; j += p) {
                if (j-l >= 0) isPrime[j-l] = 0;
            }
        }
        // vector<int> isPrime = segmentSieve(l, r);

        for (int p = l; p <= min(r, n); p++) {
            if (!isPrime[p-l]) continue;
            if (cnt == need[idx]) {
                res.push_back(p);
                idx++;
            }
            cnt++;
            if (idx == (int)need.size()) break;
        }

        if (idx == (int)need.size()) break;
    }

    cout << cnt_pi << ' ' << res.size() << '\n';
    for (int x : res) cout << x << ' ';
}