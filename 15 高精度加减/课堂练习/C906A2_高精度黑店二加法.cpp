#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、高精度加法：两个大数相加（均可达 10^1000）；
2、字符串读入，倒序存入数组（低位在前），逐位相加并进位；
3、位数取两者较大值 + 1（可能的最高进位）；
4、倒序输出结果。
*/
string a, b;
int A[1005], B[1005], C[1005];

int main() {
    cin >> a >> b;
    int la = a.size(), lb = b.size();
    for (int i = 0; i < la; ++i) A[i] = a[la - 1 - i] - '0';
    for (int i = 0; i < lb; ++i) B[i] = b[lb - 1 - i] - '0';
    int len = max(la, lb);
    // 逐位相加并进位
    for (int i = 0; i < len; ++i) {
        C[i] += A[i] + B[i];
        if (C[i] >= 10) {
            C[i + 1] += C[i] / 10;
            C[i] %= 10;
        }
    }
    // 倒序输出
    int start = len;
    while (start > 0 && C[start] == 0) start--;
    for (; start >= 0; --start) cout << C[start];
    cout << endl;
    return 0;
}
