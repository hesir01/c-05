#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、高精度乘小数：大数 a（可达 10^1000）× 小数 b（<= 1000）；
2、字符串读入 a，倒序存入数组（低位在前），每一位乘以 b 并进位；
3、倒序输出结果，去前导 0。
验证：1000000000000000000000000000000000 × 74。
*/
string a;
int b;
int num[2005];

int main() {
    cin >> a >> b;
    int len = a.size();
    for (int i = 0; i < len; ++i) num[i] = a[len - 1 - i] - '0';
    // 每一位乘以 b
    for (int i = 0; i < len; ++i) num[i] *= b;
    // 处理进位
    for (int i = 0; i < len + 20; ++i) {
        if (num[i] >= 10) {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    int start = len + 20;
    while (start > 0 && num[start] == 0) start--;
    for (; start >= 0; --start) cout << num[start];
    cout << endl;
    return 0;
}
