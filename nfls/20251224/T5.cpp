#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;
int dp[105][105]; // dp[i][j] 存储区间 [i, j] 的最小不满意值
int D[105];       // 存储每个男生的屌丝值
int sum[105];     // 前缀和数组，用于快速计算区间和

// 获取区间 [i, j] 的 D 值之和
int get_sum(int i, int j) {
    if (i > j) return 0;
    return sum[j] - sum[i-1];
}

void solve(int t) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> D[i];
    }

    // 计算前缀和
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i-1] + D[i];
    }

    // 初始化 DP 数组
    // 实际上我们在循环中会覆盖值，但为了安全可以初始化
    memset(dp, 0, sizeof(dp));

    // 区间 DP 模板
    // len 枚举区间长度
    for (int len = 1; len <= n; ++len) {
        // i 枚举起点
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1; // j 是终点
            dp[i][j] = INF;

            // k 枚举分割点
            // i+1...k 在 i 之前出栈
            // k+1...j 在 i 之后出栈
            for (int k = i; k <= j; ++k) {
                // 计算第一部分的代价
                int cost_part1 = (i + 1 > k) ? 0 : dp[i+1][k];
                
                // 计算 i 本身的代价：位置是 k-i (0-based)
                int cost_i = (k - i) * D[i];
                
                // 计算第二部分的代价
                int cost_part2 = (k + 1 > j) ? 0 : dp[k+1][j];
                
                // 第二部分因为排在后面产生的额外偏移代价
                // 偏移量 = Part1人数 + i本身 = (k-i) + 1
                int cost_delay = (k - i + 1) * get_sum(k+1, j);

                int total = cost_part1 + cost_i + cost_part2 + cost_delay;
                dp[i][j] = min(dp[i][j], total);
            }
        }
    }

    cout << "Case #" << t << ": " << dp[1][n] << endl;
}

int main() {
    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; ++i) {
            solve(i);
        }
    }
    return 0;
}
