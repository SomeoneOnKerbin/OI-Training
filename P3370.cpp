#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;
const int BASE = 233;

set<int> st;

int mask = time(nullptr);

unsigned int shift(unsigned int x) {
    x ^= mask;
    x ^= (x << 13);
    x ^= (x >> 5);
    x ^= (x << 17);
    return x ^ mask;
}

unsigned int hs(string s) {
    unsigned int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res *= BASE;
        res += shift(s[i]);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        st.insert(hs(s));
    }

    cout << st.size();

    return 0;
}