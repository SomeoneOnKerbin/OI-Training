#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int m[N];
vector<int> adj[N];

int tot;
int m[N], sum[N];

void dfs1(int u, int pa, int dist) {
    sum[u] += m[u];

    tot += dist * m[u];

    for (auto &v : adj[u]) {
        if (v == pa)
            continue;
        dfs1(v, u, dist + 1);
        sum[u] += sum[v];
    }
}

void dfs2(int u, int pa) {
    for (auto &v : adj[u]) {
        if (v == pa)
            continue;
        m[v] = m[u] + sum[1] - 2 * sum[v];
        dfs2(v, u);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef LOCAL
    freopen("pirate.in", "r", stdin);
    freopen("pirate.out", "w", stdout);
#endif

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 0, 0);
    m[1] = tot;
    dfs2(1, 0);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, m[i]);
    }

    cout << ans;

    return 0;
}
