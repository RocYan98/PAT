#include <iostream>
#include <string>

using namespace std;
struct Node {
    string data;
    int lchild, rchild;
} nodes[21];
int is_root[21];

int root = 1;
void in_order(int rt) {
    if (rt == -1) return;
    bool is_leaf = nodes[rt].lchild == -1 && nodes[rt].rchild == -1;
    if (rt != root && !is_leaf) printf("(");
    in_order(nodes[rt].lchild);
    printf("%s", nodes[rt].data.c_str());
    in_order(nodes[rt].rchild);
    if (rt != root && !is_leaf) printf(")");
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        cin >> nodes[i].data;
        scanf("%d%d", &nodes[i].lchild, &nodes[i].rchild);
        if (nodes[i].lchild != -1) is_root[nodes[i].lchild] = 1;
        if (nodes[i].rchild != -1) is_root[nodes[i].rchild] = 1;
    }
    while (is_root[root]) root++;
    in_order(root);
    return 0;
}
