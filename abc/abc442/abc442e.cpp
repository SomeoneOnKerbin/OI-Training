// Problem: E - Laser Takahashi
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc442/tasks/abc442_e
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
const double deg = 57.29578;

pair<int, int> a[N];
double theta[N];

int pfx[N], diff[N];

vector<double> nums;

int getid(double x) {
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

double getang(double x, double y) {
    double ang = 0;

    if (x == 0) {
        if (y > 0) {
            ang = 90;
        } else {
            ang = -90;
        }
    } else if (y == 0) {
        if (x > 0) {
            ang = 0;
        } else {
            ang = 180;
        }
    } else if (x > 0 && y > 0)
        ang = atanf64(y * 1.0 / x) * deg;
    else if (x < 0 && y > 0) {
        ang = atanf64(-x * 1.0 / y) * deg + 90;
    } else if (x < 0 && y < 0) {
        ang = atanf64(y * 1.0 / x) * deg + 180;
    } else if (x > 0 && y < 0) {
        ang = atanf64(y * 1.0 / x) * deg;
    }

    return ang;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 1; i <= n; i++) {
        int x = a[i].first, y = a[i].second;
        theta[i] = getang(x, y);
        nums.push_back(theta[i]);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (int i = 1; i <= n; i++) {
        theta[i] = getid(theta[i]);
        diff[(int)theta[i]]++;
        diff[(int)theta[i] + 1]--;

        cerr << theta[i] << " ";
    }

    for (int i = 1; i <= n; i++) {
        pfx[i] = pfx[i - 1] + diff[i];
    }

    cerr << "\n";

    while (q--) {
        int x, y;
        cin >> x >> y;

        int tmp = -2, ans = 0;

        while (tmp <= 2) {
            double end = getang(a[x].first, a[x].second) + 360 * tmp;
            double start = getang(a[y].first, a[y].second) + 360 * tmp;

            int ee = getid(end), ss = getid(start);

            cerr << ss << " " << ee << " " << pfx[ee] - pfx[ss - 1] << "\n";

            ans += pfx[ee] - pfx[ss - 1];
            tmp++;
        }

        cerr << "\n";
        cout << ans << "\n";
    }

    return 0;
}