// Problem: A. 力量与精神
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2416/problem/1
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int C, n;
int m[N], b[N], c[N], d[N];

bool removed[N];

// 初始力量为 lambda 时，能否穿戴上所有装备
// 不考虑精神
bool check1(int lambda) {
    memset(removed, false, sizeof removed);

    // 在当前的合法区间穿戴更多的装备
    int val = lambda;

    while (true) {
        bool flag = false;

        for (int i = 1; i <= n; i++) {
            if (m[i] <= val && removed[i] == false) {
                val += c[i];
                removed[i] = true;
                flag = true;
            }
        }

        if (flag == false) {
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (removed[i] == false) {
            return false;
        }
    }

    return true;
}

// 初始力量为 power，初始精神为 lambda，是否可以穿戴所有装备
bool check2(int lambda, int power) {
    memset(removed, false, sizeof removed);

    int aval = power, bval = lambda;

    while (true) {
        bool flag = false;

        for (int i = 1; i <= n; i++) {
            if (aval >= m[i] && bval >= b[i] && removed[i] == false) {
                aval += c[i];
                bval += d[i];
                flag = true;
                removed[i] = true;
            }
        }

        if (flag == false) {
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (removed[i] == false) {
            return false;
        }
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef LOCAL
    freopen("strength.in", "r", stdin);
    freopen("strength.out", "w", stdout);
#endif

    cin >> C >> n;

    for (int i = 1; i <= n; i++) {
        cin >> m[i] >> b[i] >> c[i] >> d[i];
    }

    int l = 0, r = 1e14, ans1 = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check1(mid)) {
            r = mid - 1;
            ans1 = mid;
        } else {
            l = mid + 1;
        }
    }

    l = 0, r = 1e14;
    int ans2 = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check2(mid, ans1)) {
            r = mid - 1;
            ans2 = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << ans1 << " " << ans2;

    return 0;
}