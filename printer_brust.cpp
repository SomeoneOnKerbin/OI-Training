#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    deque<pair<int, int>> dq;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        dq.push_back({x, i});
    }

    int krem = dq[k - 1].first;

    int time = 0;
    while (krem > 0) {
        auto tmp = dq.front();
        dq.pop_front();

        tmp.first--;
        time++;

        if (tmp.second == k) {
            if (tmp.first == 0) {
                cout << time << "\n";
                return 0;
            }
        }

        if (tmp.first > 0) {
            dq.push_back(tmp);
        }
    }

    return 0;
}