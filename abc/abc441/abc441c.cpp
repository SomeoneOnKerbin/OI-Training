// Problem: C - Sake or Water
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc441/tasks/abc441_c
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int m[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, x;
    cin >> n >> k >> x;

    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }

    sort(m + 1, m + n + 1, greater<int>());

    // [1, n-k]  是水
    int now = 0, tgt = 0;
    for (int i = n - k + 1; i <= n; i++) {
        now += m[i];
        if (now >= x) {
            tgt = i;
            break;
        }
    }

    if (tgt != 0) {
        cout << tgt;
    } else {
        cout << -1;
    }

    return 0;
}