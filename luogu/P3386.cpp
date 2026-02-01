// Problem: P3386 【模板】二分图最大匹配
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P3386
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, m, e;
vector<int> adj[N];

int vis[N], match[N];

bool dfs(int u) {
    for (auto &v : adj[u]) {
        if (vis[v])
            continue;
        vis[v] = true;

        if (match[v] == 0 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }

    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> e;

    for (int i = 1; i <= e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        if (dfs(i)) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}