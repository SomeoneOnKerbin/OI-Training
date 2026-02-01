// Problem: P2051 [AHOI2009] 中国象棋
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P2051
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 10;
const int MOD = 9999973;

int n, m;
int f[N][N][N];

int C2(int n) { return n * (n - 1) / 2; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= m - j; k++) {
                f[i][j][k] = f[i - 1][j][k];

                if (j >= 1) {
                    f[i][j][k] =
                        (f[i][j][k] + f[i - 1][j - 1][k] * (m - (j - 1) - k)) %
                        MOD;
                }

                if (k >= 1) {
                    f[i][j][k] =
                        (f[i][j][k] + f[i - 1][j + 1][k - 1] * (j + 1)) % MOD;
                }

                if (j >= 2) {
                    f[i][j][k] = (f[i][j][k] +
                                  f[i - 1][j - 2][k] * C2(m - (j - 2) - k)) %
                                 MOD;
                }

                if (k >= 2) {
                    f[i][j][k] =
                        (f[i][j][k] + f[i - 1][j + 2][k - 2] * C2(j + 2)) % MOD;
                }

                if (k >= 1) {
                    f[i][j][k] =
                        (f[i][j][k] +
                         f[i - 1][j][k - 1] * (m - j - (k - 1)) % MOD * j) %
                        MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= m; j++) {
        for (int k = 0; k <= m - j; k++) {
            ans += f[n][j][k];
            ans %= MOD;
        }
    }

    cout << ans;

    return 0;
}