#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、读入一个整数 n；
2、用 for 循环让 i 从 n 开始，每次减 1，直到 1；
3、每轮把当前的 i 输出到一行，即得到 n~1 的所有整数。
*/
int n;

int main() {
    cin >> n;

    // 循环输出 n 到 1 的每一个整数，每行一个
    for (int i = n; i >= 1; --i) {
        cout << i << endl;
    }

    return 0;
}
