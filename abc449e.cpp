#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;

int cnt[N];
pair<int, int> qrys[N];
int answers[N];

struct state {
    int l, r, begin, end;
    bool operator<(state &st) const { return l < st.l; }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    map<int, vector<int>> mpcnt;

    int maxcnt = 0;
    for (int i = 1; i <= m; i++) {
        mpcnt[cnt[i]].push_back(i);
        maxcnt = max(maxcnt, cnt[i]);
    }

    set<int> st;
    for (int i = 0; i <= n; i++) {
        for (auto x : mpcnt[i]) {
            st.insert(x);
        }

        for (auto x : st) {
            a.push_back(x);
        }
    }

    for (int i = 1; i < a.size(); i++) {
        cerr << a[i] << " ";
    }

    int q;
    cin >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
    }

    return 0;
}