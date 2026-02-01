// Problem: B. Apple Tree
// Time Limit: 2000 ms
// URL: https://codeforces.com/problemset/problem/348/B
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n, K = 1, tot = 0;
int a[N], k[N];
bool leaf[N];
vector<int> adj[N];

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

int lcm(int a, int b) {
    int x, y;
    int d = exgcd(a, b, x, y);

    if (d == 0) {
        cout << tot;
        exit(0);
    }

    return (a * b) / d;
}

void dfs(int u, int pa, int nowk) {
    k[u] = nowk;

    for (auto &v : adj[u]) {
        if (v == pa)
            continue;

        if (u != 1) {
            dfs(v, u, nowk * (adj[u].size() - 1));
        } else {
            dfs(v, u, nowk * adj[u].size());
        }

        leaf[u] = false;
    }

    if (leaf[u]) {
        K = lcm(K, nowk);

        if (K > tot) {
            cout << tot;
            exit(0);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(leaf, 1, sizeof leaf);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 1);

    // W === 0 (mod K)
    // W / k[i] <= a[i]

    int minval = 1e14;
    for (int i = 1; i <= n; i++) {
        if (leaf[i])
            minval = min(minval, (int)(a[i] * k[i]));
    }

    if (K == 0) {
        cout << tot;
        exit(0);
    }

    int ans = (minval / K) * K;

    cerr << minval << " " << K << "\n";

    cout << tot - ans;

    return 0;
}