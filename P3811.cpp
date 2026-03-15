#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 5;

int n, p;
int inv[N];

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int modinv(int a) {
    // ax + py === 1
    int x, y;
    int d = exgcd(a, p, x, y);

    if (d != 1)
        return -1;
    return (x % p + p) % p;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;

    inv[1] = 1;
    cout << inv[1] << "\n";
    for (int i = 2; i <= n; i++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
        cout << inv[i] << "\n";
    }

    return 0;
}