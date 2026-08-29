#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、用欧几里得算法（辗转相除法）求最大公约数：
   gcd(a,b) = gcd(b, a%b)，直到 b 为 0，返回 a；
2、递归函数 gcd(a,b)：直接按上面的公式翻译；
   出口：b == 0 时返回 a；
3、main 读入 M、N，输出 gcd(M,N)。
注意：M、N 在长整型范围内，用 long long。
*/
long long M, N;

// 递归求 a 和 b 的最大公约数
long long gcd(long long a, long long b) {
    if (b == 0) return a;               // 出口：余数为 0
    return gcd(b, a % b);               // 辗转相除
}

int main() {
    cin >> M >> N;
    cout << gcd(M, N) << endl;
    return 0;
}
