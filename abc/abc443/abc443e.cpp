// Problem: E - Climbing Silver
// Time Limit: 4000 ms
// URL: https://atcoder.jp/contests/abc443/tasks/abc443_e
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e3 + 10;

int n, c;
bool mat[N][N], mat2[N][N];
int f[N][N];

int nxt[3][2] = {-1, -1, -1, 0, -1, +1};
bool vis[N][N];

void bfs() {
    deque<pair<int, int>> dq;

    dq.push_front({n, c});

    while (!dq.empty()) {
        auto tmp = dq.front();
        dq.pop_front();

        if (!(1 <= tmp.first && tmp.first <= n && 1 <= tmp.second &&
              tmp.second <= n)) {
            continue;
        }

        for (int i = 0; i < 3; i++) {
            int nx = tmp.first + nxt[i][0];
            int ny = tmp.second + nxt[i][1];

            if (mat2[nx][ny])
                continue;

            if (!vis[nx][ny]) {
                dq.push_back({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

void solve() {
    memset(mat, 0, sizeof mat);
    memset(mat2, 0, sizeof mat2);
    memset(f, 0, sizeof f);
    memset(vis, 0, sizeof vis);

    cin >> n >> c;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        s.insert(s.begin(), 'X');
        for (int j = 1; j <= n; j++) {
            if (s[j] == '#')
                mat[i][j] = mat2[i][j] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (mat[n][i] == false) {
            // cerr << i << " ";

            for (int j = 1; j <= n; j++) {
                mat2[j][i] = false;
            }
        }
    }

    bfs();

    for (int j = 1; j <= n; j++) {
        cout << vis[1][j];
    }

    cout << "\n";

    // for (int j = 1; j <= n; j++) {
    //     for (int i = 1; i <= n; i++) {
    //         f[i][j] = f[i - 1][j] + mat[i][j];
    //     }
    // }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cerr << mat2[i][j];
        }
        cerr << "\n";
    }

    cerr << "\n\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}