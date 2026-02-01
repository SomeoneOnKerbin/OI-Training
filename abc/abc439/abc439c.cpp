// Problem: C - 2026
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc439/tasks/abc439_c
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e8 + 10;

int ava[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int x = 1; x <= 1e5; x++) {
        for (int y = x + 1; y <= 1e5; y++) {
            int val = x * x + y * y;

            if (val > n)
                break;

            ava[val]++;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (ava[i] == 1)
            cnt++;
    }

    cout << cnt << "\n";

    for (int i = 1; i <= n; i++) {
        if (ava[i] == 1)
            cout << i << " ";
    }

    return 0;
}