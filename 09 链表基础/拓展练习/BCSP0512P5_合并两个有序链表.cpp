#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、分别用尾插法建立两条升序单链表；
2、合并两条升序链表（类似归并的 merge）：
   双指针 p1、p2 比较当前节点值，小的接在新链表尾部；
   一条链结束后把另一条剩余部分全部接上；
3、遍历输出合并后的升序链表。
*/
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};
int n, m;

// 尾插法建表
Node* build(int len) {
    Node *head = nullptr, *tail = nullptr;
    for (int i = 1; i <= len; ++i) {
        int x;
        scanf("%d", &x);
        Node* p = new Node(x);
        if (head == nullptr) head = tail = p;
        else { tail->next = p; tail = p; }
    }
    return head;
}

int main() {
    scanf("%d", &n);
    Node* h1 = build(n);
    scanf("%d", &m);
    Node* h2 = build(m);
    // 合并两条升序链表
    Node dummy(0);
    Node* tail = &dummy;
    Node *p1 = h1, *p2 = h2;
    while (p1 && p2) {
        if (p1->val <= p2->val) {
            tail->next = p1;
            p1 = p1->next;
        } else {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }
    tail->next = (p1 ? p1 : p2);            // 接上剩余部分
    for (Node* p = dummy.next; p; p = p->next) printf("%d ", p->val);
    printf("\n");
    return 0;
}
