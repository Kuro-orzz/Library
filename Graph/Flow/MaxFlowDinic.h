// // vnoi version
// struct Dinic {
//     int n;
//     vector<vector<int>> adj;
//     vector<vector<ll>> c, f;
//     vector<int> d, ptr;

//     Dinic(int n) : n(n), adj(n + 1), c(n + 1, vector<ll>(n + 1, 0)), f(n + 1, vector<ll>(n + 1, 0)) {}

//     void addEdge(int u, int v, ll w) {
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         c[u][v] += w;
//     }

//     bool bfs(int s, int t) {
//         d.assign(n + 1, -1);
//         d[s] = 0;
//         queue<int> q; q.push(s);
//         while (!q.empty()) {
//             int u = q.front(); q.pop();
//             for (int v : adj[u]) {
//                 if (d[v] != -1 || c[u][v] - f[u][v] == 0) continue;
//                 d[v] = d[u] + 1;
//                 q.push(v);
//             }
//         }
//         return d[t] != -1;
//     }

//     ll dfs(int u, int t, ll delta) {
//         if (u == t) return delta;
//         for (; ptr[u] < (int)adj[u].size(); ptr[u]++) {
//             int v = adj[u][ptr[u]];
//             if (d[v] != d[u] + 1 || c[u][v] - f[u][v] == 0) continue;
//             ll got = dfs(v, t, min(delta, c[u][v] - f[u][v]));
//             if (got == 0) continue;
//             f[u][v] += got;
//             f[v][u] -= got;
//             return got;
//         }
//         return 0;
//     }

//     ll maxFlow(int s, int t) {
//         ll res = 0;
//         while (bfs(s, t)) {
//             ptr.assign(n + 1, 0);
//             while (ll delta = dfs(s, t, LLONG_MAX)) res += delta;
//         }
//         return res;
//     }

//     bool inA(int u) { return d[u] != -1; }
// };

// optimize memory version
struct Dinic {
    struct Edge {
        int v, rev;
        ll cap, flow;
    };
    int n;
    vector<vector<Edge>> g;
    vector<int> d, ptr;

    Dinic(int n) : n(n), g(n + 1) {}

    void addEdge(int u, int v, ll c) {
        int iu = g[u].size(), iv = g[v].size() + (u == v);
        g[u].push_back({v, iv, c, 0});
        g[v].push_back({u, iu, 0, 0});
    }

    bool bfs(int s, int t) {
        d.assign(n + 1, -1);
        d[s] = 0;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (Edge &e : g[u]) {
                if (d[e.v] != -1 || e.cap - e.flow == 0) continue;
                d[e.v] = d[u] + 1;
                q.push(e.v);
            }
        }
        return d[t] != -1;
    }

    ll dfs(int u, int t, ll delta) {
        if (u == t) return delta;
        for (; ptr[u] < (int)g[u].size(); ptr[u]++) {
            Edge &e = g[u][ptr[u]];
            if (d[e.v] != d[u] + 1 || e.cap - e.flow == 0) continue;
            ll got = dfs(e.v, t, min(delta, e.cap - e.flow));
            if (got == 0) continue;
            e.flow += got;
            g[e.v][e.rev].flow -= got;
            return got;
        }
        return 0;
    }

    ll maxFlow(int s, int t) {
        ll res = 0;
        while (bfs(s, t)) {
            ptr.assign(n + 1, 0);
            while (ll delta = dfs(s, t, LLONG_MAX)) res += delta;
        }
        return res;
    }

    bool inA(int u) { return d[u] != -1; }
};
