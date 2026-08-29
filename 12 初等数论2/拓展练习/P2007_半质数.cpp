#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、半质数：恰好能分解成两个质数的乘积（两质数可以相同）；
2、用筛法预处理每个数的最小质因数 SPF，
   然后递推每个数的质因子个数（含重复）f[x] = f[x/spf[x]] + 1；
3、质因子总数恰好等于 2 的数就是半质数；
4、main 统计 [S, E] 内半质数的个数。
验证：4~26 → 10 个（4,6,9,10,14,15,21,22,25,26）。
*/
int S, E;
int spf[5000005], f[5000005];

int main() {
    cin >> S >> E;
    // 筛最小质因数
    for (int i = 2; i <= E; ++i) {
        if (spf[i] == 0) {
            for (int j = i; j <= E; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
    // 递推质因子总数
    f[1] = 0;
    int cnt = 0;
    for (int x = S; x <= E; ++x) {
        f[x] = f[x / spf[x]] + 1;           // 质因子总数
        if (f[x] == 2) cnt++;               // 恰好两个质因子 = 半质数
    }
    cout << cnt << endl;
    return 0;
}
