// Contest: Baidu Astar
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

void solve() {
    int n, d, l;
    cin >> n >> d >> l;

    if (n >= l) {
        cout << 0 << " " << 0 << "\n";
        return;
    }

    int ans1 = n * max(0.0, ceil((l - 1 - d) * 1.0 / (d - n + 1))) + 1;
    int ans2 = max(0ll, (l - n - 1) * n + 1);

    if (l <= 2 + d) {
        ans1 = min(ans1, 2ll);
    }

    cout << ans1 << " " << ans2 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
