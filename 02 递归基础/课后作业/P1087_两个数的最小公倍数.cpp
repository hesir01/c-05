#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、最小公倍数 = 两数乘积 ÷ 最大公约数：
   lcm(M,N) = M / gcd(M,N) * N；
2、递归函数 gcd(a,b)：欧几里得算法求最大公约数；
   出口：b == 0 时返回 a；否则返回 gcd(b, a%b)；
3、main 读入 M、N，先除后乘防溢出，输出 lcm。
注意：M、N 可达 2^63-1，先除后乘保证乘积不超范围，用 long long。
*/
long long M, N;

// 递归求最大公约数
long long gcd(long long a, long long b) {
    if (b == 0) return a;               // 出口
    return gcd(b, a % b);               // 辗转相除
}

int main() {
    cin >> M >> N;
    // 先除后乘，避免中间结果溢出
    cout << M / gcd(M, N) * N << endl;
    return 0;
}
