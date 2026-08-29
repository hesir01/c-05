#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、n 个不超过 10^6 的数，求每个数的因子个数；
2、筛法：枚举每个可能的因子 d，给 d 的所有倍数"打卡"（因子个数 +1）；
3、预处理 1~10^6 的因子个数数组，O(n log n)；
4、main 对每个询问输出因子个数。
*/
int n, a[100005];
int divCnt[1000005];

int main() {
    cin >> n;
    int maxa = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    // 筛法统计因子个数
    for (int d = 1; d <= maxa; ++d) {
        for (int j = d; j <= maxa; j += d) {
            divCnt[j]++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << divCnt[a[i]] << (i == n ? '\n' : ' ');
    }
    return 0;
}
