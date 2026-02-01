#include <bits/stdc++.h>
using namespace std;

struct Dsu {
    vector<int> pa;

    Dsu(int size) {
        pa.resize(size + 128);
        for (int i = 1; i <= size; i++)
            pa[i] = i;
    }

    int find(int x) {
        if (pa[x] == x)
            return x;
    }

    void merge(int x, int y) { pa[find(x)] = find(y); }
};