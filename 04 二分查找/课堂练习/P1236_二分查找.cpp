#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、数组递增无重复，用二分查找 x：
   递归函数 bs(l, r)：在 a[l..r] 中查找 x；
   若 a[mid] == x 返回 mid+1（位置从 1 开始）；
   若 a[mid] > x 递归左半，否则递归右半；
   出口：l > r 返回 -1；
2、main 读入数组，调用 bs(1,n) 输出位置或 -1。
*/
int n, x, a[1000005];

// 递归二分查找：在 a[l..r] 中找 x，返回位置（从 1 开始），找不到返回 -1
int bs(int l, int r) {
    if (l > r) return -1;                       // 出口：区间为空
    int mid = (l + r) / 2;
    if (a[mid] == x) return mid;                // 找到
    if (a[mid] > x) return bs(l, mid - 1);      // 去左半找
    return bs(mid + 1, r);                      // 去右半找
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    scanf("%d", &x);
    int pos = bs(1, n);
    printf("%d\n", pos);                        // 位置从 1 开始，不存在输出 -1
    return 0;
}
