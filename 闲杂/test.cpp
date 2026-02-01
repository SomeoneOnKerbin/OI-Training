#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2000005;
const int MOD = 998244353;

int n, m, Q;
unsigned int randseed;
int x[MAXN], y[MAXN];
int qt[MAXN], qu[MAXN], qv[MAXN], qid[MAXN];
int p_old[MAXN], p_new[MAXN], ans[MAXN];
int head[MAXN], nxt[MAXN], qidx[MAXN], tot;

void add_query(int t, int idx) {
    qidx[++tot] = idx;
    nxt[tot] = head[t];
    head[t] = tot;
}

unsigned int rnd() {
    unsigned int r = randseed = randseed * 1103515245 + 12345;
    return (r << 16) | ((r >> 16) & 0xFFFF);
}

int student_at[MAXN], curr_pos[MAXN], fpop[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    if (!(cin >> n >> m >> Q >> randseed))
        return 0;
    for (int i = 1; i <= m; i++) {
        x[i] = rnd() % n + 1;
        y[i] = rnd() % n + 1;
    }
    for (int i = 1; i <= Q; i++) {
        qt[i] = rnd() % m + 1;
        qu[i] = rnd() % n + 1;
        qv[i] = rnd() % n + 1;
        qid[i] = rnd() % n + 1;
        add_query(qt[i], i);
    }
    for (int i = 1; i <= n; i++) {
        student_at[i] = curr_pos[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = head[i]; j; j = nxt[j])
            p_old[qidx[j]] = curr_pos[qid[qidx[j]]];
        int s1 = student_at[x[i]], s2 = student_at[y[i]];
        swap(student_at[x[i]], student_at[y[i]]);
        curr_pos[s1] = y[i];
        curr_pos[s2] = x[i];
    }
    for (int i = 1; i <= Q; i++) {
        if (p_old[i] == qu[i])
            p_new[i] = qv[i];
        else if (p_old[i] == qv[i])
            p_new[i] = qu[i];
        else
            p_new[i] = p_old[i];
    }
    for (int i = 1; i <= n; i++)
        fpop[i] = i;
    for (int i = m; i >= 1; i--) {
        for (int j = head[i]; j; j = nxt[j])
            ans[qidx[j]] = fpop[p_new[qidx[j]]];
        swap(fpop[x[i]], fpop[y[i]]);
    }
    long long final_ans = 0;
    for (int i = 1; i <= Q; i++)
        final_ans = (final_ans + 1LL * i * ans[i]) % MOD;
    cout << final_ans << endl;
    return 0;
}