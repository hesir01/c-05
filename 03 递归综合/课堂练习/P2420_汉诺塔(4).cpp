#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、只允许相邻移动的汉诺塔，把 n 个盘从 a 移到 c（b 在中间）：
   ① 先把 n-1 个盘从 a 移到 c（相邻规则），腾出 a；
   ② 最大盘从 a 移到 b；
   ③ 再把 n-1 个盘从 c 移到 a；
   ④ 最大盘从 b 移到 c；
   ⑤ 最后把 n-1 个盘从 a 移到 c；
2、递归函数 hanoi(k, a, b, c)：按上面五步递归打印；
   出口：k == 0 时返回；
3、main 读入 n，调用 hanoi(n,'A','B','C')。
验证：n=2 输出 8 步，与样例一致。
*/
int n;

// 递归：相邻移动，把 k 个盘从 a 经 b 移到 c
void hanoi(int k, char a, char b, char c) {
    if (k == 0) return;                     // 出口
    hanoi(k - 1, a, b, c);                  // ① n-1 个盘 a->c
    cout << a << " To " << b << endl;       // ② 最大盘 a->b
    hanoi(k - 1, c, b, a);                  // ③ n-1 个盘 c->a
    cout << b << " To " << c << endl;       // ④ 最大盘 b->c
    hanoi(k - 1, a, b, c);                  // ⑤ n-1 个盘 a->c
}

int main() {
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
