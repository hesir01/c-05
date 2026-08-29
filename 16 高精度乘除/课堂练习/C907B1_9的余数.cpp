#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、求大数 n 除以 9 的余数：一个数 mod 9 = 各位数字之和 mod 9；
2、n 的位数可达 10^6，逐位累加数字和，最后对 9 取余；
3、main 处理 m 组测试数据。
*/
int m;

int main() {
    cin >> m;
    while (m--) {
        string n;
        cin >> n;
        long long sum = 0;
        for (char c : n) {
            sum += c - '0';                 // 累加各位数字
        }
        cout << sum % 9 << endl;            // 和 mod 9
    }
    return 0;
}
