#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、幸运数：存在完全平方数 s >= a 且 s 能整除 x；
   即 x 的质因数分解中，能凑出的"最大平方因子" >= a；
2、判断 x 是否幸运：分解质因数，最大平方因子 s = ∏p^(2*(e/2))，
   若 s >= a 则幸运；
3、幸运化：找最小的 y >= x 且 y 幸运；
   枚举 k（k^2 >= a），候选 y = k^2 * ceil(x / k^2)，取最小；
4、main 对每个 x 输出 lucky 或幸运化结果。
验证：a=2,x=1 → 4；a=2,x=5 → 8；a=2,x=9 → lucky。
*/
long long a, n, x;

// 判断 x 是否幸运数
bool isLucky(long long x) {
    long long s = 1;                        // 最大平方因子
    long long m = x;
    for (long long p = 2; p * p <= m; ++p) {
        if (m % p == 0) {
            long long e = 0;
            while (m % p == 0) { m /= p; e++; }
            for (long long k = 0; k < e / 2; ++k) s *= p;  // 每 2 个 p 组成一个平方因子
        }
    }
    return s >= a;                          // 平方因子 >= a 则幸运
}

int main() {
    cin >> a >> n;
    while (n--) {
        cin >> x;
        if (isLucky(x)) {
            cout << "lucky" << endl;
            continue;
        }
        // 幸运化：枚举 k 从 ceil(sqrt(a)) 到 ceil(sqrt(x)) + 1
        long long k0 = max(1LL, (long long)ceil(sqrt((double)a)));
        long long ans = -1;
        for (long long k = k0; k <= (long long)ceil(sqrt((double)x)) + 1; ++k) {
            long long kk = k * k;
            // 最小的 >= x 且能被 kk 整除的数
            long long y = kk * ((x + kk - 1) / kk);
            if (ans == -1 || y < ans) ans = y;
        }
        cout << ans << endl;
    }
    return 0;
}
