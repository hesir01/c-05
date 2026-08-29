#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、两个质数 p、q 面值的纪念币，能凑出的瓶数是 p 和 q 的非负整数组合；
2、Frobenius 定理：两个互质数 p、q 的最大凑不出数 = p*q - p - q；
3、[1, p*q] 内凑不出的个数 = (p-1)*(q-1)/2；
4、main 输出两行。
验证：3 5 → 最大凑不出 15-3-5=7，凑不出个数 (2*4)/2=4。
*/
long long p, q;

int main() {
    cin >> p >> q;
    cout << p * q - p - q << endl;          // 最大凑不出的瓶数
    cout << (p - 1) * (q - 1) / 2 << endl;  // [1,pq] 内凑不出的个数
    return 0;
}
