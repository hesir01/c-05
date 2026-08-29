#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、二分答案"最大承受伤害 X"：X 越大越容易通过；
2、check(X)：从第 1 行任意房间出发 BFS，只走伤害值 <= X 的房间，
   若能到达第 n 行任意房间则可行；
3、递归二分框架：在 [0, 1000] 中找满足 check 的最小 X；
4、输出最小伤害代价。
注意：第 1 行和第 n 行伤害为 0；用队列 BFS，避免走回头。
*/
int n, m, a[1005][1005], vis[1005][1005];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

// 检查最大伤害 X 时能否从第 1 行走到第 n 行
bool check(int X) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    // 第 1 行所有房间都可作为入口
    for (int j = 1; j <= m; ++j) {
        if (a[1][j] <= X) {
            vis[1][j] = 1;
            q.push({1, j});
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == n) return true;            // 到达第 n 行
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (!vis[nx][ny] && a[nx][ny] <= X) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    int lo = 0, hi = 1000, ans = 1000;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {                   // 可行，尝试更小
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
