#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、递归函数 cnt2(x)：求 x 能连续整除 2 的次数；
2、递归出口：x 是奇数（x % 2 != 0）时，返回 0；
3、一般情况：返回 1 + cnt2(x / 2)，
   即"这一次除以 2 + 剩余部分还能除几次"；
4、main 读入 n，输出 cnt2(n)。
*/
int n;

// 递归求 x 能整除几次 2
int cnt2(int x) {
    if (x % 2 != 0) return 0;    // 出口：不是偶数
    return 1 + cnt2(x / 2);      // 除了一次 2，继续递归
}

int main() {
    cin >> n;
    cout << cnt2(n) << endl;
    return 0;
}
