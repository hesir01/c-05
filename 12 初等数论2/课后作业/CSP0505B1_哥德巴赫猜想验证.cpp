#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、哥德巴赫猜想验证：找 p <= q 且 p + q = n 的质数对；
2、先筛 2~n 的质数，从小到大枚举 p，若 p 和 n-p 都是质数则找到；
3、main 输出第一组满足条件的质数对。
*/
int n;
bool isPrime[100005];

int main() {
    cin >> n;
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    for (int p = 2; p <= n / 2; ++p) {
        if (isPrime[p] && isPrime[n - p]) {
            cout << p << ' ' << n - p << endl;
            return 0;
        }
    }
    return 0;
}
