#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、奇妙数字：x = p^a（p 为质数，a 为正整数）；
2、n = ∏p_i^e_i。对每个质因子 p_i，选出的奇妙数字 p_i^a 的指数和 ≤ e_i；
   选指数 a=1,2,3,...（互不相同），贪心选最小的 a，
   能选的最大数量 k 满足 k(k+1)/2 ≤ e_i；
3、各质因子的贡献独立，答案 = 所有质因子能选的数量之和；
4、main 读入 n（≤10^12），分解质因数后输出答案。
验证：128 = 2^7 → k(k+1)/2 ≤ 7 → k=3，答案 3。
*/
long long n;

int main() {
    cin >> n;
    long long ans = 0;
    long long m = n;
    // 质因数分解
    for (long long p = 2; p * p <= m; ++p) {
        if (m % p == 0) {
            long long e = 0;
            while (m % p == 0) { m /= p; e++; }
            // 找最大 k 满足 k(k+1)/2 <= e
            long long k = 0;
            while ((k + 1) * (k + 2) / 2 <= e) k++;
            ans += k;
        }
    }
    if (m > 1) ans += 1;                    // 剩余大质因子指数 1，只能选 1 个
    cout << ans << endl;
    return 0;
}
