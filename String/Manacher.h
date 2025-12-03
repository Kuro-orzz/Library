#include "../template.h"

// Base = 1
// s = '$' + s;
// vector<int> odd = calc_odd(s);
// vector<int> even = calc_even(s);
// not count center as palindrome

vector<int> calc_odd(string &s) {
    int n = s.size();
    vector<int> d(n);
    int l = 1, r = 0;
    for (int i = 1; i < n; i++) {
        if (i > r) d[i] = 0;
        else d[i] = min(r-i, d[l+r-i]);
        while (i-d[i]-1 > 0 && i+d[i]+1 < n && s[i-d[i]-1] == s[i+d[i]+1]) {
            d[i]++;
        }
        if (i + d[i] > r) {
            l = i - d[i];
            r = i + d[i];
        }
    }
    return d;
}

vector<int> calc_even(string &s) {
    int n = s.size();
    vector<int> d(n);
    int l = 1, r = 0;
    for (int i = 1; i < n-1; i++) {
        int j = i+1;
        if (j > r) d[i] = 0;
        else d[i] = min(r-j+1, d[l+r-j]);
        while (i-d[i] >= 0 && j+d[i] < n && s[i-d[i]] == s[j+d[i]]) {
            d[i]++;
        }
        if (i + d[i] > r) {
            l = j - d[i];
            r = i + d[i];
        }
    }
    return d;
}