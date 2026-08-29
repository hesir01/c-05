#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、汉诺塔移动规律：编号最小的盘（盘 1）在奇数步移动，
   盘 2 每 2 步移动一次，盘 3 每 4 步移动一次……
   即第 k 步移动的盘号 = k 中从右往左第一个二进制 1 的位置 + 1；
2、递归函数 which(k)：
   出口：k 是奇数时返回 1（最低位是 1 → 盘 1）；
   否则返回 1 + which(k / 2)（右移一位继续看）；
3、main 读入 n、k，输出 which(k)。
验证：n=3,k=4（二进制100）→ 盘 3，符合样例。
*/
int n, k;

// 递归求第 k 步移动的盘子编号
int which(int k) {
    if (k % 2 == 1) return 1;               // 出口：最低位 1 → 盘 1
    return 1 + which(k / 2);                // 右移一位，盘号加 1
}

int main() {
    cin >> n >> k;
    cout << which(k) << endl;
    return 0;
}
