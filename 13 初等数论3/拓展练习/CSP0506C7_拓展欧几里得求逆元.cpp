#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、求 a 在模 m 下的乘法逆元：最小的正整数 x 使 a*x ≡ 1 (mod m)；
2、用扩展欧几里得算法求 ax + my = 1 的一组解 (x, y)，
   x 就是逆元（可能为负，取模到 [1, m-1] 范围）；
3、递归函数 exgcd(a, b, &x, &y)：返回 gcd 并求一组解；
4、main 输出最小正整数逆元。
*/
long long a, m;

// 扩展欧几里得：求 ax + by = gcd(a,b) 的一组解
long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

int main() {
    cin >> a >> m;
    long long x, y;
    exgcd(a, m, x, y);
    x = (x % m + m) % m;                    // 转成最小正整数
    if (x == 0) x = m;                      // 逆元最小是 1，x=0 时修正
    cout << x << endl;
    return 0;
}
