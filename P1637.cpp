// Problem: P1637 三元上升子序列
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P1637
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n;
int a[N];

struct BIT {
    int n;
    vector<int> t;

    BIT(int size) {
        n = size;
        t.resize(size + 128);
    }

    int lowbit(int x) { return x & -x; }

    int query(int x) {
        int res = 0;

        if (x <= 0) {
            return 0;
        }

        while (x >= 1) {
            res += t[x];
            x -= lowbit(x);
        }
        return res;
    }

    int querylr(int l, int r) { return query(r) - query(l - 1); }

    void add(int p, int x) {
        while (p <= n) {
            t[p] += x;
            p += lowbit(p);
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int maxx = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }

    BIT s(maxx + 128), d(maxx + 128);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int ns = s.query(a[i] - 1);
        int nt = d.query(a[i] - 1);

        d.add(a[i], ns);
        ans += nt;

        s.add(a[i], 1);
    }

    cout << ans;

    return 0;
}
