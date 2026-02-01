// Problem: D. Discrete Centrifugal Jumps
// Time Limit: 2000 ms
// URL: https://codeforces.com/problemset/problem/1407/D
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n;
int h[N], f[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(f, 0x3f, sizeof f);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    f[1] = 0;
    stack<int> a, b;
    for (int i = 1; i <= n; i++) {
        f[i] = min(f[i - 1] + 1, f[i]);

        while (!a.empty() && h[a.top()] >= h[i]) {
            // i 是在右边第一个比 u 大的
            int u = a.top();
            f[i] = min(f[i], f[u] + 1);
            a.pop();
        }

        if (!a.empty()) {
            // u 是第一个在左边比 i 大的数
            int u = a.top();
            f[i] = min(f[i], f[u] + 1);
        }

        while (!b.empty() && h[b.top()] <= h[i]) {
            // i 是第一个在右边比 u 小的数
            int u = b.top();
            f[i] = min(f[i], f[u] + 1);
            b.pop();
        }

        if (!b.empty()) {
            // u 是第一个在左边比 i 小的数
            int u = b.top();
            f[i] = min(f[i], f[u] + 1);
        }

        a.push(i);
        b.push(i);
    }

    cout << f[n];

    return 0;
}