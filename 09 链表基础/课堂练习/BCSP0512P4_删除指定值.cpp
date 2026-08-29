#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、尾插法建立单链表；
2、对每次查询 v：删除链表中第一个值等于 v 的节点（若存在）；
   删除时需要记录前驱节点，注意删除头节点的特殊情况；
3、所有查询执行完，从头到尾输出链表；链表为空输出 empty。
*/
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};
int n, q;

int main() {
    scanf("%d", &n);
    Node *head = nullptr, *tail = nullptr;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        Node* p = new Node(x);
        if (head == nullptr) head = tail = p;
        else { tail->next = p; tail = p; }
    }
    scanf("%d", &q);
    while (q--) {
        int v;
        scanf("%d", &v);
        // 找第一个值等于 v 的节点并删除
        Node* prev = nullptr;
        Node* cur = head;
        while (cur && cur->val != v) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr) continue;       // 不存在，不操作
        if (prev == nullptr) head = cur->next;      // 删的是头节点
        else prev->next = cur->next;                // 跳过 cur
        if (cur == tail) tail = prev;               // 更新尾指针
        delete cur;
    }
    if (head == nullptr) {
        puts("empty");
    } else {
        for (Node* p = head; p; p = p->next) printf("%d ", p->val);
        printf("\n");
    }
    return 0;
}
