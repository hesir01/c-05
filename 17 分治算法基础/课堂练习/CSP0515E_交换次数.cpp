#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、逆序对：i < j 且 a[i] > a[j]；
2、用归并排序分治统计：合并两个有序段时，
   每当右段的数被取出，左段剩余的所有数都大于它，构成逆序对；
3、递归函数 mergeSort(l, r)：对 a[l..r] 归并排序并返回逆序对数；
   出口：l == r 返回 0；
4、main 输出逆序对总数。
*/
int n, a[105], b[105];

// 归并排序统计逆序对
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
            cnt += mid - i + 1;             // 左段剩余的都大于 a[j]
        }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (int t = l; t <= r; ++t) a[t] = b[t];
    return cnt;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << mergeSort(1, n) << endl;
    return 0;
}
