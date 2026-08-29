#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、活动选择问题：按结束时间升序排序，贪心选"结束最早且相容"的活动；
2、相容条件：活动 A 结束时刻 <= 活动 B 开始时刻（e_A <= s_B，含端点）；
3、main 输出最多能参加的活动数。
*/
int n;
struct Act {
    int s, e;
} a[100005];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].s, &a[i].e);
    sort(a + 1, a + n + 1, [](Act u, Act v) { return u.e < v.e; });
    int cnt = 0, now = -1;                  // now 是上一个活动的结束时刻
    for (int i = 1; i <= n; ++i) {
        if (a[i].s >= now) {                // 相容（e_A <= s_B 即 now <= s_i）
            cnt++;
            now = a[i].e;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
