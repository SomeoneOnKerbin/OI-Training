#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;

vector<int> adj[N];
int dfn[N], low[N], timestamp = 1;
stack<int> stk;

vector<vector<int>> bcc;

void tarjan(int u, int fa) {
    dfn[u] = low[u] = timestamp++;
    stk.push(u);

    int child = 0;
    for (auto v : adj[u]) {
        if (v == fa)
            continue;

        if (!dfn[v]) {
            child++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] >= dfn[u]) {
                vector<int> block;
                while (true) {
                    int x = stk.top();
                    stk.pop();
                    block.push_back(x);
                    if (x == v)
                        break;
                }
                block.push_back(u);
                bcc.push_back(block);
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (fa == 0 && child == 0) {
        bcc.push_back({u});
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
        adj[u].push_back(v);
        adj[v].push_back(u);
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