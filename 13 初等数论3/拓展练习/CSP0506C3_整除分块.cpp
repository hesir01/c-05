#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、求 S = sum_{i=1}^{n} floor(n / i)；
2、整数分块：floor(n/i) 的值只随 i 分块变化，
   当 i 在 [l, r] 区间内时 floor(n/i) 相同，其中 r = n / (n / l)；
   每块直接 值 * 块长 累加，时间复杂度 O(sqrt(n))；
3、n 最大 10^12，用 long long。
验证：n=10 → floor(10/i) = 10+5+3+2+2+1+1+1+1+1 = 27。
*/
long long n;

int main() {
    cin >> n;
    long long ans = 0;
    for (long long l = 1; l <= n; ) {
        long long v = n / l;                // 当前块的值
        long long r = n / v;                // 块的右端点
        ans += v * (r - l + 1);             // 值 * 块长
        l = r + 1;
    }
    cout << ans << endl;
    return 0;
}
