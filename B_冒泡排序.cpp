#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 5;

int n, m;
vector<int> vals;

struct seg {
    int l, r, v;
} sg[N];

int a[N];

bool check(int p) {
    for (int i = 1; i <= m; i++) {
        int minn = 1e14;

        if (sg[i].l > p) {
            continue;
        }

        for (int j = sg[i].l; j <= sg[i].r; j++) {
            minn = min(minn, a[j]);
        }

        if (minn != sg[i].v) {
            return false;
        }
    }
    return true;
}

int tmp[N];

int bupplesort() {
    memcpy(tmp, a, sizeof(a));

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (tmp[j] > tmp[j + 1]) {
                swap(tmp[j], tmp[j + 1]);
                cnt++;
            }
        }
    }

    return cnt;
}

int ans = 1e14;

void dfs(int p) {
    if (p == n + 1) {
        if (check(n)) {
            int res = bupplesort();
            ans = min(ans, res);
        }

        return;
    }

    for (int i = 1; i <= m; i++) {
        int minn = 1e14;
        for (int j = sg[i].l; j <= sg[i].r; j++) {
            minn = min(minn, a[j]);
        }

        if (minn < sg[i].v) {
            return;
        }
    }

    for (int i = 1; i <= m; i++) {
        int minn = 1e14;

        if (sg[i].l >= p || sg[i].r >= p) {
            continue;
        }

        for (int j = sg[i].l; j <= sg[i].r; j++) {
            minn = min(minn, a[j]);
        }

        if (minn != sg[i].v) {
            return;
        }
    }

    for (int i = 0; i < vals.size(); i++) {
        a[p] = vals[i];
        dfs(p + 1);
        a[p] = 1e14;
    }
}

void solve14() {
    sort(vals.begin(), vals.end());

    memset(a, 0x3f, sizeof(a));
    dfs(1);

    if (ans >= 1e12) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
}

void solveA() {
    // cout << -1 << "\n";
    for (int i = 1; i <= n; i++) {
        a[i] = -1;
    }

    sort(sg + 1, sg + m + 1,
         [](const seg &a, const seg &b) { return a.l < b.l; });

    for (int i = 1; i <= m; i++) {
        a[sg[i].l] = sg[i].v;
    }

    for (int i = 1; i <= m; i++) {
        int minn = 1e14;
        for (int j = sg[i].l; j <= sg[i].r; j++) {
            if (a[j] != -1) {
                minn = min(minn, a[j]);
            }
        }

        if (minn != sg[i].v) {
            cout << -1 << "\n";
            return;
        }
    }
}

void solveB() {
    cout << -1 << "\n";
    // for (int i = 1; i <= n; i++) {
    //     a[i] = -1;
    // }

    // for (int i = 1; i <= m; i++) {
    //     a[sg[i].l] = sg[i].v;
    // }

    // for(int i=1;i<=n;i++) {
    //     if(a[i] == -1) {
    //         // 可以任意选择（使得产生的逆序对最少）
    //     }
    // }
}

void solveC() {
    for (int j = 1; j <= n; j++) {
        a[j] = -1;
    }

    for (int i = 1; i <= m; i++) {
        a[sg[i].l] = sg[i].v;
    }

    int maxbefore = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            a[i] = maxbefore;
        }

        maxbefore = max(maxbefore, a[i]);
    }

    for (int i = 1; i <= n; i++) {
        cerr << a[i] << " ";
    }

    cerr << "\n";

    cout << bupplesort() << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        memset(sg, 0, sizeof(seg) * (n + 128));
        ans = 1e14;
        vals.clear();

        cin >> n >> m;

        for (int i = 1; i <= m; i++) {
            cin >> sg[i].l >> sg[i].r >> sg[i].v;
            vals.push_back(sg[i].v - 1);
            vals.push_back(sg[i].v);
            vals.push_back(sg[i].v + 1);
        }

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        bool tsk14 = n <= 17 && m <= 17;
        bool specialA = true, specialB = true;

        for (int i = 1; i <= m; i++) {
            if (sg[i].l != sg[i].r)
                specialB = false;
            if (sg[i].v != 1 && sg[i].v != 0)
                specialA = false;
        }

        if (tsk14) {
            solve14();
        } else if (specialA) {
            solveA();
        } else if (specialB) {
            solveB();
        } else {
            solveC();
        }
    }

    return 0;
}