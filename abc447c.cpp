#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

// s 的第 i-1 个 B 到第 i 个 B 之间的 A 的数量
int sss[N], ttt[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;

    s.insert(s.begin(), 'A');
    t.insert(t.begin(), 'A');

    string snoa, tnoa;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != 'A') {
            snoa += s[i];
        }
    }

    for (int i = 1; i < t.size(); i++) {
        if (t[i] != 'A') {
            tnoa += t[i];
        }
    }

    cerr << snoa << " " << tnoa << "\n";

    if (snoa != tnoa) {
        cout << -1;
        return 0;
    }

    for (auto &c : s) {
        if (c != 'A') {
            c = 'B';
        }
    }

    for (auto &c : t) {
        if (c != 'A') {
            c = 'B';
        }
    }

    int idxs = 1, cnt = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'B') {
            sss[idxs] = cnt;
            idxs++;
            cnt = 0;
        } else {
            cnt++;
        }
    }

    if (cnt > 0) {
        sss[idxs] = cnt;
    }

    int idxt = 1;
    cnt = 0;
    for (int i = 1; i < t.size(); i++) {
        if (t[i] == 'B') {
            ttt[idxt] = cnt;
            idxt++;
            cnt = 0;
        } else {
            cnt++;
        }
    }

    if (cnt > 0) {
        ttt[idxt] = cnt;
    }

    int res = 0;
    for (int i = 1; i <= max(idxs, idxt); i++) {
        cerr << sss[i] << " " << ttt[i] << "\n";
        res += abs(sss[i] - ttt[i]);
    }

    cout << res;

    return 0;
}