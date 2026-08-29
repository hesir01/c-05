#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、最简分数：分子分母同时除以它们的最大公约数；
2、递归函数 gcd(a,b)：欧几里得算法；
3、main 读入 p、q，输出 p/gcd 和 q/gcd 的分数形式。
验证：6 8 → 3/4。
*/
long long p, q;

// 递归求最大公约数
long long gcd(long long x, long long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    cin >> p >> q;
    long long g = gcd(p, q);
    cout << p / g << '/' << q / g << endl;  // 约分后的最简分数
    return 0;
}
