#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、digit(n,k)：分离 n 从右边数第 k 个数字；
2、递归：
   出口：k == 1 时返回 n % 10（右边第 1 个数字就是个位）；
   否则返回 digit(n / 10, k - 1)，去掉个位后继续找第 k-1 个；
3、main 读入 n、k，输出 digit(n,k)。
*/
long long n, k;

// 递归求 n 从右边数第 k 个数字
long long digit(long long x, long long k) {
    if (k == 1) return x % 10;          // 出口：右边第 1 个数字
    return digit(x / 10, k - 1);        // 去掉个位，找第 k-1 个
}

int main() {
    cin >> n >> k;
    cout << digit(n, k) << endl;
    return 0;
}
