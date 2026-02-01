// Problem: P1082 [NOIP 2012 提高组] 同余方程
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P1082
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        // ax + by = ax = gcd(a, 0)
        // x = 1, y = 0
        x = 1;
        y = 0;
        return a;
    }

    // bx' + (a % b)y' = gcd(a, b)
    // bx' + (a - (a / b) * b)y' = gcd(a, b)
    // bx' + ay' - (a/b)*b*y' = gcd(a, b)
    // ay' + b(x' - (a/b)*y') = gcd(a, b)

    // therefore
    // x = y'
    // y = x' - (a/b)*y
    // / means divide with floor

    int d = exgcd(b, a % b, y, x);

    y -= (a / b) * x;

    return d;
}

int modinv(int a, int p) {
    // ax === 1 (mod p)
    // ax + py = 1 when gcd(a, p) = 1

    int x, y;
    int d = exgcd(a, p, x, y);

    if (d != 1) {
        return -1;
    }

    return x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    int ans = ((modinv(a, b) % b) + b) % b;

    cout << ans;

    return 0;
}