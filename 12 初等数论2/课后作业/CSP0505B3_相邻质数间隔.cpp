#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、先筛 2~n 的质数，把质数按顺序存到数组；
2、相邻质数之差，记录最大间隔和第一次出现的质数对；
3、main 输出间隔最大的相邻质数对。
验证：n=20 → 质数 2 3 5 7 11 13 17 19，最大间隔在 7 和 11（差 4）。
*/
int n;
bool isPrime[1000005];
int primes[1000005], pcnt;

int main() {
    cin >> n;
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) primes[++pcnt] = i;
    }
    int maxGap = 0, ansA = 0, ansB = 0;
    for (int i = 1; i < pcnt; ++i) {
        int gap = primes[i + 1] - primes[i];
        if (gap > maxGap) {                 // 严格大于才更新（保留第一次）
            maxGap = gap;
            ansA = primes[i];
            ansB = primes[i + 1];
        }
    }
    cout << ansA << ' ' << ansB << endl;
    return 0;
}
