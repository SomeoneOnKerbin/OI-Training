// Problem: D - Paid Walk
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc441/tasks/abc441_d
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, m, l, s, t;
vector<pair<int, int>> adj[N];

bool ava[N];

struct node {
    int u, l, w;
};

void bfs() {
    queue<node> q;

    q.push({1, 0, 0});

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();

        if (tmp.l > 10)
            continue;

        if (s <= tmp.w && tmp.w <= t && tmp.l == l) {
            ava[tmp.u] = true;
        }

        if (tmp.w > t) {
            continue;
        }

        for (auto &ed : adj[tmp.u]) {
            int v = ed.first, w = ed.second;
            q.push({v, tmp.l + 1, tmp.w + w});
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> l >> s >> t;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    bfs();

    for (int i = 1; i <= n; i++) {
        if (ava[i]) {
            cout << i << " ";
        }
    }

    return 0;
}