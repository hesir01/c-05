#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、约瑟夫问题：n 个人围一圈，每数到 k 淘汰一人；
2、n 最大 10^6，链表模拟 O(nk) 会超时，用数学递推：
   f(i) 表示 i 个人时最后幸存者的编号（0-indexed）：
   f(1) = 0，f(i) = (f(i-1) + k) % i；
3、递推循环从 1 到 n，最后输出 f(n) + 1（转 1-indexed）。
验证：5 3 → f: 0,1,1,0,3 → 答案 4。
*/
int n, k;

int main() {
    scanf("%d%d", &n, &k);
    int f = 0;                              // 1 个人时幸存者编号 0
    for (int i = 2; i <= n; ++i) {
        f = (f + k) % i;                    // 递推公式
    }
    printf("%d\n", f + 1);
    return 0;
}
