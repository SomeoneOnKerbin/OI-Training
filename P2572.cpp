// Problem: P2572 [SCOI2010] 序列操作
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P2572
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

struct node {
    int l, r;
    mutable int val;

    node(int L, int R = -1, int V = 0) : l(L), r(R), val(V) {}

    int len() const { return r - l + 1; }

    bool operator<(const node &o) const { return l < o.l; }
};

struct ODT {
    set<node> st;

    ODT() { st.insert(node(0, 1e18, 0)); }

    auto split(int pos) {
        auto it = st.lower_bound(node(pos));

        if (it != st.end() && it->l == pos)
            return it;

        it--;

        int l = it->l, r = it->r, val = it->val;
        st.erase(it);

        st.insert(node(l, pos - 1, val));
        return st.insert(node(pos, r, val)).first;
    }

    void assign(int l, int r, int val) {
        auto itr = split(r + 1), itl = split(l);
        st.erase(itl, itr);
        st.insert(node(l, r, val));
    }
} odt;

void query1(int l, int r) { odt.assign(l, r, 0); }

void query2(int l, int r) { odt.assign(l, r, 1); }

void query3(int l, int r) {
    auto itr = odt.split(r + 1), itl = odt.split(l);

    for (auto it = itl; it != itr; it++) {
        if (it->val == 0)
            it->val = 1;
        else
            it->val = 0;
    }
}

int query4(int l, int r) {
    int ans = 0;
    auto itr = odt.split(r + 1), itl = odt.split(l);

    for (auto it = itl; it != itr; it++) {
        if (it->val == 1) {
            ans += it->len();
        }
    }

    return ans;
}

int query5(int l, int r) {
    int ans = 0, tmp = 0;
    auto itr = odt.split(r + 1), itl = odt.split(l);

    for (auto it = itl; it != itr; it++) {
        if (it->val == 1) {
            tmp += it->len();
        } else if (it->val == 0 && tmp != 0) {
            ans = max(ans, tmp);
            tmp = 0;
        }
    }

    if (tmp != 0) {
        ans = max(ans, tmp);
        tmp = 0;
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    odt.st.clear();
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        odt.st.insert(node(i, i, val));
    }

    odt.st.insert(node(n + 1, n + 1, 0));
    odt.st.insert(node(0, 0, 0));

    while (m--) {
        int op;
        cin >> op;
        int l, r;
        cin >> l >> r;

        l++;
        r++;

        if (op == 0)
            query1(l, r);
        else if (op == 1)
            query2(l, r);
        else if (op == 2)
            query3(l, r);
        else if (op == 3)
            cout << query4(l, r) << "\n";
        else if (op == 4)
            cout << query5(l, r) << "\n";
    }

    return 0;
}