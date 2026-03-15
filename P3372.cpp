#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

struct node {
    int l, r;
    int lson, rson;
    int val, tag;

#define lson(p) t[p].lson
#define rson(p) t[p].rson
#define val(p) t[p].val
#define tag(p) t[p].tag
#define len(p) (t[p].r - t[p].l + 1)
} t[N];

int cnt = 1;

void pushup(int p) { val(p) = val(lson(p)) + val(rson(p)); }

void pushdown(int p) {
    if (tag(p)) {
        tag(lson(p)) += tag(p);
        tag(rson(p)) += tag(p);
        val(lson(p)) += tag(p) * len(lson(p));
        val(rson(p)) += tag(p) * len(rson(p));
        tag(p) = 0;
    }
}

void update(int &p, int L, int R, int v) {
    if (!p) {
        p = ++cnt;
        t[p].l = L;
        t[p].r = R;
    }

    int l = t[p].l, r = t[p].r;
    if (L <= l && r <= R) {
        val(p) += v * len(p);
        tag(p) += v;
        return;
    }

    int mid = (l + r) / 2;
    pushdown(p);
    if (L <= mid)
        update(lson(p), L, R, v);
    if (R > mid)
        update(rson(p), L, R, v);
    pushup(p);
}

int query(int p, int L, int R) {
    if (!p)
        return 0;

    int l = t[p].l, r = t[p].r;
    if (L <= l && r <= R) {
        return val(p);
    }

    int mid = (l + r) / 2;
    pushdown(p);
    int res = 0;
    if (L <= mid)
        res += query(lson(p), L, R);
    if (R > mid)
        res += query(rson(p), L, R);
    return res;
}

int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    t[1].l = 1;
    t[1].r = n + 128;

    int root = cnt++;

    for (int i = 1; i <= n; i++) {
        update(root, i, i, a[i]);
    }

    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1) {
            int v;
            cin >> v;
            update(root, l, r, v);
        } else {
            cout << query(root, l, r) << "\n";
        }
    }

    return 0;
}