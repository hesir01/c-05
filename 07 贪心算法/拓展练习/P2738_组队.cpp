#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、两两组队，能力值不同的两人要做题补差距；
2、能力值升序排序后，相邻两人配对最优（贪心）：
   因为能力值相近的配对差值最小，且不会交叉（交叉配对比相邻配对差）；
3、答案 = sum(第 2 个 - 第 1 个、第 4 个 - 第 3 个 ...)；
4、main 输出最少需要做的题数。
验证：5 10 2 3 14 5 → 排序 2 3 5 5 10 14 → (3-2)+(5-5)+(14-10)=5。
*/
int n, a[105];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);                 // 能力值升序
    int ans = 0;
    for (int i = 1; i <= n; i += 2) {
        ans += a[i + 1] - a[i];             // 相邻配对补差距
    }
    printf("%d\n", ans);
    return 0;
}
