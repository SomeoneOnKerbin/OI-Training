// Problem: C. Dragon Balls
// Time Limit: 2000 ms
// URL: http://nflsoi.cc:20035/contest/2418/problem/3
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

struct Dsu {
    vector<int> pa, mov, siz;

    Dsu(int size) {
        pa.resize(size + 128);
        mov.resize(size + 128);
        siz.resize(size + 128);

        for (int i = 1; i <= size; i++) {
            pa[i] = i;
            siz[i] = 1;
        }
    }

    int find(int x) {
        if (pa[x] == x)
            return x;

        int tmp = pa[x];
        pa[x] = find(pa[x]);
        mov[x] += mov[tmp];

        return pa[x];
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        pa[rootX] = rootY;
        mov[rootX] = 1;
        siz[rootY] += siz[rootX];
    }
};

void solve(int id) {
    int n, q;
    cin >> n >> q;

    Dsu dsu(n + q + 1024);

    cout << "Case " << id << ":\n";
    while (q--) {
        char op;
        cin >> op;

        if (op == 'T') {
            int a, b;
            cin >> a >> b;

            dsu.merge(a, b);
        } else {
            int a;
            cin >> a;

            int x = dsu.find(a);
            int y = dsu.siz[x];
            int z = dsu.mov[a];

            cout << x << " " << y << " " << z << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        solve(i);
    }

    return 0;
}