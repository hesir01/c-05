#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、读入整数 n（n <= 9999）；
2、枚举 1~n 的每一个数；
3、对每个数，把各位数字拆出来求和：
   - 若数位和既不能被 2 整除，也不能被 5 整除，计数加 1；
4、输出满足条件的数的个数。
*/
int n, cnt;

int main() {
    cin >> n;

    cnt = 0;
    // 枚举 1 到 n 的每个数
    for (int i = 1; i <= n; ++i) {
        int t = i, sum = 0;
        // 拆出每一位并求和
        while (t > 0) {
            sum += t % 10;
            t /= 10;
        }
        // 数位和既不能被 2 整除也不能被 5 整除
        if (sum % 2 != 0 && sum % 5 != 0) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
