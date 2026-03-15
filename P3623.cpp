#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

struct edge {
    int u, v, c;

    bool operator<(const edge &other) const { return c > other.c; }
} e[N];

bool used[N];

struct Dsu {
    vector<int> fa, sz;

    Dsu(int n) {
        fa.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
    }
};

bool req[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].c;
    }

    sort(e + 1, e + m + 1);

    Dsu dsu(n + 128);

    for (int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v, c = e[i].c;
        if (dsu.find(u) != dsu.find(v)) {
            dsu.merge(u, v);
            req[i] = true;
        }
    }

    int reqa = 0;
    for (int i = 1; i <= m; i++) {
        if (e[i].c == 0 && req[i]) {
            reqa++;
        }
    }

    if (reqa > k) {
        cout << "no solution" << endl;
        return 0;
    }

    Dsu dsu2(n + 128);

    int cntk = 0;
    for (int i = 1; i <= m; i++) {
        if (cntk >= k)
            break;

        if (e[i].c == 0 && req[i]) {
            cntk++;
            used[i] = true;
            dsu2.merge(e[i].u, e[i].v);
        }
    }

    for (int i = 1; i <= m; i++) {
        if (cntk >= k)
            break;

        if (e[i].c == 0 && !used[i] && dsu2.find(e[i].u) != dsu2.find(e[i].v)) {
            cntk++;
            used[i] = true;
            dsu2.merge(e[i].u, e[i].v);
        }
    }

    if (cntk < k) {
        cout << "no solution" << endl;
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        if (used[i])
            continue;
        if (e[i].c == 0)
            continue;

        if (dsu2.find(e[i].u) != dsu2.find(e[i].v)) {
            dsu2.merge(e[i].u, e[i].v);
            used[i] = true;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (used[i]) {
            cnt++;
        }
    }

    if (cnt != n - 1) {
        cout << "no solution" << endl;
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        if (used[i]) {
            cout << e[i].u << " " << e[i].v << " " << e[i].c << endl;
        }
    }

    return 0;
}