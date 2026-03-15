#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9 + 7;

int n, m;
vector<pair<int, int>> adj[N];

struct edge {
    int u, v, w;
} e[N];

int in[N], out[N];
int dis[N];

int ans[N];

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    dis[s] = 0;
    pq.emplace(0, s);

    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        int u = tmp.second, d = tmp.first;
        if (d > dis[u])
            continue;

        for (auto ed : adj[u]) {
            int v = ed.first, w = ed.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.emplace(dis[v], v);
            }
        }
    }
}

void solve(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));

    dijkstra(s);

    vector<pair<int, int>> tmp;

    for (int i = 1; i <= n; i++) {
        tmp.emplace_back(dis[i], i);
    }

    sort(tmp.begin(), tmp.end());

    vector<int> topo;
    for (auto &p : tmp) {
        topo.push_back(p.second);
    }

    in[s] = 1;

    for (auto u : topo) {
        for (auto ed : adj[u]) {
            int v = ed.first, w = ed.second;

            if (dis[u] + w == dis[v]) {
                in[v] += in[u];
                in[v] %= MOD;
            }
        }
    }

    reverse(topo.begin(), topo.end());

    for (auto u : topo) {
        if (out[u] == 0) {
            out[u] = 1;
        }

        for (auto ed : adj[u]) {
            int v = ed.first, w = ed.second;

            if (dis[u] + w == dis[v]) {
                out[u] += out[v];
                out[u] %= MOD;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;

        if (dis[u] + w == dis[v]) {
            ans[i] += (in[u] * out[v]) % MOD;
            ans[i] %= MOD;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        e[i] = {u, v, w};
    }

    for (int i = 1; i <= n; i++) {
        solve(i);
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] % MOD << "\n";
    }

    return 0;
}