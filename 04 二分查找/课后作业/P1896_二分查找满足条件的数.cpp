#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、数组有序不递减，q 次查询：找第一个 >= x 的元素的位置；
2、递归函数 lower(l, r)：在 a[l..r] 中找第一个 >= x 的位置；
   - 若 a[mid] >= x，答案在左半（含 mid），递归 lower(l, mid)；
   - 否则递归 lower(mid+1, r)；
   - 出口：l == r 返回 l；
3、若 a[p] >= x 输出 p，否则输出 -1（不存在）；
4、main 处理 q 次查询。
*/
int n, q, x, a[1000005];

// 递归二分：求第一个 >= x 的位置
int lower(int l, int r) {
    if (l == r) return l;                       // 出口
    int mid = (l + r) / 2;
    if (a[mid] >= x) return lower(l, mid);
    return lower(mid + 1, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        int p = lower(1, n);
        if (a[p] >= x) printf("%d\n", p);       // 第一个 >= x 的位置
        else printf("-1\n");
    }
    return 0;
}
