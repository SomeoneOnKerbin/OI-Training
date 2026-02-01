#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int m[N];

int readint() {
    char c = getchar_unlocked();
    int x = 0;
    bool neg = false;

    while (!isdigit(c)) {
        if (c == '-')
            neg = true;
        c = getchar_unlocked();
    }

    while (isdigit(c)) {
        if (x < 120)
            x = x * 10 + (c - '0');

        c = getchar_unlocked();
    }

    if (neg)
        return -x;
    else
        return x;
}

string readstring() {
    char c = getchar_unlocked();
    string s;

    while (!isalpha(c)) {
        c = getchar_unlocked();
    }

    while (isalpha(c)) {
        s += c;
        c = getchar_unlocked();
    }

    return s;
}

void solve() {
    memset(m, 0, sizeof m);

    string s = readstring();
    int k = readint();

    cerr << s << " " << k << "\n";

    string raws = s;
    for (int i = 1; i <= min(k - 1, (int)raws.size()); i++) {
        s += raws;
    }

    s.insert(s.begin(), 'X');
    int n = s.size() - 1;

    for (int i = 1; i <= n; i++) {
        m[i] = 1;

        for (int j = 1; j < i; j++) {
            if (s[i] > s[j]) {
                m[i] = max(m[i], m[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, m[i]);
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = readint();

    while (T--)
        solve();

    return 0;
}