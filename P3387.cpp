#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

int n, m;
int a[N];
vector<int> adj[N], adj2[N];
stack<int> stk;

int color[N], dfn[N], low[N], val[N];
int timestamp = 1, bcnt = 1;

bool instk[N];

void tarjan(int u) {
    dfn[u] = low[u] = timestamp++;

    stk.push(u);
    instk[u] = true;

    for (auto v : adj[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (instk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        while (true) {
            int x = stk.top();
            stk.pop();

            instk[x] = false;
            color[x] = bcnt;
            val[bcnt] += a[x];

            if (x == u)
                break;
        }

        bcnt++;
    }
}

vector<pair<int, int>> edges;

int ans = 0;
int f[N], in[N];

void toposort() {
    deque<int> dq;

    for (int i = 1; i < bcnt; i++) {
        if (in[i] == 0) {
            dq.push_back(i);
        }
    }

    while (!dq.empty()) {
        auto u = dq.front();
        dq.pop_front();

        f[u] += val[u];
        ans = max(ans, f[u]);

        for (auto v : adj2[u]) {
            in[v]--;
            f[v] = max(f[v], f[u]);

            if (in[v] == 0) {
                dq.push_back(v);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        edges.push_back({u, v});
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    for (int i = 1; i <= m; i++) {
        int u = edges[i - 1].first;
        int v = edges[i - 1].second;

        if (color[u] != color[v]) {
            adj2[color[u]].push_back(color[v]);
            in[color[v]]++;
        }
    }

    toposort();

    cout << ans;

    return 0;
}