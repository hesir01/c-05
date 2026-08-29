#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、每次查询 x：手写循环找 x 第一次出现的位置（1-based，不存在输出 0）
   并统计出现次数；
2、不使用 find/count 库函数，全部手写循环；
3、main 输出每次查询的两个结果。
*/
int n, q;
vector<int> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int firstPos = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] == x) {
                if (firstPos == 0) firstPos = i + 1;  // 第一次出现位置
                cnt++;                                // 计数
            }
        }
        cout << firstPos << ' ' << cnt << endl;
    }
    return 0;
}
