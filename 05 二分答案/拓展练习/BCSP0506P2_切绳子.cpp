#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、二分答案小绳子长度 x：x 越大能切出的段数越少；
2、check(x)：每段绳子能切出 a[i]/x 段（整除），
   总段数 = sum(a[i]/x)，若 >= m 则可行；
3、递归二分框架：在 [1, max(a)] 中找满足 check 的最大 x；
4、若长度为 1 都切不出 m 段，输出 0（check(1) 为假时）。
注意：n 最大 1e5，m 最大 1e6，用 long long。
*/
int n;
long long m, a[100005], maxa;

// 检查每段长 x 时能否切出至少 m 段
bool check(long long x) {
    long long cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += a[i] / x;
        if (cnt >= m) return true;          // 提前结束
    }
    return cnt >= m;
}

int main() {
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        maxa = max(maxa, a[i]);
    }
    // 长度为 1 都切不出 m 段，输出 0
    if (!check(1)) {
        printf("0\n");
        return 0;
    }
    // 二分找最大可行长度
    long long lo = 1, hi = maxa, ans = 1;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
