// Problem: P8047 [COCI 2015/2016 #4] GALAKSIJA
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P8047
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

struct edge {
    int u, v, w;
} e[N];

vector<pair<int, int>> adj[N];
int p[N], d[N];

int answers[N];

struct Dsu {
    int ans = 0;
    vector<int> pa, siz;
    vector<unordered_map<int, int>> cnt;

    Dsu(int size) {
        pa.resize(size + 128);
        cnt.resize(size + 128);
        siz.resize(size + 128);

        for (int i = 1; i <= size; i++) {
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

        siz[rootY] += rootY;
        for (auto &p : cnt[rootX]) {
            ans += cnt[rootY][p.first] * p.second;
            cnt[rootY][p.first] += p.second;
        }
    }
};

void dfs(int u, int pa) {
    for (auto &ed : adj[u]) {
        int v = ed.first, w = ed.second;
        if (v == pa)
            continue;

        d[v] = d[u] ^ w;
        dfs(v, u);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;

        adj[e[i].u].push_back({e[i].v, e[i].w});
        adj[e[i].v].push_back({e[i].u, e[i].w});
    }

    dfs(1, 0);

    Dsu dsu(2e5);

    for (int i = 1; i <= n; i++) {
        dsu.cnt[i][d[i]]++;
    }

    for (int i = 1; i <= n - 1; i++) {
        cin >> p[i];
    }

    for (int i = n - 1; i >= 1; i--) {
        int u = e[p[i]].u, v = e[p[i]].v, w = e[p[i]].w;

        answers[i] = dsu.ans;

        if (dsu.find(u) != dsu.find(v)) {
            dsu.merge(u, v);
        }
    }

    answers[0] = dsu.ans;

    for (int i = 0; i <= n - 1; i++) {
        cout << answers[i] << "\n";
    }

    return 0;
}