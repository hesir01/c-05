#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、递归函数 steps(x)：返回 x 变成 1 需要的运算次数；
2、递归出口：x == 1 时返回 0；
3、一般情况：
   - x 是偶数：返回 1 + steps(x / 2)；
   - x 是奇数：返回 1 + steps(x * 3 + 1)；
4、main 读入 n，输出 steps(n)。
注意：运算过程中数值会变大，用 long long。
*/
long long n;

// 递归求 x 经过多少次运算变成 1
long long steps(long long x) {
    if (x == 1) return 0;                    // 出口：已经是 1
    if (x % 2 == 0) {
        return 1 + steps(x / 2);             // 偶数除以 2
    }
    return 1 + steps(x * 3 + 1);             // 奇数乘 3 加 1
}

int main() {
    cin >> n;
    cout << steps(n) << endl;
    return 0;
}
