#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int m[N], b[N], c[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    mt19937_64 rng(time(nullptr));

    int x = rng();
    int cnt1 = 0, cnt2 = 0;

    for (int i = 1; i <= 1e18; i++) {
        if (x <= 0)
            x = rng();

        if (x % 2 == 0) {
            cnt1++;
        } else {
            cnt2++;
        }

        // if (i <= 1e9 / 2) {
        //     cnt1++;
        // } else {
        //     cnt2++;
        // }

        x = x / 2;
    }

    return 0;
}
