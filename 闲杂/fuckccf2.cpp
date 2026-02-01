#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N = 4e5 + 10;

int k;
double p;

mt19937 rng(time(nullptr));

bool good() {
    double x = rng() % (int)1e7;
    x /= (int)1e7;

    if (x >= p)
        return true;
    else
        return false;
}

bool solve() {
    int left = 0, right = 0;

    for (int i = 1; i <= k; i++) {
        if (good())
            left++;
        else
            right++;
    }

    return left >= right;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k;
    cin >> p;

    int right = 0, wrong = 0;
    for (int i = 1; i <= 1e7; i++) {
        if (solve())
            right++;
        else
            wrong++;
    }

    cout << right << " " << wrong << " " << setprecision(32)
         << (right * 1.0) / (right + wrong);

    return 0;
}
