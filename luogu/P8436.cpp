// Problem: P8436 【模板】边双连通分量
// Time Limit: 2000 ms
// URL: https://www.luogu.com.cn/problem/P8436
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;

int id = 2, timestamp = 1;
int dfn[N], low[N];
vector<pair<int, int>> adj[N];
vector<vector<int>> ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back({v, id++});
        adj[v].push_back({u, id++});
    }

    stack<int> stk;
    auto tarjan = [&](auto &&self, int u, int from) -> void {
        stk.push(u);
        dfn[u] = low[u] = timestamp++;

        for (auto &ed : adj[u]) {
            int v = ed.first, eid = ed.second;
            if (eid == (from ^ 1))
                continue;

            if (!dfn[v]) {
                self(self, v, eid);
                low[u] = min(low[u], low[v]);
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }

        if (low[u] == dfn[u]) {
            vector<int> comp;

            while (!stk.empty() && stk.top() != u) {
                comp.push_back(stk.top());
                stk.pop();
            }

            comp.push_back(stk.top());
            stk.pop();

            ans.push_back(comp);
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(tarjan, i, 0);
        }
    }

    cout << ans.size() << "\n";
    for (auto &comp : ans) {
        cout << comp.size() << " ";
        for (auto &x : comp) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}