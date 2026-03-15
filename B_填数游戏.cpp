#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;

int n, m;
vector<int> alice[N], bob[N];

struct Dsu {
    vector<int> pa, siz, val;

    Dsu(int size) {
        pa.resize(size);
        siz.resize(size, 1);
        val.resize(size, 0);

        for (int i = 0; i < size; i++) {
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
        x = find(x);
        y = find(y);

        if (x == y)
            return;

        if (siz[x] < siz[y])
            swap(x, y);

        pa[y] = x;
        siz[x] += siz[y];
        val[x] += val[y];
    }
};

void solve() {
    for (int i = 1; i <= n; i++) {
        alice[i].clear();
        bob[i].clear();
    }

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++) {
            int y;
            cin >> y;
            alice[i].push_back(y);
        }
    }

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++) {
            int y;
            cin >> y;
            bob[i].push_back(y);
        }
    }

    Dsu dsu(m + 128);

    for (int i = 1; i <= n; i++) {
        int u = bob[i][0], v;

        if (bob[i].size() == 1) {
            v = u;
        } else {
            v = bob[i][1];
        }

        if (dsu.find(u) == dsu.find(v)) {
            dsu.val[dsu.find(u)]++;
            continue;
        }

        dsu.merge(u, v);
    }

    int maxval = 0;
    for (int i = 1; i <= m; i++) {
        if (dsu.find(i) == i) {
            maxval = max(maxval, dsu.val[i]);
        }
    }

    if (maxval >= 2) {
        cout << -1 << "\n";
    } else {
        cout << 0 << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}