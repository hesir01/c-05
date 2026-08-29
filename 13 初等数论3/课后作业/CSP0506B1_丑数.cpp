#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、丑数：质因子只有 2、3、5 的数（1 也是丑数）；
2、用三指针法：三个指针 p2、p3、p5 分别指向"下一个乘以 2/3/5 的候选"，
   每次取三个候选中最小者作为下一个丑数，相应指针前进（去重）；
3、main 输出第 n 个丑数。
*/
int n;
long long ugly[10005];

int main() {
    cin >> n;
    ugly[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; ++i) {
        long long a = ugly[p2] * 2;
        long long b = ugly[p3] * 3;
        long long c = ugly[p5] * 5;
        long long mn = min(a, min(b, c));
        ugly[i] = mn;
        // 去重：所有等于 mn 的候选都前进
        if (mn == a) p2++;
        if (mn == b) p3++;
        if (mn == c) p5++;
    }
    cout << ugly[n] << endl;
    return 0;
}
