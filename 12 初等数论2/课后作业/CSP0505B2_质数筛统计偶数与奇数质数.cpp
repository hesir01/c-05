#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、2~n 中唯一的偶质数是 2，其余质数都是奇数；
2、用埃氏筛统计：偶质数个数（有且只有 2 一个）、奇质数个数；
3、main 输出两个数：偶质数个数、奇质数个数。
验证：n=10 → 质数 2 3 5 7，偶质数 1 个（2），奇质数 3 个。
*/
int n;
bool isPrime[1000005];

int main() {
    cin >> n;
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    int even = 0, odd = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            if (i % 2 == 0) even++;
            else odd++;
        }
    }
    cout << even << ' ' << odd << endl;
    return 0;
}
