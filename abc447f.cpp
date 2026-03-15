#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

int n;
vector<int> adj[N];

// f[u][0] 以 u 为根可以构成的最长的蜈蚣图，u 是中心节点
// f[u][1] 以 u 为根可以构成的最长的蜈蚣图，u 是叶子节点
int f[N][4];

int ans = 0;

void dfs(int u, int pa) {
    int child = 0;

    for (auto v : adj[u]) {
        if (v == pa)
            continue;
        child++;
    }

    for (auto v : adj[u]) {
        if (v == pa)
            continue;

        dfs(v, u);

        if (adj[v].size() - 1 == 1) {
            f[u][1] = max({f[u][1], f[v][0] + 1, 1ll});
        } else if (adj[v].size() - 1 >= 2) {
            f[u][1] = max(f[u][1], f[v][0] + 1);
        }

        if (child >= 2) {
            f[u][0] = max(f[u][0], 1ll);
        }

        if (child >= 3) {
            f[u][0] = max(f[u][0], f[v][0] + 1);
        }

        ans = max({ans, f[u][0], f[u][1]});
    }
}

void solveA() {
    memset(f, 0, sizeof(f[0]) * (n + 128));

    ans = 0;

    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solveA();
    }

    return 0;
}