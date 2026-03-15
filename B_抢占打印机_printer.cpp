#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef LOCAL
    freopen("printer.in", "r", stdin);
    freopen("printer.out", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= k) {
            ans += min(a[i], a[k]);
        } else {
            ans += min(a[i], a[k] - 1);
        }
    }

    cout << ans;

    return 0;
}