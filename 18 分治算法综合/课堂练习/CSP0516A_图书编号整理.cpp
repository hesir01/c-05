#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、归并排序：把数组分成两半分别排序，再合并两个有序段；
2、递归函数 mergeSort(l, r)：
   出口：l == r 返回；
   否则递归左右，再合并（双指针）到临时数组并拷回；
3、main 读入 n 个数，归并排序后从小到大输出。
*/
int n, a[100005], b[100005];

// 归并排序
void mergeSort(int l, int r) {
    if (l == r) return;                     // 出口
    int mid = (l + r) / 2;
    mergeSort(l, mid);                      // 左半排序
    mergeSort(mid + 1, r);                  // 右半排序
    // 合并两个有序段
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (int t = l; t <= r; ++t) a[t] = b[t];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    mergeSort(1, n);
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
