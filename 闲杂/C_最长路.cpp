// Problem: C. 最长路
// Time Limit: 1000 ms
// URL: http://oj.mqcoj.cn:5000/p/5894?tid=697b4c87ac2ac5ec76c5e80d
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, m;
vector<pair<int, int>> adj[N];

int dis[N];

void spfa() {
    queue<pair<int, int>> q;

    dis[1] = 0;
    q.push({0, 1});

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();

        int d = tmp.first, u = tmp.second;

        dis[u] = max(dis[u], d);

        for (auto &ed : adj[u]) {
            int v = ed.first, w = ed.second;

            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dis, -0x3f, sizeof dis);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    spfa();

    if (dis[n] < -1e14)
        cout << -1;
    else
        cout << dis[n];

    return 0;
}