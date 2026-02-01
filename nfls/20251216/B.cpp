#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n;
int m[N]; // u 被感染后，其子树内最多能拯救的节点数
int tag[N];
vector<int> adj[N];

void dfs(int u, int pa) {
    tag[u] = 1;
    m[u] = 0;
    vector<int> son;

    for (auto &v : adj[u]) {
        if (v == pa)
            continue;
        dfs(v, u);
        tag[u] += tag[v];
        son.push_back(v);
    }

    if (son.empty()) {
        m[u] = 0;
    } else if (son.size() == 1) {
        m[u] = tag[son[0]] - 1;
    } else {
        int L = son[0];
        int R = son[1];
        m[u] = max(m[L] + tag[R] - 1, m[R] + tag[L] - 1);
    }
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        tag[i] = 0;
        m[i] = 0;
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << m[1] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
