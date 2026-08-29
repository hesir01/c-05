#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、集合 M：k 是元素，且 y 是元素则 2y+1、3y+1 都是元素；
2、判断 x 是否在 M 中，从 x 反向推：
   - 若 x == k：是（出口）；
   - 若 x < k：不是（集合只会增大，出口）；
   - 若 x 由某个 y 生成，则 (x-1) 必须能被 2 或 3 整除：
     尝试 (x-1)/2 或 (x-1)/3，递归判断它们是否在 M 中；
3、递归函数 check(x)：返回 x 是否属于 M。
注意：输入格式是 "k,x" 逗号间隔。
*/
long long k, x;

// 递归判断 x 是否是集合 M 的元素
bool check(long long x) {
    if (x == k) return true;                // 出口：就是初始元素
    if (x < k) return false;                // 出口：比初始元素还小，不可能在集合中
    // 尝试反向：(x-1)/2 或 (x-1)/3
    if ((x - 1) % 2 == 0 && check((x - 1) / 2)) return true;
    if ((x - 1) % 3 == 0 && check((x - 1) / 3)) return true;
    return false;
}

int main() {
    char c;
    cin >> k >> c >> x;                     // 读入 "k,x"
    cout << (check(x) ? "YES" : "NO") << endl;
    return 0;
}
