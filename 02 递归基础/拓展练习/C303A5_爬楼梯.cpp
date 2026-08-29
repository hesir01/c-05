#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、每次只能走 2 级或 3 级，走到第 n 级的最后一步可能是 2 级或 3 级：
   f(n) = f(n-2) + f(n-3)；
2、递归出口：
   n == 1 时返回 0（1 级既不能走 2 级也不能走 3 级）；
   n == 2 时返回 1（走一次 2 级）；
   n == 3 时返回 1（走一次 3 级）；
   n == 0 时返回 1（空台阶，作为组合边界）；
3、main 循环读入 N，读到 0 结束，每行输出对应走法数。
注意：N 最大 50，走法数增长快，用 long long。
*/
long long n;

// 递归求走 n 级楼梯的走法数（每次 2 级或 3 级）
long long ways(long long x) {
    if (x == 0) return 1;               // 边界：0 级算 1 种
    if (x == 1) return 0;               // 1 级无法走
    if (x == 2) return 1;               // 走一次 2 级
    if (x == 3) return 1;               // 走一次 3 级
    return ways(x - 2) + ways(x - 3);   // 最后一步走 2 级或 3 级
}

int main() {
    while (cin >> n && n != 0) {
        cout << ways(n) << endl;
    }
    return 0;
}
