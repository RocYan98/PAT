#include <iostream>

using namespace std;
struct Node {
    int lchild, rchild;
} nodes[30];
int n;
int is_root[30];

int last_node, last_idx = 1;
void DFS(int root, int idx) {
    if (idx > last_idx) {
        last_idx = idx;
        last_node = root;
    }
    if (nodes[root].lchild != -1) DFS(nodes[root].lchild, idx * 2);
    if (nodes[root].rchild != -1) DFS(nodes[root].rchild, idx * 2 + 1);
}

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        string l, r;
        cin >> l >> r;
        nodes[i].lchild = l == "-" ? -1 : stoi(l);
        nodes[i].rchild = r == "-" ? -1 : stoi(r);
        if (nodes[i].lchild != -1) is_root[nodes[i].lchild] = 1;
        if (nodes[i].rchild != -1) is_root[nodes[i].rchild] = 1;
    }
    int root = 0;
    while (is_root[root]) root++;

    DFS(root, 1);
    last_idx == n ? printf("YES %d", last_node) : printf("NO %d", root);

    return 0;
}
