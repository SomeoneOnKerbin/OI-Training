#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e1 + 10;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int BDX[] = {-1, 0, 0};   // 黑棋移动方向: 上、左、右
const int BDY[] = {0, -1, 1};
const int RBDX[] = {1, 0, 0};   // 黑棋移动的逆方向（用于求前驱）
const int RBDY[] = {0, 1, -1};
char mat[N][N];

// 反向 BFS 全局数组
const int MAXS = 2000002;
int8_t ga_res[MAXS];   // 0=未定/平局, 1=当前玩家胜, -1=当前玩家败
int ga_dist[MAXS];     // 从该状态到终态步数
int16_t ga_deg[MAXS];  // 未解决的后继数量

void solve14() {
    memset(mat, 0, sizeof(mat));

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<pair<int, int>> black, red;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mat[i][j] == 'X') {
                black.emplace_back(i, j);
            } else if (mat[i][j] == 'O') {
                red.emplace_back(i, j);
            }
        }
    }

    bool canmov = false;

    for (auto &p : red) {
        for (int k = 0; k < 4; k++) {
            int x = p.first + dx[k], y = p.second + dy[k];

            if (x < 1 || x > n || y < 1 || y > m) {
                continue;
            }

            if (mat[x][y] != '#' && mat[x][y] != 'O') {
                canmov = true;
                break;
            }
        }
    }

    if (canmov) {
        cout << "Tie\n";
    } else {
        cout << "Black 0\n";
    }
}

void solve56() {
    int n, m;
    cin >> n >> m;
    int nm = n * m;

    bool obs[10][10] = {};
    int b0 = -1, r1_0 = -1, r2_0 = -1;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') obs[i][j] = true;
            else if (s[j] == 'X') b0 = i * m + j;
            else if (s[j] == 'O') {
                if (r1_0 == -1) r1_0 = i * m + j;
                else r2_0 = i * m + j;
            }
        }
    }

    int total = nm * nm * nm * 2;
    memset(ga_res, 0, total * sizeof(int8_t));
    memset(ga_dist, 0, total * sizeof(ga_dist[0]));
    memset(ga_deg, 0, total * sizeof(int16_t));

    // 状态编码: ((b * nm + r1) * nm + r2) * 2 + turn
    // turn: 0=红方走, 1=黑方走
    auto enc = [&](int b, int r1, int r2, int t) -> int {
        return ((b * nm + r1) * nm + r2) * 2 + t;
    };

    queue<int> q;

    // ====== 第一步: 枚举所有合法状态, 标记终态, 计算出度 ======
    for (int b = 0; b < nm; b++) {
        int br = b / m, bc = b % m;
        if (obs[br][bc]) continue;
        for (int r1 = 0; r1 < nm; r1++) {
            int r1r = r1 / m, r1c = r1 % m;
            if (obs[r1r][r1c]) continue;
            for (int r2 = 0; r2 < nm; r2++) {
                if (r1 == r2) continue;
                int r2r = r2 / m, r2c = r2 % m;
                if (obs[r2r][r2c]) continue;

                for (int t = 0; t < 2; t++) {
                    int s = enc(b, r1, r2, t);

                    // 终止条件 1: 黑棋到达第一行 → 黑方胜
                    if (br == 0) {
                        // turn=1(黑的回合)→当前玩家(黑)胜=1; turn=0(红的回合)→当前玩家(红)败=-1
                        ga_res[s] = (t == 1) ? 1 : -1;
                        q.push(s);
                        continue;
                    }
                    // 终止条件 2: 黑棋与红棋重叠 → 上一步走棋的人胜
                    // 当前玩家还没走, 所以当前玩家是被动方, 败
                    if (b == r1 || b == r2) {
                        ga_res[s] = -1;
                        q.push(s);
                        continue;
                    }

                    // 计算当前玩家的合法操作数
                    int d = 0;
                    if (t == 0) { // 红方: 可以移动 r1 或 r2
                        for (int dir = 0; dir < 4; dir++) {
                            int nr = r1r + dx[dir], nc = r1c + dy[dir];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m
                                && !obs[nr][nc] && nr * m + nc != r2)
                                d++;
                        }
                        for (int dir = 0; dir < 4; dir++) {
                            int nr = r2r + dx[dir], nc = r2c + dy[dir];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m
                                && !obs[nr][nc] && nr * m + nc != r1)
                                d++;
                        }
                    } else { // 黑方: 上/左/右
                        for (int dir = 0; dir < 3; dir++) {
                            int nr = br + BDX[dir], nc = bc + BDY[dir];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m
                                && !obs[nr][nc])
                                d++;
                        }
                    }

                    // 终止条件 3: 无合法操作 → 当前玩家败
                    if (d == 0) {
                        ga_res[s] = -1;
                        q.push(s);
                    } else {
                        ga_deg[s] = d;
                    }
                }
            }
        }
    }

    // ====== 第二步: 反向 BFS 传播胜负 ======
    while (!q.empty()) {
        int s = q.front(); q.pop();
        int tmp = s;
        int t = tmp % 2; tmp /= 2;
        int r2 = tmp % nm; tmp /= nm;
        int r1 = tmp % nm; tmp /= nm;
        int b = tmp;
        int br = b / m, bc = b % m;
        int r1r = r1 / m, r1c = r1 % m;
        int r2r = r2 / m, r2c = r2 % m;

        int pt = 1 - t; // 前驱状态的轮次

        // 更新前驱状态
        auto upd = [&](int pred) {
            if (ga_res[pred] != 0 || ga_deg[pred] == 0) return;
            if (ga_res[s] == -1) {
                // 后继对当前玩家是败 → 前驱做了这步棋就能赢
                ga_res[pred] = 1;
                ga_dist[pred] = ga_dist[s] + 1;
                q.push(pred);
            } else if (ga_res[s] == 1) {
                // 后继对当前玩家是胜 → 对前驱来说这步棋不好
                if (--ga_deg[pred] == 0) {
                    // 所有后继都对前驱不利 → 前驱必败
                    ga_res[pred] = -1;
                    ga_dist[pred] = ga_dist[s] + 1;
                    q.push(pred);
                }
            }
        };

        if (pt == 0) {
            // 前驱是红方回合, 红方移动了某个棋子到达状态 s
            // 情况 1: 红方移动了 r1 (从某相邻位置移到 r1 当前位置)
            for (int dir = 0; dir < 4; dir++) {
                int pr = r1r + dx[dir], pc = r1c + dy[dir];
                if (pr >= 0 && pr < n && pc >= 0 && pc < m && !obs[pr][pc]) {
                    int pp = pr * m + pc;
                    if (pp != r2) upd(enc(b, pp, r2, 0));
                }
            }
            // 情况 2: 红方移动了 r2
            for (int dir = 0; dir < 4; dir++) {
                int pr = r2r + dx[dir], pc = r2c + dy[dir];
                if (pr >= 0 && pr < n && pc >= 0 && pc < m && !obs[pr][pc]) {
                    int pp = pr * m + pc;
                    if (pp != r1) upd(enc(b, r1, pp, 0));
                }
            }
        } else {
            // 前驱是黑方回合, 黑方移动到了 b 当前位置
            // 逆向: 黑可以上/左/右 → 前驱黑棋在 下/右/左
            for (int dir = 0; dir < 3; dir++) {
                int pr = br + RBDX[dir], pc = bc + RBDY[dir];
                if (pr >= 0 && pr < n && pc >= 0 && pc < m && !obs[pr][pc]) {
                    upd(enc(pr * m + pc, r1, r2, 1));
                }
            }
        }
    }

    // ====== 输出结果 ======
    int init = enc(b0, r1_0, r2_0, 0);
    if (ga_res[init] == 0) cout << "Tie\n";
    else if (ga_res[init] == 1) cout << "Red " << ga_dist[init] << "\n";
    else cout << "Black " << ga_dist[init] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef LOCAL
    freopen("zu.in", "r", stdin);
    freopen("zu.out", "w", stdout);
#endif

    int id, T;
    cin >> id >> T;

    while (T--) {
        if (1 <= id && id <= 4)
            solve14();
        else
            solve56();
    }

    return 0;
}