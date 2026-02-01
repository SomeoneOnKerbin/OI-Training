// Problem: P1516 青蛙的约会
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P1516
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

    int x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;

    int A = m - n, B = l, C = y - x;

    if (A < 0) {
        A = -A;
        C = -C;
    }

    int t, k;
    int d = exgcd(A, B, t, k);

    cerr << A << "*" << t << " + " << B << "*" << k << " = " << C << "\n";
    cerr << d << " ";

    if (C % d != 0) {
        cout << "Impossible";
    } else {
        int x, y;
        int mod = l / exgcd(A, l, x, y);

        cout << ((t * (C / d) % mod) + mod) % mod;
    }

    return 0;
}