#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、先线性筛预处理 1~n 的最小质因子 SPF 数组：
   每个合数只被它的最小质因子筛掉一次，spf[i] 记录 i 的最小质因子；
2、分解：不断取 x 的 spf[x]（记为 p），统计指数 e，直到 x 变为 1；
3、按质因子从小到大输出 "p e"（指数为 1 也输出 e）；
4、main 读入 n，输出质因数分解结果。
注意：n 最大 10^6，spf 数组开 10^6+5。
*/
int n, spf[1000005];

// 线性筛预处理最小质因子
void build_spf(int m) {
    for (int i = 2; i <= m; ++i) {
        if (spf[i] == 0) {                  // i 是质数
            for (int j = i; j <= m; j += i) {
                if (spf[j] == 0) spf[j] = i; // 记录 j 的最小质因子
            }
        }
    }
}

int main() {
    cin >> n;
    build_spf(n);
    int x = n;
    // 不断取最小质因子分解
    while (x > 1) {
        int p = spf[x], e = 0;
        while (x % p == 0) {
            x /= p;
            e++;
        }
        cout << p << ' ' << e << endl;
    }
    return 0;
}
