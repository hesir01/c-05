#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、把 n 个盘从起点柱 a 移到目标柱 c，可借助中间柱 b；
2、递归函数 hanoi(k, a, b, c)：
   ① 先把 k-1 个盘从 a 借助 c 移到 b；
   ② 把第 k 个盘从 a 移到 c，打印 "a->k->c"；
   ③ 再把 k-1 个盘从 b 借助 a 移到 c；
   出口：k == 0 时返回；
3、main 读入盘数 n 和三个柱子的编号（字符），调用 hanoi 输出每一步。
注意：输出格式为 "源柱->盘号->目标柱"，如 a->3->b。
*/
int n;
char p1, p2, p3;

// 递归：把 k 个盘从 a 借助 b 移到 c，打印移动记录
void hanoi(int k, char a, char b, char c) {
    if (k == 0) return;                     // 出口
    hanoi(k - 1, a, c, b);                  // ① k-1 个盘 a->b
    cout << a << "->" << k << "->" << c << endl;  // ② 第 k 个盘 a->c
    hanoi(k - 1, b, a, c);                  // ③ k-1 个盘 b->c
}

int main() {
    cin >> n >> p1 >> p2 >> p3;             // 盘数 + 三个柱子的编号
    hanoi(n, p1, p2, p3);
    return 0;
}
