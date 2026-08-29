#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、素数：大于 1 且只有 1 和自身两个约数的数；
2、判断 x 是否为素数：枚举 2 到 sqrt(x)，若存在整除则不是素数；
   2 是素数，1 不是素数；
3、main 读入 n 个数，逐个判断，素数输出 Yes 否则 No。
注意：x 可能较大，枚举到 sqrt(x) 即可。
*/
int n;
long long x;

// 判断 x 是否为素数
bool isPrime(long long x) {
    if (x < 2) return false;                    // 1 不是素数
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;           // 有约数
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        cout << (isPrime(x) ? "Yes" : "No") << (i == n ? "\n" : " ");
    }
    return 0;
}
