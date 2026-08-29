#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、尾插法建立单链表；
2、反转链表：用三个指针 prev、cur、next 原地反转，
   每次让 cur->next 指向 prev，三个指针依次后移；
3、遍历输出反转后的链表。
*/
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};
int n;

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
    // 反转链表
    Node *prev = nullptr, *cur = head;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;                   // 指向前一个
        prev = cur;
        cur = nxt;
    }
    head = prev;                            // 新头是原尾
    for (Node* p = head; p; p = p->next) printf("%d ", p->val);
    printf("\n");
    return 0;
}
