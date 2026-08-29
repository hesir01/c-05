#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、统计 a 和 b 的正因数个数，比较多者输出；
2、因数个数：枚举 1 到 sqrt(x)，成对统计；
3、main 输出 a、b 或 equal。
验证：8(因数1,2,4,8=4个) vs 12(1,2,3,4,6,12=6个) → b。
*/
long long a, b;

// 求 x 的正因数个数
long long countDiv(long long x) {
    long long cnt = 0;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            cnt++;
            if (i * i != x) cnt++;          // 成对的另一个因数
        }
    }
    return cnt;
}

int main() {
    cin >> a >> b;
    long long ca = countDiv(a), cb = countDiv(b);
    if (ca > cb) cout << 'a' << endl;
    else if (ca < cb) cout << 'b' << endl;
    else cout << "equal" << endl;
    return 0;
}
