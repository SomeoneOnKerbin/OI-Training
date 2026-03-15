#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef LOCAL
    // freopen("problem.in", "r", stdin);
    // freopen("problem.out", "w", stdout);
#endif

    double d;
    cin >> d;
    cout << fixed << setprecision(24) << M_PI * powf64(d / 2, 2);

    return 0;
}