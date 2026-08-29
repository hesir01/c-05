#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、多次询问区间 [L, R]（<= 10^6）内的素数个数和最大素数；
2、预处理：埃氏筛求 10^6 内素数，
   前缀和 cnt[i] 记录 1~i 的素数个数，
   lastPrime[i] 记录 1~i 内最后一个素数；
3、每次询问：素数个数 = cnt[R] - cnt[L-1]，
   最大素数 = 第一个 <= R 的素数（lastPrime[R]），
   若 < L 则区间内没有素数，输出 0；
4、main 处理 q 次询问。
*/
int q;
bool isPrime[1000005];
int cnt[1000005], lastPrime[1000005];

int main() {
    cin >> q;
    // 埃氏筛
    fill(isPrime, isPrime + 1000001, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 1000000; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 1000000; j += i) isPrime[j] = false;
        }
    }
    // 前缀和 + 最后一个素数
    for (int i = 1; i <= 1000000; ++i) {
        cnt[i] = cnt[i - 1] + (isPrime[i] ? 1 : 0);
        if (isPrime[i]) lastPrime[i] = i;
        else lastPrime[i] = lastPrime[i - 1];
    }
    while (q--) {
        int L, R;
        cin >> L >> R;
        int num = cnt[R] - cnt[L - 1];      // 区间素数个数
        int mx = lastPrime[R];              // 1~R 内最大素数
        if (mx < L) mx = 0;                 // 最大素数不在区间内
        cout << num << ' ' << mx << endl;
    }
    return 0;
}
