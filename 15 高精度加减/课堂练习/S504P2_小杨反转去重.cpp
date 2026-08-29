#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、第一行：反转整个名单输出；
2、第二行：反转后从左到右去重（每个编号只保留第一次出现）；
3、用 map 或 set 记录已出现的编号；
4、main 输出两行结果。
*/
int n;
vector<int> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    // 反转
    reverse(v.begin(), v.end());
    // 输出反转后的完整名单
    for (int x : v) cout << x << ' ';
    cout << endl;
    // 去重（保留第一次出现）
    set<int> seen;
    for (int x : v) {
        if (!seen.count(x)) {
            cout << x << ' ';
            seen.insert(x);
        }
    }
    cout << endl;
    return 0;
}
