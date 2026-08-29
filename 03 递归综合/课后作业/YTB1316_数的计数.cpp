#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、规则：在 n 左边加一个不超过 n 一半的自然数，可反复进行；
   满足条件的数的个数 f(n) = 1（n 本身）+ f(1)+f(2)+...+f(n/2)；
2、递归函数 count(x)：
   出口：x == 1 时返回 1；
   否则返回 1 + count(1)+count(2)+...+count(x/2)；
3、用数组 memo 记忆化，避免重复计算；
4、main 读入 n，输出 count(n)。
验证：n=6 → 1 + f(1)+f(2)+f(3) = 1+1+2+2 = 6，符合样例。
*/
int n, memo[1005];

// 递归求满足条件的数的个数（记忆化）
int count(int x) {
    if (x == 1) return 1;                   // 出口
    if (memo[x]) return memo[x];            // 记忆化：已算过直接返回
    int s = 1;                              // 本身算一种
    for (int i = 1; i <= x / 2; ++i) {
        s += count(i);
    }
    return memo[x] = s;
}

int main() {
    cin >> n;
    cout << count(n) << endl;
    return 0;
}
