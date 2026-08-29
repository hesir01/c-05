#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、读入一个正整数 n；
2、重复以下过程直到 n 变成 1：
   - 若 n 是偶数，n 除以 2；
   - 若 n 是奇数，n 乘 3 加 1；
   每做一次运算，次数 cnt 加 1；
3、输出总运算次数 cnt。
注意：n 最大 20000，运算过程中数值会变大，用 long long 保险。
*/
long long n;
int cnt;

int main() {
    cin >> n;

    cnt = 0;
    // 只要还没有变成 1 就继续运算
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;       // 偶数除以 2
        } else {
            n = n * 3 + 1; // 奇数乘 3 加 1
        }
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
