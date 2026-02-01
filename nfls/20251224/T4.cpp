#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1005;
const int N = 1e18;

struct Point {
    int pos;
    bool ava;

    const bool operator<(const Point &other) const { return pos < other.pos; }
} a[N];

int f[N][N][2];
int pfx[N];

int query(int l, int r) {
    if (l > r)
        return 0;
    return pfx[r] - pfx[l - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].pos;
        a[i].ava = true;
    }

    a[n + 1].pos = 0;
    a[n + 1].ava = false;

    int m = n + 1;

    sort(a + 1, a + m + 1);

    int start = 0;
    for (int i = 1; i <= m; i++) {
        pfx[i] = pfx[i - 1] + a[i].ava;

        if (!a[i].ava)
            start = i;
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j][0] = f[i][j][1] = N;
        }
    }

    f[start][start][0] = 0;
    f[start][start][1] = 0;

    for (int len = 2; len <= m; len++) {
        for (int l = 1; l + len - 1 <= m; l++) {
            int r = l + len - 1;

            int cnt = n - query(l + 1, r);

            if (f[l + 1][r][0] != N) {
                int dist = a[l + 1].pos - a[l].pos;
                f[l][r][0] = min(f[l][r][0], f[l + 1][r][0] + dist * cnt);
            }

            if (f[l + 1][r][1] != N) {
                int dist = a[r].pos - a[l].pos;
                f[l][r][0] = min(f[l][r][0], f[l + 1][r][1] + dist * cnt);
            }

            cnt = n - query(l, r - 1);

            if (f[l][r - 1][0] != N) {
                int dist = a[r].pos - a[l].pos;
                f[l][r][1] = min(f[l][r][1], f[l][r - 1][0] + dist * cnt);
            }

            if (f[l][r - 1][1] != N) {
                int dist = a[r].pos - a[r - 1].pos;
                f[l][r][1] = min(f[l][r][1], f[l][r - 1][1] + dist * cnt);
            }
        }
    }

    cout << min(f[1][m][0], f[1][m][1]) << endl;

    return 0;
}
