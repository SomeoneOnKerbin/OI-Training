// Problem: A. 营救
// Time Limit: 1000 ms
// URL: http://oj.mqcoj.cn:5000/p/P1396?tid=697b4c87ac2ac5ec76c5e80d
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

struct edge {
    int u, v, w;

    bool operator<(const edge &ed) const { return w < ed.w; }
} edges[N];

struct Dsu {
    vector<int> pa, siz;

    Dsu(int size) {
        pa.resize(size);
        siz.resize(size);
        fill(siz.begin(), siz.end(), 1);

        for (int i = 1; i < size; i++) {
            pa[i] = i;
        }
    }

    int find(int x) {
        if (pa[x] == x)
            return x;
        pa[x] = find(pa[x]);
        return pa[x];
    }

    void merge(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY)
            return;

        if (siz[rootX] > siz[rootY]) {
            swap(x, y);
            swap(rootX, rootY);
        }

        pa[rootX] = rootY;
        siz[rootY] += siz[rootX];
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges + 1, edges + m + 1);

    Dsu dsu(n + 128);
    for (int i = 1; i <= m; i++) {
        dsu.merge(edges[i].u, edges[i].v);

        if (dsu.find(s) == dsu.find(t)) {
            cout << edges[i].w;
            break;
        }
    }

    return 0;
}