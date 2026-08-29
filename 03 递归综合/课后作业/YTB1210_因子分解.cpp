#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、用试除法从小到大分解 n：从 2 开始，能整除就记录并继续除；
2、每个质因子统计出现次数（指数）；
3、输出表达式：指数 > 1 时写 a^b，指数 == 1 时直接写 a，因子间用 * 连接；
4、n 本身 < 100，试除到 sqrt(n) 即可，剩余部分若 > 1 是最后一个质因子。
*/
int n, cnt[100];

int main() {
    cin >> n;
    int m = n;
    // 试除 2 到 sqrt(m)，统计每个质因子的指数
    for (int p = 2; p * p <= m; ++p) {
        while (m % p == 0) {
            cnt[p]++;
            m /= p;
        }
    }
    // 输出表达式
    bool first = true;
    for (int p = 2; p * p <= n; ++p) {
        if (cnt[p] > 0) {
            if (!first) cout << '*';
            first = false;
            if (cnt[p] > 1) cout << p << '^' << cnt[p];
            else cout << p;
        }
    }
    // 剩余的大质因子（大于 sqrt(n) 的部分）
    if (m > 1) {
        if (!first) cout << '*';
        cout << m;
    }
    cout << endl;
    return 0;
}
