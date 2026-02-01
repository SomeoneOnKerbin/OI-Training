#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    struct node {
        int l, r;
        int val = 0;
    };

    vector<node> t;

    void pushup(int p) { /* Pushup Code Here */ }

    void pushdown(int p) { /* Pushdown Code Here */ }

    SegmentTree(int size) { t.resize(4 * size); }

    void build(int p, int l, int r) {
        t[p].l = l;
        t[p].r = r;

        if (l == r) {
            /* Default Value Here */
            return;
        }

        int mid = (l + r) / 2;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);
        pushup(p);
    }

    void update(int p, int k, int v) {
        int l = t[p].l, r = t[p].r;
        if (l == r) {
            /* Update value at leaf node here */
            return;
        }

        int mid = (l + r) / 2;
        if (k <= mid)
            update(p * 2, k, v);
        else
            update(p * 2 + 1, k, v);

        pushup(p);
    }

    /* Design Custom Query Here */
};