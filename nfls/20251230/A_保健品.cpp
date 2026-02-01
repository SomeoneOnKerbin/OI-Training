// Problem: A. 保健品
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2410/problem/1
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;
const int MOD = 1e9 + 7;

int m[N], last[N], l[N];
int f[N], pfx[N];

unordered_map<int, int> cnt;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> m[i];
        last[i] = cnt[m[i]];
        cnt[m[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        l[i] = max(l[i - 1], last[i] + 1);
    }

    f[0] = 1;
    pfx[0] = 1;

    for (int i = 1; i <= n; i++) {
        /*         for (int j = l[i] - 1; j < i; j++) {
                    f[i] += f[j];
                    f[i] %= MOD;
                } */

        f[i] = (pfx[i - 1] - pfx[l[i] - 2] + MOD) % MOD;
        pfx[i] = pfx[i - 1] + f[i];
    }

    cout << f[n] << "\n";

    return 0;
}