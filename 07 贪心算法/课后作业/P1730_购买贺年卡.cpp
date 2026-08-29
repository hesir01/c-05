#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、要花最少的钱买 m 张贺卡，肯定先买单价最便宜的（贪心）；
2、把商铺按单价升序排序；
3、从最便宜的商铺开始买，每店最多买它的存货量，
   直到凑够 m 张，累加花费；
4、main 输出最少花费。
*/
int m, n;
struct Shop {
    int price, stock;
} a[1005];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].price, &a[i].stock);
    sort(a + 1, a + n + 1, [](Shop u, Shop v) { return u.price < v.price; });
    int need = m;
    long long cost = 0;
    for (int i = 1; i <= n && need > 0; ++i) {
        int buy = min(need, a[i].stock);    // 该店最多买存货量
        cost += (long long)buy * a[i].price;
        need -= buy;
    }
    printf("%lld\n", cost);
    return 0;
}
