// Problem: P6006 [USACO20JAN] Farmer John Solves 3SUM G
// Time Limit: 2000 ms
// URL: https://www.luogu.com.cn/problem/P6006
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
#define int long long
using namespace std;
const int N = 6e3 + 10;
const int OFFSET = 2e6 + 10;
const int A = 6e6;

int a[N];
long long g[N][N];
int cnt[A];
// gp_hash_table<int, int> cnt;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int l = 1; l <= n; l++) {
        for (int r = l + 2; r <= n; r++) {
            cnt[a[r - 1] + OFFSET]++;

            g[l][r] = cnt[-(a[r] + a[l]) + OFFSET];
        }

        for (int j = l + 2; j <= n; j++) {
            cnt[a[j - 1] + OFFSET] = 0;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int l = 1; l <= n; l++) {
            int r = l + len - 1;
            g[l][r] += g[l + 1][r] + g[l][r - 1] - g[l + 1][r - 1];
        }
    }

    while (q--) {
        int L, R;
        cin >> L >> R;

        int ans = g[L][R];
        cout << ans << "\n";
    }

    return 0;
}