#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、线性筛预处理 1~n 的最小质因数 SPF；
2、对每次询问 x：不断取 spf[x]，统计指数并除以 spf[x]，
   直到 x 变为 1，得到质因数分解；
3、输出每次询问的质因数分解。
*/
int n, q, spf[1000005];

// 线性筛求最小质因数
void build_spf(int m) {
    vector<int> primes;
    for (int i = 2; i <= m; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;                     // i 是质数
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || 1LL * i * p > m) break;
            spf[i * p] = p;                 // 记录最小质因数
        }
    }
}

int main() {
    scanf("%d%d", &n, &q);
    build_spf(n);
    while (q--) {
        int x;
        scanf("%d", &x);
        bool first = true;
        while (x > 1) {
            int p = spf[x], e = 0;
            while (x % p == 0) { x /= p; e++; }
            for (int i = 0; i < e; ++i) {
                if (!first) printf("*");
                first = false;
                printf("%d", p);
            }
        }
        printf("\n");
    }
    return 0;
}
