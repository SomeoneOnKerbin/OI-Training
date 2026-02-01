// Problem: A. 动物园
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2420/problem/1#
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, m;
int m[N];
vector<pair<int, int>> edges;

bool cmp(pair<int, int> x, pair<int, int> y) {
    return min(m[x.first], m[x.second]) > min(m[y.first], m[y.second]);
}

struct Dsu {
    vector<int> pa, siz;

    Dsu(int n) {
        pa.resize(n + 128);
        siz.resize(n + 128);
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
        siz[find(y)] += siz[find(x)];
        pa[find(x)] = find(y);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef LOCAL
    freopen("zoo.in", "r", stdin);
    freopen("zoo.out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < m; i++) {
        // cerr << edges[i].first << ' ' << edges[i].second << '\n';
    }

    int sum = 0;
    Dsu dsu(n + 128);

    for (int i = 0; i < m; i++) {
        int rootX = dsu.find(edges[i].first);
        int rootY = dsu.find(edges[i].second);
        int w = min(m[edges[i].first], m[edges[i].second]);

        int left = dsu.siz[rootX], right = dsu.siz[rootY];
        if (dsu.find(rootX) != dsu.find(rootY)) {
            // 沟通两个联通块
            dsu.merge(rootX, rootY);
            sum += left * right * w;
        }
    }

    cout << fixed << setprecision(3) << sum * 2.0 / (n * (n - 1));

    return 0;
}