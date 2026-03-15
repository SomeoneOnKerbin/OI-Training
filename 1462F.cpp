#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;

int n;
pair<int, int> a[N];
int pfxl[N], pfxr[N];

vector<int> nums;

int getid(int x) {
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
}

int query(int *pfx, int l, int r) {
    if (l > r)
        return 0;
    return pfx[r] - pfx[l - 1];
}

void solveA() {
    cin >> n;

    memset(a, 0, sizeof(pair<int, int>) * (4 * n + 128));
    memset(pfxl, 0, sizeof(int) * (4 * n + 128));
    memset(pfxr, 0, sizeof(int) * (4 * n + 128));

    nums.clear();

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        nums.push_back(a[i].first);
        nums.push_back(a[i].second);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (int i = 1; i <= n; i++) {
        a[i].first = getid(a[i].first);
        a[i].second = getid(a[i].second);
    }

    for (int i = 1; i <= n; i++) {
        pfxl[a[i].first]++;
        pfxr[a[i].second]++;
    }

    int maxnum = nums.size();

    for (int i = 1; i <= maxnum; i++) {
        pfxl[i] += pfxl[i - 1];
        pfxr[i] += pfxr[i - 1];
    }

    int ans = 1e15;

    for (int i = 1; i <= n; i++) {
        int l = a[i].first, r = a[i].second;
        int cntl = query(pfxr, 1, l - 1);
        int cntr = query(pfxl, r + 1, maxnum);
        ans = min(ans, cntl + cntr);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef LOCAL
    freopen("good.in", "r", stdin);
    freopen("good.out", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--) {
        solveA();
    }

    return 0;
}