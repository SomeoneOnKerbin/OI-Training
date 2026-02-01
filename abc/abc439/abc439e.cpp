// Problem: E - Kite
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc439/tasks/abc439_e
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

pair<int, int> a[N];
int f[N];

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }

    return a.first < b.first;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a + 1, a + 1 + n, cmp);

    vector<int> tails;
    for (int i = 1; i <= n; i++) {
        int val = a[i].second;
        if (tails.empty() || tails.back() < val) {
            tails.push_back(val);
        } else {
            auto it = lower_bound(tails.begin(), tails.end(), val);
            *it = val;
        }
    }

    cout << tails.size();

    return 0;
}