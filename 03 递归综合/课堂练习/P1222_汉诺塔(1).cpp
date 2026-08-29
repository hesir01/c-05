#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、汉诺塔经典递归：
   - 先把上面 n-1 个盘从 A 借助 C 移到 B；
   - 把第 n 个盘从 A 移到 C；
   - 再把 n-1 个盘从 B 借助 A 移到 C；
2、递归函数 hanoi(n, a, b, c)：把 n 个盘从 a 借助 b 移到 c；
   出口：n == 0 时直接返回；
3、main 读入 n，调用 hanoi(n,'A','B','C')，逐行输出移动步骤。
*/
int n;

// 递归：把 n 个盘从 a 借助 b 移到 c
void hanoi(int k, char a, char b, char c) {
    if (k == 0) return;                     // 出口
    hanoi(k - 1, a, c, b);                  // n-1 个盘 a->b（借助 c）
    cout << a << " To " << c << endl;       // 最大的盘 a->c
    hanoi(k - 1, b, a, c);                  // n-1 个盘 b->c（借助 a）
}

int main() {
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
