#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、埃氏筛：开一个 bool 数组，从 2 开始，把每个质数的倍数全部标记为合数；
2、筛完后没被标记的就是质数，按顺序输出 2~n 的所有质数；
3、n 最大 10^6，数组开 n+1。
*/
int n;
bool isPrime[1000005];

int main() {
    cin >> n;
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;        // 0 和 1 不是质数
    // 埃氏筛
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;         // 标记合数
            }
        }
    }
    bool first = true;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            if (!first) cout << ' ';
            first = false;
            cout << i;
        }
    }
    cout << endl;
    return 0;
}
