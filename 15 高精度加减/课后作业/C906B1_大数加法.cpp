#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、大数 n（可达 10^1000）+ 2023；
2、字符串读入，倒序存入数组，从低位加 2023 并进位；
3、倒序输出结果。
验证：10000000000000 + 2023 = 10000000002023。
*/
string n;
int num[1005];

int main() {
    cin >> n;
    int len = n.size();
    for (int i = 0; i < len; ++i) num[i] = n[len - 1 - i] - '0';
    // 加 2023
    int i = 0;
    long long b = 2023;
    while (b > 0) {
        num[i] += b % 10;
        b /= 10;
        i++;
    }
    for (i = 0; i < len + 10; ++i) {
        if (num[i] >= 10) {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    int start = len + 10;
    while (start > 0 && num[start] == 0) start--;
    for (; start >= 0; --start) cout << num[start];
    cout << endl;
    return 0;
}
