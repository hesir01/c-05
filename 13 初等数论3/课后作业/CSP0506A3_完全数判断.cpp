#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、完全数：等于所有真因子（除本身外）之和；
2、枚举 1 到 sqrt(n) 找因数，累加真因子（i 和 n/i，n/i != n）；
3、若真因子和 == n 则是完全数；
4、main 输出 YES/NO。
验证：6 → 真因子 1+2+3 = 6，是完全数。
*/
long long n;

int main() {
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i != n) sum += i;           // 真因子
            if (i * i != n && n / i != n) sum += n / i;  // 成对因子（排除本身）
        }
    }
    cout << (sum == n ? "YES" : "NO") << endl;
    return 0;
}
