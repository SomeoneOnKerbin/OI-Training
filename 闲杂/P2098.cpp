// Problem: P2098 [USACO16DEC] Team Building P
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P2098
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 10;
const int MOD = 1e9 + 9;

int n, m, K;
int f[2][N][20];

int a[N], b[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> K;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= m; j++) {
            f[i% 2][j][0] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= K; k++) {
                f[i % 2][j][k] = f[(i - 1) % 2][j][k] + f[i % 2][j - 1][k] -
                             f[(i - 1) % 2][j - 1][k];

                if (a[i] > b[j]) {
                    f[i % 2][j][k] += f[(i - 1) % 2][j - 1][k - 1];
                }

                f[i % 2][j][k] %= MOD;
                f[i % 2][j][k] += MOD;
                f[i % 2][j][k] %= MOD;
            }
        }
    }

    int ans = f[n % 2][m][K];
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         ans += f[i][j][K];
    //     }
    // }

    cout << ans;

    return 0;
}