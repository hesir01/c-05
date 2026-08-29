#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、叠罗汉总高度要 >= 书架高度 B，奶牛数量最少；
2、贪心：肯定先踩最高的奶牛（降序排序，从高到低叠）；
3、逐个累加高度，一旦 >= B 就输出当前用的奶牛数；
4、main 输出最少奶牛数。
*/
int N, B, h[20005];

int main() {
    scanf("%d%d", &N, &B);
    for (int i = 1; i <= N; ++i) scanf("%d", &h[i]);
    sort(h + 1, h + N + 1, greater<int>()); // 高度降序
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += h[i];
        if (sum >= B) {                     // 够高了
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
