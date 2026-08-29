#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、图书编码排序后，对每个需求码找"以它结尾的最小编码"；
2、对每个读者：需求码长度 len、需求码 x；
   把图书编码升序排序，用二分找第一个 >= x 的编码，
   从它开始向后检查是否以 x 结尾（后 10^len 位 == x）；
3、递归函数 lower(l, r, x)：找第一个 >= x 的位置；
   出口：l == r 返回 l；
4、main 对每个读者输出最小满足编码，没有则输出 -1。
注意：编码位数可能比需求码短，直接跳过。
*/
int n, q;
long long code[1005];

// 递归二分：找第一个 >= x 的位置
int lower(int l, int r, long long x) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (code[mid] >= x) return lower(l, mid, x);
    return lower(mid + 1, r, x);
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%lld", &code[i]);
    sort(code + 1, code + n + 1);           // 编码升序
    while (q--) {
        int len;
        long long x;
        scanf("%d%lld", &len, &x);
        long long mod = 1;
        for (int i = 0; i < len; ++i) mod *= 10;  // 10^len
        int p = lower(1, n, x);             // 第一个 >= x 的编码
        bool ok = false;
        // 从 p 向后找以 x 结尾的最小编码
        for (int i = p; i <= n; ++i) {
            if (code[i] % mod == x) {
                printf("%lld\n", code[i]);
                ok = true;
                break;
            }
        }
        if (!ok) puts("-1");
    }
    return 0;
}
