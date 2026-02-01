// Problem: A. 聪明的质检员
// Time Limit: 1000 ms
// URL: http://oj.mqcoj.cn:5000/p/18248?tid=697c73b4ac2ac5ec76c877fb
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N = 4e5 + 10;

int n, k;
double p;

double per[N];
double ans = 0;

unordered_map<double, double> f;

// 有 lambda 的概率被引导到 [l, r] 区间
double pre(int l, int r, double lambda) {
    int mid = (l + r) >> 1;

    // cerr << l << " " << mid << " " << r << " " << " " << lambda << "\n";

    double error = powf64(1 - p, ceil(k * 1.0 / 2.0));

    // 接下来这次是比对 mid，所以说发现它的概率就是到达此处的概率 = lambda
    // per[mid] = lambda;

    if (r - l + 1 == 2) {
        // per[l] = lambda;
        // per[r] = lambda;

        return lambda * 2;
    } else if (r - l + 1 == 1) {
        // per[l] = lambda;
        return lambda;
    }

    // 如果不是 mid 的问题，说明在任意两个子区间内，他们被引导到的概率就是
    double res = lambda;
    if (l <= mid - 1)
        res += pre(l, mid - 1, lambda * (1 - error));

    if (mid + 1 <= r)
        res += pre(mid + 1, r, lambda * (1 - error));

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
    ans = pre(1, n, 1) * (1.0 / n);

    // for (int i = 1; i <= n; i++) {
    //     ans += (1.0 / n) * per[i];
    //     cerr << per[i] << " ";
    // }

    cout << fixed << setprecision(4) << ans;

    return 0;
}