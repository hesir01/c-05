#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、递归函数 toBin(x)：输出 x 的二进制表示；
   出口：x == 0 时返回；
   先递归输出 x / 2 的二进制（高位），再输出 x % 2（当前位），
   这样后序输出正好是二进制的正常顺序；
2、特判：n == 0 时直接输出 0；
3、main 读入 n（0 <= n <= 32767），调用 toBin(n)。
*/
int n;

// 递归输出 x 的二进制表示
void toBin(int x) {
    if (x == 0) return;         // 出口
    toBin(x / 2);               // 先递归输出高位
    cout << x % 2;              // 再输出当前位
}

int main() {
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;      // 0 的二进制就是 0
    } else {
        toBin(n);
        cout << endl;
    }
    return 0;
}
