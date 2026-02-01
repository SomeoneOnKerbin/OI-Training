#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n;
int m[N], g[N];
vector<pair<int, int>> adj[N];

void dfs1(int u, int pa) {
    for (auto &ed : adj[u]) {
        if (ed.first == pa)
            continue;

        if (ed.second == -1) {
            m[ed.first]++;
        }

        dfs1(ed.first, u);

        m[u] += m[ed.first];
    }
}

void dfs2(int u, int pa) {
    for (auto &ed : adj[u]) {
        if (ed.first == pa)
            continue;

        int v = ed.first;

        g[v] = g[u] + ed.second;
        dfs2(ed.first, u);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back({v, 1});
        adj[v].push_back({u, -1});
    }

    dfs1(1, 0);
    g[1] = m[1];

    dfs2(1, 0);

    int ans = 1e14;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, g[i]);
    }

    cout << ans << "\n";

    for (int i = 1; i <= n; i++) {
        if (g[i] == ans) {
            cout << i << " ";
        }
    }

    return 0;
}
