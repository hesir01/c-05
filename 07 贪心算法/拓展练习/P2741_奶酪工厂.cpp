#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、每周交付 Y_i 单位奶酪，可以用本周生产的，也可以用以前存货；
2、贪心：维护"到本周为止的最低单位成本"（含仓储费）：
   minc = min(minc + S, C_i)；
   第 i 周用 minc 的成本生产本周需要的 Y_i；
3、cost += minc * Y_i，累加 N 周；
4、main 输出最小总代价。
*/
int N;
long long S, c[10005], y[10005];

int main() {
    scanf("%d%lld", &N, &S);
    for (int i = 1; i <= N; ++i) scanf("%lld%lld", &c[i], &y[i]);
    long long minc = c[1];                  // 初始最低成本
    long long cost = 0;
    for (int i = 1; i <= N; ++i) {
        if (i > 1) minc = min(minc + S, c[i]);  // 存货一周的仓储费 or 本周生产
        cost += minc * y[i];                // 用最低成本满足本周需求
    }
    printf("%lld\n", cost);
    return 0;
}
