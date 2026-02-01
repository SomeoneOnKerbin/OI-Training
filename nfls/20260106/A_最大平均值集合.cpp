// Problem: A. 最大平均值集合
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2415/problem/1
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int val[N];
unordered_map<int, int> cnt;

int comb(int n, int r) {
    if (r < 0 || r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    if (r > n / 2)
        r = n - r;

    double res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }

    return (int)(res + 0.5);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    sort(val + 1, val + n + 1, greater<int>());

    int sum = 0;
    for (int i = 1; i <= a; i++) {
        sum += val[i];
    }

    double avg = sum * 1.0 / a;

    int ans2 = 0;

    if (val[1] == val[a]) {
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            if (val[i] == val[1])
                cnt++;
        }

        for (int k = a; k <= b && k <= cnt; k++) {
            ans2 += comb(cnt, k);
        }
    } else {
        int tot = 0, need = 0;

        for (int i = 1; i <= n; i++) {
            if (val[i] == val[a])
                tot++;
        }

        for (int i = 1; i <= a; i++) {
            if (val[i] == val[a])
                need++;
        }

        ans2 = comb(tot, need);
    }

    cout << fixed << setprecision(6) << avg << "\n" << ans2;

    return 0;
}