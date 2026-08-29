#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、Hermite 多项式递推公式：
   h(0,x)=1，h(1,x)=2x；
   h(n,x)=2x*h(n-1,x) - 2(n-1)*h(n-2,x)；
2、递归函数 h(n,x)：按公式直接翻译；
   出口：n==0 返回 1，n==1 返回 2*x；
3、main 读入 n 和 x，输出 h(n,x)，保留两位小数。
*/
int n;
double x;

// 递归求 Hermite 多项式 h(n,x)
double h(int k, double x) {
    if (k == 0) return 1.0;                          // 出口：n=0
    if (k == 1) return 2.0 * x;                      // 出口：n=1
    return 2.0 * x * h(k - 1, x) - 2.0 * (k - 1) * h(k - 2, x);
}

int main() {
    cin >> n >> x;
    cout << fixed << setprecision(2) << h(n, x) << endl;
    return 0;
}
