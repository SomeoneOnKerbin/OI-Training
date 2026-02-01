#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, k;
double p;
int pos;

mt19937 rng(time(nullptr));

bool good() {
    double x = rng() % (int)1e7;
    x /= (int)1e7;

    if (x >= p)
        return true;
    else
        return false;
}

bool isleft(int now) {
    if (now <= pos) {
        return good();
    } else {
        return !good();
    }
}

bool isleft2(int now) {
    int left = 0, right = 0;
    for (int i = 1; i <= k; i++) {
        if (isleft(now))
            left++;
        else
            right++;
    }

    // cerr << left << " " << right << "\n";

    if (left >= right)
        return true;
    else
        return false;
}

bool isleft3(int now) {
    // cerr << now << " " << pos << " 11111\n\n";
    if (now <= pos)
        return true;
    else
        return false;
}

int solve() {
    int l = 1, r = n, res = 0;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (mid == pos)
            return mid;

        if (r - l + 1 <= 2) {
            if (mid == pos)
                return mid;
            else {
                if (l == mid)
                    return r;
                else
                    return l;
            }
        }

        // cerr << l << " " << mid << " " << r << "\n";

        if (isleft2(mid)) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef LOCAL
    freopen("tiancai.in", "r", stdin);
    freopen("tiancai.out", "w", stdout);
#endif

    cin >> n >> p >> k;

    // pos = 6;
    // cout << solve();

    double ans = 0;
    for (int i = 1; i <= n; i++) {
        // pos = i;
        // cout << solve() << "\n";

        pos = i;
        int wrong = 0, right = 0;
        for (int j = 1; j <= 100000; j++) {
            if (solve() == pos)
                right++;
            else
                wrong++;
        }

        double x = right * 1.0 / (wrong + right);

        // cout << right << " " << wrong << " " << (right * 1.0) / (right +
        // wrong)
        //  << "\n";

        cerr << x << "\n";

        ans += x * (1.0 / n);
    }

    cout << ans;

    return 0;
}
