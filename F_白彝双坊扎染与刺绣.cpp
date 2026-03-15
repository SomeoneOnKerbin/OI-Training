#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;

int n;
int t[N];
int a[N], b[N];

struct task {
    int t, a, b, id;
};

struct result {
    int time; // all finised
    vector<int> order;
};

bool cmpA(task &x, task &y) { return x.a < y.a; }

bool cmpB(task &x, task &y) { return x.b > y.b; }

result johnson(vector<task> &tasks) {
    vector<task> typeA, typeB;

    for (auto &task : tasks) {
        if (task.a < task.b) {
            typeA.push_back(task);
        } else {
            typeB.push_back(task);
        }
    }

    sort(typeA.begin(), typeA.end(), cmpA);
    sort(typeB.begin(), typeB.end(), cmpB);

    result res;

    int timeA = 0;
    deque<pair<task, int>> dq;

    for (auto &task : typeA) {
        res.order.push_back(task.id);
        timeA += task.a;
        dq.push_back({task, timeA});
    }

    for (auto &task : typeB) {
        res.order.push_back(task.id);
        timeA += task.a;
        dq.push_back({task, timeA});
    }

    int timeB = 0;
    for (auto &p : dq) {
        int start = max(p.second, timeB);
        timeB = start + p.first.b;
    }

    res.time = timeB;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef LOCAL
    freopen("dye.in", "r", stdin);
    freopen("dye.out", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> a[i] >> b[i];
    }

    vector<task> task0, task1;
    for (int i = 1; i <= n; i++) {
        if (t[i] == 0) {
            task0.push_back({t[i], a[i], b[i], i});
        } else {
            task1.push_back({t[i], a[i], b[i], i});
        }
    }

    result res0 = johnson(task0);
    result res1 = johnson(task1);

    int tot = max(res0.time, res1.time);

    cout << tot << "\n";
    cout << res0.time << "\n";
    for (auto &x : res0.order) {
        cout << x << " ";
    }
    cout << "\n";

    cout << res1.time << "\n";
    for (auto &x : res1.order) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}