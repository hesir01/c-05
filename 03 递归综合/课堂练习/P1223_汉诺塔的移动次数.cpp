#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、n 个盘的汉诺塔最少移动次数 f(n) 满足：
   f(1)=1，f(n)=2*f(n-1)+1，解得 f(n)=2^n-1；
2、递归函数 moves(n)：
   出口：n == 1 时返回 1；
   否则返回 2*moves(n-1) + 1；
3、main 读入 n，输出 moves(n)。
*/
int n;

// 递归求 n 个盘的汉诺塔最少移动次数
long long moves(int k) {
    if (k == 1) return 1;                   // 出口：1 个盘移动 1 次
    return 2 * moves(k - 1) + 1;            // 先移 n-1 个，再移最大盘，再移 n-1 个
}

int main() {
    cin >> n;
    cout << moves(n) << endl;
    return 0;
}
