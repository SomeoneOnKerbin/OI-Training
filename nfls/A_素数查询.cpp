// Problem: A. 素数查询
// Time Limit: 2000 ms
// URL: http://nflsoi.cc:20035/contest/2424/problem/1
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 10;

int maxval = 0;

int a[N];
// unordered_map<int, int> cnt;
int cnt[N];

int f[N], pfx[N];
bool isp[N];
vector<int> primes;

void search() {
    for (int i = 2; i <= maxval; i++) {
        if (isp[i]) {
            for (int k = 2; i * k <= maxval; k++) {
                isp[i * k] = false;
            }
        }
    }

    for (int i = 2; i <= maxval; i++) {
        if (isp[i])
            primes.push_back(i);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(isp, 1, sizeof isp);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;

        maxval = max(maxval, a[i]);
    }

    search();

    for (auto &p : primes) {
        for (int k = 1; p * k <= maxval; k++) {
            f[p] += cnt[p * k];
        }
    }

    for (int i = 1; i <= maxval; i++) {
        pfx[i] = pfx[i - 1] + f[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        if (r >= maxval) {
            r = maxval;
        }

        cout << pfx[r] - pfx[l - 1] << "\n";
    }

    return 0;
}