#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、想买最多包辣条，肯定先买便宜的（贪心）；
2、每种辣条价格不同且只剩 10 包：把价格升序排序，
   从最便宜的开始，每种最多买 10 包，直到钱不够；
3、main 读入 m 元、n 种辣条和各自单价，输出最多能买的包数。
验证：100 3 / 5 50 10 → 5元买10包(50元) + 10元买5包(50元) = 15 包。
*/
int m, n, p[105];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
    sort(p + 1, p + n + 1);                 // 单价升序
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        // 该种最多买 10 包，取钱能买的数量
        int buy = min(10, m / p[i]);
        cnt += buy;
        m -= buy * p[i];
    }
    printf("%d\n", cnt);
    return 0;
}
