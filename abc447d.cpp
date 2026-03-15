#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    s.insert(s.begin(), 'X');

    stack<int> a, ab;

    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'A') {
            a.push(i);
        } else if (s[i] == 'B') {
            if (!a.empty()) {
                a.pop();
                ab.push(i);
            }
        } else if (s[i] == 'C') {
            if (!ab.empty()) {
                ab.pop();
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}