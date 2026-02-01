// Problem: D. 猜数字
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2424/problem/4
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const __int128_t N = 4e5 + 10;

int a[N], b[N];

__int128_t exgcd(__int128_t a, __int128_t b, __int128_t &x, __int128_t &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    __int128_t d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;

    return d;
}

__int128_t modinv(__int128_t a, __int128_t m) {
    // ax + my = 1
    __int128_t x, y;
    __int128_t d = exgcd(a, m, x, y);

    if (d != 1) {
        return -1;
    }

    return x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k;
    for (__int128_t i = 1; i <= k; i++) {
        cin >> a[i];
    }

    for (__int128_t i = 1; i <= k; i++) {
        cin >> b[i];
    }

    __int128_t M = 1;
    for (__int128_t i = 1; i <= k; i++) {
        M *= b[i];
    }

    __int128_t ans = 0;
    for (__int128_t i = 1; i <= k; i++) {
        __int128_t mi = M / b[i];
        __int128_t t = modinv(mi, b[i]);
        __int128_t base = mi * t;
        ans += base * a[i];
    }

    ans = ((ans % M) + M) % M;

    cout << (int)ans;

    return 0;
}