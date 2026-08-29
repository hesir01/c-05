#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、最大公约数用欧几里得算法（辗转相除）；
2、最小公倍数 = a / gcd * b（先除后乘防溢出）；
3、main 读入 a、b，输出两行：GCD 和 LCM。
*/
long long a, b;

// 递归求最大公约数
long long gcd(long long x, long long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    cin >> a >> b;
    long long g = gcd(a, b);
    cout << g << endl;                  // 最大公约数
    cout << a / g * b << endl;          // 最小公倍数
    return 0;
}
