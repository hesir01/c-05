#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、分治判断是否排好序（非递减）：
   递归检查左右两半各自有序，且左半最后一个 <= 右半第一个；
2、递归函数 isSorted(l, r)：
   出口：l == r 时返回 true；
   否则返回 isSorted(l, mid) && isSorted(mid+1, r) && a[mid] <= a[mid+1]；
3、main 输出 Yes/No。
*/
int n, a[105];

// 递归分治判断 a[l..r] 是否非递减
bool isSorted(int l, int r) {
    if (l == r) return true;                // 出口：单个元素有序
    int mid = (l + r) / 2;
    // 左右各自有序，且交界处不下降
    return isSorted(l, mid) && isSorted(mid + 1, r) && a[mid] <= a[mid + 1];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << (isSorted(1, n) ? "Yes" : "No") << endl;
    return 0;
}
