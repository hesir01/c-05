#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、乘积的约数和：质因数分解所有 a_i，得到质因子 p 和指数 e；
   约数和 = ∏(1 + p + p^2 + ... + p^e)；
2、等比数列求和用"递归二分"（避免除法求逆元的麻烦）：
   sum(p, e) 表示 p^0 + p^1 + ... + p^e；
3、快速幂计算 p 的幂；
4、答案对 10^9+7 取模。
*/
const long long MOD = 1000000007;
int n;

// 快速幂
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

// 递归求等比数列和 1 + p + p^2 + ... + p^e
long long geoSum(long long p, long long e) {
    if (e == 0) return 1;
    if (e % 2 == 1) {                       // e 为奇数：1+...+p^e = (1+p^(e/2+1)) * (1+...+p^(e/2))
        return geoSum(p, e / 2) % MOD * (1 + powmod(p, e / 2 + 1)) % MOD;
    }
    // e 为偶数：1+...+p^e = (1+...+p^(e-1)) + p^e
    return (geoSum(p, e - 1) + powmod(p, e)) % MOD;
}

int main() {
    cin >> n;
    map<long long, long long> mp;
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        for (long long p = 2; p * p <= x; ++p) {
            while (x % p == 0) { mp[p]++; x /= p; }
        }
        if (x > 1) mp[x]++;
    }
    long long ans = 1;
    for (auto &pr : mp) {
        ans = ans * geoSum(pr.first % MOD, pr.second) % MOD;
    }
    cout << ans << endl;
    return 0;
}
