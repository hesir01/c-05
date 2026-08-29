#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、Pell 数列：a1=1，a2=2，a(n) = 2*a(n-1) + a(n-2)；
2、k 最大接近 1000000，若用递归求第 k 项会递归 100 万层导致栈溢出，
   因此这里把"递归思想"改造成递推（循环）——这正是"递归改造循环"；
3、递推时每一步都对 32767 取模，防止数值爆炸；
4、main 读入组数 n，每组读一个 k，输出第 k 项模 32767 的值。
*/
int n, k;

// 递推求第 k 项 Pell 数列模 32767 的值
int pell(int k) {
    if (k == 1) return 1;                   // 第 1 项
    if (k == 2) return 2;                   // 第 2 项
    int a1 = 1, a2 = 2, cur;
    // 从第 3 项递推到第 k 项
    for (int i = 3; i <= k; ++i) {
        cur = (2 * a2 + a1) % 32767;
        a1 = a2;
        a2 = cur;
    }
    return cur;
}

int main() {
    cin >> n;
    while (n--) {
        cin >> k;
        cout << pell(k) << endl;
    }
    return 0;
}
