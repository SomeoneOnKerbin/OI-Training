// Problem: A - Octave
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc440/tasks/abc440_a
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int qpow(int a, int k) {
    if (k == 0)
        return 1;

    if (k % 2 == 1) {
        return qpow(a, k - 1) * a;
    } else {
        int base = qpow(a, k / 2);
        return base * base;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x, y;
    cin >> x >> y;

    cout << x * qpow(2, y);

    return 0;
}