// Problem: B. 联通
// Time Limit: 1000 ms
// URL: http://oj.mqcoj.cn:5000/p/18245?tid=697a114cac2ac5ec76c48475
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

struct Dsu {
    vector<int> pa, siz;

    Dsu(int size) {
        pa.resize(size + 128);
        siz.resize(size + 128);

        for (int i = 1; i < size; i++) {
            pa[i] = i;
            siz[i] = 1;
        }
    }

    int find(int x) {
        if (pa[x] == x)
            return x;
        pa[x] = find(pa[x]);
        return pa[x];
    }

    void merge(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY)
            return;

        // 最晚的并入本联通块的时间
        pa[rootX] = rootY;
        siz[rootY] += siz[rootX];
    }
};

vector<pair<int, int>> edge;
vector<int> tim;

vector<pair<int, int>> adj[N];

int tot = 1;
int a[N], fa[N], son[N], top[N], siz[N], id[N], wt[N], dep[N];

struct SegmentTree {
    struct node {
        int l, r;
        int minn = 1e14, maxx = 0;
    };

    vector<node> t;

    SegmentTree(int size) {
        t.resize(4 * size + 128);
        build(1, 1, size + 4);
    }

    void pushup(int p) {
        t[p].maxx = max(t[p * 2].maxx, t[p * 2 + 1].maxx);
        t[p].minn = min(t[p * 2].minn, t[p * 2 + 1].minn);
    }

    void build(int p, int l, int r) {
        t[p].l = l;
        t[p].r = r;

        if (l == r) {
            t[p].maxx = wt[l];
            t[p].minn = wt[l];
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
            t[p].maxx = v;
            t[p].minn = v;
            return;
        }

        int mid = (l + r) / 2;
        if (k <= mid) {
            update(p * 2, k, v);
        } else {
            update(p * 2 + 1, k, v);
        }

        pushup(p);
    }

    int get(int p, int k) {
        int l = t[p].l, r = t[p].r;

        if (l == r) {
            return t[p].minn;
        }

        int mid = (l + r) / 2;
        if (k <= mid) {
            return get(p * 2, k);
        } else {
            return get(p * 2 + 1, k);
        }
    }

    int querymax(int p, int L, int R) {
        int l = t[p].l, r = t[p].r;
        // cerr << p << " " << l << " " << r << "\n";

        if (L <= l && r <= R) {
            return t[p].maxx;
        }

        int mid = (l + r) / 2, res = 0;

        if (L <= mid) {
            res = max(res, querymax(p * 2, L, R));
        }

        if (R > mid) {
            res = max(res, querymax(p * 2 + 1, L, R));
        }

        return res;
    }

    int querymin(int p, int L, int R) {
        int l = t[p].l, r = t[p].r;

        if (L <= l && r <= R) {
            return t[p].minn;
        }

        int mid = (l + r) / 2, res = 1e14;

        if (L <= mid) {
            res = min(res, querymin(p * 2, L, R));
        }

        if (R > mid) {
            res = min(res, querymin(p * 2 + 1, L, R));
        }

        return res;
    }
};

void dfs1(int u, int pa) {
    siz[u] = 1;
    fa[u] = pa;
    dep[u] = dep[pa] + 1;

    int maxx = 0;

    for (auto &ed : adj[u]) {
        int v = ed.first, w = ed.second;
        if (v == pa)
            continue;

        a[v] = max(a[v], w);

        dfs1(v, u);
        siz[u] += siz[v];

        if (siz[v] >= maxx) {
            maxx = siz[v];
            son[u] = v;
        }
    }
}

void dfs2(int u, int topfa) {
    id[u] = tot++;
    top[u] = topfa;
    wt[id[u]] = a[u];

    if (!son[u])
        return;

    dfs2(son[u], topfa);

    for (auto &ed : adj[u]) {
        int v = ed.first;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

SegmentTree tree(2e5);

// x --> LCA(不计) --> y
int querymax(int x, int y) {
    int res = 0;

    while (top[x] != top[y]) {
        if (dep[top[x]] > dep[top[y]])
            swap(x, y);

        res = max(res, tree.querymax(1, id[top[y]], id[y]));
        y = fa[top[y]];
    }

    if (dep[x] > dep[y]) {
        swap(x, y);
    }

    res = max(res, tree.querymax(1, id[x] + 1, id[y]));

    return res;
}

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] > dep[top[y]]) {
            swap(x, y);
        }

        y = fa[top[y]];
    }

    if (dep[x] > dep[y])
        return y;
    else
        return x;
}

int cost[N];

int read() {
    int x = 0;
    char c = getchar_unlocked();
    bool neg = false;

    while (!isdigit(c)) {
        if (c == '-')
            neg = true;
        c = getchar_unlocked();
    }

    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar_unlocked();
    }

    if (neg)
        return -x;
    else
        return x;
}

void write(int x) {
    if (x < 0) {
        x = -x;
        putchar_unlocked('-');
    }

    if (x >= 10) {
        write(x / 10);
    }

    putchar_unlocked(x % 10 + '0');
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef LOCAL
    freopen("link.in", "r", stdin);
    freopen("link.out", "w", stdout);
#endif

    int n = read(), m = read(), q = read();

    Dsu dsu(n + 128);
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();

        if (dsu.find(u) != dsu.find(v)) {
            edge.push_back({u, v});
            tim.push_back(i);
            dsu.merge(u, v);

            adj[u].push_back({v, i});
            adj[v].push_back({u, i});

            // cerr << u << " " << v << "\n";
        }
    }

    edge.insert(edge.begin(), {0, 0});
    tim.insert(tim.begin(), 0);

    dfs1(1, 0);
    dfs2(1, 1);
    tree.build(1, 1, n);

    SegmentTree costtree(n + 128);
    for (int i = 1; i <= n - 1; i++) {
        cost[i] = querymax(i, i + 1);
        costtree.update(1, i, cost[i]);
    }

    while (q--) {
        int x = read(), y = read();
        // cin >> x >> y;

        int ans = costtree.querymax(1, x, y - 1);
        write(ans);
        putchar_unlocked(' ');

        // cout << ans << " ";

        // int ans = 0, LCA = x;
        // for (int j = x; j <= y; j++) {
        //     LCA = lca(LCA, j);
        // }

        // int ans = 0;
        // for (int j = x; j <= y - 1; j++) {
        //     ans = max(ans, querymax(j, j + 1));
        // }

        // cout << ans << " ";
    }

    return 0;
}
