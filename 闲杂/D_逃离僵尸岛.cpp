// Problem: C. 逃离僵尸岛
// Time Limit: 1000 ms
// URL: http://oj.mqcoj.cn:5000/p/P3393?tid=697b4c87ac2ac5ec76c5e80d
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;

int n, m, K, s;
int p, q;
int c[N];

bool vis[N];
unordered_map<int, bool> danger, ilikeit;

int dis[N];
vector<int> adj[N];

int getval(int x) {
    if (x == 1 || x == n)
        return 0;

    if (danger.find(x) != danger.end() && danger[x] == true)
        return q;
    else
        return p;
}

void bfs(int src) {
    queue<pair<int, int>> q;
    q.push({src, 0});

    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();

        int u = tmp.first, d = tmp.second;

        if (d > s)
            continue;

        danger[u] = true;

        for (auto &v : adj[u]) {
            if (!vis[v]) {
                q.push({v, d + 1});
                vis[v] = true;
            }
        }
    }
}

void dijsktra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({getval(1), 1});
    dis[1] = getval(1);

    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        int d = tmp.first, u = tmp.second;

        if (ilikeit[u])
            continue;

        if (d > dis[u])
            continue;

        for (auto &v : adj[u]) {
            if (ilikeit[v])
                continue;

            if (dis[v] > dis[u] + getval(v)) {
                dis[v] = dis[u] + getval(v);
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dis, 0x3f, sizeof dis);

    cin >> n >> m >> K >> s;
    cin >> p >> q;

    for (int i = 1; i <= K; i++) {
        cin >> c[i];
        ilikeit[c[i]] = true;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= K; i++) {
        memset(vis, 0, sizeof vis);
        bfs(c[i]);
    }

    dijsktra();

    cout << dis[n];

    return 0;
}