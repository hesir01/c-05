#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、维护单链表，支持两种操作：
   1 v：尾插 v；
   2 k v：把 v 插入到第 k 个节点之后（k=0 表示插入表头）；
2、实现：
   - 尾插：维护 tail 指针；
   - 按位置插入：走 k 步找到第 k 个节点，把新节点插在其后；
     若 k=0，新节点成为新的头节点；
3、最后从头到尾遍历输出。
*/
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};
int m;

int main() {
    scanf("%d", &m);
    Node *head = nullptr, *tail = nullptr;
    while (m--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {                      // 尾插
            int v;
            scanf("%d", &v);
            Node* p = new Node(v);
            if (head == nullptr) head = tail = p;
            else { tail->next = p; tail = p; }
        } else {                            // 插入到第 k 个节点之后
            int k, v;
            scanf("%d%d", &k, &v);
            Node* p = new Node(v);
            if (k == 0) {                   // 插入表头
                p->next = head;
                head = p;
                if (tail == nullptr) tail = p;
            } else {
                Node* cur = head;
                for (int i = 1; i < k; ++i) cur = cur->next; // 走到第 k 个节点
                p->next = cur->next;        // 插到 cur 之后
                cur->next = p;
                if (cur == tail) tail = p;  // 更新尾指针
            }
        }
    }
    for (Node* p = head; p; p = p->next) printf("%d ", p->val);
    printf("\n");
    return 0;
}
