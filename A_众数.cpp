#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;

struct node {
    int ref = 0, val = 0;
};

vector<node> a[N];

int query_back(int x) {
    if (a[x].size() == 0)
        return -1;

    if (a[x].back().ref == 0) {
        return a[x].back().val;
    } else {
        return query_back(a[x].back().ref);
    }
}

bool pop_back(int x) {
    // 是一个引用节点
    while (a[x].back().ref != 0) {
        int ref = a[x].back().ref;
        bool res = pop_back(ref);

        // 空的，清除
        if (!res) {
            a[x].pop_back();
        } else {
            if (query_back(ref) == -1) {
                a[x].pop_back();
            }

            return true;
        }
    }

    // 是一个值节点
    a[x].pop_back();
    return true;
}

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
            a[i].push_back({0, x});
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
            a[x].push_back({0, y});
        } else if (op == 2) {
            int x;
            cin >> x;
            int tgt = query_back(x);

            mp[x][tgt]--;
            pop_back(x);
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

            for (auto p : mp[x1]) {
                if (p.second > 0) {
                    mp[x3][p.first] += p.second;
                }
            }

            for (auto p : mp[x2]) {
                if (p.second > 0) {
                    mp[x3][p.first] += p.second;
                }
            }

            a[x3].push_back({x1, 0});
            a[x3].push_back({x2, 0});

            mp[x1].clear();
            mp[x2].clear();
        }
    }

    return 0;
}