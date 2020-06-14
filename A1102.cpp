#include <iostream>
#include <queue>

using namespace std;
struct Node {
    int lchild, rchild;
} nodes[10];
int is_root[10];

void level_order(int root) {
    queue<int> q;
    q.push(root);
    while (q.size()) {
        int top = q.front();
        q.pop();
        if (nodes[top].lchild != -1) q.push(nodes[top].lchild);
        if (nodes[top].rchild != -1) q.push(nodes[top].rchild);
        printf("%d", top);
        if (q.size()) printf(" ");
    }
    printf("\n");
}

int count = 0;
void in_order(int root) {
    if (root == -1) return;
    in_order(nodes[root].lchild);
    if (count) printf(" ");
    count++;
    printf("%d", root);
    in_order(nodes[root].rchild);
}

int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        char l, r;
        scanf("%c %c", &l, &r);
        getchar();
        nodes[i].rchild = l == '-' ? -1 : l - '0';
        nodes[i].lchild = r == '-' ? -1 : r - '0';
        if (nodes[i].rchild != -1) is_root[nodes[i].rchild] = 1;
        if (nodes[i].lchild != -1) is_root[nodes[i].lchild] = 1;
    }

    int root = 0;
    while (is_root[root]) root++;
    level_order(root);
    in_order(root);
    return 0;
}
