#pragma once

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())

#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll get_rand(ll r) { return uniform_int_distribution<ll>(0, r - 1)(rng); }

const int mod = 998244353;

void solve();

int main() {
    // if (FILE* f = fopen(TASK ".inp", "r")) {
    //     fclose(f);
    //     freopen(TASK ".inp", "r", stdin);
    //     freopen(TASK ".out", "w", stdout);
    // }
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}