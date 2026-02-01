// Problem: B. 采购特价商品
// Time Limit: 1000 ms
// URL: http://oj.mqcoj.cn:5000/p/P1744?tid=697b4c87ac2ac5ec76c5e80d
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

struct P {
    int x, y;

    double dis(P &other) const {
        return sqrt(powf64(x - other.x, 2) + powf64(y - other.y, 2));
    }
} p[N];

int n, m, s, t;
double dis[N];
vector<pair<int, double>> adj[N];

void dijsktra() {
    priority_queue<pair<double, int>, vector<pair<double, int>>,
                   greater<pair<double, int>>>
        pq;

    pq.push({0, s});
    dis[s] = 0;

    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();

        int u = tmp.second;
        double d = tmp.first;

        if (d > dis[u])
            continue;

        for (auto &ed : adj[u]) {
            int v = ed.first;
            double w = ed.second;

            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    for (int i = 1; i <= n; i++) {
        dis[i] = 1e14;
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        double w = p[u].dis(p[v]);

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cin >> s >> t;

    dijsktra();

    cout << fixed << setprecision(2) << dis[t];

    return 0;
}