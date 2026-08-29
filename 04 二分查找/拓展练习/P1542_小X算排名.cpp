#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、排名 = 得分严格高于自己的同学数 + 1（相同得分排名相同）；
2、把得分升序排序，对每个同学的得分 x：
   严格大于 x 的个数 = n - p + 1，其中 p 是第一个 > x 的位置
   （若不存在则 p = n+1，个数为 0）；
   排名 = n - p + 2；
3、递归函数 upper(l, r)：在排序数组中求第一个 > x 的位置；
   出口：l > r 返回 l（找不到时返回 n+1）；
4、按原始顺序输出每个同学的排名。
注意：N 最大 100000，用 scanf/printf 提升读写效率。
*/
int n, x, a[100005], score[100005];

// 递归二分：在 a[l..r] 中求第一个 > x 的位置
int upper(int l, int r) {
    if (l > r) return l;                        // 出口：区间空，返回插入位置
    int mid = (l + r) / 2;
    if (a[mid] > x) return upper(l, mid - 1);
    return upper(mid + 1, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &score[i]);
        a[i] = score[i];
    }
    sort(a + 1, a + n + 1);                     // 升序排序
    for (int i = 1; i <= n; ++i) {
        x = score[i];
        int p = upper(1, n);                    // 第一个 > x 的位置
        printf("%d\n", n - p + 2);              // 排名 = 严格高于我的人数 + 1
    }
    return 0;
}
