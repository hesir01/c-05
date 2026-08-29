#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、高精度减法：大数 a（可达 10^100）- 小数 b（<= 10^9），保证 a > b；
2、字符串读入 a，倒序存入数组（低位在前），从低位开始减 b；
   不够减就向高位借 1；
3、倒序输出结果，去掉前导 0。
验证：233549053042353405748571245025347513637 - 3637。
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
    // 从低位开始减 b
    int i = 0;
    while (b > 0) {
        num[i] -= b % 10;
        b /= 10;
        i++;
    }
    // 处理借位
    for (i = 0; i < len; ++i) {
        if (num[i] < 0) {
            num[i] += 10;
            num[i + 1]--;                   // 向高位借 1
        }
    }
    // 倒序输出，去前导 0
    int start = len;
    while (start > 0 && num[start] == 0) start--;
    for (; start >= 0; --start) cout << num[start];
    cout << endl;
    return 0;
}
