// Problem: G. Exercise
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2424/problem/7
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, m;

int f[N];
bool isprime[N];
vector<int> primes;

void init() {
    memset(isprime, 1, sizeof isprime);

    for (int i = 2; i <= 1e4; i++) {
        for (int j = i + i; j <= 1e4; j += i) {
            isprime[j] = false;
        }
    }

    for (int i = 2; i <= 1e4; i++) {
        if (isprime[i])
            primes.push_back(i);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    init();

    f[0] = 1;
    for (auto &p : primes) {
        for (int j = n; j >= p; j--) {
            int pp = p;
            while (pp <= j) {
                f[j] = f[j] + f[j - pp] * pp;
                f[j] %= m;

                // pp * p < n
                if (n / p < pp) {
                    break;
                }

                pp *= p;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += f[i];
        ans %= m;
    }

    cout << ans;

    return 0;
}