#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            cnt1++;
        } else {
            cnt2++;
        }
    }

    cerr << cnt1 << " " << cnt2 << "\n";

    if (cnt1 >= m || cnt2 >= m) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}