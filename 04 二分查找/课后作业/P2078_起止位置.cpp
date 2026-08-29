#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、年龄数组有序，查询 x 的首次位置和末次位置：
   首次 = 第一个 >= x 的位置（左侧边界 lower）；
   末次 = 第一个 > x 的位置 - 1（upper - 1）；
2、递归函数 lower(l, r)：求第一个 >= x 的位置；
   递归函数 upper(l, r)：求第一个 > x 的位置；
   出口均为 l == r 返回 l；
3、若 a[首次] == x 输出 首次 末次，否则输出 -1 -1。
*/
int n, q, x, a[1000005];

// 递归二分：求第一个 >= x 的位置
int lower(int l, int r) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (a[mid] >= x) return lower(l, mid);
    return lower(mid + 1, r);
}

// 递归二分：求第一个 > x 的位置
int upper(int l, int r) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (a[mid] > x) return upper(l, mid);
    return upper(mid + 1, r);
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    while (q--) {
        scanf("%d", &x);
        int L = lower(1, n);                    // 首次位置
        if (a[L] != x) {
            printf("-1 -1\n");                  // 不存在
        } else {
            int R = upper(1, n) - 1;            // 末次位置
            printf("%d %d\n", L, R);
        }
    }
    return 0;
}
