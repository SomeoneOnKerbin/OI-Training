// Problem: F - Must Buy
// Time Limit: 2500 ms
// URL: https://atcoder.jp/contests/abc441/tasks/abc441_f
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 10;
const int M = 5e4 + 10;

int v[N], w[N];
int f[N][M], inc[N][M], exc[N][M];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
        }
    }

    for (int k = 1; k <= n; k++) {
        memset(inc, 0, sizeof inc);
        memset(exc, 0, sizeof exc);

        for (int i = 1; i <= n; i++) {
            for (int j = w[i]; j <= m; j++) {
                if (i == k)
                    inc[i][j] = inc[i - 1][j - w[i]] + v[i];
                else
                    inc[i][j] = max(inc[i - 1][j], inc[i - 1][j - w[i]] + v[i]);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = w[i]; j <= m; j++) {
                if (i == k)
                    exc[i][j] = exc[i - 1][j];
                else
                    exc[i][j] = max(exc[i - 1][j], exc[i - 1][j - w[i]] + v[i]);
            }
        }

        cerr << k << " " << inc[n][m] << " " << exc[n][m] << " " << f[n][m]
             << "\n";

        if (inc[n][m] == f[n][m] && exc[n][m] != f[n][m]) {
            cout << 'A';
        } else if (inc[n][m] == f[n][m] && exc[n][m] == f[n][m]) {
            cout << 'B';
        } else if (inc[n][m] != f[n][m] && exc[n][m] = f[n][m]) {
            cout << 'C';
        } else {
            cout << 'U';
        }
    }

    return 0;
}