#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、硬币面值 {1, 5, 11}，对金额 n：
   - 贪心硬币数：优先用大面值；
   - 最优硬币数：完全背包 DP（dp[i] = 凑出 i 的最少硬币数）；
2、若贪心数 == 最优数输出 Yes，否则 No；
3、main 输出三行。
验证：15 → 贪心 5 枚，最优 3 枚（5+5+5），No。
*/
int n;
int coin[3] = {1, 5, 11};
int dp[100005];

int main() {
    cin >> n;
    // 贪心
    int g = 0, m = n;
    for (int i = 2; i >= 0; --i) {          // 从大面值开始
        g += m / coin[i];
        m %= coin[i];
    }
    // DP 求最优
    fill(dp, dp + n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int c : coin) {
            if (i >= c) dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    cout << g << endl;                      // 贪心硬币数
    cout << dp[n] << endl;                  // 最优硬币数
    cout << (g == dp[n] ? "Yes" : "No") << endl;
    return 0;
}
