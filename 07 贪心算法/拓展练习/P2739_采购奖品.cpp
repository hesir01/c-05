#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、买最多件奖品，肯定先买单价最便宜的（贪心）；
2、把物品按单价升序排序，每件物品最多买库存数；
3、从最便宜的买起，直到钱不够，统计总件数；
4、main 输出最多能买的奖品件数。
*/
int m, n;
struct Item {
    int price, stock;
} a[105];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].price, &a[i].stock);
    sort(a + 1, a + n + 1, [](Item u, Item v) { return u.price < v.price; });
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        // 该种最多买库存数，取钱能买的数量
        int buy = min(a[i].stock, m / a[i].price);
        cnt += buy;
        m -= buy * a[i].price;
    }
    printf("%d\n", cnt);
    return 0;
}
