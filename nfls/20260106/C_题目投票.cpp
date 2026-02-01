// Problem: C. 题目投票
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2415/problem/3
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, m, v, p;
int m[N];

// 第 k 个题目能否被选中
bool check(int k) {
    int t = m[k] + m;

    if (t < m[p])
        return false;

    int rem = (v - 1) * m;
    int cap = (p - 1) * m + (n - k) * m;

    for (int i = p; i <= k - 1; i++) {
        cap += t - m[i];
    }

    cerr << k << " " << cap << " " << rem << "\n";

    return cap >= rem;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> v >> p;

    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }

    sort(m + 1, m + n + 1, greater<int>());

    int l = 0, r = n + 1, res = 0;

    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
            res = mid;
        } else {
            r = mid;
        }
    }

    cout << res;

    return 0;
}