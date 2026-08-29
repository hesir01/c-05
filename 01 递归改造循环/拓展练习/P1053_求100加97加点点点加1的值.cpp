#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、要求 100+97+...+4+1 的值，相邻两项相差 3；
2、递归函数 sum(i)：求从 i 开始、每次减 3 直到 1 的和；
   出口：i < 1 时返回 0；
   否则返回 i + sum(i - 3)，即"当前项 + 后面各项之和"；
3、main 输出 sum(100)。
*/
// 递归求 100+97+...+1 的和
long long sum(int i) {
    if (i < 1) return 0;        // 出口：减到小于 1 就没有项了
    return i + sum(i - 3);      // 当前项 + 后面各项
}

int main() {
    cout << sum(100) << endl;
    return 0;
}
