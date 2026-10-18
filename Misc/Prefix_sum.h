#include "../template.h"

/* ---------- 2D prefix sum (range sum query) ---------- */
vector<vector<ll>> prefix_2d_init(int n, int m, const vector<vector<int>> &a) {
    vector<vector<ll>> pref(n+1, vector<ll>(m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i-1][j-1];
        }
    }
    return pref;
}

ll get(const vector<vector<ll>> &pref, int a, int b, int c, int d) {
    return pref[c][d]-pref[c][b-1]-pref[a-1][d]+pref[a-1][b-1];
}

/* ---------- 2D difference (range add -> point value) ---------- */
vector<vector<ll>> diff_2d_init(int n, int m) {
    return vector<vector<ll>>(n+2, vector<ll>(m+2));
}

void diff_2d_add(vector<vector<ll>> &d, int x1, int y1, int x2, int y2, ll v) {
    d[x1][y1] += v;
    d[x2+1][y1] -= v;
    d[x1][y2+1] -= v;
    d[x2+1][y2+1] += v;
}

void diff_2d_build(vector<vector<ll>> &d, int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];
        }
    }
}

/* ---------- 3D difference (range add -> point value) ---------- */
vector<vector<vector<ll>>> diff_3d_init(int n, int m, int p) {
    return vector<vector<vector<ll>>>(n+2, vector<vector<ll>>(m+2, vector<ll>(p+2)));
}

void diff_3d_add(vector<vector<vector<ll>>> &d,
                 int x1, int y1, int z1, int x2, int y2, int z2, ll v) {
    d[x1][y1][z1]       += v;
    d[x2+1][y1][z1]     -= v;
    d[x1][y2+1][z1]     -= v;
    d[x1][y1][z2+1]     -= v;
    d[x2+1][y2+1][z1]   += v;
    d[x2+1][y1][z2+1]   += v;
    d[x1][y2+1][z2+1]   += v;
    d[x2+1][y2+1][z2+1] -= v;
}

void diff_3d_build(vector<vector<vector<ll>>> &d, int n, int m, int p) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= p; k++) {
                d[i][j][k] += d[i-1][j][k] + d[i][j-1][k] + d[i][j][k-1]
                            - d[i-1][j-1][k] - d[i-1][j][k-1] - d[i][j-1][k-1]
                            + d[i-1][j-1][k-1];
            }
        }
    }
}