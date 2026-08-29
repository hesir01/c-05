#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、分治同时求最大值和最小值：递归求两半各自的最值，合并取极值；
2、递归函数 solve(l, r, &mx, &mn)：
   出口：l == r 时 mx = mn = a[l]；
   否则分别递归左右两半，合并时取较大/较小；
3、main 输出最大值和最小值。
*/
int n, a[105];

// 递归分治：求 a[l..r] 的最大值和最小值（引用返回）
void solve(int l, int r, int &mx, int &mn) {
    if (l == r) {
        mx = mn = a[l];                     // 出口
        return;
    }
    int mid = (l + r) / 2;
    int mx1, mn1, mx2, mn2;
    solve(l, mid, mx1, mn1);                // 左半
    solve(mid + 1, r, mx2, mn2);            // 右半
    mx = max(mx1, mx2);                     // 合并：取较大
    mn = min(mn1, mn2);                     // 合并：取较小
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int mx, mn;
    solve(1, n, mx, mn);
    cout << mx << ' ' << mn << endl;
    return 0;
}
