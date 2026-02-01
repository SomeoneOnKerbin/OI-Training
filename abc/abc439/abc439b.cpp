// Problem: B - Happy Number
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc439/tasks/abc439_b
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int f(int x) {
    int res = 0;

    if (x >= 10) {
        res += f(x / 10);
    }

    return res + ((x % 10) * (x % 10));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x;
    cin >> x;

    int iter = 1;
    while (x != 1 && iter <= 1e5) {
        x = f(x);
        iter++;

        // cerr << x << " ";
    }

    if (x == 1) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}