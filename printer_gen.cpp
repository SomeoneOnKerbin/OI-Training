#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    mt19937 rng(time(nullptr));

    int n = 5, k = rng() % 5 + 1;
    cout << n << " " << k << "\n";
    for (int i = 1; i <= n; i++) {
        cout << rng() % 10 + 1 << " ";
    }

    return 0;
}