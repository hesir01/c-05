#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、亲和数对 (A, B)：A 的真因子和 = B，B 的真因子和 = A，且 A < B；
2、枚举 A 从 1 到 n，求 A 的真因子和 B；
   若 B > A 且 B <= n，再验证 B 的真因子和 == A；
3、main 输出所有亲和数对（较小数在前，按较小数排序）。
*/
int n;

// 求 x 的真因子和（不含 x 本身）
long long sumDiv(long long x) {
    long long s = 0;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            if (i != x) s += i;
            if (i * i != x && x / i != x) s += x / i;
        }
    }
    return s;
}

int main() {
    cin >> n;
    for (int A = 2; A <= n; ++A) {
        long long B = sumDiv(A);
        if (B > A && B <= n && sumDiv(B) == A) {
            cout << A << ' ' << B << endl;
        }
    }
    return 0;
}
