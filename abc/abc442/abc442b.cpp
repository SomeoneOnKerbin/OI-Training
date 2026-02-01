// Problem: B - Music Player
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc442/tasks/abc442_b
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;
    bool play = false;
    int vol = 0;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            vol++;
        } else if (op == 2) {
            if (vol >= 1)
                vol--;
        } else if (op == 3) {
            play = !play;
        }

        if (vol >= 3 && play) {
            cout << "Yes\n";
        } else
            cout << "No\n";
    }

    return 0;
}