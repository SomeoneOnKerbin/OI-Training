#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> t;

    BIT(int size) {
        n = size;
        t.resize(n + 128);
    }

    int lowbit(int x) { return x & -x; }

    void add(int k, int delta) {
        while (k <= n) {
            t[k] += delta;
            k += lowbit(k);
        }
    }

    int query(int p) {
        int res = 0;
        while (p > 0) {
            res += t[p];
            p -= lowbit(p);
        }

        return res;
    }
};