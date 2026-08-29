#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、数根：不断把各位数字相加，直到变成一位数；
2、递归函数 digitSum(x)：求 x 的各位数字之和；
   出口：x == 0 时返回 0；否则返回 x%10 + digitSum(x/10)；
3、递归函数 root(x)：求 x 的数根；
   出口：x < 10 时返回 x（已经是一位数）；
   否则返回 root(digitSum(x))，继续求和；
4、main 读入 n，输出 root(n)。
*/
long long n;

// 递归求各位数字之和
long long digitSum(long long x) {
    if (x == 0) return 0;                 // 出口
    return x % 10 + digitSum(x / 10);     // 个位 + 剩余位之和
}

// 递归求数根
long long root(long long x) {
    if (x < 10) return x;                 // 出口：已是一位数
    return root(digitSum(x));             // 继续对各位和求数根
}

int main() {
    cin >> n;
    cout << root(n) << endl;
    return 0;
}
