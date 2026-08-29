#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、要派最少的师傅，肯定先派加工能力最强的（贪心）；
2、把每个师傅每天能加工的零件数降序排序，从大到小累加；
3、当累加数量 >= m 时输出用了几个师傅；
4、若所有师傅加起来都不够 m，输出 NO。
*/
int m, n, a[105];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater<int>()); // 加工能力降序
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        if (sum >= m) {                     // 够了
            printf("%d\n", i);
            return 0;
        }
    }
    puts("NO");                             // 全部师傅都不够
    return 0;
}
