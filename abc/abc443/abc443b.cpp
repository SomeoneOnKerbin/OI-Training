// Problem: B - Setsubun
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc443/tasks/abc443_b
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int now = 0;
    for (int i = n; i <= k*100; i++) {
        now += i;

        if (now >= k) {
            cout << max(i - n, 0ll);
            break;
        }
    }

    return 0;
}