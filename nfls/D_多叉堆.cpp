#include <bits/stdc++.h>
#define int long long
#ifndef ONLINE_JUDGE
#define DEBUG
#endif
const int N = 6e5 + 10;
const int MOD = 1e9 + 7;
using namespace std;

int fac[N];

int power(int a, int b) {
    if (b == 0)
        return 1;

    if (b % 2 == 1) {
        return (power(a, b - 1) * a) % MOD;
    } else {
        int base = power(a, b / 2);
        return (base * base) % MOD;
    }
}

int modinv(int x) { return power(x, MOD - 2) % MOD; }

void pre(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
}

int comb(int n, int m) {
    if (m < 0 || m > n) {
        return 0;
    }
    if (m == 0 || m == n) {
        return 1;
    }
    if (fac[m] == 0 || fac[n - m] == 0) {
        return 0;
    }
    long long d = (fac[m] * fac[n - m]) % MOD;
    return (fac[n] * modinv(d)) % MOD;
}

struct Dsu {
    vector<int> pa, ans, size;

    Dsu(int n) {
        pa.resize(n);
        ans.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            pa[i] = i;
            ans[i] = 1;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (x == pa[x])
            return x;
        return pa[x] = find(pa[x]);
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        pa[px] = py;

        ans[py] = (((ans[px] * ans[py]) % MOD) *
                   comb(size[px] + size[py] - 1, size[px])) %
                  MOD;
        size[py] += size[px];
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    pre(n + q);

    Dsu dsu(n);

    int lastans = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int px, py;
            cin >> px >> py;

            int x = px;
            int y = py;
            dsu.merge(x, y);
        } else {
            int px;
            cin >> px;

            int x = px;
            int root = dsu.find(x);
            lastans = dsu.ans[root];
            cout << lastans << "\n";
        }
    }

    return 0;
}