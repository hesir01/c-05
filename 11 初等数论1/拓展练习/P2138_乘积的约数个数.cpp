#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、乘积的约数个数：把每个 a_i 质因数分解，统计所有质因子的指数；
   乘积的约数个数 = ∏(指数 + 1)；
2、对每个 a_i 试除 2 到 sqrt(a_i)，统计质因子指数；
   a_i ≤ 2×10^9，剩余部分若 >1 是质因子（指数 1）；
3、答案对 10^9+7 取模；
4、main 输出约数个数。
*/
const long long MOD = 1000000007;
int n;
long long cnt[100000];                      // 质因子指数（按质因子大小记录）

int main() {
    cin >> n;
    map<long long, long long> mp;           // 质因子 -> 指数
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        // 质因数分解 x
        for (long long p = 2; p * p <= x; ++p) {
            while (x % p == 0) {
                mp[p]++;
                x /= p;
            }
        }
        if (x > 1) mp[x]++;                 // 剩余的大质因子
    }
    long long ans = 1;
    for (auto &pr : mp) {
        ans = ans * ((pr.second + 1) % MOD) % MOD;  // 约数个数 = ∏(e+1)
    }
    cout << ans << endl;
    return 0;
}
