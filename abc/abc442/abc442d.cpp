// Problem: D - Swap and Range Sum
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc442/tasks/abc442_d
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, q;
int a[N];
int f[N];

int lowbit(int x) { return x & -x; }

void add(int p, int delta) {
    while (p <= n) {
        f[p] += delta;
        p += lowbit(p);
    }
}

int query(int p) {
    int res = 0;
    while (p >= 1) {
        res += f[p];
        p -= lowbit(p);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i]);
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            int delta1 = a[x] - a[x + 1];
            int delta2 = a[x + 1] - a[x];

            swap(a[x], a[x + 1]);
            add(x, delta2);
            add(x + 1, delta1);
        } else {
            int l, r;
            cin >> l >> r;
            int ans = query(r) - query(l - 1);
            cout << ans << "\n";
        }
    }

    return 0;
}