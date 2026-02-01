// Problem: B. Almost Union-Find
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2418/problem/2
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int cnt = 1;
unordered_map<int, int> mp;

struct Dsu {
    vector<int> pa;
    vector<int> siz, sum;

    Dsu(int size) {
        pa.resize(size + 128);
        siz.resize(size + 128);
        sum.resize(size + 128);

        fill(siz.begin(), siz.end(), 1);

        for (int i = 1; i <= size; i++) {
            pa[i] = i;
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

        if (rootX != rootY) {
            pa[rootX] = rootY;
            siz[rootY] += siz[rootX];
            sum[rootY] += sum[rootX];
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;

    while (cin >> n >> m) {
        cnt = 1;
        Dsu dsu(1e6);

        for (int i = 1; i <= n; i++) {
            mp[i] = cnt++;
            dsu.sum[mp[i]] = i;
        }

        for (int i = 1; i <= m; i++) {
            int op;
            cin >> op;

            if (op == 1) {
                int p, q;
                cin >> p >> q;

                if (dsu.find(mp[p]) != dsu.find(mp[q])) {
                    dsu.merge(mp[p], mp[q]);
                }
            } else if (op == 2) {
                int p, q;
                cin >> p >> q;

                dsu.siz[dsu.find(mp[p])]--;
                dsu.sum[dsu.find(mp[p])] -= p;
                mp[p] = cnt++;
                dsu.sum[mp[p]] = p;

                dsu.merge(mp[p], mp[q]);
            } else {
                int p;
                cin >> p;
                int sum = dsu.sum[dsu.find(mp[p])];
                int siz = dsu.siz[dsu.find(mp[p])];

                cout << siz << " " << sum << "\n";
            }
        }
    }

    return 0;
}