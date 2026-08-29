#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、找最长连续子数组，使得每个元素整除后一个元素（a[i] | a[i+1]）；
2、从左到右扫描，用 len 记录当前连续段的长度：
   若 a[i] % a[i-1] == 0 则 len++，否则 len = 1；
3、维护最大长度；
4、main 输出最长连续整除子序列长度。
*/
int n, a[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int len = 1, best = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] % a[i - 1] == 0) {
            len++;                          // 延续当前段
        } else {
            len = 1;                        // 重新开始
        }
        best = max(best, len);
    }
    cout << best << endl;
    return 0;
}
