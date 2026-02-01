#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int ans = 0;
int m[N];

vector<pair<int, int>> adj[N];

void dfs(int u, int pa, int dis, int minn) {
    if (u != 1) {
        if (dis - m[u] > minn) {
            return;
        }
    }

    ans++;
    for (auto &ed : adj[u]) {
        int v = ed.first, w = ed.second;
        if (v == pa)
            continue;

        dfs(v, u, dis + w, min(minn, dis));
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }

    for (int i = 2; i <= n; i++) {
        int fa, w;
        cin >> fa >> w;

        adj[fa].push_back({i, w});
        adj[i].push_back({fa, w});
    }

    dfs(1, 0, 0, 1e9);

    cout << n - ans;

    return 0;
}
