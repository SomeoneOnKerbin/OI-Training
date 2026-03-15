#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

int cnt[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    for (auto c : s) {
        cnt[c]++;
    }

    int maxx = 0, tgt = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if (cnt[i] > maxx) {
            maxx = cnt[i];
            tgt = i;
        }
    }

    vector<char> tgts;

    for (int i = 'a'; i <= 'z'; i++) {
        if (cnt[i] == maxx) {
            tgts.push_back(i);
        }
    }

    for (auto c : s) {
        bool flag = true;
        for (auto t : tgts) {
            if (c == t) {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << c;
    }

    return 0;
}