#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、数组排序后，从小到大枚举较小的数 a[i]，
   用二分查找 m - a[i] 是否存在（位置在 i 之后，保证两个数不同位置）；
2、递归函数 bs(l, r, val)：在 a[l..r] 中找 val，返回位置（不存在返回 0）；
3、第一个找到的配对（a[i] 最小）就是答案：输出 a[i] 和 m-a[i]；
4、全部找不到输出 No。
注意：m 最大 2^30，用 long long。
*/
int n;
long long m, a[100005];

// 递归二分：在 a[l..r] 中找 val，返回位置（不存在返回 0）
int bs(int l, int r, long long val) {
    if (l > r) return 0;                    // 出口
    int mid = (l + r) / 2;
    if (a[mid] == val) return mid;
    if (a[mid] > val) return bs(l, mid - 1, val);
    return bs(mid + 1, r, val);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    scanf("%lld", &m);
    sort(a + 1, a + n + 1);                 // 排序
    for (int i = 1; i <= n; ++i) {
        long long need = m - a[i];
        int p = bs(i + 1, n, need);         // 在 i 之后找，避免同一位置
        if (p != 0) {
            printf("%lld %lld\n", a[i], a[p]);
            return 0;
        }
    }
    puts("No");
    return 0;
}
