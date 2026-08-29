#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、维护队伍链表，支持加入队尾和插队（第 k 人之后，k=0 为队首）；
2、实现与"指定位置插入"相同：
   - 1 v：尾插；
   - 2 k v：走到第 k 个节点，把 v 插到其后；
3、输出最终队伍从前往后的编号。
*/
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};
int n, m;

int main() {
    scanf("%d", &n);
    Node *head = nullptr, *tail = nullptr;
    for (int i = 1; i <= n; ++i) {
        int v;
        scanf("%d", &v);
        Node* p = new Node(v);
        if (head == nullptr) head = tail = p;
        else { tail->next = p; tail = p; }
    }
    scanf("%d", &m);
    while (m--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {                      // 加入队尾
            int v;
            scanf("%d", &v);
            Node* p = new Node(v);
            tail->next = p;
            tail = p;
        } else {                            // 插到第 k 人之后
            int k, v;
            scanf("%d%d", &k, &v);
            Node* p = new Node(v);
            if (k == 0) {                   // 插到队首
                p->next = head;
                head = p;
            } else {
                Node* cur = head;
                for (int i = 1; i < k; ++i) cur = cur->next;
                p->next = cur->next;
                cur->next = p;
                if (cur == tail) tail = p;
            }
        }
    }
    for (Node* p = head; p; p = p->next) printf("%d ", p->val);
    printf("\n");
    return 0;
}
