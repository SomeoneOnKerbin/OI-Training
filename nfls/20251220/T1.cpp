#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int m[N], tag[N];
set<int> adj[N];

int dfs(int u, int fa) {
    tag[u] = 1;

    for (auto &v : adj[u]) {
        if (v == fa)
            continue;
        dfs(v, u);

        m[u] += m[v];
        tag[u] += tag[v];
    }

    m[u] += tag[u];

    return 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef LOCAL
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
#endif

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int fa;
        cin >> fa;

        adj[fa].insert(i);
        adj[i].insert(fa);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << m[i] << " ";
    }

    return 0;
}
