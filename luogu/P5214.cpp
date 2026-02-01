// Problem: P5214 [SHOI2014] 神奇化合物
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P5214
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

struct Dsu {
    vector<int> pa;

    Dsu(int size) {
        pa.resize(size + 128);
        for (int i = 1; i <= size; i++) {
            pa[i] = i;
        }
    }

    int find(int x) {
        if (x == pa[x])
            return x;
        pa[x] = find(pa[x]);
        return pa[x];
    }

    void merge(int x, int y) { pa[find(x)] = find(y); }
};

int cnt = 1;
int node[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Dsu dsu(n + 128);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        node[u] = cnt++;
        node[v] = cnt++;
        dsu.merge(node[u], node[v]);
    }

    int q; cin>>q;

    while(q--) {
        
    }

    return 0;
}