#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、删数问题：从左到右扫描，如果当前数字比它右边的数字大，
   删掉它能让结果更小（贪心）；
2、用字符串模拟栈：把数字依次压栈，
   若栈顶数字 > 当前数字且还有删除名额，就弹出栈顶（删掉）；
3、最后若还有剩余删除名额，从末尾删；
4、输出剩下的数字（去掉前导 0）。
验证：153748 删 2 个 → 依次处理得到 1348。
*/
string s;
int k;

int main() {
    cin >> s >> k;
    string st;                              // 用字符串当栈
    for (char c : s) {
        // 栈顶比当前数字大且还有删除名额，弹出（删除）
        while (!st.empty() && k > 0 && st.back() > c) {
            st.pop_back();
            k--;
        }
        st.push_back(c);
    }
    // 还有剩余删除名额，从末尾删
    while (k > 0) {
        st.pop_back();
        k--;
    }
    // 去掉前导 0（题目保证结果非 0，所以至少保留一位）
    int i = 0;
    while (i + 1 < (int)st.size() && st[i] == '0') i++;
    cout << st.substr(i) << endl;
    return 0;
}
