#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、二分答案锯片高度 H：H 越高，得到的木材越少；
2、check(H)：计算 sum(max(0, h[i]-H))，若 >= M 则可行（可再抬高 H）；
3、递归二分（二分答案框架）：在 [low, high] 中找满足 check 的最大 H；
   用 while 循环实现二分，取上界 10^9（树高上限）；
4、输出满足条件的最大 H。
验证：5 20 / 4 42 40 26 46 → H=36 时木材 (42-36)+(40-36)+(46-36)=20 >= 20，H=37 时 19 < 20，答案 36。
*/
long long n, m, h[1000005], maxh;

// 检查高度 H 能否得到至少 m 米木材
bool check(long long H) {
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i] > H) s += h[i] - H;
        if (s >= m) return true;            // 提前结束
    }
    return s >= m;
}

int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &h[i]);
        maxh = max(maxh, h[i]);
    }
    // 二分答案：找满足 check 的最大 H
    long long lo = 0, hi = maxh, ans = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;                      // 可行，尝试更高
            lo = mid + 1;
        } else {
            hi = mid - 1;                   // 不可行，降低
        }
    }
    printf("%lld\n", ans);
    return 0;
}
