#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、计算 n!（n 在 10000 以内，但 n! 非常大，用高精度数组）；
2、数组存各位数字（低位在前），初始为 1，从 2 乘到 n；
3、每一位乘 i 后统一进位，记录实际位数 len；
4、倒序输出结果。
注意：n 较大时用 int 数组，每位存 0~9 便于教学理解。
*/
int n;
int num[100000];

int main() {
    cin >> n;
    num[0] = 1;                             // 0! = 1
    int len = 1;
    for (int k = 2; k <= n; ++k) {
        // 每一位乘 k
        for (int i = 0; i < len; ++i) num[i] *= k;
        // 进位
        for (int i = 0; i < len; ++i) {
            if (num[i] >= 10) {
                num[i + 1] += num[i] / 10;
                num[i] %= 10;
                if (i + 1 == len) len++;    // 最高位进位，长度加 1
            }
        }
    }
    for (int i = len - 1; i >= 0; --i) cout << num[i];
    cout << endl;
    return 0;
}
