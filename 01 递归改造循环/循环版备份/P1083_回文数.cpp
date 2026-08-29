#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、读入一个整数 n；
2、把 n 的各个数位颠倒过来得到 rev；
3、如果 n 等于 rev，说明已经是回文数，输出 0；
4、否则让 n = n + rev，次数加 1，重复这个过程，直到 n 变成回文数；
5、输出一共处理了多少次。
*/
long long n, rev, cnt;

int main() {
    cin >> n;

    cnt = 0;
    while (true) {
        // 求出 n 的颠倒数 rev
        rev = 0;
        long long t = n;
        while (t > 0) {
            rev = rev * 10 + t % 10;
            t /= 10;
        }

        // 已经是回文数，结束
        if (rev == n) {
            break;
        }

        // 该数加上它的颠倒数，处理次数加 1
        n = n + rev;
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
