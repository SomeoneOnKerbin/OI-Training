#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 10;

int a[N], b[N], p[N];

void solve() {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(p, 0, sizeof p);

    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 等价
    if (x < 0) {
        x = -x;
        k = n - k;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - x;
        p[i] = p[i - 1] + b[i];
    }

    int minpre = 0;
    for (int i = 1; i <= n; i++) {
        if (i > k) {
            ans = max(ans, p[i] - minpre + 2 * k * x);
            minpre = min(minpre, p[i - k]);
        }
    }

    for (int i = 1; i <= n; i++) {
        b[i] = a[i] + x;
        p[i] = p[i - 1] + b[i];
    }

    deque<int> dq;
    dq.push_back(0);

    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && dq.front() < i - k) {
            dq.pop_front();
        }

        if (!dq.empty()) {
            ans = max(ans, p[i] - p[dq.front()]);
        }

        while (!dq.empty() && p[dq.back()] >= p[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef LOCAL
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
#endif

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}
