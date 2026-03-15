#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

int n, m;
vector<int> adj[N];

int dfn[N], low[N], color[N], timestamp = 1, bcnt = 1;
int siz[N];

stack<int> stk;

bool instk[N];

void tarjan(int u) {
    dfn[u] = low[u] = timestamp++;
    stk.push(u);
    instk[u] = 1;

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
            int v = stk.top();
            stk.pop();
            instk[v] = 0;
            siz[bcnt]++;
            color[v] = bcnt;
            if (v == u)
                break;
        }

        bcnt++;
    }
}

vector<int> adj2[N];
int in[N], out[N];
vector<pair<int, int>> edges;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);

        edges.emplace_back(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cerr << "Node " << i << ": color = " << color[i] << "\n";
    }

    for (auto ed : edges) {
        int u = ed.first, v = ed.second;
        if (color[u] != color[v]) {
            adj2[color[u]].push_back(color[v]);

            in[color[v]]++;
            out[color[u]]++;
        }
    }

    int cnt = 0, tgt = 0;
    for (int i = 1; i < bcnt; i++) {
        if (out[i] == 0) {
            cnt++;
            tgt = i;
        }
    }

    if (cnt != 1) {
        cout << 0;
    } else {
        cout << siz[tgt];
    }

    return 0;
}