#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、B-smooth 数：最大质因子不超过 B 的正整数；
2、n ≤ 10^6：筛法求每个数的最大质因子 maxPrime[x]；
   枚举质数 p，它的倍数 x 的 maxPrime[x] 更新为 p（最终留最大）；
3、统计 1~n 中 maxPrime[x] <= B 的个数（1 的最大质因子视为 1 <= B）；
4、main 输出数量。
验证：10 3 → 3-smooth 数 {1,2,3,4,6,8,9} 共 7 个。
*/
int n, B, maxPrime[1000005];

int main() {
    cin >> n >> B;
    // 筛法求每个数的最大质因子
    for (int p = 2; p <= n; ++p) {
        if (maxPrime[p] == 0) {             // p 是质数
            for (int x = p; x <= n; x += p) {
                maxPrime[x] = p;
            }
        }
    }
    int cnt = 0;
    for (int x = 1; x <= n; ++x) {
        if (maxPrime[x] <= B) cnt++;        // 最大质因子不超过 B
    }
    cout << cnt << endl;
    return 0;
}
