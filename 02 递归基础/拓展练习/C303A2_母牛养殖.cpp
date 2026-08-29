#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、母牛每年年初生一头小母牛，小母牛第 4 年开始生：
   第 n 年的牛数 = 去年的牛数 + 今年新出生的小牛数；
   新出生的小牛数 = 3 年前就存在的母牛数 = f(n-3)；
   所以 f(n) = f(n-1) + f(n-3)；
2、递归出口：n<=3 时，f(1)=1，f(2)=2，f(3)=3（还没有小牛到 4 岁）；
3、main 读入 n，输出 f(n)。
验证：f(5) = f(4)+f(2) = 4+2 = 6，符合样例。
*/
long long n;

// 递归求第 n 年的母牛总数
long long cow(long long x) {
    if (x == 1) return 1;               // 第一年 1 头
    if (x == 2) return 2;               // 第二年 2 头
    if (x == 3) return 3;               // 第三年 3 头
    return cow(x - 1) + cow(x - 3);     // 去年总数 + 三年前出生的牛开始生
}

int main() {
    cin >> n;
    cout << cow(n) << endl;
    return 0;
}
