#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、分治求最大值：把数组分成两半，递归求各自最大值，取较大者；
2、递归函数 getMax(l, r)：求 a[l..r] 的最大值；
   出口：l == r 时返回 a[l]；
   否则返回 max(getMax(l, mid), getMax(mid+1, r))；
3、main 输出最大值。
*/
int n, a[105];

// 递归分治求 a[l..r] 的最大值
int getMax(int l, int r) {
    if (l == r) return a[l];                // 出口：只剩一个数
    int mid = (l + r) / 2;
    int lm = getMax(l, mid);                // 左半最大值
    int rm = getMax(mid + 1, r);            // 右半最大值
    return max(lm, rm);                     // 合并
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << getMax(1, n) << endl;
    return 0;
}
