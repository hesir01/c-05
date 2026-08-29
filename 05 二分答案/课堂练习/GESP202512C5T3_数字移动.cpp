#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、求最小的 x：每次移动花费不超过 x 时，能让每对相同数字相邻；
2、数值 > x 的数字不能被移动，它们必须最终能"就地"相邻：
   对每个 >x 的数字 v，取出它在序列中的两个位置；
   若两个位置之间夹着奇数个 >x 的数字，则这些 >x 数字无法全部成对，
   x 不可行（需要移动 >x 的数字，花费超 x）；
3、check(x)：用前缀和 cnt[i] 统计前 i 个位置中 >x 的数字个数，
   对每个 >x 的数字检查区间内 >x 数量是否为偶数；
4、二分答案 x（1..max(A)），输出最小可行 x。
验证：{1,2,1,3,2,3}，x=2 可行（3 的区间内无其他 >2），x=1 不可行 → 答案 2。
*/
int n, a[100005], pos[100005][2], maxa;

// 检查花费上限 x 是否可行
bool check(int x) {
    // 前缀和：cnt[i] = 前 i 个位置中 >x 的数字个数
    static int cnt[100005];
    for (int i = 1; i <= n; ++i)
        cnt[i] = cnt[i - 1] + (a[i] > x);
    // 对每个 >x 的数字 v，检查两位置之间的 >x 数量是否为偶数
    for (int v = 1; v <= maxa; ++v) {
        if (v <= x) continue;               // 可移动的数字不用检查
        int p1 = pos[v][0], p2 = pos[v][1];
        int between = cnt[p2 - 1] - cnt[p1]; // 两位置之间的 >x 数字个数
        if (between % 2 == 1) return false;  // 奇数个，无法全部成对
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        maxa = max(maxa, a[i]);
        if (pos[a[i]][0] == 0) pos[a[i]][0] = i;
        else pos[a[i]][1] = i;
    }
    // 二分答案：找最小可行 x
    int lo = 1, hi = maxa, ans = maxa;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
