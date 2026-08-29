#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、排序数组，对每次查询 x 用二分找首次出现位置（lower_bound）；
2、分组：每组内任意两数差 <= w（即组内最大-最小 <= w），
   排序后从第一个数开始贪心：若当前数 - 组首 > w 则新开一组；
3、main 先输出 q 行查询结果，最后输出分组数。
验证：1 3 3 5 8，查 3→2、4→-1；w=2 → {1,3,3}{5}{8} 共 3 组。
*/
int n, q;
long long a[100005], w;

// 递归二分：找第一个 >= x 的位置
int lower(int l, int r, long long x) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (a[mid] >= x) return lower(l, mid, x);
    return lower(mid + 1, r, x);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    cin >> q;
    while (q--) {
        long long x;
        cin >> x;
        int p = lower(1, n, x);
        if (a[p] == x) cout << p << endl;   // 首次出现位置
        else cout << -1 << endl;
    }
    cin >> w;
    int groups = 1;
    long long groupStart = a[1];            // 每组第一个数
    for (int i = 2; i <= n; ++i) {
        if (a[i] - groupStart > w) {        // 组内最大-最小超限，新开一组
            groups++;
            groupStart = a[i];
        }
    }
    cout << groups << endl;
    return 0;
}
