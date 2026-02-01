// Problem: C. 通信网络
// Time Limit: 900 ms
// URL: http://oj.mqcoj.cn:5000/p/18246?tid=697a114cac2ac5ec76c48475
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, K;
pair<int, int> w[N];

vector<int> adj[N];

int tree[N];

void clear() {
    for (int i = 0; i <= n; i++)
        tree[i] = 0;
}

int lowbit(int x) { return x & -x; }

void add(int x, int v) {
    for (; x <= n; x += lowbit(x))
        tree[x] += v;
}

int query(int x) {
    int res = 0;
    for (; x; x -= lowbit(x))
        res += tree[x];
    return res;
}

int query(int l, int r) { return query(r) - query(l - 1); }

int comb2(int n) { return n * (n - 1) / 2; }

int tot = 0;
int dfn[N], siz[N], fa[N];

void dfs(int u, int pa) {
    fa[u] = pa;
    dfn[u] = ++tot;
    siz[u] = 1;
    for (auto &v : adj[u]) {
        if (v == pa)
            continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
}

bool check(int lambda) {
    clear();

    int ptr = 1;

    for (int i = 1; i <= n; i++) {
        int idz = w[i].second;
        int valz = w[i].first;

        int limit = valz + lambda;

        while (ptr <= n && w[ptr].first <= limit) {
            int tmpid = w[ptr].second;
            add(dfn[tmpid], 1);
            ptr++;
        }

        int tot = ptr - 1;
        int load = comb2(tot);

        for (auto &v : adj[idz]) {
            if (v == fa[idz])
                continue;

            int cnt = query(dfn[v], dfn[v] + siz[v] - 1);
            load -= comb2(cnt);
        }

        int subcnt = query(dfn[idz], dfn[idz] + siz[idz] - 1);
        int facnt = tot - subcnt;
        load -= comb2(facnt);

        if (load >= K)
            return false;
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef LOCAL
    freopen("network.in", "r", stdin);
    freopen("network.out", "w", stdout);
#endif

    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        cin >> w[i].first;
        w[i].second = i;
    }

    sort(w + 1, w + n + 1);

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    int l = -1e6, r = 1e6, res = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << res;
    return 0;
}
