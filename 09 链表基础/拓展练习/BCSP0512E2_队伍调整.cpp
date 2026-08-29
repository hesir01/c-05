#include <bits/stdc++.h>
using namespace std;
/*
思路：
1、尾插法建立队伍链表；
2、先把整支队伍反转（三指针原地反转）；
3、执行 q 次删除：删除反转后队伍中第一个编号为 v 的人（若存在）；
4、输出最终队伍；队伍为空输出 empty。
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
        int v;
        scanf("%d", &v);
        Node* p = new Node(v);
        if (head == nullptr) head = tail = p;
        else { tail->next = p; tail = p; }
    }
    // 反转队伍
    Node *prev = nullptr, *cur = head;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;
    tail = nullptr;                         // 尾指针由后续删除维护
    // 执行删除操作
    scanf("%d", &q);
    while (q--) {
        int v;
        scanf("%d", &v);
        Node *p = nullptr, *c = head;
        while (c && c->val != v) {
            p = c;
            c = c->next;
        }
        if (c == nullptr) continue;         // 不存在
        if (p == nullptr) head = c->next;   // 删头节点
        else p->next = c->next;
        delete c;
    }
    if (head == nullptr) {
        puts("empty");
    } else {
        for (Node* p = head; p; p = p->next) printf("%d ", p->val);
        printf("\n");
    }
    return 0;
}
