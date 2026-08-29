#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、计算 2^N（N <= 100），结果超过 long long，用高精度；
2、数组存各位数字（低位在前），初始为 1，乘 N 次 2；
3、每乘一次统一进位；
4、倒序输出结果。
验证：N=5 → 32。
*/
int N;
int num[105];

int main() {
    cin >> N;
    num[0] = 1;                             // 初始 2^0 = 1
    int len = 1;
    for (int k = 0; k < N; ++k) {
        // 每一位乘 2
        for (int i = 0; i < len; ++i) num[i] *= 2;
        // 进位
        for (int i = 0; i < len; ++i) {
            if (num[i] >= 10) {
                num[i + 1] += num[i] / 10;
                num[i] %= 10;
            }
        }
        if (num[len] > 0) len++;            // 最高位有进位
    }
    for (int i = len - 1; i >= 0; --i) cout << num[i];
    cout << endl;
    return 0;
}
