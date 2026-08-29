#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、读入一个正整数 n；
2、不断检查 n 能否被 2 整除：能整除就除以 2，次数加 1；
3、直到 n 不能被 2 整除为止，输出次数。
*/
int n, cnt;

int main() {
    cin >> n;

    cnt = 0;
    // 只要 n 还是偶数，就除以 2，并计数
    while (n % 2 == 0) {
        n /= 2;
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
