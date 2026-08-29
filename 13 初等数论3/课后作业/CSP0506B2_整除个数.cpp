#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、1~n 中能被 k 整除的数的个数 = n / k；
2、这些数是 k, 2k, 3k, ..., (n/k)*k，和为 k * (1+2+...+(n/k))；
3、main 输出个数和总和。
验证：20 3 → 20/3=6 个，3*(1+...+6)=63。
*/
long long n, k;

int main() {
    cin >> n >> k;
    long long cnt = n / k;                  // 能被 k 整除的个数
    long long sum = k * cnt * (cnt + 1) / 2; // 等差数列求和
    cout << cnt << ' ' << sum << endl;
    return 0;
}
