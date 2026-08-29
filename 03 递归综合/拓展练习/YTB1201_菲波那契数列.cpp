#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、菲波那契数列：第 1、2 项为 1，后面每项等于前两项之和；
2、递归函数 fib(x)：
   出口：x == 1 或 x == 2 时返回 1；
   否则返回 fib(x-1) + fib(x-2)；
3、main 读入组数 n，每组读一个 a，输出第 a 项。
注意：a 最大 20，fib(20) = 6765，int 足够。
*/
int n, a;

// 递归求第 x 项菲波那契数
int fib(int x) {
    if (x == 1 || x == 2) return 1;         // 出口
    return fib(x - 1) + fib(x - 2);         // 前两项之和
}

int main() {
    cin >> n;
    while (n--) {
        cin >> a;
        cout << fib(a) << endl;
    }
    return 0;
}
