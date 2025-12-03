#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "../../template.h"
#include "../Manacher.h"

void solve() {
    string s; cin >> s;
    s = '$' + s;
    vector<int> odd = calc_odd(s);
    vector<int> even = calc_even(s);
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (i != n-1) {
            cout << odd[i]*2+1 << ' ' << even[i]*2 << ' ';
        } else {
            cout << odd[i]*2+1;
        }
    }
}