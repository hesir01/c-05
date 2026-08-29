#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、二分答案"最短跳跃距离 d"：d 越大越难满足（需要移走更多石头）；
2、check(d)：从起点（位置 0）出发，依次看每块石头：
   若当前石头与上一个保留石头距离 < d，就移走它（计数 +1）；
   否则保留它，更新上一个保留位置；
   最后若移走数 <= M 则可行（可尝试更大的 d）；
3、递归二分框架：在 [1, L] 中找满足 check 的最大 d；
4、输出最大最短跳跃距离。
注意：终点 L 也算一个"保留点"，最后判断终点与上一保留点距离。
*/
int L, N, M, d[50005];

// 检查最短跳跃距离至少为 x 时，需要移走的石头数是否 <= M
bool check(int x) {
    int cnt = 0, last = 0;                  // last 是上一个保留的石头位置
    for (int i = 1; i <= N; ++i) {
        if (d[i] - last < x) {
            cnt++;                          // 距离太近，移走这块石头
        } else {
            last = d[i];                    // 保留
        }
    }
    if (L - last < x) cnt++;                // 终点也要满足距离
    return cnt <= M;
}

int main() {
    scanf("%d%d%d", &L, &N, &M);
    for (int i = 1; i <= N; ++i) scanf("%d", &d[i]);
    int lo = 1, hi = L, ans = 0;
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
