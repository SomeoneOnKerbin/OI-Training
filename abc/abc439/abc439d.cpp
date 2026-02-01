// Problem: D - Kadomatsu Subsequence
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc439/tasks/abc439_d
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n;
int a[N];
unordered_map<int, int> cnt;

int solve() {
    cnt.clear();

    int ans = 0;

    for (int j = 1; j <= n; j++) {
        if (a[j] % 5 == 0) {
            int ai = a[j] / 5 * 3;
            int ak = a[j] / 5 * 7;

            // cerr << ai << " " << a[j] << " " << ak << '\n';

            ans += cnt[ai] * cnt[ak];
        }

        cnt[a[j]]++;
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = solve();

    reverse(a + 1, a + 1 + n);

    ans += solve();

    cout << ans;

    return 0;
}