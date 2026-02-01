// Problem: B - Two Languages
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc441/tasks/abc441_b
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

    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;
    int q;
    cin >> q;

    while (q--) {
        string w;
        cin >> w;

        bool taka = true, aoki = true;
        for (auto &c : w) {
            bool exists = false;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == c) {
                    exists = true;
                    break;
                }
            }

            if (!exists)
                taka = false;
        }

        for (auto &c : w) {
            bool exists = false;
            for (int i = 0; i < t.size(); i++) {
                if (t[i] == c) {
                    exists = true;
                    break;
                }
            }

            if (!exists)
                aoki = false;
        }

        if (taka && !aoki) {
            cout << "Takahashi\n";
        } else if (aoki && !taka) {
            cout << "Aoki\n";
        } else {
            cout << "Unknown\n";
        }
    }

    return 0;
}