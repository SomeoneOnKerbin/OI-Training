// Problem: P1495 【模板】中国剩余定理（CRT）/ 曹冲养猪
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P1495
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const __int128_t N = 4e5 + 10;

__int128_t r[N], m[N];

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
    // ax === 1 (mod m)
    // ax + my = 1
    __int128_t x, y;
    __int128_t d = exgcd(a, m, x, y);

    if (d != 1) {
        return -1;
    }

    return ((x % m) + m) % m;
}

__int128_t read() {
    __int128_t x = 0;
    bool neg = false;
    char c = getchar_unlocked();

    while (!isdigit(c)) {
        if (c == '-')
            neg = true;
        c = getchar_unlocked();
    }

    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar_unlocked();
    }

    if (neg)
        x = -x;

    return x;
}

void write(__int128_t x) {
    if (x < 0) {
        putchar_unlocked('-');
        x = -x;
    }

    if (x >= 10) {
        write(x / 10);
    }

    putchar_unlocked(x % 10 + '0');
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    __int128_t n = read();
    // cin >> n;

    for (__int128_t i = 1; i <= n; i++) {
        // cin >> m[i] >> r[i];
        m[i] = read();
        r[i] = read();
    }

    __int128_t M = 1;

    for (__int128_t i = 1; i <= n; i++) {
        M *= m[i];
    }

    __int128_t ans = 0;
    for (__int128_t i = 1; i <= n; i++) {
        __int128_t mi = M / m[i];
        // t * mi === 1 (mod m[i])
        __int128_t t = modinv(mi, m[i]);
        __int128_t base = mi * t;
        ans += base * r[i];
    }

    ans = ((ans % M) + M) % M;

    write(ans);

    return 0;
}