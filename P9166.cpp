#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

pair<int, int> seg[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, x;
    cin >> n >> m >> x;

    for (int i = 1; i <= m; i++) {
        cin >> seg[i].first >> seg[i].second;
    }

    int rmax = x;
    sort(seg + 1, seg + m + 1);

    for (int i = 1; i <= m; i++) {
        if (seg[i].first <= rmax) {
            rmax = max(rmax, seg[i].second);
        }
    }

    int lmax = x;
    sort(seg + 1, seg + m + 1,
         [](const pair<int, int> &a, const pair<int, int> &b) {
             return a.second > b.second;
         });

    for (int i = 1; i <= m; i++) {
        if (seg[i].second >= lmax) {
            lmax = min(lmax, seg[i].first);
        }
    }

    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        if (x < seg[i].second && seg[i].second <= rmax) {
            ans.push_back(seg[i].second);
        }
    }

    cerr << lmax << " " << rmax << "\n";

    for (int i = 1; i <= m; i++) {
        if (lmax <= seg[i].first && seg[i].first < x) {
            ans.push_back(seg[i].first);
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (auto x : ans) {
        cout << x << " ";
    }

    return 0;
}