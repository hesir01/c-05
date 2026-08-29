#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、求 gcd(a1+i, a2+i, ..., an+i)；
2、利用 gcd(x, y) = gcd(x, y-x)：
   gcd(a1+i, ..., an+i) = gcd(a1+i, a2-a1, a3-a1, ..., an-a1)；
   设 d = gcd(a2-a1, a3-a1, ..., an-a1)（固定值，预处理），
   答案 = gcd(a1 + i, d)；
3、递归函数 gcd：欧几里得算法；
4、main 对 q 次询问输出答案。
验证：6 9 12 18 30，d=gcd(3,6,12,24)=3；i=3 → gcd(9,3)=3。
*/
int n, q;
long long a[100005], d;

// 递归求最大公约数
long long gcd(long long x, long long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    // 预处理 d = gcd(a2-a1, a3-a1, ..., an-a1)
    d = 0;
    for (int i = 2; i <= n; ++i) {
        d = gcd(d, a[i] - a[1]);
    }
    while (q--) {
        long long i;
        cin >> i;
        cout << gcd(a[1] + i, d) << endl;   // 答案 = gcd(a1+i, d)
    }
    return 0;
}
