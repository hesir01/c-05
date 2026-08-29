#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、求 1~n 中质数个数，n 最大 10^6；
2、埃氏筛标记合数，统计质数个数；
3、main 输出结果。
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
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
