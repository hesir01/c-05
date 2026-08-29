#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、学校分数线排序后，对每个学生的估分 b：
   用二分找第一个 >= b 的位置 p；
   与 b 差最小的分数线在 a[p] 和 a[p-1] 中选一个；
2、递归函数 lower(l, r, b)：在 a[l..r] 中找第一个 >= b 的位置；
   出口：l == r 返回 l；
3、main 对每个学生输出最小差值。
*/
int n, m, a[1000005];

// 递归二分：在 a[l..r] 中找第一个 >= b 的位置
int lower(int l, int r, int b) {
    if (l == r) return l;                       // 出口
    int mid = (l + r) / 2;
    if (a[mid] >= b) return lower(l, mid, b);
    return lower(mid + 1, r, b);
}

int main() {
    scanf("%d%d", &m, &n);                      // m 所学校，n 个学生
    for (int i = 1; i <= m; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + m + 1);                     // 分数线升序
    while (n--) {
        int b;
        scanf("%d", &b);
        int p = lower(1, m, b);                 // 第一个 >= b 的分数线
        int diff = abs(a[p] - b);               // 与 a[p] 的差
        if (p > 1) diff = min(diff, abs(a[p - 1] - b));  // 与 a[p-1] 的差
        printf("%d\n", diff);
    }
    return 0;
}
