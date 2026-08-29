#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、每次走 1 级或 2 级，到第 n 级的最后一步可能走 1 级或 2 级：
   f(n) = f(n-1) + f(n-2)；
2、递归出口：
   n == 1 时返回 1（走一次 1 级）；
   n == 2 时返回 2（1+1 或 2）；
3、main 循环读入 N，读到文件结束，每行输出对应走法数。
注意：N 最大 30，走法数用 long long。
*/
long long n;

// 递归求走 n 级楼梯的走法数（每次 1 级或 2 级）
long long ways(long long x) {
    if (x == 1) return 1;               // 出口：1 级 1 种
    if (x == 2) return 2;               // 出口：2 级 2 种
    return ways(x - 1) + ways(x - 2);   // 最后一步走 1 级或 2 级
}

int main() {
    while (cin >> n) {
        cout << ways(n) << endl;
    }
    return 0;
}
