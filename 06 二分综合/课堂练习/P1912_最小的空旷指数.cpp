#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、二分答案"空旷指数 d"：d 越大需要增设的路标越少；
2、check(d)：相邻两个原有路标相距 dist 时，
   要让间距 <= d 需要增设 (dist - 1) / d 个路标；
   统计所有相邻间距需要的增设总数，若 <= K 则可行；
3、递归二分框架：在 [1, L] 中找满足 check 的最小 d；
4、输出最小空旷指数。
*/
int L, N, K, pos[100005];

// 检查空旷指数 <= d 时，需要增设的路标数是否 <= K
bool check(int d) {
    int need = 0;
    for (int i = 1; i < N; ++i) {
        int dist = pos[i + 1] - pos[i];
        need += (dist - 1) / d;             // 相邻间距内需增设的数量
        if (need > K) return false;         // 提前结束
    }
    return need <= K;
}

int main() {
    scanf("%d%d%d", &L, &N, &K);
    for (int i = 1; i <= N; ++i) scanf("%d", &pos[i]);
    int lo = 1, hi = L, ans = L;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {                   // 可行，尝试更小
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
