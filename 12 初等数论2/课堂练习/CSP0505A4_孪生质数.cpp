#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、孪生质数：p 和 p+2 都是质数；
2、先用埃氏筛标记 2~n 的质数，再遍历 p 判断 p 和 p+2；
3、main 输出所有孪生质数对。
验证：n=20 → 3 5 / 5 7 / 11 13 / 17 19。
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
    for (int p = 2; p + 2 <= n; ++p) {
        if (isPrime[p] && isPrime[p + 2]) {
            cout << p << ' ' << p + 2 << endl;
        }
    }
    return 0;
}
