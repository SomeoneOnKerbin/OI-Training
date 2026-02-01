// Problem: D - Forbidden List 2
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc440/tasks/abc440_d
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, q;
int m[N];

int gap[N], pfx[N];

void solve() {
    int x, y;
    cin >> x >> y;

    // 列表中最大的 < x 的数字
    int tmp = lower_bound(m + 1, m + n + 1, x) - m - 1;
    // 有多少个不在列表中的数 < x
    int less = pfx[tmp] + (x - m[tmp] - 1);
    int tgt = less + y;

    // cerr << a[tmp] << " " << tgt << "\n";

    // 找到全局第 tgt 大的不在列表中的数字
    int num = 0, ans = 0;
    int idx = lower_bound(pfx + 1, pfx + n + 1, tgt) - pfx;
    num = pfx[idx];

    // for (int i = 1; i <= n; i++) {
    //     num += gap[i]; // 在 i 之前的空位
    //     // cerr << num << " ";

    //     if (num >= tgt) {
    //         ans = a[i] + (tgt - num) - 1;
    //         break;
    //     }
    // }

    cerr << idx << " " << m[idx] << " " << pfx[idx] << " " << num << "\n";

    if (idx > n) {
        ans = m[n] + (tgt - pfx[n]);
    } else {
        ans = m[idx] + (tgt - num) - 1;
    }

    cerr << "\n\n";

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }

    sort(m + 1, m + n + 1);

    for (int i = 1; i <= n; i++) {
        gap[i] = m[i] - m[i - 1] - 1;
        pfx[i] = pfx[i - 1] + gap[i];
        cerr << m[i] << " ";
    }

    cerr << "\n";

    while (q--) {
        solve();
    }

    return 0;
}