#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;
const int MOD = 1e9 + 7;

int n, k;
pair<int, int> a[N];

int ans = 0;
int b[N];
int c[N];

int tmp[N];

vector<vector<int>> deltas;

bool check(int *arr) {
    memcpy(tmp, arr, sizeof(int) * (n + 1));

    for (int i = 1; i <= n; i++) {
        if (tmp[i] >= 3) {
            tmp[i] = 1;
        } else if (tmp[i] == 2) {
            tmp[i] = 0;
        }
    }

    return true;
}

void dfs(int p) {
    if (p == n + 1) {
        bool flag = false;

        for (auto &d : deltas) {
            for (int i = 1; i <= n; i++) {
                c[i] = b[i] + d[i - 1];
            }

            if (check(c)) {
                // cerr << "check yes:\n";
                // cerr << "b: ";
                // for (int i = 1; i <= n; i++) {
                //     cerr << b[i] << " ";
                // }
                // cerr << "\nc: ";
                // for (int i = 1; i <= n; i++) {
                //     cerr << c[i] << " ";
                // }
                // cerr << "\n\n";

                flag = true;
                break;
            }
        }

        if (flag) {
            ans++;
            ans %= MOD;
        }

        // for (int i = 1; i <= n; i++) {
        //     cerr << b[i] << " ";
        // }

        // cerr << "check:" << flag << "\n";

        return;
    }

    for (int i = a[p].first; i <= a[p].second; i++) {
        b[p] = i;
        dfs(p + 1);
    }
}

void dfs2(int p, int used, vector<int> delta) {
    if (p == n + 1) {
        if (used != k)
            return;

        deltas.push_back(delta);
        for (auto x : delta) {
            cerr << x << " ";
        }
        cerr << " delta" << "\n";

        return;
    }

    for (int i = 0; i <= k - used; i++) {
        delta.push_back(i);
        dfs2(p + 1, used + i, delta);
        delta.pop_back();
    }
}

void solve() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    deltas.clear();

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ans = 0;

    dfs2(1, 0, {});
    dfs(1);

    cout << ans % MOD << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}