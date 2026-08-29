#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、三个大整数求和（位数不超过 1000）；
2、字符串读入，倒序存入数组（低位在前），逐位相加并进位；
3、倒序输出结果。
*/
string a, b, c;
int A[1005], B[1005], C[1005], S[1005];

int main() {
    cin >> a >> b >> c;
    int la = a.size(), lb = b.size(), lc = c.size();
    for (int i = 0; i < la; ++i) A[i] = a[la - 1 - i] - '0';
    for (int i = 0; i < lb; ++i) B[i] = b[lb - 1 - i] - '0';
    for (int i = 0; i < lc; ++i) C[i] = c[lc - 1 - i] - '0';
    int len = max(la, max(lb, lc));
    // 逐位相加并进位
    for (int i = 0; i < len; ++i) {
        S[i] += A[i] + B[i] + C[i];
        if (S[i] >= 10) {
            S[i + 1] += S[i] / 10;
            S[i] %= 10;
        }
    }
    int start = len;
    while (start > 0 && S[start] == 0) start--;
    for (; start >= 0; --start) cout << S[start];
    cout << endl;
    return 0;
}
