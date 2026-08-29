#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、第十天早上只剩 1 个桃子；
2、每天吃前一天剩下的一半再多一个，逆推公式：
   前一天剩下的 = (当天剩下的 + 1) * 2；
3、递归函数 peach(day)：返回第 day 天早上的桃子数；
   出口：day == 10 时返回 1；
   否则返回 (peach(day + 1) + 1) * 2；
4、main 输出 peach(1)，即第一天摘的桃子总数。
*/
// 递归求第 day 天早上的桃子数
long long peach(int day) {
    if (day == 10) return 1;                    // 出口：第十天剩 1 个
    return (peach(day + 1) + 1) * 2;            // 逆推前一天的数量
}

int main() {
    cout << peach(1) << endl;
    return 0;
}
