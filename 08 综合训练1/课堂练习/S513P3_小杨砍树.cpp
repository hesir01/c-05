#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、二分答案锯口高度 x：x 越高收获越少；
2、check(x)：收获 = sum(max(0, h[i]-x))，若 >= S 则可行；
3、二分框架：在 [0, max(h)] 中找满足 check 的最大 x；
4、输出最大锯口高度。
验证：5 8 / 4 7 2 8 6 → x=4 时收获 9 >= 8，x=5 时 6 < 8，答案 4。
*/
int n;
long long S, h[100005];

// 检查锯口 x 时收获量是否 >= S
bool check(long long x) {
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i] > x) s += h[i] - x;
        if (s >= S) return true;            // 提前结束
    }
    return s >= S;
}

int main() {
    scanf("%d%lld", &n, &S);
    long long maxh = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &h[i]);
        maxh = max(maxh, h[i]);
    }
    long long lo = 0, hi = maxh, ans = 0;
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
