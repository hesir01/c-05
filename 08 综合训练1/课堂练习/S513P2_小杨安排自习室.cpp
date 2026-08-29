#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、二分答案"最近距离 d"：d 越大能选出的自习室越少；
2、先对坐标排序，check(d)：从最左开始，每隔至少 d 选一间，
   看能否选够 k 间；
3、二分框架：在 [1, 最大坐标-最小坐标] 中找满足 check 的最大 d；
4、输出最大分散度。
*/
int n, k, pos[100005];

// 检查最近距离 >= d 时能否选出 k 间自习室
bool check(int d) {
    int cnt = 1, last = pos[1];             // 第一间选最左
    for (int i = 2; i <= n; ++i) {
        if (pos[i] - last >= d) {           // 距离够远
            cnt++;
            last = pos[i];
        }
    }
    return cnt >= k;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &pos[i]);
    sort(pos + 1, pos + n + 1);             // 坐标排序
    int lo = 1, hi = pos[n] - pos[1], ans = 0;
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
