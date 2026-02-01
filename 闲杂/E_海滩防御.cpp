// Problem: E. 海滩防御
// Time Limit: 1000 ms
// URL: http://oj.mqcoj.cn:5000/p/5873?tid=697b4c87ac2ac5ec76c5e80d
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N = 4e5 + 10;

int n, m;

struct P {
    int x, y;

    double dis(P &o) const {
        return sqrtl(powl(x - o.x, 2) + powl(y - o.y, 2));
    }
} p[N];

bool vis[N];

bool check(double lambda) {
    memset(vis, 0, sizeof vis);

    queue<int> q;

    for (int i = 1; i <= m; i++) {
        if (p[i].x <= lambda) {
            q.push(i);
            vis[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (p[u].x >= n - lambda) {
            return true;
        }

        for (int v = 1; v <= m; v++) {
            if (v == u)
                continue;

            if (p[u].dis(p[v]) > lambda * 2)
                continue;

            if (vis[v])
                continue;

            q.push(v);
            vis[v] = true;
        }
    }

    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> p[i].x >> p[i].y;
    }

    double l = 0, r = 1e14, res = 0;

    while (r - l >= 1e-9) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
            res = mid;
        } else {
            l = mid;
        }
    }

    cout << fixed << setprecision(2) << res;

    return 0;
}