#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、从 2 开始逐个判断是否为质数，数到第 k 个时输出；
2、k 最大 10000，第 10000 个质数约 104729，
   逐个试除判断即可（无需大数组）；
3、main 输出第 k 个质数。
*/
int k;

// 判断 x 是否为质数
bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    cin >> k;
    int cnt = 0;
    for (int x = 2; ; ++x) {
        if (isPrime(x)) {
            cnt++;
            if (cnt == k) {
                cout << x << endl;
                return 0;
            }
        }
    }
    return 0;
}
