// Problem: A. 识别垃圾邮件
// Time Limit: 1500 ms
// URL: http://nflsoi.cc:20035/contest/2418/problem/1
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e6 + 10;

int pa[N], node[N], tag[N];
int cnt = 0;

void init(int n) {
    for (int i = 1; i <= n; i++) {
        pa[i] = i;
    }
}

int find(int x) {
    if (x == pa[x])
        return x;
    pa[x] = find(pa[x]);
    return pa[x];
}

void merge(int x, int y) { pa[find(x)] = find(y); }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    int n, m;

    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            return 0;

        memset(pa, 0, sizeof pa);
        memset(tag, 0, sizeof tag);
        memset(node, 0, sizeof node);
        cnt = 100;

        init(n + m + 1024);

        for (int i = 1; i <= n; i++) {
            node[i] = cnt++;
        }

        for (int i = 1; i <= m; i++) {
            char op;
            cin >> op;

            if (op == 'M') {
                int x, y;
                cin >> x >> y;
                merge(node[x], node[y]);
            } else {
                int x;
                cin >> x;
                node[x] = cnt++;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            cerr << find(node[i]) << "\n";

            if (tag[find(node[i])] != -1) {
                ans++;
                tag[find(node[i])] = -1;
            }
        }

        cerr << "\n\n";

        cout << "Case #" << T << ": " << ans << "\n";

        T++;
    }

    return 0;
}