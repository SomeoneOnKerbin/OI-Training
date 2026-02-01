// Problem: A - 2^n - 2*n
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc439/tasks/abc439_a
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

    int n;
    cin >> n;

    int a = 1 << n;
    int b = 2 * n;

    cout << a - b;

    return 0;
}