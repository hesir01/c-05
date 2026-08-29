#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、用分治法同时求最大最小值：把数组从中间分成两半；
2、左半部分递归求出自己的最小值和最大值；
3、右半部分递归求出自己的最小值和最大值；
4、整体最小值 = 两半最小值的较小者，整体最大值 = 两半最大值的较大者；
5、递归边界：区间只有一个数时，最小值和最大值都是它自己。
*/
long long a[100005];
int n;

// 分治函数：求区间 [l, r] 的最小值和最大值（用引用返回）
void solve(int l, int r, long long &mn, long long &mx) {
    if (l == r) {            // 只剩一个数
        mn = mx = a[l];
        return;
    }
    int mid = (l + r) / 2;
    long long mn1, mx1, mn2, mx2;
    solve(l, mid, mn1, mx1);     // 左半部分
    solve(mid + 1, r, mn2, mx2); // 右半部分
    mn = min(mn1, mn2);          // 合并：取较小者
    mx = max(mx1, mx2);          // 合并：取较大者
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    long long mn, mx;
    solve(1, n, mn, mx);

    // 输出最小值和最大值
    cout << mn << ' ' << mx << endl;

    return 0;
}
