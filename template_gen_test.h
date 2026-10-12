#include <bits/stdc++.h>
using namespace std;

#define TASK "test"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) { return l + rng() % (r - l + 1); }

void gen() {
    ofstream f(TASK ".inp");
    // int n = rnd(1, 10);
    // f << n << "\n";
    // for (int i = 0; i < n; i++) f << rnd(1, 100) << " \n"[i == n - 1];
}

vector<ll> solve1(istream& cin) { vector<ll> ans; return ans; } // optimize solution
vector<ll> solve2(istream& cin) { vector<ll> ans; return ans; } // bruteforce solution

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for (int t = 1; t <= 100; t++) {
        gen();

        ifstream i1(TASK ".inp"), i2(TASK ".inp");
        vector<ll> a = solve1(i1), b = solve2(i2);
        
        if (a.empty() && b.empty()) {
            cout << "Rong, kiem tra gen/solve\n";
            return 0;
        }
        if (a != b) {
            cout << "WRONG at test " << t << " (xem " TASK ".inp)\n";
            cout << "sol  :"; for (ll x : a) cout << ' ' << x; cout << '\n';
            cout << "brute:"; for (ll x : b) cout << ' ' << x; cout << '\n';
            return 0;
        }
    }
    cout << "AC\n";
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}