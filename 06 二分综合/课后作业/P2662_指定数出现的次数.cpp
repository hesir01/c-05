#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、数组排序后，X 出现的次数 = 最后一个 <= X 的位置 - 第一个 >= X 的位置 + 1
   = upper_bound(X) - lower_bound(X)；
2、递归函数 lower(l, r)：求第一个 >= x 的位置；
   递归函数 upper(l, r)：求第一个 > x 的位置；
   出口均为 l == r 返回 l，upper 需支持 l > r 返回 l；
3、main 读入 M 次询问，输出每个 X 出现的次数。
*/
int N, M, x, a[100005];

// 递归二分：求第一个 >= x 的位置
int lower(int l, int r) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (a[mid] >= x) return lower(l, mid);
    return lower(mid + 1, r);
}

// 递归二分：求第一个 > x 的位置
int upper(int l, int r) {
    if (l > r) return l;
    int mid = (l + r) / 2;
    if (a[mid] > x) return upper(l, mid - 1);
    return upper(mid + 1, r);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + N + 1);                 // 排序
    for (int i = 1; i <= M; ++i) {
        scanf("%d", &x);
        printf("%d ", upper(1, N) - lower(1, N));  // 出现次数
    }
    printf("\n");
    return 0;
}
