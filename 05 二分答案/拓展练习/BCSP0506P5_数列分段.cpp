#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、二分答案"最大段和 x"：x 越大需要的段数越少；
2、check(x)：贪心分段——从前往后累加，
   当前段和超过 x 就新开一段，统计总段数；
   若总段数 <= m 则可行（x 可以更小）；
3、递归二分框架：在 [max(wi), sum(wi)] 中找满足 check 的最小 x；
4、输出最小的最大段和。
*/
int n, m, w[100005];
long long sumw, maxw;

// 检查最大段和不超过 x 时，分段数是否 <= m
bool check(long long x) {
    long long cur = 0;
    int seg = 1;                            // 至少一段
    for (int i = 1; i <= n; ++i) {
        if (cur + w[i] > x) {               // 放不下，新开一段
            seg++;
            cur = w[i];
        } else {
            cur += w[i];
        }
    }
    return seg <= m;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
        sumw += w[i];
        maxw = max(maxw, (long long)w[i]);
    }
    long long lo = maxw, hi = sumw, ans = sumw;
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
