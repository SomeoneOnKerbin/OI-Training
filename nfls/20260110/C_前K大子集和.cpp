// Problem: C. 前K大子集和
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2416/problem/3
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;
typedef pair<int, int> item;

int m[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef LOCAL
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
#endif

    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }

    sort(m + 1, m + n + 1);

    priority_queue<item, vector<item>, greater<item>> pq;
    int ans = 0, sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += m[i];
    }

    ans += sum;
    pq.push(make_pair(m[1], 1));

    int cnt = 1;
    while (!pq.empty()) {
        item tmp = pq.top();
        pq.pop();

        int loss = tmp.first;
        int lstidx = tmp.second;

        ans += sum - loss;
        // cerr << loss << " " << loss + a[lstidx + 1] << " "
        //      << loss - a[lstidx] + a[lstidx + 1] << "\n";

        cnt++;

        if (cnt >= m)
            break;

        if (lstidx < n) {
            // 增加
            pq.push(make_pair(loss + m[lstidx + 1], lstidx + 1));

            // 替换
            pq.push(make_pair(loss - m[lstidx] + m[lstidx + 1], lstidx + 1));
        }
    }

    cout << ans;

    return 0;
}