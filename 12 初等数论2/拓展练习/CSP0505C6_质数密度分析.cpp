#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、素数定理：π(n) ≈ n / ln(n)，验证 n=10^2..10^k 时的误差；
2、误差 = 实际质数个数 - n/ln(n)（四舍五入保留小数？）；
   按题面要求输出每个 n 的误差；
3、k 最大 6（10^6），埃氏筛到 10^6 统计质数个数；
4、输出 10^2 到 10^k 每个 n 的 π(n) 与 n/ln(n) 的差。
注意：题目输出格式需与样例一致，此处输出每行 "n 误差"。
*/
int k;
bool isPrime[1000005];
int pi[1000005];                            // pi[n] = n 以内质数个数

int main() {
    cin >> k;
    int N = 1;
    for (int i = 0; i < k; ++i) N *= 10;    // 10^k
    // 埃氏筛
    fill(isPrime, isPrime + N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) isPrime[j] = false;
        }
    }
    for (int i = 2; i <= N; ++i) {
        pi[i] = pi[i - 1] + (isPrime[i] ? 1 : 0);
    }
    // 输出 10^2 到 10^k 的误差
    for (int e = 2; e <= k; ++e) {
        long long n = 1;
        for (int i = 0; i < e; ++i) n *= 10;
        double approx = (double)n / log((double)n);   // n/ln(n)
        printf("%lld %.2f\n", n, pi[n] - approx);
    }
    return 0;
}
