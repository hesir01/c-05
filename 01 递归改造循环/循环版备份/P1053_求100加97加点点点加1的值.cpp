#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、要求 100+97+...+4+1 的值，观察发现公差是 3；
2、用 for 循环让 i 从 100 开始，每次减 3，直到 i 不小于 1；
3、每次把 i 累加进 sum；
4、循环结束后输出 sum。
*/
int sum;

int main() {
    sum = 0;

    // i 从 100 开始，每次减 3，覆盖 100, 97, ..., 4, 1
    for (int i = 100; i >= 1; i -= 3) {
        sum += i;
    }

    cout << sum << endl;

    return 0;
}
