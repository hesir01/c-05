#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、头插法：每读入一个数，创建新节点插入链表头部（新节点成为新的头）；
2、因此链表从头到尾的输出顺序与输入顺序相反；
3、遍历链表输出每个节点的值。
*/
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};
int n, x;

int main() {
    scanf("%d", &n);
    Node* head = nullptr;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        Node* p = new Node(x);
        p->next = head;                     // 新节点插到头部
        head = p;
    }
    for (Node* p = head; p; p = p->next) {
        printf("%d ", p->val);              // 从头到尾输出（与输入相反）
    }
    printf("\n");
    return 0;
}
