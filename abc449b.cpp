#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w, q;
    cin >> h >> w >> q;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int r;
            cin >> r;

            cout << r * w << "\n";
            h -= r;
        } else {
            int c;
            cin >> c;
            cout << c * h << "\n";
            w -= c;
        }
    }

    return 0;
}