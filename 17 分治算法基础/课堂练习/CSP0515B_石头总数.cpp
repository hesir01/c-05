#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、分治求总和：把数组分成两半，递归求各自总和，再相加；
2、递归函数 getSum(l, r)：求 a[l..r] 的总和；
   出口：l == r 时返回 a[l]；
   否则返回 getSum(l, mid) + getSum(mid+1, r)；
3、main 输出总和。
*/
int n, a[105];

// 递归分治求 a[l..r] 的总和
long long getSum(int l, int r) {
    if (l == r) return a[l];                // 出口
    int mid = (l + r) / 2;
    return getSum(l, mid) + getSum(mid + 1, r);  // 合并
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << getSum(1, n) << endl;
    return 0;
}
