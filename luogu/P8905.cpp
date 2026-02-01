// Problem: P8905 [USACO22DEC] Strongest Friendship Group G
// Time Limit: 2000 ms
// URL: https://www.luogu.com.cn/problem/P8905
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, m;
int ans = 0;

vector<int> adj[N];

int maxsiz = 0;

int rem[N], degrem[N], act[N];
int deg[N];

void toposort() {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    for (int i = 1; i <= n; i++) {
        pq.push({deg[i], i});
    }

    int idx = 1;
    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();

        int u = tmp.second, d = tmp.first;
        if (rem[u] != 0)
            continue;

        rem[u] = idx;
        degrem[u] = d;
        idx++;

        for (auto &v : adj[u]) {
            if (rem[v] == 0) {
                deg[v]--;
                pq.push({deg[v], v});
            }
        }
    }
}

struct Dsu {
    vector<int> pa, siz;

    Dsu(int size) {
        pa.resize(size + 128);
        siz.resize(size + 128);

        for (int i = 1; i <= n; i++) {
            pa[i] = i;
            siz[i] = 1;
        }
    }

    int find(int x) {
        if (x == pa[x])
            return x;
        pa[x] = find(pa[x]);
        return pa[x];
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (siz[rootX] > siz[rootY]) {
            swap(rootX, rootY);
            swap(x, y);
        }

        pa[rootX] = rootY;
        siz[rootY] += siz[rootX];

        maxsiz = max(maxsiz, siz[rootY]);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }

    toposort();

    // [删除顺序, Node Id]
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
        pq;

    for (int i = 1; i <= n; i++) {
        pq.push({rem[i], i});
    }

    Dsu dsu(n + 128);
    while (!pq.empty()) {
        auto tmp = pq.top();
        int u = tmp.second;

        pq.pop();

        int mind = degrem[u];
        act[u] = true;

        for (auto &v : adj[u]) {
            if (act[v]) {
                dsu.merge(u, v);
            }
        }


        // cerr << u << " " << mind << " " << maxsiz << "\n";

        ans = max(ans, maxsiz * mind);
    }

    cout << ans;

    return 0;
}