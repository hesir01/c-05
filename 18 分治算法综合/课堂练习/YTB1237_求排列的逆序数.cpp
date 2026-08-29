#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、求排列的逆序数：i < j 且 a[i] > a[j] 的对数；
2、用归并排序分治统计：合并时右段元素被取出时，
   左段剩余的所有元素都大于它，累加逆序对数；
3、递归函数 mergeSort(l, r) 返回逆序对数；
4、main 输出逆序数。
*/
int n, a[100005], b[100005];

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
            cnt += mid - i + 1;             // 左段剩余的都比 a[j] 大
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
