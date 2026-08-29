#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、每组最多 2 件且价格和不超过 w，分组数最少；
2、贪心：价格升序排序，最贵的一件尽量和最便宜的一件配对
   （双指针：如果 a[l]+a[r] <= w 就配对，否则最贵的单独一组）；
3、main 输出最少分组数。
*/
int w, n, a[30005];

int main() {
    scanf("%d%d", &w, &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);                 // 价格升序
    int l = 1, r = n, cnt = 0;
    while (l <= r) {
        if (l != r && a[l] + a[r] <= w) {
            l++;                            // 最便宜和最贵配对
        }
        r--;                                // 最贵的必被处理（配对或单独）
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
