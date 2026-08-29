#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、莫比乌斯函数 μ(n)：
   - n 含平方因子：μ(n) = 0；
   - n 是 k 个不同质数乘积：μ(n) = (-1)^k；
   - μ(1) = 1；
2、用筛法求 μ(1)~μ(n)：
   枚举每个数 i，对质数 p，μ(i*p)：
   - 若 i % p == 0：含平方因子，μ = 0；
   - 否则 μ(i*p) = -μ(i)；
3、main 读入 n，输出 μ(1)~μ(n) 的值（空格分隔）。
*/
int n, mu[1000005];

// 筛法求莫比乌斯函数
void build_mu(int m) {
    vector<int> primes;
    vector<char> isComp(m + 1, 0);
    mu[1] = 1;
    for (int i = 2; i <= m; ++i) {
        if (!isComp[i]) {
            primes.push_back(i);
            mu[i] = -1;                     // 单个质数：(-1)^1 = -1
        }
        for (int p : primes) {
            if (1LL * i * p > m) break;
            isComp[i * p] = 1;
            if (i % p == 0) {
                mu[i * p] = 0;              // 含平方因子
                break;
            }
            mu[i * p] = -mu[i];             // 增加一个不同质因子
        }
    }
}

int main() {
    cin >> n;
    build_mu(n);
    for (int i = 1; i <= n; ++i) {
        cout << mu[i] << (i == n ? '\n' : ' ');
    }
    return 0;
}
