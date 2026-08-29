#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、尾插法：每读入一个数，创建新节点插到链表尾部；
   维护 tail 尾指针，保证每次插入 O(1)；
2、因此链表从头到尾的输出顺序与输入顺序相同；
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
    Node *head = nullptr, *tail = nullptr;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        Node* p = new Node(x);
        if (head == nullptr) {
            head = tail = p;                // 空表：新节点既是头也是尾
        } else {
            tail->next = p;                 // 接到尾部
            tail = p;
        }
    }
    for (Node* p = head; p; p = p->next) {
        printf("%d ", p->val);              // 与输入顺序相同
    }
    printf("\n");
    return 0;
}
