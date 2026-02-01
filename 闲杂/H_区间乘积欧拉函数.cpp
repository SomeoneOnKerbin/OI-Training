// Problem: H. 区间乘积欧拉函数
// Time Limit: 3000 ms
// URL: http://nflsoi.cc:20035/contest/2424/problem/8
//
// Powered by CPH-NG and VSCode

#include <bits/stdc++.h>
#define int long long
// #define int128 __int128_t
#define int128 long long
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int128 n, q;
int128 a[N];

struct query {
    int128 l, r, id, ans = 0;
} qrys[N];

bool cmpid(query &a, query &b) { return a.id < b.id; }
bool cmpr(query &a, query &b) { return a.r < b.r; }

bool isp[N];

int128 spf[N], pfx[N];
vector<int128> primes;

int128 power(int128 a, int128 k) {
    a %= MOD;

    if (k == 0)
        return 1;
    if (k % 2 == 1) {
        return (power(a, k - 1) * a) % MOD;
    } else {
        int128 base = power(a, k / 2);
        return (base * base) % MOD;
    }
}

int128 modinverse(int128 x) { return power(x, MOD - 2); }

void pre() {
    memset(isp, 1, sizeof isp);
    memset(spf, 0x3f, sizeof spf);

    pfx[0] = 1;

    for (int128 i = 1; i <= n; i++) {
        pfx[i] = pfx[i - 1] * a[i];
        pfx[i] %= MOD;
    }

    iota(spf, spf + N, 0);
    for (int128 i = 2; i < N; i++) {
        if (isp[i])
            primes.push_back(i);
        for (auto &p : primes) {
            if (i * p >= N)
                break;
            isp[i * p] = false;

            if (p < spf[i * p]) {
                spf[i * p] = p;
            }
        }
    }

    // for (int128 i = 2; i < N; i++) {
    //     for (auto &p : primes) {
    //         if (i * p >= N || p > spf[i])
    //             break;
    //         spf[i * p] = p;
    //     }
    // }
}

vector<int128> getfracs(int128 x) {
    vector<int128> res;

    while (x > 1) {
        res.push_back(spf[x]);
        x /= spf[x];
    }

    return res;
}

// unordered_map<int, int> last;
int last[N];
struct BIT {
    int128 n;
    vector<int128> t;

    BIT(int128 size) {
        n = size;
        t.resize(size + 128);
        fill(t.begin(), t.end(), 1);
    }

    int128 lowbit(int128 x) { return x & -x; }

    int128 query(int128 p) {
        int128 res = 1;
        while (p >= 1) {
            res *= t[p];
            res %= MOD;

            p -= lowbit(p);
        }

        return res % MOD;
    }

    void mut(int128 p, int128 d) {
        d %= MOD;

        while (p <= n) {
            t[p] *= d;
            t[p] %= MOD;

            p += lowbit(p);
        }
    }
};

int128 read() {
    int128 x = 0;
    bool neg = false;
    char c = getchar_unlocked();

    while (!isdigit(c)) {
        if (c == '-')
            neg = true;
        c = getchar_unlocked();
    }

    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar_unlocked();
    }

    if (neg)
        x = -x;

    return x;
}

void write(int128 x) {
    if (x < 0) {
        putchar_unlocked('-');
        x = -x;
    }

    if (x >= 10) {
        write(x / 10);
    }

    putchar_unlocked(x % 10 + '0');
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // cin >> n;
    n = read();
    for (int128 i = 1; i <= n; i++) {
        // cin >> a[i];
        a[i] = read();
    }

    // cin >> q;
    q = read();
    for (int128 i = 1; i <= q; i++) {
        // cin >> qrys[i].l >> qrys[i].r;
        qrys[i].l = read();
        qrys[i].r = read();
        qrys[i].id = i;
    }

    sort(qrys + 1, qrys + q + 1, cmpr);

    pre();

    BIT tree(1e6 + 10);
    int128 lastr = 0;
    for (int128 i = 1; i <= q; i++) {
        int128 l = qrys[i].l, r = qrys[i].r;
        int128 range = (pfx[r] * modinverse(pfx[l - 1])) % MOD;

        for (int128 j = lastr + 1; j <= r; j++) {
            vector<int128> fracs = getfracs(a[j]);

            for (auto &p : fracs) {
                // if (last.find(p) != last.end()) {
                if (last[p] != 0) {
                    tree.mut(last[p], modinverse((p - 1) * modinverse(p)));
                }

                tree.mut(j, (p - 1) * modinverse(p));
                last[p] = j;
            }
        }

        int128 euler = (tree.query(r) * modinverse(tree.query(l - 1))) % MOD;
        int128 ans = (range * euler) % MOD;

        // cerr << range << " " << euler << " " << pfx[l - 1] << "\n";

        qrys[i].ans = (ans + MOD) % MOD;

        lastr = r;
    }

    sort(qrys + 1, qrys + q + 1, cmpid);

    for (int128 i = 1; i <= q; i++) {
        // cout << qrys[i].ans << "\n";
        write(qrys[i].ans);
        putchar('\n');
    }

    return 0;
}