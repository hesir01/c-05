#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、标准分解式：n = p1^e1 * p2^e2 * ...，质因子从小到大；
2、第一行输出分解式（指数 1 省略 ^1，* 连接）；
3、第二行输出最大质因子；
4、第三行输出所有不同质因子之和；
5、试除分解 n。
验证：360 = 2^3*3^2*5，最大质因子 5，质因子和 2+3+5=10。
*/
long long n;

int main() {
    cin >> n;
    long long m = n;
    bool first = true;
    long long maxPrime = 0, sumPrime = 0;
    // 试除分解
    for (long long p = 2; p * p <= m; ++p) {
        if (m % p == 0) {
            long long e = 0;
            while (m % p == 0) { m /= p; e++; }
            if (!first) cout << '*';
            first = false;
            if (e > 1) cout << p << '^' << e;
            else cout << p;
            maxPrime = p;
            sumPrime += p;
        }
    }
    if (m > 1) {                            // 剩余的大质因子
        if (!first) cout << '*';
        cout << m;
        maxPrime = m;
        sumPrime += m;
    }
    cout << endl;
    cout << maxPrime << endl;               // 最大质因子
    cout << sumPrime << endl;               // 质因子之和
    return 0;
}
