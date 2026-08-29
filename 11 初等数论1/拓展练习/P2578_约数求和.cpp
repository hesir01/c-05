#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、求 A^B 的所有约数之和 mod 9901；
2、A^B 的质因数分解：A = ∏p_i^e_i，则 A^B = ∏p_i^(e_i * B)；
   约数和 = ∏(1 + p_i + p_i^2 + ... + p_i^(e_i * B))；
3、等比数列求和用递归二分（避免求逆元）：
   sum(p, n) = 1 + p + ... + p^n；
4、快速幂计算 p 的幂，全部 mod 9901。
验证：A=2, B=3 → 2^3=8，约数和 1+2+4+8=15。
*/
const int MOD = 9901;
long long A, B;

// 快速幂 mod 9901
long long powmod(long long a, long long b) {
    long long r = 1;
    a %= MOD;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

// 递归求等比数列和 1 + p + ... + p^n
long long geoSum(long long p, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 1) {
        return geoSum(p, n / 2) % MOD * (1 + powmod(p, n / 2 + 1)) % MOD;
    }
    return (geoSum(p, n - 1) + powmod(p, n)) % MOD;
}

int main() {
    cin >> A >> B;
    if (A == 0) {                           // 0 的约数和为 0
        cout << 0 << endl;
        return 0;
    }
    long long ans = 1;
    // 质因数分解 A
    for (long long p = 2; p * p <= A; ++p) {
        if (A % p == 0) {
            long long e = 0;
            while (A % p == 0) { A /= p; e++; }
            ans = ans * geoSum(p % MOD, e * B) % MOD;  // 指数乘 B
        }
    }
    if (A > 1) {                            // 剩余的大质因子
        ans = ans * geoSum(A % MOD, B) % MOD;
    }
    cout << ans << endl;
    return 0;
}
