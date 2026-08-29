#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、把 a 分解成若干因子的乘积，且因子非降序（1 < a1 <= a2 <= ...）；
2、递归函数 dfs(x, start)：把 x 分解，因子至少从 start 开始；
   对每个满足 start <= d <= sqrt(x) 且 x%d==0 的因子 d：
   - 当前层用因子 d 继续分解 x/d（下一层最小因子是 d）；
   每进入一层"以 d 开头"就产生一种分解；
3、递归出口：x == 1 时返回 1（这一种分解成立）；
4、main 读入多组 a，输出每组分解种数。
*/
int t, a;

// 递归：把 x 分解成非降序因子乘积的种数，最小因子为 start
int dfs(int x, int start) {
    int ways = 1;                           // x 本身作为最后一项
    for (int d = start; d * d <= x; ++d) {
        if (x % d == 0) {
            ways += dfs(x / d, d);          // 用 d 继续分解 x/d
        }
    }
    return ways;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> a;
        cout << dfs(a, 2) << endl;
    }
    return 0;
}
