#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、求 1~N 中质数的个数，N 最大 10^8；
2、用埃氏筛 + char 数组（约 100MB）标记合数；
3、注意 i*i 可能溢出 int，用 long long；
4、main 输出质数个数。
*/
int N;
vector<char> isPrime;

int main() {
    cin >> N;
    isPrime.assign(N + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (long long i = 2; i * i <= N; ++i) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= N; j += i) isPrime[j] = 0;
        }
    }
    int cnt = 0;
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
