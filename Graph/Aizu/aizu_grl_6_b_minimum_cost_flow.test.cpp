#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

#include "../../template.h"
#include "../Flow/MinCostFlow.h"

void solve() {
    int n, m; ll F; cin >> n >> m >> F;
    MinCostFlow mcf(n);
    for (int i = 0; i < m; i++) {
        int u, v; ll c, d; cin >> u >> v >> c >> d;
        mcf.addEdge(u, v, c, d);
    }
    auto [flow, cost] = mcf.minCostFlow(0, n-1, F);
    cout << (flow < F ? -1 : cost) << '\n';
}