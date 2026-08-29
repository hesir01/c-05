#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、水仙花数：各位数字的立方和等于该数本身；
2、用百位 a、十位 b、个位 c 分别表示一个三位数的每一位；
3、枚举 100~999 的所有数，判断 a*a*a + b*b*b + c*c*c 是否等于 i；
4、满足条件就输出，自然是从小到大的顺序。
*/
int a, b, c;

int main() {
    // 枚举 100 到 999 的所有三位数
    for (int i = 100; i <= 999; ++i) {
        a = i / 100;        // 百位
        b = i / 10 % 10;    // 十位
        c = i % 10;         // 个位

        // 判断是否为水仙花数
        if (a * a * a + b * b * b + c * c * c == i) {
            cout << i << endl;
        }
    }

    return 0;
}
