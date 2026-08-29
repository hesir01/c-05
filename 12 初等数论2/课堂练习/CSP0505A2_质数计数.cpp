#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、埃氏筛标记 1~n 的合数，统计质数个数；
2、n 最大 10^7，用 char 数组节省内存（约 10MB）；
3、main 读入 n，输出 1~n 中质数的个数。
*/
int n;
vector<char> isPrime;

int main() {
    cin >> n;
    isPrime.assign(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = 0;
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
