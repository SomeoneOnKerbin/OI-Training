// Problem: B. 重复染色
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2415/problem/2
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

// f: 全量前缀和, g: 最优前缀和
int m[N], f[N], g[N];

int query(int l, int r, int *f) { return f[r] - f[l - 1]; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> m[i];
        f[i] = f[i - 1] + m[i];
        g[i] = g[i - 1] + max(m[i], 0ll);
    }

    int ans = 0;
    for (int r = 1; r <= n; r++) {
        int l = r - k + 1;

        if (l <= 0) {
            continue;
        }

        int res =
            max(query(l, r, f), 0ll) + query(1, l - 1, g) + query(r + 1, n, g);
        ans = max(ans, res);
    }

    cout << ans;

    return 0;
}