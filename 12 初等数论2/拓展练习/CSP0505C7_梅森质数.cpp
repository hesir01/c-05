#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、梅森质数：形如 2^p - 1（p 为质数）的质数；
2、枚举 p <= m（m <= 30），计算 2^p - 1 并判断是否为质数；
3、用快速幂或直接 long long 计算 2^p（p<=30 不溢出）；
4、main 输出所有梅森质数。
验证：p=2,3,5,7 → 3,7,31,127 都是梅森质数。
*/
int m;

// 判断 x 是否为质数
bool isPrime(long long x) {
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    cin >> m;
    for (int p = 2; p <= m; ++p) {
        long long x = (1LL << p) - 1;       // 2^p - 1
        if (isPrime(x)) {
            cout << x << ' ';
        }
    }
    cout << endl;
    return 0;
}
