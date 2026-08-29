#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、区间 [l, r] 内所有数对 (i, j)（i < j）中 gcd(i,j)=1 的对数；
2、双重枚举 i 从 l 到 r，j 从 i+1 到 r，用 gcd 判断是否互质；
3、递归函数 gcd(a,b)：欧几里得算法；
4、main 输出互质对数量。
验证：1 5 → (1,2)(1,3)(1,4)(1,5)(2,3)(2,5)(3,4)(3,5)(4,5) = 9。
*/
int l, r;

// 递归求最大公约数
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    cin >> l >> r;
    int cnt = 0;
    for (int i = l; i <= r; ++i) {
        for (int j = i + 1; j <= r; ++j) {
            if (gcd(i, j) == 1) cnt++;      // 互质
        }
    }
    cout << cnt << endl;
    return 0;
}
