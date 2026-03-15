#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;
const int MOD = 998244353;

int n, m;

struct edge {
    int u, v, idx = 1;

    bool operator<(const edge &other) const { return idx > other.idx; }
} edges[N];

int power(int a, int k) {
    if (k == 0)
        return 1;

    if (k % 2 == 0) {
        int base = power(a, k / 2);
        return base * base % MOD;
    } else {
        return a * power(a, k - 1) % MOD;
    }
}

struct Dsu {
    vector<int> pa, siz;

    Dsu(int size) {
        pa.resize(size + 1);
        siz.resize(size + 1, 1);
        iota(pa.begin(), pa.end(), 0);
    }

    int find(int x) {
        if (x == pa[x]) {
            return x;
        }
        pa[x] = find(pa[x]);
        return pa[x];
    }

    void merge(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) {
            return;
        }

        // keep rootX >= rootY
        if (siz[rootX] < siz[rootY]) {
            swap(rootX, rootY);
            swap(x, y);
        }

        pa[rootY] = rootX;
        siz[rootX] += siz[rootY];
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> edges[i].u >> edges[i].v;
        edges[i].idx = i;
    }

    int cnt = n;

    sort(edges + 1, edges + m + 1);

    Dsu dsu(n + 128);

    int cost = 0;
    for (int i = 1; i <= m; i++) {
        int u = edges[i].u, v = edges[i].v;

        if (cnt == 2) {
            for (int j = i; j <= m; j++) {
                int uu = edges[j].u, vv = edges[j].v;

                if (dsu.find(uu) == dsu.find(vv)) {
                    continue;
                }

                cerr << edges[j].idx << "\n";
                cost += power(2, edges[j].idx);
                cost %= MOD;
            }

            break;
        }

        if (dsu.find(u) != dsu.find(v)) {
            dsu.merge(u, v);
            cnt--;
        }

        cerr << "merge " << u << " " << v << " " << cnt << "\n";
    }

    cout << cost;

    return 0;
}