#include "../../template.h"


ll inf = 1e18;

struct Node {
    ll max1, max2, cntMax, min1, min2, cntMin, sum, lazy, sz;

    Node() {
        max1 = max2 = -inf;
        min1 = min2 = inf;
        cntMax = cntMin = 0;
        sum = lazy = sz = 0;
    }

    Node(ll val) {
        max1 = min1 = val;
        max2 = -inf;
        min2 = inf;
        cntMax = cntMin = 1;
        sum = val;
        lazy = 0;
        sz = 1;
    }

    Node operator+(const Node &b) {
        Node res;

        res.max1 = max(max1, b.max1);
        res.max2 = max(max2, b.max2);
        if (res.max1 != max1) res.max2 = max(res.max2, max1);
        if (res.max1 != b.max1) res.max2 = max(res.max2, b.max1); 
        res.cntMax = 0;
        if (res.max1 == max1) res.cntMax += cntMax;
        if (res.max1 == b.max1) res.cntMax += b.cntMax;

        res.min1 = min(min1, b.min1);
        res.min2 = min(min2, b.min2);
        if (res.min1 != min1) res.min2 = min(res.min2, min1);
        if (res.min1 != b.min1) res.min2 = min(res.min2, b.min1);
        res.cntMin = 0;
        if (res.min1 == min1) res.cntMin += cntMin;
        if (res.min1 == b.min1) res.cntMin += b.cntMin;

        res.sum = sum + b.sum;
        res.lazy = 0;
        res.sz = sz + b.sz;

        return res;
    }

    void setMin(ll x) {
        if (x >= max1) return;
        sum -= (max1 - x) * cntMax;
        max1 = x;
        min1 = min(min1, x);
        if (min2 != inf) min2 = min(min2, x);
    }

    void setMax(ll x) {
        if (x <= min1) return;
        sum += (x-min1) * cntMin;
        min1 = x;
        max1 = max(max1, x);
        if (max2 != -inf) max2 = max(max2, x);
    }

    void add(ll x) {
        max1 += x;
        min1 += x;
        if (max2 != -inf) max2 += x;
        if (min2 != inf) min2 += x;
        sum += x * sz;
        lazy += x;
    }
};

// range chmin, chmax, update range, sum
class SegTreeBeats {
public:
    vector<Node> tree;

    SegTreeBeats(int n): tree(4*n+6) {}

    void build(int id, int l, int r, int pos, ll val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            tree[id] = Node(val);
            return;
        }
        int mid = (l + r) >> 1;
        build(id*2, l, mid, pos, val);
        build(id*2+1, mid+1, r, pos, val);
        tree[id] = tree[id*2] + tree[id*2+1];
    }   

    void push(int id) {
        tree[id*2].add(tree[id].lazy);
        tree[id*2+1].add(tree[id].lazy);
        tree[id].lazy = 0;

        tree[id*2].setMax(tree[id].min1);
        tree[id*2+1].setMax(tree[id].min1);

        tree[id*2].setMin(tree[id].max1);
        tree[id*2+1].setMin(tree[id].max1);
    }

    void updateChmax(int id, int l, int r, int u, int v, ll x) {
        if (l > v || r < u) return;
        if (tree[id].min1 >= x) return;
        if (u <= l && r <= v && tree[id].min2 > x) {
            tree[id].setMax(x);
            return;
        }
        push(id);
        int mid = (l + r) >> 1;
        updateChmax(id*2, l, mid, u, v, x);
        updateChmax(id*2+1, mid+1, r, u, v, x);
        tree[id] = tree[id*2] + tree[id*2+1];
    }

    void updateChmin(int id, int l, int r, int u, int v, ll x) {
        if (l > v || r < u) return;
        if (tree[id].max1 <= x) return;
        if (u <= l && r <= v && tree[id].max2 < x) {
            tree[id].setMin(x);
            return;
        }
        push(id);
        int mid = (l + r) >> 1;
        updateChmin(id*2, l, mid, u, v, x);
        updateChmin(id*2+1, mid+1, r, u, v, x);
        tree[id] = tree[id*2] + tree[id*2+1];
    }

    void updateRange(int id, int l, int r, int u, int v, ll x) {
        if (l > v || r < u) return;
        if (u <= l && r <= v) {
            tree[id].add(x);
            return;
        }
        push(id);
        int mid = (l + r) >> 1;
        updateRange(id*2, l, mid, u, v, x);
        updateRange(id*2+1, mid+1, r, u, v, x);
        tree[id] = tree[id*2] + tree[id*2+1];
    }

    ll getSum(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return tree[id].sum;
        push(id);
        int mid = (l + r) >> 1;
        ll t1 = getSum(id*2, l, mid, u, v);
        ll t2 = getSum(id*2+1, mid+1, r, u, v);
        return t1 + t2;
    }
};