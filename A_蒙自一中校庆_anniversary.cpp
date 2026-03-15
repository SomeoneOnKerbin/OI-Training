#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

int n, k;
int a[N];
int b[N];

bool check(int lambda) {
    memcpy(b, a, sizeof(a));

    int rem = 0;

    for (int i = k + 1; i <= n; i++) {
        if (b[i] >= 3) {
            rem += b[i] / 3;
            b[i] -= b[i] / 3 * 3;
        }
    }

    for (int i = 1; i <= k; i++) {
        if (b[i] - lambda >= 3) {
            rem += (b[i] - lambda) / 3;
            b[i] -= (b[i] - lambda) / 3 * 3;
        }
    }

    for (int i = 1; i <= k; i++) {
        if (b[i] < lambda) {
            int need = lambda - b[i];
            if (need > rem) {
                return false;
            }

            rem -= need;
        }
    }

    if (rem >= 0)
        return true;
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef LOCAL
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);
#endif

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    int l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans;

    return 0;
}