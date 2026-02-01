// Problem: C. Multiplicity
// Time Limit: 3000 ms
// URL: https://codeforces.com/problemset/problem/1061/C
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int n;
int a[N], f[N];
set<int> divs[N];
bool exists[N];

void pre() {
    for (int i = 1; i <= 1e6 + 10; i++) {
        for (int k = 1; i * k <= 1e6 + 10; k++) {
            int val = i * k;

            if (exists[val] == true) {
                divs[val].insert(i);
                divs[val].insert(k);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        exists[a[i]] = true;
    }

    pre();

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        // for (int j = n; j >= 1; j--) {
        //     if (a[i] % j == 0) {
        //         f[j] += f[j - 1];
        //         f[j] %= MOD;
        //     }
        // }

        for (auto j = divs[a[i]].rbegin(); j != divs[a[i]].rend(); j++) {
            int d = *j;

            f[d] += f[d - 1];
            f[d] %= MOD;
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += f[i];
        ans %= MOD;
    }

    cout << ans;

    return 0;
}