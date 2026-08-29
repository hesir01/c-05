#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、稳定排序：按分数从小到大排，分数相同保持报名顺序（编号小在前）；
2、归并排序天然稳定：合并时左段元素 <= 右段元素才先取左段，
   相同分数时左段（编号小）先输出；
3、结构体存编号和分数，按分数排序；
4、main 输出排好序的选手编号。
*/
struct Player {
    int id, score;
} p[100005], tmp[100005];
int n;

// 归并排序（按分数升序，稳定）
void mergeSort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (p[i].score <= p[j].score) {     // 分数小的在前（相等取左段=稳定）
            tmp[k++] = p[i++];
        } else {
            tmp[k++] = p[j++];
        }
    }
    while (i <= mid) tmp[k++] = p[i++];
    while (j <= r) tmp[k++] = p[j++];
    for (int t = l; t <= r; ++t) p[t] = tmp[t];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        p[i].id = i;                        // 报名顺序编号
        scanf("%d", &p[i].score);
    }
    mergeSort(1, n);
    for (int i = 1; i <= n; ++i) printf("%d ", p[i].id);
    printf("\n");
    return 0;
}
