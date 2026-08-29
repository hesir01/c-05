#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、螺旋方阵从外圈往内圈填：上边、右边、下边、左边各填一圈；
2、递归函数 fill(x, y, k, v)：
   以 (x,y) 为左上角、边长为 k 的方阵，从数值 v 开始填；
   填完当前外圈后，递归 fill(x+1, y+1, k-2, v+4*(k-1)) 填内圈；
   出口：k <= 0 时返回；
3、main 读入 n，调用 fill(1,1,n,1)，最后按场宽 3 输出方阵。
*/
int a[15][15], n;

// 递归填充以 (x,y) 为左上角、边长为 k 的螺旋圈
void fill(int x, int y, int k, int v) {
    if (k <= 0) return;                    // 出口：没有格子了
    if (k == 1) {                          // 边长 1：填中间一个
        a[x][y] = v;
        return;
    }
    // 上边：从左到右
    for (int i = 0; i < k; ++i) a[x][y + i] = v++;
    // 右边：从上到下
    for (int i = 1; i < k; ++i) a[x + i][y + k - 1] = v++;
    // 下边：从右到左
    for (int i = k - 2; i >= 0; --i) a[x + k - 1][y + i] = v++;
    // 左边：从下到上
    for (int i = k - 2; i >= 1; --i) a[x + i][y] = v++;
    // 递归填内圈
    fill(x + 1, y + 1, k - 2, v);
}

int main() {
    cin >> n;
    fill(1, 1, n, 1);
    // 按场宽 3 输出
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
