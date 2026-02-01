// Problem: P2193 HXY和序列
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P2193
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e3 + 10;
const int MOD = 1e9 + 7;

int n, p;
set<int> divs[N];
int f[N][N]; // 长度为 i，结尾数字是 k 的方案数

void pre() {
    for (int i = 1; i <= n; i++) {
        for (int k = 1; i * k <= n; k++) {
            int val = i * k;
            divs[val].insert(i);
            divs[val].insert(k);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> p;

    pre();

    // f[i][k] = sum(f[i-1][kk], kk | k)

    f[0][1] = 1;
    for (int i = 1; i <= p; i++) {
        for (int k = 1; k <= n; k++) {
            // for (int kk = 1; kk <= n; kk++) {
            //     if (k % kk != 0)
            //         continue;

            //     cerr << k << " " << kk << "\n";
            //     f[i][k] += f[i - 1][kk];
            //     f[i][k] %= MOD;
            // }

            for (auto kk = divs[k].begin(); kk != divs[k].end(); kk++) {
                // cerr << k << " " << *kk << "\n";

                f[i][k] += f[i - 1][*kk];
                f[i][k] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int k = 1; k <= n; k++) {
        ans += f[p][k];
        ans %= MOD;
    }

    cout << ans;

    return 0;
}