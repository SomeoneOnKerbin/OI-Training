// Contest: Baidu Astar
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int it = 0;
    while (it <= 1) {
        void *p = malloc(1024 * 1024 * 1024); // 1gb
        memset(p, 0x3f, 1024 * 1024 * 1024);
        cout << p << "\n";
        it++;
    }

    return 0;
}
