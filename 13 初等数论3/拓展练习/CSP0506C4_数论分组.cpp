#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、数论分组：每组内任意两数 gcd > 1（两两不互质），求最少组数；
2、n <= 100，用贪心：把每个数尝试加入已有组（与组内所有数 gcd>1），
   放不进去就新建一组；
3、递归函数 gcd(a,b)：欧几里得算法；
4、main 输出最少分组数。
验证：2 3 4 6 9 → [2,4,6] 和 [3,9] 共 2 组。
*/
int n, a[105];
vector<vector<int>> groups;

// 递归求最大公约数
long long gcd(long long x, long long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

// 检查 x 能否加入组 g（与组内所有数都 gcd>1）
bool canJoin(vector<int>& g, int x) {
    for (int v : g) {
        if (gcd(v, x) == 1) return false;   // 有互质的，不能同组
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        bool placed = false;
        for (auto &g : groups) {
            if (canJoin(g, a[i])) {
                g.push_back(a[i]);          // 加入已有组
                placed = true;
                break;
            }
        }
        if (!placed) {
            groups.push_back({a[i]});       // 新建一组
        }
    }
    cout << groups.size() << endl;
    return 0;
}
