#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;

vector<pair<int, int>> adj[N];
int dfn[N], low[N], timestamp = 1;
stack<int> stk;

vector<vector<int>> bcc;

void tarjan(int u, int fid) {
    dfn[u] = low[u] = timestamp++;
    stk.push(u);

    int child = 0;
    for (auto e : adj[u]) {
        int v = e.first, id = e.second;
        if (id == fid)
            continue;

        if (!dfn[v]) {
            child++;
            tarjan(v, id);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u]) {
        vector<int> block;
        while (true) {
            int x = stk.top();
            stk.pop();
            block.push_back(x);
            if (x == u)
                break;
        }
        bcc.push_back(block);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i])
            tarjan(i, 0);
    }

    cout << bcc.size() << "\n";
    for (auto block : bcc) {
        cout << block.size() << " ";
        for (auto x : block)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}