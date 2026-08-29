#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、因数：能整除 n 的数；
2、枚举 1 到 sqrt(n)，找到成对的因数 i 和 n/i；
   注意 i*i == n 时只算一次；
3、按从小到大输出所有因数，再输出因数和、因数个数。
验证：10 → 因数 1 2 5 10，和 18，个数 4。
*/
int n;

int main() {
    cin >> n;
    vector<int> small, big;
    long long sum = 0;
    // 枚举到 sqrt(n)
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            small.push_back(i);
            if (i * i != n) big.push_back(n / i);  // 成对的另一半
        }
    }
    // 输出所有因数（小到大）
    for (int x : small) { cout << x << endl; sum += x; }
    for (int i = (int)big.size() - 1; i >= 0; --i) { cout << big[i] << endl; sum += big[i]; }
    cout << sum << endl;                    // 因数和
    cout << small.size() + big.size() << endl;  // 因数个数
    return 0;
}
