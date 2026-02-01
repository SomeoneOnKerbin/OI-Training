// Problem: E. Enemy is weak
// Time Limit: 5000 ms
// URL: https://codeforces.com/problemset/problem/61/E
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 10;

int n;
int a[N];

struct BIT {
    int n;
    vector<int> t;

    BIT(int size) {
        n = size;
        t.resize(size + 128);
    }

    int lowbit(int x) { return x & -x; }

    int query(int x) {
        int res = 0;

        if (x <= 0) {
            return 0;
        }

        while (x >= 1) {
            res += t[x];
            x -= lowbit(x);
        }
        return res;
    }

    int querylr(int l, int r) { return query(r) - query(l - 1); }

    void add(int p, int x) {
        while (p <= n) {
            t[p] += x;
            p += lowbit(p);
        }
    }
};

int b[N];
vector<int> nums;

int getid(int x) {
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nums.push_back(a[i]);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (int i = 1; i <= n; i++) {
        b[i] = getid(a[i]);
    }

    BIT s(n + 128), d(n + 128);

    int maxx = n + 16;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int nd = s.querylr(b[i] + 1, maxx);
        int nt = d.querylr(b[i] + 1, maxx);

        d.add(b[i], nd);
        ans += nt;

        s.add(b[i], 1);
    }

    cout << ans;

    return 0;
}