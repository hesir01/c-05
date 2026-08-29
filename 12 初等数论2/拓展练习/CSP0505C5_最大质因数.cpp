#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、求每个数的最大质因数；
2、预处理：用筛法求 1~10^6 每个数的最大质因数；
   - 对每个质数 p，它的倍数 x 的 maxPrime[x] 至少是 p；
   - 用类似埃氏筛的方式，从小到大枚举质数，更新倍数；
3、main 对每个查询输出最大质因数。
*/
int n, a[100005];
int maxPrime[1000005];

int main() {
    cin >> n;
    int maxa = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    // 筛法求每个数的最大质因数
    for (int p = 2; p <= maxa; ++p) {
        if (maxPrime[p] == 0) {             // p 是质数
            for (int x = p; x <= maxa; x += p) {
                maxPrime[x] = p;            // 记录（质数从小到大，最终留下最大的）
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << maxPrime[a[i]] << (i == n ? '\n' : ' ');
    }
    return 0;
}
