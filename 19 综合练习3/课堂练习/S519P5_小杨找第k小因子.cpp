#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、求 n 的第 k 小因子（n <= 10^9，k <= 1400）；
2、枚举 1 到 sqrt(n)，找到成对因子 i 和 n/i；
   把较小的一半和较大的一半分别收集，合并排序；
3、若因子总数 < k，输出 -1；
4、main 输出第 k 小因子。
验证：12 3 → 因子 1,2,3,4,6,12，第 3 个是 3。
*/
long long n, k;

int main() {
    cin >> n >> k;
    vector<long long> small, big;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            small.push_back(i);
            if (i * i != n) big.push_back(n / i);
        }
    }
    if ((long long)small.size() + big.size() < k) {
        cout << -1 << endl;
        return 0;
    }
    // 排序：small 已升序，big 反转后接上
    sort(big.rbegin(), big.rend());         // big 反转升序
    long long ans;
    if (k <= (long long)small.size()) {
        ans = small[k - 1];
    } else {
        ans = big[k - small.size() - 1];
    }
    cout << ans << endl;
    return 0;
}
