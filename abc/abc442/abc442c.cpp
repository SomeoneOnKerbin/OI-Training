// Problem: C - Peer Review
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc442/tasks/abc442_c
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int cnt[N];
int fact[N];

void pre() {
    // fact[0] = 1;
    // fact[1] = 1;
    // for (int i = 2; i < N; i++) {
    //     fact[i] = fact[i - 1] * i;
    // }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }

    pre();

    for (int i = 1; i <= n; i++) {
        int val = n - 1 - cnt[i];
        int ans = 0;

        // cerr << i << " " << val << " " << cnt[i] << "\n";

        if (val >= 3) {
            // ans = comb(val, 3);
            ans = val * (val - 1) * (val - 2) / 6;
        }

        cout << ans << " ";
    }

    return 0;
}