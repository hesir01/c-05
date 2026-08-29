#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、区间筛求 [l, r] 内质数个数，l 可达 10^12 但区间长度 <= 10^6；
2、先用普通埃氏筛筛出 sqrt(r) 以内的质数；
3、再用这些质数在区间 [l, r] 内标记合数（偏移数组）；
4、统计区间内没被标记的质数个数。
*/
long long l, r;
bool smallPrime[1000005];                   // sqrt(r) 内的质数标记
bool rangeComp[1000005];                    // 区间内合数标记（偏移）

int main() {
    cin >> l >> r;
    int lim = sqrt((double)r) + 1;
    // 筛出 sqrt(r) 内的质数
    fill(smallPrime, smallPrime + lim + 1, true);
    smallPrime[0] = smallPrime[1] = false;
    for (int i = 2; i * i <= lim; ++i) {
        if (smallPrime[i]) {
            for (int j = i * i; j <= lim; j += i) smallPrime[j] = false;
        }
    }
    // 用这些质数在区间内筛合数
    for (int p = 2; p <= lim; ++p) {
        if (!smallPrime[p]) continue;
        // 第一个 >= l 的 p 的倍数
        long long start = max(2LL * p, (l + p - 1) / p * p);
        for (long long j = start; j <= r; j += p) {
            rangeComp[j - l] = true;        // 偏移标记
        }
    }
    int cnt = 0;
    for (long long i = l; i <= r; ++i) {
        if (i < 2) continue;
        if (!rangeComp[i - l]) cnt++;       // 质数
    }
    cout << cnt << endl;
    return 0;
}
