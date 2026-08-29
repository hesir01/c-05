#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、n 是两个不同质数的乘积，从 2 开始找第一个能整除 n 的质数 p，
   另一个质数就是 n/p，较大的那个是 max(p, n/p)；
2、由于 n 是两质数乘积，第一个找到的因子就是较小质数；
3、main 输出较大的质数。
验证：21 = 3*7 → 输出 7。
*/
long long n;

int main() {
    cin >> n;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            cout << n / p << endl;          // n/p 是较大的质数
            return 0;
        }
    }
    return 0;
}
