#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、读入整数 X（2 <= X <= 10）；
2、递归函数 findN(k)：s 是 1+1/2+...+1/k 的当前和，逐步累加；
   先把 1.0/k 累加进 s；
   若 s > X，出口，返回 k（找到答案）；
   否则递归 findN(k + 1) 继续加下一项；
3、main 读入 X，s 置 0，输出 findN(1)。
注意：1/k 是整除，必须写成 1.0/k 才能得到小数。
*/
int X;
double s;

// 递归求第一个使 1+1/2+...+1/k > X 的 k
int findN(int k) {
    s += 1.0 / k;               // 累加当前项
    if (s > X) return k;        // 出口：总和已经大于 X
    return findN(k + 1);        // 递归加下一项
}

int main() {
    cin >> X;
    s = 0;
    cout << findN(1) << endl;
    return 0;
}
