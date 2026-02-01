// Problem: P3951 [NOIP 2017 提高组] 小凯的疑惑
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P3951
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

    int a, b;
    cin >> a >> b;
    cout << (a - 1) * (b - 1) - 1;

    return 0;
}