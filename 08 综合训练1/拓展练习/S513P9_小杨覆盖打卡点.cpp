#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、区间选点问题：每个区间至少要有一个整数点被摄像头覆盖；
2、贪心：按右端点升序排序，若当前区间还没被覆盖，
   就把摄像头装在该区间的右端点（覆盖当前区间且给后面留最大余地）；
3、main 输出最少摄像头数量。
验证：3 / [1,3] [2,5] [3,6] → 位置 3 覆盖全部，答案 1。
*/
int n;
struct Seg {
    int l, r;
} a[100005];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].l, &a[i].r);
    sort(a + 1, a + n + 1, [](Seg u, Seg v) { return u.r < v.r; });
    int cnt = 0, last = -1;                 // last 是上一个摄像头位置
    for (int i = 1; i <= n; ++i) {
        if (a[i].l > last) {                // 当前区间没被覆盖
            cnt++;
            last = a[i].r;                  // 摄像头装在右端点
        }
    }
    printf("%d\n", cnt);
    return 0;
}
