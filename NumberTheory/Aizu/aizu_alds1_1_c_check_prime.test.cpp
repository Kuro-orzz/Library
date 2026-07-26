#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C"

#include "../../template.h"
#include "../Math/CheckPrime.h"

void solve() {
    int n; cin >> n;
    int cnt = 0;
    while (n--) {
        ll x; cin >> x;
        cnt += BruteForce(x);
    }
    cout << cnt << '\n';
}