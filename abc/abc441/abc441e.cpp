// Problem: E - A > B substring
// Time Limit: 2000 ms
// URL: https://atcoder.jp/contests/abc441/tasks/abc441_e
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
const int OFFSET = 5e5 + 10;

int pa[N], pb[N];
int g[N];

struct BIT {
    int n;
    vector<int> a;

    BIT(int size) {
        n = size;
        a.resize(size + 128);
    }

    int lowbit(int x) { return x & -x; }

    int query(int p) {
        p = p + OFFSET;
        int res = 0;

        while (p > 0) {
            res += a[p];
            p -= lowbit(p);
        }

        return res;
    }

    void mut(int p, int delta) {
        p = p + OFFSET;

        while (p <= n) {
            a[p] += delta;
            p += lowbit(p);
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    s.insert(s.begin(), 'X');

    for (int i = 1; i <= n; i++) {
        pa[i] = pa[i - 1] + bool(s[i] == 'A');
        pb[i] = pb[i - 1] + bool(s[i] == 'B');
    }

    for (int i = 1; i <= n; i++) {
        g[i] = pa[i] - pb[i];
    }

    BIT tree(5e6);
    int ans = 0;

    tree.mut(0, 1);
    for (int i = 1; i <= n; i++) {
        int tmp = tree.query(g[i] - 1);
        ans += tmp;
        tree.mut(g[i], 1);

        // cerr << i << " " << g[i] << " " << tmp << "\n";
    }

    cout << ans;

    return 0;
}