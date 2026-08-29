#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、逆序对总数用归并排序分治统计；
2、交换一次相邻元素后：只要存在逆序对，就存在相邻逆序元素，
   交换它们恰好让逆序对减少 1；任何一次相邻交换最多减少 1；
   所以最少逆序对数 = max(0, 总逆序对 - 1)；
3、递归函数 mergeSort(l, r)：归并排序并返回逆序对数；
4、main 输出两个数：总逆序对数、交换一次后的最少逆序对数。
注意：答案可能超出 int，用 long long。
*/
int n, a[100005], b[100005];

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
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    long long cnt = mergeSort(1, n);
    printf("%lld %lld\n", cnt, max(0LL, cnt - 1));
    return 0;
}
