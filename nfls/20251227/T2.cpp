#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int pfx[N];
int c[N];

int query(int l, int r) { return pfx[r] - pfx[l - 1]; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];

        if (i % 2 == 0) {
            c[i] = -c[i];
        }

        pfx[i] = pfx[i - 1] + c[i];
    }

    int ans = 0;

    for (int l = 1; l <= n; l++) {
        for (int r = l + 1; r <= n; r++) {
            int mid = 0;

            if (r - l + 1 >= 3) {
                mid = query(l + 1, r - 1);
            }

            // 左边和右边任取一部分，可以填满 mid
            // x_1 \in [0, c[l]], 
        }
    }

    cout << ans;

    return 0;
}
