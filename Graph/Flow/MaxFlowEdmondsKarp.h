// // vnoi version
// struct EdmondsKarp {
//     int n;
//     vector<vector<int>> adj;
//     vector<vector<ll>> c, f;
//     vector<int> trace;

//     EdmondsKarp(int n) : n(n), adj(n + 1), c(n + 1, vector<ll>(n + 1, 0)), f(n + 1, vector<ll>(n + 1, 0)) {}

//     void addEdge(int u, int v, ll w) {
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         c[u][v] += w;
//     }

//     bool bfs(int s, int t) {
//         trace.assign(n + 1, 0);
//         queue<int> q;
//         q.push(s);
//         trace[s] = -1;
//         while (!q.empty()) {
//             int u = q.front(); q.pop();
//             for (int v : adj[u]) {
//                 if (trace[v] || c[u][v] - f[u][v] == 0) continue;
//                 trace[v] = u;
//                 q.push(v);
//             }
//         }
//         return trace[t] != 0;
//     }

//     ll maxFlow(int s, int t) {
//         ll res = 0;
//         while (bfs(s, t)) {
//             ll delta = LLONG_MAX;
//             for (int v = t; v != s; v = trace[v]) {
//                 int u = trace[v];
//                 delta = min(delta, c[u][v] - f[u][v]);
//             }
//             for (int v = t; v != s; v = trace[v]) {
//                 int u = trace[v];
//                 f[u][v] += delta;
//                 f[v][u] -= delta;
//             }
//             res += delta;
//         }
//         return res;
//     }

//     bool inA(int u) { return trace[u] != 0; }
// };

// optimize memory version
struct EdmondsKarp {
    struct Edge {
        int v, rev;
        ll cap, flow;
    };
    int n;
    vector<vector<Edge>> g;
    vector<int> trace, id;

    EdmondsKarp(int n) : n(n), g(n + 1) {}

    void addEdge(int u, int v, ll c) {
        int iu = g[u].size(), iv = g[v].size() + (u == v);
        g[u].push_back({v, iv, c, 0});
        g[v].push_back({u, iu, 0, 0});
    }

    bool bfs(int s, int t) {
        trace.assign(n + 1, -1);
        id.assign(n + 1, -1);
        trace[s] = s;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < (int)g[u].size(); i++) {
                Edge &e = g[u][i];
                if (trace[e.v] != -1 || e.cap - e.flow == 0) continue;
                trace[e.v] = u;
                id[e.v] = i;
                q.push(e.v);
                if (e.v == t) return true;
            }
        }
        return trace[t] != -1;
    }

    ll maxFlow(int s, int t) {
        ll res = 0;
        while (bfs(s, t)) {
            ll delta = LLONG_MAX;
            for (int v = t; v != s; v = trace[v]) {
                Edge &e = g[trace[v]][id[v]];
                delta = min(delta, e.cap - e.flow);
            }
            for (int v = t; v != s; v = trace[v]) {
                Edge &e = g[trace[v]][id[v]];
                e.flow += delta;
                g[v][e.rev].flow -= delta;
            }
            res += delta;
        }
        return res;
    }

    bool inA(int u) { return trace[u] != -1; }
};
