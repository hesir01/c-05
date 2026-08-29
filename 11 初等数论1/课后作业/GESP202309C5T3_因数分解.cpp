#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、因数分解式：把 N 分解成质因数的幂次乘积，如 20 = 2^2*5；
2、试除 2 到 sqrt(N)，统计每个质因子的指数；
   指数 > 1 时输出 p^e，指数 == 1 时输出 p，用 * 连接；
3、N 最大 10^12，试除到 sqrt(N)，剩余部分若 >1 是最后一个质因子；
4、main 输出因数分解式。
*/
long long n;

int main() {
    cin >> n;
    long long m = n;
    bool first = true;
    // 试除 2 到 sqrt(m)
    for (long long p = 2; p * p <= m; ++p) {
        if (m % p == 0) {
            int e = 0;
            while (m % p == 0) { m /= p; e++; }
            if (!first) cout << '*';
            first = false;
            if (e > 1) cout << p << '^' << e;
            else cout << p;
        }
    }
    if (m > 1) {                            // 剩余的大质因子
        if (!first) cout << '*';
        cout << m;
    }
    cout << endl;
    return 0;
}
