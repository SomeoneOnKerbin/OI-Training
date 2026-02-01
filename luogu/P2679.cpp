// Problem: P2679 [NOIP 2015 提高组] 子串
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P2679
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long
using namespace std;
const int N = 1e3 + 10, M = 2e2 + 10;
const int MOD = 1e9 + 7;

unsigned int f[4][M][M][2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, K;
    cin >> n >> m >> K;

    string a, b;
    cin >> a >> b;

    a.insert(a.begin(), 'X');
    b.insert(b.begin(), 'X');

    for (int i = 0; i <= 2; i++) {
        f[(i) % 2][0][0][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= K; k++) {
                f[i % 2][j][k][0] =
                    (f[(i - 1) % 2][j][k][0] + f[(i - 1) % 2][j][k][1]) % MOD;

                if (a[i] == b[j]) {
                    f[i % 2][j][k][1] = (f[(i - 1) % 2][j - 1][k - 1][0] +
                                         f[(i - 1) % 2][j - 1][k - 1][1] +
                                         f[(i - 1) % 2][j - 1][k][1]) %
                                        MOD;
                } else {
                    f[i % 2][j][k][1] = 0;
                }
            }
        }
    }

    cout << (f[n % 2][m][K][0] + f[n % 2][m][K][1]) % MOD;

    return 0;
}