// // spfa version
// struct MinCostFlow {
//     struct Edge {
//         int v, rev;
//         ll cap, flow, cost;
//     };
//     const ll INF = LLONG_MAX / 4;
//     int n;
//     vector<vector<Edge>> g;
//     vector<ll> d;
//     vector<int> trace, id;
//     vector<bool> inq;

//     MinCostFlow(int n) : n(n), g(n + 1) {}

//     void addEdge(int u, int v, ll cap, ll cost) {
//         int iu = g[u].size(), iv = g[v].size() + (u == v);
//         g[u].push_back({v, iv, cap, 0, cost});
//         g[v].push_back({u, iu, 0, 0, -cost});
//     }

//     bool spfa(int s, int t) {
//         d.assign(n + 1, INF);
//         trace.assign(n + 1, -1), id.assign(n + 1, -1), inq.assign(n + 1, false);
//         queue<int> q;
//         d[s] = 0, q.push(s), inq[s] = true;
//         while (!q.empty()) {
//             int u = q.front(); q.pop();
//             inq[u] = false;
//             for (int i = 0; i < (int)g[u].size(); i++) {
//                 Edge &e = g[u][i];
//                 if (e.cap - e.flow == 0 || d[u] + e.cost >= d[e.v]) continue;
//                 d[e.v] = d[u] + e.cost;
//                 trace[e.v] = u, id[e.v] = i;
//                 if (!inq[e.v]) inq[e.v] = true, q.push(e.v);
//             }
//         }
//         return d[t] < INF;
//     }

//     pair<ll, ll> minCostFlow(int s, int t, ll k = LLONG_MAX) {
//         ll flow = 0, cost = 0;
//         while (flow < k && spfa(s, t)) {
//             ll delta = k - flow;
//             for (int v = t; v != s; v = trace[v]) {
//                 Edge &e = g[trace[v]][id[v]];
//                 delta = min(delta, e.cap - e.flow);
//             }
//             for (int v = t; v != s; v = trace[v]) {
//                 Edge &e = g[trace[v]][id[v]];
//                 e.flow += delta;
//                 g[v][e.rev].flow -= delta;
//             }
//             flow += delta;
//             cost += delta * d[t];
//         }
//         return {flow, cost};
//     }
// };

// vnoi version (dijkstra + potential)
struct MinCostFlow {
    struct Edge {
        int v, rev;
        ll cap, flow, cost;
    };
    const ll INF = LLONG_MAX / 4;
    int n;
    bool negCost = false;
    vector<vector<Edge>> g;
    vector<ll> pi, d;
    vector<int> trace, id;

    MinCostFlow(int n) : n(n), g(n + 1) {}

    void addEdge(int u, int v, ll cap, ll cost) {
        int iu = g[u].size(), iv = g[v].size() + (u == v);
        g[u].push_back({v, iv, cap, 0, cost});
        g[v].push_back({u, iu, 0, 0, -cost});
        negCost |= cost < 0;
    }

    void bellmanFord(int s) {
        pi.assign(n + 1, INF);
        pi[s] = 0;
        for (int it = 0; it < n; it++) {
            bool upd = false;
            for (int u = 0; u <= n; u++) {
                if (pi[u] == INF) continue;
                for (Edge &e : g[u])
                    if (e.cap - e.flow > 0 && pi[u] + e.cost < pi[e.v]) pi[e.v] = pi[u] + e.cost, upd = true;
            }
            if (!upd) break;
        }
    }

    bool dijkstra(int s, int t) {
        d.assign(n + 1, INF);
        trace.assign(n + 1, -1), id.assign(n + 1, -1);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        d[s] = 0, pq.push({0, s});
        while (!pq.empty()) {
            auto [du, u] = pq.top(); pq.pop();
            if (du != d[u]) continue;
            for (int i = 0; i < (int)g[u].size(); i++) {
                Edge &e = g[u][i];
                if (e.cap - e.flow == 0) continue;
                ll w = e.cost + pi[u] - pi[e.v];
                if (d[u] + w >= d[e.v]) continue;
                d[e.v] = d[u] + w;
                trace[e.v] = u, id[e.v] = i;
                pq.push({d[e.v], e.v});
            }
        }
        for (int u = 0; u <= n; u++)
            if (d[u] < INF) pi[u] += d[u];
        return d[t] < INF;
    }

    pair<ll, ll> minCostFlow(int s, int t, ll k = LLONG_MAX) {
        pi.assign(n + 1, 0);
        if (negCost) bellmanFord(s);
        ll flow = 0, cost = 0;
        while (flow < k && dijkstra(s, t)) {
            ll delta = k - flow, pathCost = 0;
            for (int v = t; v != s; v = trace[v]) {
                Edge &e = g[trace[v]][id[v]];
                delta = min(delta, e.cap - e.flow);
                pathCost += e.cost;
            }
            for (int v = t; v != s; v = trace[v]) {
                Edge &e = g[trace[v]][id[v]];
                e.flow += delta;
                g[v][e.rev].flow -= delta;
            }
            flow += delta;
            cost += delta * pathCost;
        }
        return {flow, cost};
    }
};
