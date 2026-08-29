#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、n! = 1×2×...×n，递归定义：n! = n * (n-1)!，1! = 1；
2、递归函数 fac(n)：返回 n 的阶乘；
   出口：n == 1 时返回 1；
   否则返回 n * fac(n - 1)；
3、main 读入 n，输出 fac(n)。
注意：n 最大 20，20! ≈ 2.4e18，用 long long。
*/
int n;

// 递归求 n 的阶乘
long long fac(int x) {
    if (x == 1) return 1;                // 出口：1! = 1
    return x * fac(x - 1);               // n * (n-1)!
}

int main() {
    cin >> n;
    cout << fac(n) << endl;
    return 0;
}
