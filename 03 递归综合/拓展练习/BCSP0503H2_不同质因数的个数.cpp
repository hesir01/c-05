#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、把 n 分解成质因数乘积 n = p1^a1 * p2^a2 * ... * pk^ak，输出 k（不同质因数的个数）；
2、用试除法：从 2 开始试除，能整除就是一个不同的质因子，计数加 1，
   并用 while 循环把 n 中该因子除尽；
3、试除到 sqrt(n) 为止，若最后 n 还大于 1，则它是一个质因子，计数再加 1；
4、main 读入 n，输出不同质因数的个数。
*/
int n;

int main() {
    cin >> n;
    int cnt = 0;
    // 试除 2 到 sqrt(n)
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            cnt++;                          // 找到一个不同的质因子
            while (n % p == 0) n /= p;      // 除尽该因子
        }
    }
    if (n > 1) cnt++;                       // 剩余的大质因子
    cout << cnt << endl;
    return 0;
}
