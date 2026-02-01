// Problem: C - Striped Horse
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc440/tasks/abc440_c
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, w;
    cin >> n >> w;

    vector<int> diff(2 * w + 2, 0);

    for (int i = 1; i <= n; i++) {
        int cost;
        cin >> cost;

        int start = (2 * w - (i % (2 * w))) % (2 * w);
        int end = (start + w - 1) % (2 * w);

        if (start <= end) {
            diff[start] += cost;
            diff[end + 1] -= cost;
        } else {
            // 周期性
            diff[start] += cost;
            diff[2 * w] -= cost;

            diff[0] += cost;
            diff[end + 1] -= cost;
        }
    }

    int minum = -1;
    int val = 0;

    for (int x = 0; x < 2 * w; x++) {
        val += diff[x];
        if (minum == -1 || val < minum) {
            minum = val;
        }
    }

    cout << minum << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
