#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、只允许相邻移动的汉诺塔，移动次数 f(n) 满足：
   f(1)=2（最大盘 A->B->C 共 2 步），
   f(n) = 3*f(n-1) + 2，解得 f(n)=3^n-1；
2、递归函数 steps(n)：
   出口：n == 1 时返回 2；
   否则返回 3*steps(n-1) + 2；
3、main 读入 n，输出 steps(n)。
验证：n=3 → 3*8+2=26，符合样例。
*/
int n;

// 递归求相邻移动汉诺塔的步数
long long steps(int k) {
    if (k == 1) return 2;                   // 出口：1 个盘相邻移动需 2 步
    return 3 * steps(k - 1) + 2;            // 三段各移 n-1 个盘 + 最大盘 2 步
}

int main() {
    cin >> n;
    cout << steps(n) << endl;
    return 0;
}
