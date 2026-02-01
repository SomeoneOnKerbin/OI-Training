// Problem: F. 因子路径
// Time Limit: 3000 ms
// URL: http://nflsoi.cc:20035/contest/2424/problem/6
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
const int N = 100;

int d, q;
int fact[N];
int invfact[N];
vector<int> primes;

int power(int a, int b) {
    if (b == 0)
        return 1;

    if (b % 2 == 1) {
        return (power(a, b - 1) * a) % MOD;
    } else {
        int base = power(a, b / 2);
        return (base * base) % MOD;
    }
}

int modinv(int n) { return power(n, MOD - 2); }

void init() {
    fact[0] = 1;
    invfact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invfact[i] = modinv(fact[i]);
    }

    int tmp = d;
    for (int i = 2; i * i <= tmp; i++) {
        if (tmp % i == 0) {
            primes.push_back(i);
            while (tmp % i == 0)
                tmp /= i;
        }
    }
    
    if (tmp > 1) {
        primes.push_back(tmp);
    }
}

int getcnt(int val) {
    if (val == 1)
        return 1;

    int tot = 0;
    int de = 1;

    for (int p : primes) {
        if (val % p == 0) {
            int cnt = 0;
            while (val % p == 0) {
                cnt++;
                val /= p;
            }
            tot += cnt;
            de = de * invfact[cnt] % MOD;
        }
    }

    return fact[tot] * de % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> d >> q;

    init();

    while (q--) {
        int u, v;
        cin >> u >> v;

        int g = __gcd(u, v);

        int ans1 = getcnt(u / g);
        int ans2 = getcnt(v / g);

        cout << (ans1 * ans2) % MOD << "\n";
    }

    return 0;
}
