#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、阿克曼函数递归定义：
   akm(0,n) = n+1；
   akm(m,0) = akm(m-1,1)；
   akm(m,n) = akm(m-1, akm(m,n-1))；
2、递归函数 akm(m,n)：按公式直接翻译；
   三个分支分别对应三种情况；
3、main 读入 m、n，输出 akm(m,n)。
*/
long long m, n;

// 递归求阿克曼函数 A(m,n)
long long akm(long long a, long long b) {
    if (a == 0) return b + 1;                     // akm(0,n) = n+1
    if (b == 0) return akm(a - 1, 1);             // akm(m,0) = akm(m-1,1)
    return akm(a - 1, akm(a, b - 1));             // 一般情况嵌套递归
}

int main() {
    cin >> m >> n;
    cout << akm(m, n) << endl;
    return 0;
}
