#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

int n;
int m[N], b[N];
int pfx[N];
int f[N][20];
int logN[N];

void pre() {
    logN[1] = 0;
    for (int i = 2; i < N; i++)
        logN[i] = logN[i / 2] + 1;
}

void build(int len) {
    for (int i = 1; i <= len; i++)
        f[i][0] = pfx[i];

    for (int j = 1; j < 20; j++) {
        for (int i = 1; i + (1 << j) - 1 <= len; i++) {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int len = r - l + 1;
    int k = logN[len];

    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

vector<int> solve(vector<int> &val) {
    vector<int> res;

    pfx[0] = 0;
    for (int i = 1; i <= n * 2; i++) {
        pfx[i] = pfx[i - 1] + val[i];
    }

    build(n * 2);

    for (int i = 1; i <= n; i++) {
        if (query(i, i + n - 1) - pfx[i - 1] >= 0) {
            res.push_back(i);
        }
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> m[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    pre();
    vector<int> ans;

    vector<int> val(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        val[i] = m[i] - b[i];
        val[i + n] = val[i];
    }

    vector<int> ans1 = solve(val);
    for (int x : ans1)
        ans.push_back(x);

    vector<int> val2(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        int rid = n - i + 1;

        int tmp = rid - 1;
        if (tmp == 0)
            tmp = n;

        val2[i] = m[rid] - b[tmp];
        val2[i + n] = val2[i];
    }

    vector<int> ans2 = solve(val2);

    for (auto &x : ans2) {
        ans.push_back(n - x + 1);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << "\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << "\n";

    return 0;
}
