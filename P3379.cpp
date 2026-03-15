#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;

int n, m, s;
vector<int> adj[N];

int dep[N], fa[N], top[N], siz[N], son[N];

void dfs(int u, int pa) {
    dep[u] = dep[pa] + 1;
    fa[u] = pa;
    siz[u] = 1;

    int maxx = 0;
    for (int v : adj[u]) {
        if (v == pa)
            continue;
        dfs(v, u);
        siz[u] += siz[v];
        if (siz[v] > maxx) {
            maxx = siz[v];
            son[u] = v;
        }
    }
}

void dfs2(int u, int topfa) {
    top[u] = topfa;
    if (!son[u])
        return;

    dfs2(son[u], topfa);

    for (auto v : adj[u]) {
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);

        x = fa[top[x]];
    }

    if (dep[x] > dep[y])
        return y;
    else
        return x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(s, 0);
    dfs2(s, s);

    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

    return 0;
}