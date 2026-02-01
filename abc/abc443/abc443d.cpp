// Problem: D - Pawn Line
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc443/tasks/abc443_d
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n;
int a[N], maxx[N], maxx2[N];

void solve() {
    memset(a, 0, sizeof(int) * n);
    memset(maxx, 0, sizeof(int) * n);
    memset(maxx2, 0, sizeof(int) * n);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    maxx[1] = a[1];
    for (int i = 2; i <= n; i++) {
        maxx[i] = min(maxx[i - 1] + 1, a[i]);
    }

    maxx2[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        maxx2[i] = min(a[i], maxx2[i + 1] + 1);
    }

    for (int i = 1; i <= n; i++) {
        int tgt = min(maxx2[i], maxx[i]);
        ans += a[i] - tgt;
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}