#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、欧拉函数求和 S = φ(1) + φ(2) + ... + φ(n)；
2、用线性筛求 φ(1)~φ(n)：
   - i 是质数：φ(i) = i-1；
   - i*p（p 最小质因子）：p|i 时 φ(i*p)=φ(i)*p，否则 φ(i*p)=φ(i)*(p-1)；
3、累加输出 S。
验证：n=10 → φ: 1,1,2,2,4,2,6,4,6,4 和 = 32。
*/
int n;
long long phi[1000005];

// 线性筛求欧拉函数并求和
long long build_phi(int m) {
    vector<int> primes;
    phi[1] = 1;
    for (int i = 2; i <= m; ++i) {
        if (phi[i] == 0) {
            phi[i] = i - 1;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (1LL * i * p > m) break;
            if (i % p == 0) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
    long long s = 0;
    for (int i = 1; i <= m; ++i) s += phi[i];
    return s;
}

int main() {
    cin >> n;
    cout << build_phi(n) << endl;
    return 0;
}
