#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、按格式输出 N = p1^a1 * p2^a2 * ... * pk^ak；
   指数为 1 时只写 p，不写 ^1；
2、特判：N == 1 时输出 1=1；
3、试除 2 到 sqrt(N)，统计每个质因子指数；
4、main 输出质因数分解表达式。
*/
long long n;

int main() {
    cin >> n;
    if (n == 1) {                           // 特判 1
        cout << "1=1" << endl;
        return 0;
    }
    cout << n << '=';
    long long m = n;
    bool first = true;
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
