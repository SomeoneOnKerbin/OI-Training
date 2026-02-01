// Problem: C - Chokutter Addiction
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc443/tasks/abc443_c
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, T;
    cin >> n >> T;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int reset = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= reset) {
            ans += a[i] - reset;
            reset = a[i] + 100;
        }
    }

    if (reset <= T)
        ans += T - reset;

    cout << ans;

    return 0;
}