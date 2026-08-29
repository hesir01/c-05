#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、递归函数 rev(x)：输出 x 的反序；
   出口：x < 10 时直接输出 x；
   否则先输出个位 x%10，再递归 rev(x/10) 输出剩余部分；
2、main 读入 n，调用 rev(n)。
注意：n 可能为 0，rev(0) 直接输出 0。
*/
long long n;

// 递归输出 x 的反序
void rev(long long x) {
    if (x < 10) {              // 出口：只剩一位
        cout << x;
        return;
    }
    cout << x % 10;            // 先输出个位
    rev(x / 10);               // 再递归输出剩余高位
}

int main() {
    cin >> n;
    rev(n);
    cout << endl;
    return 0;
}
