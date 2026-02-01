// Problem: E. 运动会
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2415/problem/5
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e2 + 10;

int n, m;
int a[N][N];

bool check(int lambda) {
    vector<int> cnt(m + 128);
    vector<bool> removed(m + 128, false);
    vector<int> ord(n + 128, 1);
    vector<vector<int>> peoples(m + 128);

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        cnt[a[i][1]]++;
        peoples[a[i][1]].push_back(i);
        ord[i] = 1;
    }

    for (int i = 1; i <= m; i++) {
        if (cnt[i] > lambda) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int id = q.front();
        q.pop();

        if (removed[id])
            continue;

        for (auto p : peoples[id]) {
            int nxt = -1;

            while (true) {
                ord[p]++;

                if (ord[p] > m) {
                    return false;
                }

                int cand = a[p][ord[p]];

                if (!removed[cand]) {
                    nxt = cand;
                    break;
                }
            }

            cnt[nxt]++;
            peoples[nxt].push_back(p);

            if (cnt[nxt] > lambda) {
                q.push(nxt);
            }
        }

        cnt[id] = 0;
        peoples[id].clear();
        removed[id] = true;
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int l = 1, r = n, res = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << res;

    return 0;
}