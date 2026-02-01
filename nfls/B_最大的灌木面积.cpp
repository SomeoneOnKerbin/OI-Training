// Problem: B. 最大的灌木面积
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2420/problem/2
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N = 1e3;
const double EPS = 1e-9;

int n, ans = 1;
int v[N][N], base[N][N];

struct Dsu {
    vector<int> pa, siz;
    Dsu(int m) {
        pa.resize(m + 1);
        siz.assign(m + 1, 1);
        iota(pa.begin(), pa.end(), 0);
    }

    int find(int x) {
        if (pa[x] == x)
            return x;
        pa[x] = find(pa[x]);
        return pa[x];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }

        pa[y] = x;
        siz[x] += siz[y];
    }
};

struct Event {
    double timestamp;
    int u, v;

    bool operator<(const Event &o) const {
        return timestamp < o.timestamp - EPS;
    }
};

inline int toid(int i, int j) { return (i - 1) * n + j; }

int tmpa[N * N], tmpsiz[N * N];

int tmpfind(int x) {
    while (x != tmpa[x])
        x = tmpa[x];
    return x;
}

void tmpmerge(int x, int y) {
    x = tmpfind(x);
    y = tmpfind(y);
    if (x != y) {
        if (tmpsiz[x] < tmpsiz[y])
            swap(x, y);
        tmpa[y] = x;
        tmpsiz[x] += tmpsiz[y];
        ans = max(ans, tmpsiz[x]);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef LOCAL
    freopen("max.in", "r", stdin);
    freopen("max.out", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> base[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> v[i][j];

    Dsu st(n * n);
    vector<Event> events;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int u = toid(i, j);

            if (i < n) {
                // if (true) {
                int vv = toid(i + 1, j);
                if (v[i][j] == v[i + 1][j]) {
                    if (base[i][j] == base[i + 1][j])
                        st.merge(u, vv);
                } else {
                    double t = (base[i + 1][j] - base[i][j]) * 1.0 /
                               (v[i][j] - v[i + 1][j]);

                    if (t >= -EPS)
                        events.push_back({t, u, vv});
                }
            }

            if (j < n) {
                int vv = toid(i, j + 1);
                if (v[i][j] == v[i][j + 1]) {
                    if (base[i][j] == base[i][j + 1])
                        st.merge(u, vv);
                } else {
                    double t = (base[i][j + 1] - base[i][j]) * 1.0 /
                               (v[i][j] - v[i][j + 1]);
                    if (t >= -EPS)
                        events.push_back({t, u, vv});
                }
            }
        }
    }

    for (int i = 1; i <= n * n; i++)
        ans = max(ans, st.siz[st.find(i)]);

    sort(events.begin(), events.end());

    for (int i = 1; i <= n * n; i++) {
        tmpa[i] = i;
        tmpsiz[i] = 0;
    }

    for (int i = 0, tot = events.size(); i < tot;) {
        int j = i;
        vector<int> nodes;

        while (j < tot &&
               fabs(events[j].timestamp - events[i].timestamp) < EPS) {
            // cerr << events[j].timestamp << "\n";

            int rootu = st.find(events[j].u);
            int rootv = st.find(events[j].v);

            if (tmpsiz[rootu] == 0) {
                tmpsiz[rootu] = st.siz[rootu];
                nodes.push_back(rootu);
            }

            if (tmpsiz[rootv] == 0) {
                tmpsiz[rootv] = st.siz[rootv];
                nodes.push_back(rootv);
            }

            tmpmerge(rootu, rootv);
            j++;
        }

        for (auto &x : nodes) {
            tmpa[x] = x;
            tmpsiz[x] = 0;
        }

        i = j;
    }

    cout << ans << "\n";

    return 0;
}
