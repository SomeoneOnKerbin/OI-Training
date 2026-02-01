// Problem: P1656 炸铁路
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P1656
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int timestamp = 1;
vector<int> adj[N];
int dfn[N], low[N];

vector<pair<int, int>> ans;

void tarjan(int u, int fa) {
    dfn[u] = low[u] = timestamp++;

    for (auto &v : adj[u]) {
        if (v == fa)
            continue;

        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] > dfn[u]) {
                ans.push_back({u, v});
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, 0);
        }
    }

    sort(ans.begin(), ans.end());

    for (auto &x : ans) {
        // if (x.first > x.second)
        // swap(x.first, x.second);

        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}