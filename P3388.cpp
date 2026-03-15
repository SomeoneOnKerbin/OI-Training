#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

vector<int> adj[N];
vector<int> ans;

int low[N], dfn[N], timestamp = 1;

void tarjan(int u, int pa) {
    int child = 0;
    low[u] = dfn[u] = timestamp++;

    for (auto v : adj[u]) {
        if (v == pa)
            continue;

        if (!dfn[v]) {
            child++;

            tarjan(v, u);
            low[u] = min(low[u], low[v]);

            if (pa != 0 && low[v] >= dfn[u]) {
                ans.push_back(u);
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (pa == 0 && child >= 2) {
        ans.push_back(u);
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
        if (!dfn[i]) {
            tarjan(i, 0);
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }

    return 0;
}