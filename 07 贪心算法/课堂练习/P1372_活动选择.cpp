#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、活动选择问题：想安排最多活动，每次选"结束时间最早"的活动
   （贪心：结束早给后面留更多时间）；
2、把所有活动按结束时间升序排序；
3、从第一个活动开始，若下一个活动的开始时间 >= 当前活动的结束时间，
   就选择它并更新结束时间；
4、main 输出最多能安排的活动个数。
*/
int n;
struct Act {
    int s, e;
} a[1005];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].s, &a[i].e);
    // 按结束时间升序排序
    sort(a + 1, a + n + 1, [](Act u, Act v) { return u.e < v.e; });
    int cnt = 0, now = -1;                  // now 是当前最后一个活动的结束时间
    for (int i = 1; i <= n; ++i) {
        if (a[i].s >= now) {                // 不冲突，选择该活动
            cnt++;
            now = a[i].e;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
