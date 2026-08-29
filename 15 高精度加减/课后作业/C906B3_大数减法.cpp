#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、大数减法 A - B（位数不超过 1000），结果可能为负；
2、先比较 A 和 B 的大小：若 A < B，交换并输出负号；
3、倒序存储，逐位相减，不够借 1；
4、输出结果去掉前导 0。
*/
string a, b;
int A[1005], B[1005], C[1005];

// 比较两个数字字符串大小（a >= b ?）
bool ge(string& a, string& b) {
    if (a.size() != b.size()) return a.size() > b.size();
    return a >= b;
}

int main() {
    cin >> a >> b;
    bool neg = false;
    if (!ge(a, b)) {
        swap(a, b);                         // 保证 A >= B
        neg = true;
    }
    int la = a.size(), lb = b.size();
    for (int i = 0; i < la; ++i) A[i] = a[la - 1 - i] - '0';
    for (int i = 0; i < lb; ++i) B[i] = b[lb - 1 - i] - '0';
    int len = max(la, lb);
    for (int i = 0; i < len; ++i) {
        C[i] += A[i] - B[i];
        if (C[i] < 0) {
            C[i] += 10;
            C[i + 1]--;
        }
    }
    if (neg) cout << '-';
    int start = len;
    while (start > 0 && C[start] == 0) start--;
    for (; start >= 0; --start) cout << C[start];
    cout << endl;
    return 0;
}
