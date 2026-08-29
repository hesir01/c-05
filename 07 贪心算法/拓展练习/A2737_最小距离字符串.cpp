#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、对每个位置独立决策：选哪个字符让总距离最小；
2、某位置上 A、B、C 三个字符：
   - 三个相同：选它，距离 0；
   - 有两个相同：选出现最多的，距离 1；
   - 三个都不同：任选一个，距离 2；
3、逐位累加最小距离，输出总和。
*/
string A, B, C;

int main() {
    cin >> A >> B >> C;
    int n = A.size();
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int cnt[26] = {0};
        cnt[A[i] - 'a']++;
        cnt[B[i] - 'a']++;
        cnt[C[i] - 'a']++;
        int mx = 0;
        for (int k = 0; k < 26; ++k) mx = max(mx, cnt[k]);
        ans += 3 - mx;                      // 距离 = 3 - 出现最多次数
    }
    printf("%lld\n", ans);
    return 0;
}
