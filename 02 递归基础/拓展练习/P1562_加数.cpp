#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、不断在右边拼接 n 的一半（整除），直到一半为 0；
2、递归函数 len(x)：返回"从 x 开始一直拼接到结束"的新数总位数；
   出口：x / 2 == 0 时，只拼 x 自己，返回 x 的位数；
   否则返回 x 的位数 + len(x / 2)；
3、位数用数字转字符串再取长度，或循环除以 10 统计。
验证：n=37 → 2位 + len(18)=2位 + len(9)=1位 + len(4)=1位 + len(2)=1位 + len(1)=1位 = 8。
*/
long long n;

// 求 x 有几位
int digits(long long x) {
    int c = 0;
    while (x > 0) {
        c++;
        x /= 10;
    }
    return c;
}

// 递归求拼接结束后的总位数
long long len(long long x) {
    if (x / 2 == 0) return digits(x);       // 出口：不能再拼接
    return digits(x) + len(x / 2);          // 自己的位数 + 拼接部分
}

int main() {
    cin >> n;
    cout << len(n) << endl;
    return 0;
}
