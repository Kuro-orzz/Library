#include "../../template.h"

// Graph
int bfs01(int s, int n, vector<vector<pii>> &g) {
    vector<int> d(n+1, INT_MAX);
    deque<int> q; 
    q.push_front(s); 
    d[s] = 0;
    while (!q.empty()){
        int u = q.front(); q.pop_front();
        for (pii edge : g[u]){
            int v = edge.fi;
            int w = edge.se;
            if (w + d[u] < d[v]){
                d[v] = w + d[u];
                if (!w) {
                    q.push_front(v);
                } else {
                    q.push_back(v);
                }
            }
        }
    }
    return d[n];
}


// Matrix 0-1
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool isValid(pii u, int n, int m) { return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m; }

int bfs01(vector<vector<int>> &grid, int n, int m) {
    vector<vector<int>> d(n, vector<int>(m, INT_MAX));
    deque<pii> q;
    q.push_front({0, 0});
    d[0][0] = grid[0][0];
    while (!q.empty()) {
        pii u = q.front(); q.pop_front();
        for (int i = 0; i < 4; i++) {
            pii v = {u.fi + dx[i] ,u.se + dy[i]};
            if (!isValid(v, n, m)) continue;
            int w = grid[v.fi][v.se];
            if (w + d[u.fi][u.se] < d[v.fi][v.se]) {
                d[v.fi][v.se] = w + d[u.fi][u.se];
                if (!w) q.push_front(v);
                else q.push_back(v);
            }
        }
    }
    return d[n-1][m-1];
}