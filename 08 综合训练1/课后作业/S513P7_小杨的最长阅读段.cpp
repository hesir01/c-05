#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、二分答案阅读段长度 len：len 越长子段总时长越大（a_i >= 1 单调）；
2、check(len)：用前缀和检查是否存在长度为 len 的子段和 <= S；
   "长度 <= len 时存在合法段"随 len 增大从假变真，
   二分找最长的可行 len；
3、若所有 a_i > S（连一篇文章都读不完），输出 0；
4、main 输出最长连续阅读段长度。
验证：5 5 / 1 2 1 3 2 → len=3 可行（1+2+1=4<=5），len=4 不行，答案 3。
*/
int n;
long long S, a[100005], pre[100005];

// 检查是否存在长度为 len 的子段和 <= S
bool check(int len) {
    for (int i = len; i <= n; ++i) {
        if (pre[i] - pre[i - len] <= S) return true;
    }
    return false;
}

int main() {
    scanf("%d%lld", &n, &S);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    if (!check(1)) {                        // 连一篇都读不完
        puts("0");
        return 0;
    }
    int lo = 1, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
