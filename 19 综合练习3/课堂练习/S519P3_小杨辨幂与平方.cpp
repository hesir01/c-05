#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、统计两类特殊数字个数：
   - 2 的幂：x > 0 且 x & (x-1) == 0；
   - 完全平方数：开方后平方等于本身；
2、main 读入 n 个数，分别统计并输出。
*/
int n;
long long x;

int main() {
    cin >> n;
    int pow2 = 0, square = 0;
    while (n--) {
        cin >> x;
        if (x > 0 && (x & (x - 1)) == 0) pow2++;     // 2 的幂
        long long s = sqrt((double)x);
        if (s * s == x) square++;                   // 完全平方数
    }
    cout << pow2 << ' ' << square << endl;
    return 0;
}
