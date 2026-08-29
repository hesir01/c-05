#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、兔子从第 3 个月起每个月生一对，这就是斐波那契数列：
   f(1)=1，f(2)=1，f(n)=f(n-1)+f(n-2)；
2、递归函数 rabbit(n)：返回第 n 个月兔子的总对数；
   出口：n==1 或 n==2 时返回 1；
   否则返回 rabbit(n-1) + rabbit(n-2)；
3、main 读入 n，输出 rabbit(n)。
注意：n 最大 50，f(50) 约 1.2e10，用 long long。
*/
long long n;

// 递归求第 n 个月的兔子对数（斐波那契）
long long rabbit(long long x) {
    if (x == 1 || x == 2) return 1;          // 出口：前两个月各 1 对
    return rabbit(x - 1) + rabbit(x - 2);    // 本月 = 上月 + 上上月
}

int main() {
    cin >> n;
    cout << rabbit(n) << endl;
    return 0;
}
