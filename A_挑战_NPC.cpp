#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5;
const int BASE = 1e9 + 9;
const int MOD = 1e9 + 7;

int power(int a, int k) {
    if (k == 0)
        return 1;
    if (k % 2 == 0) {
        int base = power(a, k / 2);
        return base * base % MOD;
    } else {
        return a * power(a, k - 1) % MOD;
    }
}

int c, t, k;
vector<int> adjG[N], adjH[N];
int hsG[N], hsH[N];
int sizG[N], sizH[N];

int gethash(vector<int> v) {
    int res = 1;
    for (int i = 0; i < v.size(); i++) {
        res += v[i] * power(BASE, v.size() - i - 1);
        res %= MOD;
    }
    return res;
}

void dfs(int u, int pa, vector<int> adj[], int hs[], int siz[], int dep) {
    siz[u] = 1;
    hs[u] = gethash({dep});

    vector<pair<int, int>> childs;
    for (int v : adj[u]) {
        if (v == pa)
            continue;
        dfs(v, u, adj, hs, siz, dep + 1);
        childs.emplace_back(hs[v], v);
        siz[u] += siz[v];
    }

    sort(childs.begin(), childs.end());

    int cnt = 0;
    for (auto p : childs) {
        cnt++;
        hs[u] += gethash({hs[u], hs[p.second], cnt});
        hs[u] %= MOD;
    }
}

unordered_map<int, int> hsmpH;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// 抛弃 miss 个节点，使得 G 的哈希值能在 H 的哈希表里找到
void dfs2(int u, int pa, int dep, int &miss) {
    sizG[u] = 1;
    hsG[u] = gethash({dep});

    vector<pair<int, int>> childs;
    for (int v : adjG[u]) {
        if (v == pa)
            continue;
        dfs2(v, u, dep + 1, miss);
        childs.emplace_back(hsG[v], v);
        sizG[u] += sizG[v];
    }

    sort(childs.begin(), childs.end());

    int cnt = 0;
    int lastmatch = 0, usedcnt = 0;

    if (hsmpH.count(hsG[u])) {
        lastmatch = hsG[u];
        usedcnt = 1;
    }

    for (auto p : childs) {
        cnt++;
        hsG[u] += gethash({hsG[u], hsG[p.second], cnt});
        hsG[u] %= MOD;

        if (hsmpH.count(hsG[u])) {
            lastmatch = hsG[u];
            usedcnt = cnt;
        }
    }

    if (lastmatch != hsG[u]) {
        // cerr << "miss " << u << " " << childs.size() - usedcnt
        //  << " children mismatched\n";
        miss += childs.size() - usedcnt;
        hsG[u] = lastmatch;
    }

    hsmpH[hsG[u]]--;
}

void solve() {
    memset(sizG, 0, sizeof(sizG));
    memset(sizH, 0, sizeof(sizH));
    memset(hsG, 0, sizeof(hsG));
    memset(hsH, 0, sizeof(hsH));

    int ng;
    cin >> ng;

    int rootG = -1, rootH = -1;

    for (int i = 1; i <= ng; i++) {
        hsG[i] = 0;
        adjG[i].clear();
    }

    for (int i = 1; i <= ng; i++) {
        int fa;
        cin >> fa;
        if (fa == -1) {
            rootG = i;
            continue;
        }

        adjG[fa].push_back(i);
        adjG[i].push_back(fa);
    }

    int nh;
    cin >> nh;

    for (int i = 1; i <= nh; i++) {
        hsH[i] = 0;
        adjH[i].clear();
    }

    for (int i = 1; i <= nh; i++) {
        int fa;
        cin >> fa;
        if (fa == -1) {
            rootH = i;
            continue;
        }

        adjH[fa].push_back(i);
        adjH[i].push_back(fa);
    }

    dfs(rootH, -1, adjH, hsH, sizH, 1);
    dfs(rootG, -1, adjG, hsG, sizG, 1);

    bool flag = false;

    if (hsG[rootG] == hsH[rootH]) {
        flag = true;
    }

    for (int i = 1; i <= 10; i++) {
        vector<int> want(k, -1);
        for (auto &x : want) {
            x = rng() % nh + 1;
        }

        for (int i = 0; i < k; i++) {
            adjH[nh + i + 1].push_back(want[i]);
            adjH[want[i]].push_back(nh + i + 1);
        }

        dfs(rootH, -1, adjH, hsH, sizH, 1);

        for (int i = 0; i < k; i++) {
            adjH[nh + i + 1].pop_back();
            adjH[want[i]].pop_back();
        }

        if (hsG[rootG] == hsH[rootH]) {
            flag = true;
            break;
        }
    }

    if (flag) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> t >> k;
    while (t--) {
        solve();
    }

    return 0;
}