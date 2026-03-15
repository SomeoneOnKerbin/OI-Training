#include <algorithm>
#include <cstdio> // 为了 freopen
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s, best_ans;
int n, k, min_len;
vector<int> op; // 用于记录操作序列: 0-前加0, 1-后加0, 2-前加1, 3-后加1

// N^2 的复杂度获取字典序严格小于 s 的子串数量
int getcnt(const string &t, const string &s_ref) {
    int cnt = 0;
    int t_len = t.size();
    int m = s_ref.size();
    for (int i = 0; i < t_len; ++i) {
        for (int j = i; j < t_len; ++j) {
            int sub_len = j - i + 1;
            int p = 0;
            int limit = min(sub_len, m);
            while (p < limit && t[i + p] == s_ref[p]) {
                p++;
            }
            if (p < limit) {
                if (t[i + p] < s_ref[p])
                    cnt++;
            } else {
                if (sub_len < m)
                    cnt++;
            }
        }
    }
    return cnt;
}

// 根据 op 生成 t
string gett() {
    string t = s;
    for (int x : op) {
        if (x == 0)
            t = "0" + t;
        else if (x == 1)
            t = t + "0";
        else if (x == 2)
            t = "1" + t;
        else if (x == 3)
            t = t + "1";
    }
    return t;
}

// 赛时核心 DFS
void dfs() {
    // 1. 根据 op 生成 t
    string t = gett();

    // 2. 剪枝 (t.size() >= 16)
    if (t.size() >= 16)
        return;

    // 3. 最优性剪枝
    if (t.size() >= min_len)
        return;

    // 获取当前 cnt
    int cnt = getcnt(t, s);

    // 4. 单调性剪枝
    if (cnt > k)
        return;

    // 5. 判断是否命中目标
    if (cnt == k) {
        if (t.size() < min_len || (t.size() == min_len && t < best_ans)) {
            best_ans = t;
            min_len = t.size();
        }
        return;
    }

    // 6. 生成 op 数组，继续探索四个方向
    for (int i = 0; i < 4; ++i) {
        op.push_back(i);
        dfs();
        op.pop_back(); // 回溯
    }
}

// 针对性质 C 的“断环成链”版本子串统计
int count_less_cyclic(const string &doubled_t, int start, int len,
                      const string &s_ref) {
    int cnt = 0;
    int m = s_ref.length();
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            int sub_len = j - i + 1;
            int p = 0;
            int limit = min(sub_len, m);
            while (p < limit && doubled_t[start + i + p] == s_ref[p]) {
                p++;
            }
            if (p < limit) {
                if (doubled_t[start + i + p] < s_ref[p])
                    cnt++;
            } else {
                if (sub_len < m)
                    cnt++;
            }
        }
    }
    return cnt;
}

// 特殊性质 C 逻辑
void solve_special_C(int len_n, int target_k, const string &s_ref) {
    for (int zeros = 1; zeros <= 100; ++zeros) {
        string base = s_ref + string(zeros, '0');
        int len = base.length();

        if (len > min_len)
            break;

        string doubled_base = base + base;

        for (int shift = 0; shift < len; ++shift) {
            if (count_less_cyclic(doubled_base, shift, len, s_ref) ==
                target_k) {
                string t = doubled_base.substr(shift, len);
                if (t.length() < min_len ||
                    (t.length() == min_len && t < best_ans)) {
                    best_ans = t;
                    min_len = t.length();
                }
            }
        }
    }
}

void solve() {
    cin >> n >> k;
    cin >> s;

    best_ans = "Impossible";

    bool is_all_one = true;
    for (char c : s) {
        if (c != '1') {
            is_all_one = false;
            break;
        }
    }

    if (is_all_one) {
        min_len = 1000;
        solve_special_C(n, k, s);
    } else {
        min_len = 7;
        op.clear(); // 确保每次跑新数据前清空状态
        dfs();
    }

    cout << best_ans << "\n";
}

int main() {
    // 关流同步，追求极致的 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 标准省选文件读写
    // freopen("string.in", "r", stdin);
    // freopen("string.out", "w", stdout);

    int c, t;
    if (cin >> c >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}