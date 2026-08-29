#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、阶梯数是 7 的倍数，且同时满足：
   x % 2 == 1（每步 2 阶剩 1）、x % 3 == 2（每步 3 阶剩 2）、
   x % 5 == 4（每步 5 阶剩 4）、x % 6 == 5（每步 6 阶剩 5）；
2、递归函数 find(x)：检查 x 是否满足四个条件；
   满足：出口，返回 x；
   不满足：递归 find(x + 7)，检查下一个 7 的倍数；
3、main 输出 find(7)，第一个满足条件的 x 就是最少阶梯数。
*/
// 递归找满足条件的 7 的倍数
int find(int x) {
    if (x % 2 == 1 && x % 3 == 2 && x % 5 == 4 && x % 6 == 5) {
        return x;               // 出口：找到答案
    }
    return find(x + 7);         // 递归检查下一个 7 的倍数
}

int main() {
    cout << find(7) << endl;
    return 0;
}
