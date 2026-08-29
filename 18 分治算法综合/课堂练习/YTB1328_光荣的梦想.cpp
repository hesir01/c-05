#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、最少交换次数使数列升序 = 逆序对数；
   （每次交换相邻元素恰好消除 1 个逆序对，冒泡/归并排序的交换次数）
2、用归并排序分治统计逆序对数；
3、递归函数 mergeSort(l, r) 返回逆序对数；
4、main 输出最少交换次数。
验证：2 1 4 3 → 逆序对 (2,1)(4,3) 共 2 个。
*/
int n, a[10005], b[10005];

// 归并排序统计逆序对数
long long mergeSort(int l, int r) {
    if (l == r) return 0;                   // 出口
    int mid = (l + r) / 2;
    long long cnt = mergeSort(l, mid) + mergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (int t = l; t <= r; ++t) a[t] = b[t];
    return cnt;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    printf("%lld\n", mergeSort(1, n));
    return 0;
}
