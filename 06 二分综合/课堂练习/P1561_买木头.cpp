#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、二分答案木头长度 x：x 越大能凑出的根数越少；
2、check(x)：第 i 个供应商有 S_i 根长度 L_i 的木头，
   每根能锯出 L_i / x 根，总根数 = sum(S_i * (L_i / x))；
   若 >= m 则可行；
3、递归二分框架：在 [1, max(L)] 中找满足 check 的最大 x；
4、输出最大长度。
*/
int n;
long long m, len[100005], cnt[100005], maxlen;

// 检查每根长 x 时能否凑出至少 m 根
bool check(long long x) {
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        total += cnt[i] * (len[i] / x);
        if (total >= m) return true;        // 提前结束
    }
    return total >= m;
}

int main() {
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld", &len[i], &cnt[i]);
        maxlen = max(maxlen, len[i]);
    }
    long long lo = 1, hi = maxlen, ans = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;                      // 可行，尝试更长
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
