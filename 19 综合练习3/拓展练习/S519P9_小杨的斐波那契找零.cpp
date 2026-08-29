#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、f_n：斐波那契数列（f_1 = 1, f_2 = 1）第 n 项，n <= 30；
2、数位和：把 f_n 的各位数字相加；
3、贪心换纪念币：面值 {1, 5, 10, 50}，优先用大面值（这些面值贪心最优）；
4、main 输出三个整数。
验证：n=10 → f=55，数位和 10，55 = 50+5 共 2 枚。
*/
int n;
int coin[4] = {1, 5, 10, 50};

int main() {
    cin >> n;
    // 递推斐波那契
    long long f1 = 1, f2 = 1, fn = 1;
    for (int i = 3; i <= n; ++i) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    cout << fn << ' ';                      // 第 n 项
    // 数位和
    int digitSum = 0;
    long long t = fn;
    while (t > 0) {
        digitSum += t % 10;
        t /= 10;
    }
    cout << digitSum << ' ';                // 数位和
    // 贪心换纪念币
    int cnt = 0;
    for (int i = 3; i >= 0; --i) {
        cnt += fn / coin[i];
        fn %= coin[i];
    }
    cout << cnt << endl;                    // 最少硬币数
    return 0;
}
