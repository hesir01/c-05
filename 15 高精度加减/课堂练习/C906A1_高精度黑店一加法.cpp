#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、高精度加法：大数 a（可达 10^100）+ 小数 b（<= 10^9）；
2、把 a 的各位数字存入数组（低位在前），从低位开始与 b 逐位相加进位；
3、注意 b 的位数少，直接把 b 加到 a 的低位，处理进位；
4、倒序输出结果。
验证：233549053042353405748571245025347513637 + 54187。
*/
string a;
long long b;
int num[1005];

int main() {
    cin >> a >> b;
    int len = a.size();
    for (int i = 0; i < len; ++i) {
        num[i] = a[len - 1 - i] - '0';      // 低位在前
    }
    // 从低位开始加 b
    int i = 0;
    while (b > 0) {
        num[i] += b % 10;
        b /= 10;
        i++;
    }
    // 处理进位
    for (i = 0; i < len + 20; ++i) {
        if (num[i] >= 10) {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    // 倒序输出
    int start = len + 20;
    while (start > 0 && num[start] == 0) start--;
    for (; start >= 0; --start) cout << num[start];
    cout << endl;
    return 0;
}
