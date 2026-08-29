#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、数组有序不递减，要找 x 最后一次出现的位置（右侧边界）；
2、递归函数 upper(l, r)：在 a[l..r] 中找第一个 > x 的位置；
   - 若 a[mid] > x，答案在左半（含 mid），递归 upper(l, mid)；
   - 否则递归 upper(mid+1, r)；
   - 出口：l == r 时返回 l；
3、最后一个等于 x 的位置 = upper(1,n) - 1；
   若该位置对应元素 == x 输出它，否则输出 -1；
4、main 处理 q 次查询。
*/
int n, q, x, a[1000005];

// 递归二分：求第一个 > x 的位置
int upper(int l, int r) {
    if (l == r) return l;                       // 出口
    int mid = (l + r) / 2;
    if (a[mid] > x) return upper(l, mid);       // 答案在左半
    return upper(mid + 1, r);                   // 答案在右半
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        int p = upper(1, n) - 1;                // 最后一个 <= x 的位置
        if (p >= 1 && a[p] == x) printf("%d\n", p);
        else printf("-1\n");
    }
    return 0;
}
