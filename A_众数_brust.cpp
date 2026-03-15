#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;

vector<int> a[N];
unordered_map<int, int> mp[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;

        for (int j = 0; j < l; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
            mp[i][x]++;
        }
    }

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x, y;
            cin >> x >> y;

            mp[x][y]++;
            a[x].push_back(y);
        } else if (op == 2) {
            int x;
            cin >> x;
            int tgt = a[x].back();

            mp[x][tgt]--;
            a[x].pop_back();
        } else if (op == 3) {
            int m;
            cin >> m;
            vector<int> seq(m);
            for (auto &x : seq)
                cin >> x;

            int sum = 0;
            unordered_map<int, int> cnt;

            for (auto x : seq) {
                for (auto p : mp[x]) {
                    if (p.second > 0) {
                        cnt[p.first] += p.second;
                        sum += p.second;
                    }
                }
            }

            int ans = -1;
            for (auto p : cnt) {
                if (p.second * 2 > sum) {
                    ans = p.first;
                    break;
                }
            }

            cout << ans << "\n";
        } else if (op == 4) {
            int x1, x2, x3;
            cin >> x1 >> x2 >> x3;

            for (auto x : a[x1]) {
                a[x3].push_back(x);
                mp[x3][x]++;
            }

            for (auto x : a[x2]) {
                a[x3].push_back(x);
                mp[x3][x]++;
            }

            mp[x1].clear();
            a[x1].clear();
            mp[x2].clear();
            a[x2].clear();
        }
    }

    return 0;
}