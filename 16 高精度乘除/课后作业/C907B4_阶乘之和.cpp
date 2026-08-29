#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、计算 S = 1! + 2! + ... + n!（n <= 50），用高精度；
2、阶乘数组 fac 存当前 k!，每步乘 k；
3、和数组 sum 累加每个阶乘（高精度加法）；
4、倒序输出结果。
验证：n=3 → 1!+2!+3! = 1+2+6 = 9。
*/
int n;
int fac[100], sum[100];

int main() {
    cin >> n;
    fac[0] = 1;                             // 0! = 1
    int facLen = 1;
    for (int k = 1; k <= n; ++k) {
        // fac = fac * k（高精度乘小数）
        for (int i = 0; i < facLen; ++i) fac[i] *= k;
        for (int i = 0; i < facLen; ++i) {
            if (fac[i] >= 10) {
                fac[i + 1] += fac[i] / 10;
                fac[i] %= 10;
                if (i + 1 == facLen) facLen++;
            }
        }
        // sum = sum + fac（高精度加法）
        int carry = 0;
        for (int i = 0; i < facLen; ++i) {
            sum[i] += fac[i] + carry;
            if (sum[i] >= 10) {
                sum[i] -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if (carry) sum[facLen] = 1;         // 最高位进位
    }
    int start = 200;
    while (start > 0 && sum[start] == 0) start--;
    for (; start >= 0; --start) cout << sum[start];
    cout << endl;
    return 0;
}
