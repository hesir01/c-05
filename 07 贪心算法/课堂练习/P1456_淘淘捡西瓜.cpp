#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、想装最多的西瓜，肯定先装轻的（贪心：每次选最轻的西瓜）；
2、把西瓜重量升序排序，从小到大逐个装，装不下就停止；
3、main 读入 n、容量 x 和 n 个重量，输出能装下的西瓜个数。
验证：5 10 / 2 3 1 5 4 → 排序 1 2 3 4 5，装 1+2+3+4=10 共 4 个。
*/
int n, x, a[105];

int main() {
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);                 // 重量升序
    int cnt = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (sum + a[i] > x) break;          // 装不下就停止
        sum += a[i];                        // 装进背包
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
