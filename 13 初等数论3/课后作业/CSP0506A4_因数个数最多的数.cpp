#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、找 1~n 中因数个数最多的数（相同取最小）；
2、用筛法思想：对每个 i，枚举它的倍数 j，div[j]++，统计每个数的因数个数；
   复杂度 O(n log n)，n ≤ 10^6 可行；
3、main 输出因数个数最多的数。
验证：100 → 60（12 个因数）。
*/
int n, divCnt[1000005];

int main() {
    cin >> n;
    // 筛法统计每个数的因数个数
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            divCnt[j]++;
        }
    }
    int best = 1;
    for (int i = 2; i <= n; ++i) {
        if (divCnt[i] > divCnt[best]) best = i;  // 严格大于才更新，保证取最小
    }
    cout << best << endl;
    return 0;
}
