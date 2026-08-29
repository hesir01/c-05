#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、幸运数字：恰好有两种不同的质因子；
2、对每个数质因数分解，统计不同质因子的个数，等于 2 则幸运；
3、main 读入 n 个数，逐个判断输出 YES/NO。
*/
int n;
long long x;

// 统计 x 的不同质因子个数
int countPrimeFactor(long long x) {
    int cnt = 0;
    for (long long p = 2; p * p <= x; ++p) {
        if (x % p == 0) {
            cnt++;
            while (x % p == 0) x /= p;      // 除尽该因子
        }
    }
    if (x > 1) cnt++;                       // 剩余的大质因子
    return cnt;
}

int main() {
    cin >> n;
    while (n--) {
        cin >> x;
        cout << (countPrimeFactor(x) == 2 ? "YES" : "NO") << endl;
    }
    return 0;
}
