#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、递归函数 cubeSum(x)：求 x 的各位数字立方之和；
   出口：x == 0 时返回 0；
   否则返回 个位的立方 + cubeSum(x / 10)；
2、递归函数 find(i)：从 100 枚举到 999 找水仙花数；
   出口：i > 999 时返回；
   若 cubeSum(i) == i，说明 i 是水仙花数，输出；
   再递归 find(i + 1) 继续找下一个；
3、main 调用 find(100)，自然按从小到大输出。
*/
// 递归求各位数字的立方和
int cubeSum(int x) {
    if (x == 0) return 0;                 // 出口
    int d = x % 10;
    return d * d * d + cubeSum(x / 10);   // 个位立方 + 剩余位立方和
}

// 递归枚举 100~999 找水仙花数
void find(int i) {
    if (i > 999) return;                  // 出口
    if (cubeSum(i) == i) {
        cout << i << endl;                // 是水仙花数，输出
    }
    find(i + 1);                          // 递归找下一个
}

int main() {
    find(100);
    return 0;
}
