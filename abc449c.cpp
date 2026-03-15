#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, L, R;
    cin >> n >> L >> R;
    string s;
    cin >> s;

    s.insert(s.begin(), 'X');

    unordered_map<char, int> mp;
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        int idxold = j - R - 1;
        if (idxold >= 1) {
            mp[s[idxold]]--;
        }

        int idxnew = j - L;
        if (idxnew >= 1 && idxnew <= n) {
            mp[s[idxnew]]++;
        }

        ans += mp[s[j]];
    }

    cout << ans;

    return 0;
}