#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、递归函数 digitSum(x)：求 x 的各位数字之和；
   出口：x == 0 时返回 0；
   否则返回 x % 10 + digitSum(x / 10)；
2、递归函数 count(i)：统计 1~i 中满足条件的数的个数；
   出口：i == 0 时返回 0；
   若 i 的数位和既不能被 2 整除也不能被 5 整除，
   返回 1 + count(i - 1)，否则返回 count(i - 1)；
3、main 读入 n（n <= 9999），输出 count(n)。
*/
int n;

// 递归求 x 的各位数字之和
int digitSum(int x) {
    if (x == 0) return 0;                 // 出口
    return x % 10 + digitSum(x / 10);     // 个位 + 剩余位的和
}

// 递归统计 1~i 中满足条件的数的个数
int count(int i) {
    if (i == 0) return 0;                 // 出口
    int s = digitSum(i);
    if (s % 2 != 0 && s % 5 != 0) {
        return 1 + count(i - 1);          // i 本身满足条件
    }
    return count(i - 1);                  // i 不满足
}

int main() {
    cin >> n;
    cout << count(n) << endl;
    return 0;
}
