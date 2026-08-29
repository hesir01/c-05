#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、求 n 的正因数个数：枚举 1 到 sqrt(n)，成对统计；
2、main 输出因数个数。
验证：36 → 1,2,3,4,6,9,12,18,36 共 9 个。
*/
long long n;

// 求 x 的正因数个数
long long countDiv(long long x) {
    long long cnt = 0;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            cnt++;
            if (i * i != x) cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> n;
    cout << countDiv(n) << endl;
    return 0;
}
