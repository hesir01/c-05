#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、欧拉函数 φ(n)：不超过 n 且与 n 互质的正整数个数；
2、用线性筛同时求 φ(1)~φ(n)：
   - i 是质数：φ(i) = i - 1；
   - i * p（p 是最小质因子）：
     若 p | i，φ(i*p) = φ(i) * p；
     否则 φ(i*p) = φ(i) * (p - 1)；
3、main 读入 n，输出 φ(n)。
*/
int n, phi[1000005];

// 线性筛求欧拉函数
void build_phi(int m) {
    vector<int> primes;
    phi[1] = 1;
    for (int i = 2; i <= m; ++i) {
        if (phi[i] == 0) {
            phi[i] = i - 1;                 // i 是质数
            primes.push_back(i);
        }
        for (int p : primes) {
            if (1LL * i * p > m) break;
            if (i % p == 0) {
                phi[i * p] = phi[i] * p;    // p 是 i 的因子
                break;
            }
            phi[i * p] = phi[i] * (p - 1);  // p 不是 i 的因子
        }
    }
}

int main() {
    cin >> n;
    build_phi(n);
    cout << phi[n] << endl;
    return 0;
}
