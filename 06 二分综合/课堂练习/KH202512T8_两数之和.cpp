#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、数组有序，对每个 a[i]，用二分查找 x - a[i] 是否存在（且位置 != i）；
2、递归函数 bs(l, r, val)：在 a[l..r] 中找 val；
   出口：l > r 返回 0（不存在）；
3、main 处理 t 组数据，每组判断后输出 YES/NO。
注意：i != j，若 x-a[i] == a[i] 需确认数组中该值出现至少 2 次。
*/
int n, x, a[100005];

// 递归二分：在 a[l..r] 中找 val，返回位置（不存在返回 0）
int bs(int l, int r, int val) {
    if (l > r) return 0;                    // 出口
    int mid = (l + r) / 2;
    if (a[mid] == val) return mid;
    if (a[mid] > val) return bs(l, mid - 1, val);
    return bs(mid + 1, r, val);
}

// 判断是否存在 i != j 使 a[i]+a[j] == x
bool solve() {
    for (int i = 1; i <= n; ++i) {
        int need = x - a[i];
        int p = bs(1, n, need);
        if (p == 0) continue;               // 没找到
        if (p != i) return true;            // 位置不同，满足
        // 找到的是自己：检查是否有重复值
        if ((p > 1 && a[p - 1] == need) || (p < n && a[p + 1] == need)) return true;
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        scanf("%d", &x);
        puts(solve() ? "YES" : "NO");
    }
    return 0;
}
