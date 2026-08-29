#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、读入整数 X（2 <= X <= 10）；
2、用 double 类型的 s 累加 1 + 1/2 + 1/3 + ...；
3、每次加完判断 s 是否已经大于 X；
4、一旦 s > X，当前加到的项数 n 就是答案。
注意：1/i 是整除，必须写成 1.0/i 才得到小数。
*/
int X, n;
double s;

int main() {
    cin >> X;

    s = 0;
    n = 0;
    // 不断累加 1/n，直到总和大于 X
    while (s <= X) {
        n++;
        s = s + 1.0 / n;
    }

    cout << n << endl;

    return 0;
}
