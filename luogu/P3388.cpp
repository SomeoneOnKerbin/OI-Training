// Problem: P3388 【模板】割点（割顶）
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P3388
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int timestamp = 1;
int dfn[N], low[N];
bool iscut[N];

vector<int> adj[N];

void tarjan(int u, int fa) {
    dfn[u] = low[u] = timestamp++;
    int child = 0;

    for (auto &v : adj[u]) {
        if (v == fa)
            continue;

        if (!dfn[v]) {
            child++;
            tarjan(v, u);

            low[u] = min(low[u], low[v]);

            if (fa != 0 && low[v] >= dfn[u]) {
                iscut[u] = true;
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (fa == 0 && child >= 2) {
        iscut[u] = true;
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

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (iscut[i]) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for (auto &x : ans) {
        cout << x << " ";
    }

    return 0;
}