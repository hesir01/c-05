#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、求 n 的所有正因数之和（含 1 和 n）；
2、枚举 1 到 sqrt(n)，找到成对因数 i 和 n/i 累加；
3、main 输出因数和。
验证：12 → 1+2+3+4+6+12 = 28。
*/
long long n;

int main() {
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) sum += n / i;   // 成对的另一个因数
        }
    }
    cout << sum << endl;
    return 0;
}
