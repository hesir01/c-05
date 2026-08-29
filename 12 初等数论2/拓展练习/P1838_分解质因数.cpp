#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、区间 [a,b] 内每个整数输出质因数分解，形如 k=a1*a2*...；
2、先筛出 sqrt(b) 内的质数，再用试除分解每个数；
3、a、b <= 10000，直接逐个分解即可；
4、main 输出每个数的分解式。
验证：6 → 6=2*3。
*/
int a, b;
bool isPrime[10005];

int main() {
    cin >> a >> b;
    fill(isPrime, isPrime + b + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= b; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= b; j += i) isPrime[j] = false;
        }
    }
    for (int x = a; x <= b; ++x) {
        cout << x << '=';
        int m = x;
        bool first = true;
        for (int p = 2; p <= m; ++p) {
            if (!isPrime[p]) continue;
            while (m % p == 0) {
                if (!first) cout << '*';
                first = false;
                cout << p;
                m /= p;
            }
        }
        if (first) cout << x;               // x 本身是质数（1 的特殊情况）
        cout << endl;
    }
    return 0;
}
