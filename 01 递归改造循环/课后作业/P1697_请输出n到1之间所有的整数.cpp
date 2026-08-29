#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、递归函数 print(i)：输出 i，再递归输出 i - 1；
2、递归出口：当 i < 1 时不再输出，返回；
3、main 读入 n，调用 print(n)，依次输出 n, n-1, ..., 1。
*/
int n;

// 递归输出从 i 到 1 的所有整数
void print(int i) {
    if (i < 1) return;          // 出口：超出范围
    cout << i << endl;
    print(i - 1);               // 递归：继续输出前一个
}

int main() {
    cin >> n;
    print(n);
    return 0;
}
