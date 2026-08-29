#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、终止数：1/a 能化为有限小数 ⟺ a 只有质因子 2 和 5
   （分母除 2、5 外无其他质因子，十进制分数才有限）；
2、对 [L,R] 每个数，反复除以 2 和 5，若最后剩 1 则是终止数；
3、main 统计终止数个数。
验证：2~11 → 2 4 5 8 10 共 5 个。
*/
int L, R;

// 判断 a 是否为终止数
bool isTerm(int a) {
    while (a % 2 == 0) a /= 2;              // 去掉所有 2
    while (a % 5 == 0) a /= 5;              // 去掉所有 5
    return a == 1;                          // 只剩 1 则只含质因子 2、5
}

int main() {
    cin >> L >> R;
    int cnt = 0;
    for (int a = L; a <= R; ++a) {
        if (isTerm(a)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
