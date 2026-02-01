// Problem: C. Line
// Time Limit: 1000 ms
// URL: https://codeforces.com/problemset/problem/7/C
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;

    return d;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    if (a == 0 && b == 0) {
        cout << 0 << " " << 0;
        return 0;
    }

    int x, y;
    int d = exgcd(abs(a), abs(b), x, y);

    if (-c % d != 0) {
        cout << -1;
    } else {
        int k = -c / d;
        x = k * x;
        y = k * y;

        if (a < 0) {
            x = -x;
        }

        if (b < 0) {
            y = -y;
        }

        cout << x << " " << y;
    }

    return 0;
}