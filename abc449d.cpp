#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 50;
const int OFF = 1e6 + 10;

bool iseven[N];
int pfx[N];

int query(int l, int r) {
    if (l > r)
        return 0;
    return pfx[r + OFF] - pfx[(l - 1) + OFF];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, r, d, u;
    cin >> l >> r >> d >> u;

    for (int y = d; y <= u; y++) {
        iseven[y + OFF] = ((y % 2) == 0);
    }

    for (int i = 1; i < N; i++) {
        pfx[i] = pfx[i - 1] + iseven[i];
    }

    int ans = 0;
    for (int x = l; x <= r; x++) {
        if (x % 2 == 0) {
            int down = max(-abs(x), d);
            int up = min(abs(x), u);

            if (up >= down)
                ans += up - down + 1;

            int cnt = query(d, -abs(x) - 1) + query(abs(x) + 1, u);

            if (cnt >= 0)
                ans += cnt;
        } else {
            int cnt = query(d, -abs(x) - 1) + query(abs(x) + 1, u);

            if (cnt >= 0)
                ans += cnt;
        }
    }

    cout << ans;

    return 0;
}