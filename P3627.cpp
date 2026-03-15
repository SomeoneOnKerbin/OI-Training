#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;

int n, m;

bool bar[N], barbcc[N];

int dfn[N], low[N], timestamp = 1;
int color[N], bcnt = 1;
int wt[N], a[N];

bool instk[N];

stack<int> stk;
vector<int> adj[N];

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

    if (low[u] == dfn[u]) {
        while (true) {
            int v = stk.top();
            stk.pop();
            instk[v] = false;
            color[v] = bcnt;

            if (bar[v])
                barbcc[bcnt] = true;

            wt[bcnt] += a[v];

            if (v == u)
                break;
        }

        bcnt++;
    }
}

vector<pair<int, int>> edges;
vector<int> adj2[N];

int ans = 0;
int f[N], in[N];

int s, p;

void toposort() {
    deque<int> dq;

    for (int i = 1; i < bcnt; i++) {
        if (in[i] == 0) {
            dq.push_back(i);
        }
    }

    f[color[s]] = wt[color[s]];

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (auto v : adj2[u]) {
            f[v] = max(f[v], f[u] + wt[v]);
            in[v]--;

            if (barbcc[v]) {
                ans = max(ans, f[v]);
            }

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

    memset(f, -0x3f, sizeof f);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        edges.emplace_back(u, v);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> s >> p;

    for (int i = 1; i <= p; i++) {
        int x;
        cin >> x;
        bar[x] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    for (auto e : edges) {
        int u = e.first, v = e.second;

        if (color[u] != color[v]) {
            adj2[color[u]].push_back(color[v]);
            in[color[v]]++;
        }
    }

    toposort();

    cout << ans;

    return 0;
}