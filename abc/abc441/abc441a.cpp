// Problem: A - Black Square
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc441/tasks/abc441_a
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

    int p, q, x, y;
    cin >> p >> q >> x >> y;

    if (p <= x && x <= p + 99 && q <= y && y <= q + 99) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}