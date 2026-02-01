// Problem: B. 爬出陷阱
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2416/problem/2
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, h;
bool removed[N];
pair<int, int> a[N];

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.first + a.second < b.first + b.second;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef LOCAL
    freopen("escape.in", "r", stdin);
    freopen("escape.out", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    cin >> h;

    sort(a + 1, a + n + 1, cmp);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i].first;
    }

    int tot = 0;
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (tot <= sum + a[i].second - h) {
            pq.push(a[i].first);
            tot += a[i].first;
        } else  {
            if(!pq.empty() && a[i].first < pq)
        }
    }

    return 0;
}