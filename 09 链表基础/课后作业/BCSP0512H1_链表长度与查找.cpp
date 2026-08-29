#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、尾插法建立单链表；
2、处理 q 次查询：
   - 1：遍历链表统计节点个数输出；
   - 2 v：遍历找值第一次出现的位置（1-indexed），不存在输出 -1；
3、每行输出一个查询结果。
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
        int op;
        scanf("%d", &op);
        if (op == 1) {                      // 输出链表长度
            int len = 0;
            for (Node* p = head; p; p = p->next) len++;
            printf("%d\n", len);
        } else {                            // 查找 v 第一次出现位置
            int v;
            scanf("%d", &v);
            int pos = 0;
            Node* p = head;
            while (p && p->val != v) {
                p = p->next;
                pos++;
            }
            if (p) printf("%d\n", pos + 1); // 1-indexed
            else puts("-1");
        }
    }
    return 0;
}
