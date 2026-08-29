#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、修改最少的数字使数列严格递增 = 保留尽量多的数不动，
   即求最长严格递增子序列（LIS）的长度 L，答案 = n - L；
   （因为允许改成任意实数，所以不需要做 a[i]-i 变换）
2、用 O(n log n) 的"维护 d 数组"法求 LIS：
   d[k] 表示长度为 k 的递增子序列的最小末尾值；
   对每个 a[i]，二分找 d 中第一个 >= a[i] 的位置并替换；
3、递归函数 lower(l, r, x)：在 d[l..r] 中找第一个 >= x 的位置；
   出口：l == r 返回 l；
4、main 输出 n - L。
验证：1 3 2 → LIS=2（1,3 或 1,2），答案 3-2=1。
*/
int n, a[100005], d[100005], len;

// 递归二分：在 d[l..r] 中找第一个 >= x 的位置
int lower(int l, int r, int x) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (d[mid] >= x) return lower(l, mid, x);
    return lower(mid + 1, r, x);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    len = 0;
    for (int i = 1; i <= n; ++i) {
        // 找 d 中第一个 >= a[i] 的位置
        if (len == 0 || d[len] < a[i]) {
            d[++len] = a[i];                    // 可以接在末尾
        } else {
            int p = lower(1, len, a[i]);        // 替换该位置
            d[p] = a[i];
        }
    }
    printf("%d\n", n - len);                    // 最少修改 = n - LIS
    return 0;
}
