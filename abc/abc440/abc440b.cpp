// Problem: B - Trifecta
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc440/tasks/abc440_b
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

pair<int, int> a[N];
int rnk[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= 3; i++) {
        cout << a[i].second << " ";
    }

    return 0;
}