#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、回文质数：既是质数又是回文数，范围 [a,b] <= 10^8；
2、偶数位数的回文数必能被 11 整除（除 11 本身），
   所以只生成奇数位的回文数再判断质数；
3、枚举回文数的前半部分，构造完整回文数，判断质数且在 [a,b] 内则输出；
4、按从小到大顺序输出。
*/
int a, b;

// 判断 x 是否为质数
bool isPrime(long long x) {
    if (x < 2) return false;
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

// 由前缀 pre 和长度 len 构造回文数
long long makePal(int pre, int len) {
    // 先构造前半部分的回文：如 pre=123, len=5 → 12321
    long long r = pre;
    long long pal = pre;
    if (len % 2 == 1) r /= 10;              // 奇数位：中间位不重复
    while (r > 0) {
        pal = pal * 10 + r % 10;
        r /= 10;
    }
    return pal;
}

int main() {
    cin >> a >> b;
    vector<long long> ans;
    // 特殊处理：唯一两位数的回文质数 11（偶数位回文数能被 11 整除，11 除外）
    if (a <= 11 && 11 <= b) ans.push_back(11);
    // 生成 1~8 位的奇数位回文数
    for (int len = 1; len <= 8; len += 2) {
        int half = (len + 1) / 2;           // 前半部分位数
        long long lo = pow(10, half - 1), hi = pow(10, half);
        if (len == 1) lo = 1;               // 1 位数允许 0 开头的前缀（即 1~9）
        for (long long pre = lo; pre < hi; ++pre) {
            long long pal = makePal(pre, len);
            if (pal < a || pal > b) continue;
            if (isPrime(pal)) ans.push_back(pal);
        }
    }
    sort(ans.begin(), ans.end());           // 从小到大输出
    for (long long x : ans) cout << x << endl;
    return 0;
}
