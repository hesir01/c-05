#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、递归函数 revNum(x, r)：把 x 的数位颠倒过来，结果累积在 r 里；
   出口：x == 0 时返回 r；
   否则把 x 的个位拼到 r 的末尾，继续处理 x / 10；
2、递归函数 solve(x)：判断 x 是否是回文数（x == 颠倒数）；
   - 是回文数：出口，直接返回；
   - 不是：处理次数 cnt 加 1，再递归 solve(x + 颠倒数)；
3、main 读入 n，cnt 置 0，调用 solve(n)，输出 cnt。
*/
long long n, cnt;

// 递归求 x 的颠倒数，r 是已经拼好的部分
long long revNum(long long x, long long r) {
    if (x == 0) return r;                    // 出口：所有位取完
    return revNum(x / 10, r * 10 + x % 10);  // 个位拼到 r 末尾，继续
}

// 递归处理：加颠倒数，直到成为回文数
void solve(long long x) {
    long long r = revNum(x, 0);
    if (r == x) return;       // 出口：已经是回文数
    cnt++;
    solve(x + r);             // 递归：继续处理新数
}

int main() {
    cin >> n;
    cnt = 0;
    solve(n);
    cout << cnt << endl;
    return 0;
}
