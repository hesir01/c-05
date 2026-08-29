#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、质因子：分解 n 时得到的所有质数因子（含重复）；
2、从 2 开始试除，能整除就输出该质因子并继续除，直到除尽；
3、n 最大 32768，试除到 sqrt，剩余部分若 >1 输出；
4、按从小到大输出所有质因子，每行一个。
验证：20 → 2 2 5。
*/
int n;

int main() {
    cin >> n;
    int m = n;
    for (int p = 2; p * p <= m; ++p) {
        while (m % p == 0) {
            cout << p << endl;              // 输出质因子
            m /= p;
        }
    }
    if (m > 1) cout << m << endl;           // 剩余的大质因子
    return 0;
}
