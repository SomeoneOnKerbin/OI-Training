// Problem: P8435 【模板】点双连通分量
// Time Limit: 2000 ms
// URL: https://www.luogu.com.cn/problem/P8435
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;

stack<int> stk;
vector<int> adj[N];
vector<vector<int>> comps;

int timestamp = 1;
int dfn[N], low[N];

void tarjan(int u, int fa) {
    int child = 0;
    stk.push(u);
    dfn[u] = low[u] = timestamp++;

    for (auto &v : adj[u]) {
        if (v == fa)
            continue;
        if (!dfn[v]) {
            child++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] >= dfn[u]) {
                vector<int> comp;

                while (!stk.empty() && stk.top() != v) {
                    comp.push_back(stk.top());
                    stk.pop();
                }

                comp.push_back(v);
                stk.pop();

                comp.push_back(u);

                comps.push_back(comp);
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (fa == 0 && child == 0) {
        comps.push_back({u});
    }
}

int read() {
    int x = 0;
    bool neg = false;
    char c = getchar_unlocked();

    while (!isdigit(c)) {
        if (c == '-')
            neg = true;

        c = getchar_unlocked();
    }

    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar_unlocked();
    }

    if (neg)
        return -x;
    else
        return x;
}

void write(int x) {
    if (x < 0) {
        x = -x;
        putchar_unlocked('-');
    }

    if (x >= 10) {
        write(x / 10);
    }

    putchar_unlocked(x % 10 + '0');
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = read(), m = read();

    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            while (!stk.empty()) {
                stk.pop();
            }

            tarjan(i, 0);
        }
    }

    // cout << comps.size() << "\n";
    write(comps.size());
    putchar_unlocked('\n');

    for (auto &comp : comps) {
        // cout << comp.size() << " ";
        write(comp.size());
        putchar_unlocked(' ');

        // sort(comp.begin(), comp.end());

        for (auto &x : comp) {
            // cout << x << " ";
            write(x);
            putchar_unlocked(' ');
        }

        // cout << "\n";
        putchar_unlocked('\n');
    }

    return 0;
}