#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、质因数分解：从 2 开始试除，能整除就输出该质因子并继续除；
2、从小到大试除，输出所有质因子（含重复）；
3、n 最大 10^8，试除到 sqrt(n)，剩余部分若 >1 是最后一个质因子；
4、main 读入 n，输出质因数分解结果。
验证：12 → 2 2 3。
*/
int n;

int main() {
    cin >> n;
    int m = n;
    // 试除 2 到 sqrt(m)
    for (int p = 2; p * p <= m; ++p) {
        while (m % p == 0) {
            cout << p << ' ';               // 输出质因子
            m /= p;
        }
    }
    if (m > 1) cout << m << ' ';            // 剩余的大质因子
    cout << endl;
    return 0;
}
