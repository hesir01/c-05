#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、最长因子链：a[i] 是 a[j] 的因数且 a[i] < a[j]，则 i 可指向 j；
2、先排序，然后动态规划：dp[i] = 以 a[i] 结尾的最长因子链长度，
   dp[i] = max(dp[j]) + 1（对所有 j < i 且 a[j] | a[i]）；
3、n <= 100，O(n^2) 可行；
4、main 输出最长因子链长度。
验证：1 2 3 4 6 12 → 1→2→4→12 长度 4。
*/
int n;
long long a[105];
int dp[105];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);                 // 排序
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;                          // 自己单独一条链
        for (int j = 1; j < i; ++j) {
            if (a[i] % a[j] == 0) {         // a[j] 是 a[i] 的因数
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
