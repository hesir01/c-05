#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、n 个数互不相同，m 次询问 x 在数组中的位置（1-based），不存在输出 0；
2、排序会丢失原位置，用结构体存"值+原位置"，按值排序；
3、递归函数 bs(l, r, x)：在排序后数组中二分找 x；
   出口：l > r 返回 0；
4、main 每次查询输出对应原位置。
*/
int n, m, x;
struct Node {
    int val, pos;
} a[100005];

// 递归二分：在 a[l..r] 中找值 x，返回其原位置（不存在返回 0）
int bs(int l, int r, int x) {
    if (l > r) return 0;                    // 出口
    int mid = (l + r) / 2;
    if (a[mid].val == x) return a[mid].pos;
    if (a[mid].val > x) return bs(l, mid - 1, x);
    return bs(mid + 1, r, x);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].val);
        a[i].pos = i;                       // 记录原位置
    }
    sort(a + 1, a + n + 1, [](Node u, Node v) { return u.val < v.val; });
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &x);
        printf("%d\n", bs(1, n, x));
    }
    return 0;
}
