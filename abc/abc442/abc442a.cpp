// Problem: A - Count .
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc442/tasks/abc442_a
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

    int ans = 0;
    string s;
    cin >> s;

    for (auto &c : s) {
        if (c == 'i' || c == 'j') {
            ans++;
        }
    }

    cout << ans;

    return 0;
}