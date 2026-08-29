#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、二分答案"最大载量 x"：x 越大需要的车越少；
2、check(x)：从左到右贪心装车，当前车装不下就换下一辆，
   统计所需车辆数，若 <= k 则可行；
3、二分框架：在 [max(a), sum(a)] 中找满足 check 的最小 x；
4、输出最小最大载量。
验证：5 2 / 1 2 3 4 5 → x=9 可行（[1,2,3][4,5]），答案 9。
*/
int n, k;
long long a[100005], sum;

// 检查最大载量 x 时能否用 <= k 辆车装完
bool check(long long x) {
    long long cur = 0;
    int cars = 1;
    for (int i = 1; i <= n; ++i) {
        if (cur + a[i] > x) {               // 装不下，换车
            cars++;
            cur = a[i];
        } else {
            cur += a[i];
        }
    }
    return cars <= k;
}

int main() {
    scanf("%d%d", &n, &k);
    long long maxa = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        sum += a[i];
        maxa = max(maxa, a[i]);
    }
    long long lo = maxa, hi = sum, ans = sum;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
