#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include "../../template.h"
#include "../Flow/MaxFlowDinic.h"

void solve() {
    int n, m; cin >> n >> m;
    Dinic mxFlow(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        mxFlow.addEdge(u, v, w);
    }
    cout << mxFlow.maxFlow(0, n-1) << '\n';
}