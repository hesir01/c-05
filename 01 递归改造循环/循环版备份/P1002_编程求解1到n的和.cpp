#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、读入一个整数 n；
2、用变量 sum 记录累加和，初始为 0；
3、用 for 循环让 i 从 1 加到 n，每次把 i 累加进 sum；
4、循环结束后输出 sum，即为 1+2+3+...+n 的值。
*/
int n, sum;

int main() {
    cin >> n;

    sum = 0;
    // 从 1 累加到 n
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    cout << sum << endl;

    return 0;
}
