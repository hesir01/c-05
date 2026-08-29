#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、打水时间短的人先打，总等待时间最小（贪心：短作业优先）；
2、n 个人分配到 r 个水龙头：把打水时间升序排序后轮流分配，
   用数组 tap[j] 记录第 j 个龙头已累计的打水时间；
3、第 i 个人去龙头 j，他的完成时刻 = tap[j] + t[i]，
   总时间累加这个完成时刻，再更新 tap[j]；
4、main 输出所有人的完成时刻总和。
验证：4 2 / 2 6 4 5 → 排序 2 4 5 6，总时间 2+4+7+10 = 23。
*/
int n, r, t[505], tap[105];

int main() {
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; ++i) scanf("%d", &t[i]);
    sort(t + 1, t + n + 1);                 // 打水时间升序
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        int j = (i - 1) % r;                // 轮流分配到第 j 个龙头
        tap[j] += t[i];                     // 该龙头累计时间增加
        total += tap[j];                    // 此人的完成时刻累加
    }
    printf("%d\n", total);
    return 0;
}
