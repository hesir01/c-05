#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、用 vector 存名单，模拟四种操作：
   1 x：末尾追加（push_back）；
   2：删除末尾（pop_back）；
   3 k：删除第 k 个（erase，注意 k 从 1 开始）；
   4 k x：在第 k 个位置前插入 x（insert）；
2、执行完所有指令后输出名单。
*/
int n, m;
vector<int> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            v.push_back(x);
        } else if (op == 2) {
            v.pop_back();
        } else if (op == 3) {
            int k;
            cin >> k;
            v.erase(v.begin() + k - 1);     // 第 k 个（1-based）
        } else {
            int k, x;
            cin >> k >> x;
            v.insert(v.begin() + k - 1, x); // 第 k 个位置前插入
        }
    }
    for (int x : v) cout << x << ' ';
    cout << endl;
    return 0;
}
