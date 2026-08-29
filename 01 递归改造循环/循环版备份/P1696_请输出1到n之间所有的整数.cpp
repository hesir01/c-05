#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、读入一个整数 n；
2、用 for 循环让 i 从 1 增加到 n；
3、每轮把当前的 i 输出到一行，即得到 1~n 的所有整数。
*/
int n;

int main() {
    cin >> n;

    // 循环输出 1 到 n 的每一个整数，每行一个
    for (int i = 1; i <= n; ++i) {
        cout << i << endl;
    }

    return 0;
}
