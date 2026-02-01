// Problem: D. 传送装置
// Time Limit: 1000 ms
// URL: http://nflsoi.cc:20035/contest/2415/problem/4
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, K, ans = 0;
int m[N];

vector<int> adj[N];

int dfs(int u, int fa) {
    int maxdep = 0;

    for (auto &v : adj[u]) {
        if (v == fa)
            continue;

        int dep = dfs(v, u);

        if (dep != -1)
            maxdep = max(maxdep, dep + 1);
    }

    if (u == 1)
        return maxdep;

    if (maxdep >= K - 1) {
        if (m[u] != 1)
            ans++;

        return -1;
    }

    return maxdep;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> K;

    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }

    if (m[1] != 1) {
        ans++;
        m[1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        adj[i].push_back(m[i]);
        adj[m[i]].push_back(i);
    }

    dfs(1, 0);

    cout << ans;

    return 0;
}