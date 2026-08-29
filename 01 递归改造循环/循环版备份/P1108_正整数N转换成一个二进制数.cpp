#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、读入整数 n（0 <= n <= 32767）；
2、用短除法把 n 不断除以 2，余数（0 或 1）依次存进数组；
3、除到 n 为 0 时停止，把数组倒过来输出，就是二进制结果；
4、特判：如果 n 本来就是 0，直接输出 0。
*/
int n, a[20], len;

int main() {
    cin >> n;

    // n 为 0 时直接输出 0
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    len = 0;
    // 短除法：不断除以 2，记录余数
    while (n > 0) {
        a[len] = n % 2;
        n /= 2;
        len++;
    }

    // 倒序输出所有余数
    for (int i = len - 1; i >= 0; --i) {
        cout << a[i];
    }
    cout << endl;

    return 0;
}
