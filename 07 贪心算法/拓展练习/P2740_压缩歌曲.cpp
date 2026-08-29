#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、硬盘装不下全部无损歌曲时，压缩"节省空间最多"的歌最划算（贪心）；
2、先计算所有歌都原样存放的总大小 total；
   若 total <= m，不需要压缩，输出 0；
3、否则把每首歌压缩能节省的空间 (a[i]-b[i]) 降序排序，
   从节省最多的开始压缩，直到总大小 <= m；
4、main 输出最少需要压缩的歌曲数量。
*/
int n;
long long m, save[100005];

int main() {
    scanf("%d%lld", &n, &m);
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        total += a;                          // 全部原样存放
        save[i] = a - b;                     // 压缩这首歌节省的空间
    }
    if (total <= m) {                        // 不用压缩
        printf("0\n");
        return 0;
    }
    sort(save + 1, save + n + 1, greater<long long>()); // 节省多的在前
    for (int i = 1; i <= n; ++i) {
        total -= save[i];                    // 压缩第 i 首
        if (total <= m) {                    // 装得下了
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
