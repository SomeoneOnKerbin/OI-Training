#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100 + 5;

int n, m;
vector<int> adj[N];
int deg[N];
pair<int, int> edge[N];
int ans = 0;

int cntol[N];

void dfs(int p, bitset<32> online) {
    if (p == m + 1) {
        memset(cntol, 0, sizeof(int) * (10));

        for (int i = 1; i <= m; i++) {
            if (online[i]) {
                cntol[edge[i].first]++;
                cntol[edge[i].second]++;
            }
        }

        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (cntol[i] != deg[i] / 2) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ans++;
        }

        return;
    }

    online[p] = 0;
    dfs(p + 1, online);
    online[p] = 1;
    dfs(p + 1, online);
}

void solveA() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        deg[i] = 0;
        edge[i] = {0, 0};
        cntol[i] = 0;
    }

    ans = 0;

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        edge[i] = {u, v};

        deg[u]++;
        deg[v]++;
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 != 0) {
            cout << "0\n";
            return;
        }
    }

    dfs(1, bitset<32>());

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef LOCAL
    freopen("friends.in", "r", stdin);
    freopen("friends.out", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--) {
        solveA();
    }

    return 0;
}