// Problem: A. 倒水
// Time Limit: 1000 ms
// URL: http://oj.mqcoj.cn:5000/p/18244?tid=697a114cac2ac5ec76c48475
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 300 + 10;

struct State {
    int x, y, z, step = 0;
};

int x, y, z, n;

int f[N][N][N];

void bfs() {
    queue<State> q;

    q.push({0, 0, 0, 0});
    q.push({x, 0, 0, 2});
    q.push({0, y, 0, 2});
    q.push({0, 0, z, 2});

    q.push({x, y, 0, 4});
    q.push({x, 0, z, 4});
    q.push({0, y, z, 4});

    q.push({z, y, z, 6});

    while (!q.empty()) {
        State tmp = q.front();
        q.pop();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef LOCAL
    freopen("water.in", "r", stdin);
    freopen("water.out", "w", stdout);
#endif

    cin >> x >> y >> z >> n;

    return 0;
}
