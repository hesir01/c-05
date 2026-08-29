#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、高度合成数：因数个数严格大于所有比它小的数的因数个数；
2、用筛法求 1~n 每个数的因数个数；
3、遍历时维护当前最大因数个数，若当前数因数个数 > 已见最大值则输出；
4、main 输出所有高度合成数。
验证：100 → 1 2 4 6 12 24 36 48 60 72 84 90 96。
*/
int n, divCnt[1000005];

int main() {
    cin >> n;
    // 筛法统计因数个数
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            divCnt[j]++;
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (divCnt[i] > mx) {               // 严格大于，是高度合成数
            mx = divCnt[i];
            cout << i << endl;
        }
    }
    return 0;
}
