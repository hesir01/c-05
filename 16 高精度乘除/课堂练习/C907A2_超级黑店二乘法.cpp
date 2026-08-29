#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、高精度乘高精度：两个大数相乘（均可达 10^1000）；
2、字符串读入，倒序存入数组（低位在前）；
3、乘法：C[i+j] += A[i] * B[j]（第 i 位乘第 j 位贡献到 i+j 位），
   最后统一处理进位；
4、倒序输出结果，去前导 0。
*/
string a, b;
int A[1005], B[1005], C[2010];

int main() {
    cin >> a >> b;
    int la = a.size(), lb = b.size();
    for (int i = 0; i < la; ++i) A[i] = a[la - 1 - i] - '0';
    for (int i = 0; i < lb; ++i) B[i] = b[lb - 1 - i] - '0';
    // 逐位相乘累加
    for (int i = 0; i < la; ++i) {
        for (int j = 0; j < lb; ++j) {
            C[i + j] += A[i] * B[j];
        }
    }
    // 统一进位
    int len = la + lb;
    for (int i = 0; i < len; ++i) {
        if (C[i] >= 10) {
            C[i + 1] += C[i] / 10;
            C[i] %= 10;
        }
    }
    // 倒序输出，去前导 0
    int start = len;
    while (start > 0 && C[start] == 0) start--;
    for (; start >= 0; --start) cout << C[start];
    cout << endl;
    return 0;
}
