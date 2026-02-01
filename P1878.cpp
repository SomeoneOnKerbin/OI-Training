// Problem: P1878 舞蹈课
// Time Limit: 1000 ms
// URL: https://www.luogu.com.cn/problem/P1878
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n;

struct Person {
    int id, val;
    bool sex;
} p[N];

int lt[N], rt[N];
bool ava[N];

struct Pair {
    int a, b;

    bool isava() const {
        return (lt[b] == a) && (rt[a] == b) && (ava[a]) && (ava[b]);
    }

    int diff() const { return abs(p[a].val - p[b].val); }

    const bool operator<(const Pair &p) const {
        if (diff() == p.diff())
            return a < p.a;
        return diff() < p.diff();
    }

    const bool operator>(const Pair &p) const {
        if (diff() == p.diff())
            return a > p.a;

        return diff() > p.diff();
    }
};

vector<Pair> ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    string s;
    cin >> s;

    s.insert(s.begin(), 'X');

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'G')
            p[i].sex = true;
    }

    for (int i = 1; i <= n; i++) {
        cin >> p[i].val;
    }

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    for (int i = 1; i <= n; i++) {
        if (i != 1)
            lt[i] = i - 1;

        if (i != n)
            rt[i] = i + 1;

        ava[i] = true;

        if (i != n && p[i].sex != p[i + 1].sex) {
            pq.push(Pair{i, i + 1});
        }
    }

    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();

        if (!tmp.isava())
            continue;

        ans.push_back(tmp);

        rt[lt[tmp.a]] = rt[tmp.b];
        lt[rt[tmp.b]] = lt[tmp.a];
        ava[tmp.a] = ava[tmp.b] = false;

        if (p[lt[tmp.a]].sex != p[rt[tmp.b]].sex) {
            pq.push(Pair{lt[tmp.a], rt[tmp.b]});
        }
    }

    cout << ans.size() << "\n";
    for (auto &x : ans) {
        cout << min(x.a, x.b) << " " << max(x.a, x.b) << "\n";
    }

    return 0;
}