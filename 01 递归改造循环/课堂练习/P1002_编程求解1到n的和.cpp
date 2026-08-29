#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、递归函数 sum(i)：求 1+2+...+i 的值；
2、递归出口：当 i == 1 时，返回 1；
3、一般情况：sum(i) = i + sum(i - 1)，即"当前项 + 前面所有项的和"；
4、main 读入 n，输出 sum(n)。
*/
int n;

// 递归求 1+2+...+i 的和
int sum(int i) {
    if (i == 1) return 1;        // 出口：只有一项 1
    return i + sum(i - 1);       // 当前项 + 前面各项之和
}

int main() {
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}
