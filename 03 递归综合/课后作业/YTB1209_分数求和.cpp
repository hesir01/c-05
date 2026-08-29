#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、读入 n 个分数 p/q，累加求和；
2、递归函数 gcd(a,b)：欧几里得算法求最大公约数，用于化简；
3、累加方法：分子分母通分相加，每次加完约分，防止溢出；
   当前和 fz/fm，加 p/q：fz = fz*q + p*fm，fm = fm*q，再约分；
4、输出最简形式：若分母为 1 直接输出整数，否则输出 fz/fm。
注意：分子分母不为 0、不为负；用 long long。
*/
int n;
long long fz, fm;

// 递归求最大公约数
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin >> n;
    // 先读第一个分数作为初始值
    char c;
    cin >> fz >> c >> fm;
    // 逐个读入剩余分数并累加
    for (int i = 2; i <= n; ++i) {
        long long p, q;
        cin >> p >> c >> q;
        fz = fz * q + p * fm;       // 通分后分子相加
        fm = fm * q;                // 新分母
        long long g = gcd(fz, fm);  // 约分
        fz /= g;
        fm /= g;
    }
    // 输出最简形式
    if (fm == 1) {
        cout << fz << endl;         // 分母为 1 输出整数
    } else {
        cout << fz << "/" << fm << endl;
    }
    return 0;
}
