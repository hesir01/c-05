#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、二分答案连续段长度 len：len 越长子段和越大（a_i >= 1 单调）；
2、check(len)：用前缀和检查是否存在长度为 len 的子段和 >= S；
3、二分框架：在 [1, n] 中找满足 check 的最小 len；
   若整个数组和都 < S（check 全部失败），输出 -1；
4、main 输出最短连续段长度。
验证：5 10 / 2 1 3 5 4 → len=3 可行（3+5+4=12>=10），len=2 不可行，答案 3。
*/
int n;
long long S, a[100005], pre[100005];

// 检查是否存在长度为 len 的子段和 >= S
bool check(int len) {
    for (int i = len; i <= n; ++i) {
        if (pre[i] - pre[i - len] >= S) return true;
    }
    return false;
}

int main() {
    scanf("%d%lld", &n, &S);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        pre[i] = pre[i - 1] + a[i];         // 前缀和
    }
    if (pre[n] < S) {                       // 全部加起来都不够
        puts("-1");
        return 0;
    }
    int lo = 1, hi = n, ans = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
