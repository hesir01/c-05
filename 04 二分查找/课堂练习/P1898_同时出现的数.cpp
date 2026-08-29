#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、把第 1 组数排序，然后对第 2 组每个数二分查找是否在第 1 组中出现；
2、出现的数收集起来，最后排序输出（从小到大，保留重复）；
3、递归函数 bs(l, r, x)：在排序后的 a[l..r] 中二分找 x；
   出口：l > r 返回 false；
4、main 读入两组数，输出所有满足条件的数。
*/
int n, m, a[1000005], b[1000005], ans[1000005], cnt;

// 递归二分：在 a[l..r] 中找 x
bool bs(int l, int r, int x) {
    if (l > r) return false;                    // 出口
    int mid = (l + r) / 2;
    if (a[mid] == x) return true;
    if (a[mid] > x) return bs(l, mid - 1, x);
    return bs(mid + 1, r, x);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);                     // 第 1 组排序
    // 第 2 组中每个数判断是否在第 1 组出现
    for (int i = 1; i <= m; ++i) {
        if (bs(1, n, b[i])) ans[++cnt] = b[i];
    }
    sort(ans + 1, ans + cnt + 1);               // 从小到大输出
    for (int i = 1; i <= cnt; ++i) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
