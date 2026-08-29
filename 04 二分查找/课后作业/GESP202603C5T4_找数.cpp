#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、数组 A 与 B 均无重复元素，求同时在两数组中出现的数的个数；
2、把 A 排序，对 B 中每个数二分查找是否在 A 中；
3、递归函数 bs(l, r, x)：在 A[l..r] 中找 x；
   出口：l > r 返回 false；
4、main 统计并在两数组中都出现的数的个数并输出。
*/
int n, m, a[1000005], b[1000005];

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
    sort(a + 1, a + n + 1);                     // A 排序
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
        if (bs(1, n, b[i])) cnt++;              // B 中元素在 A 中出现
    }
    printf("%d\n", cnt);
    return 0;
}
