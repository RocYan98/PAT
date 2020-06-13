#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
struct Node {
    int data, lchild, rchild;
} nodes[110];
vector<int> ls;

int idx = 0;
void create(int root) {
    if (root == -1) return;
    create(nodes[root].lchild);
    nodes[root].data = ls[idx++];
    create(nodes[root].rchild);
}

void BFS(int root) {
    queue<int> q;
    q.push(root);
    while (q.size()) {
        int top = q.front();
        q.pop();
        if (nodes[top].lchild != -1) q.push(nodes[top].lchild);
        if (nodes[top].rchild != -1) q.push(nodes[top].rchild);
        printf("%d", nodes[top].data);
        if (q.size()) printf(" ");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &nodes[i].lchild, &nodes[i].rchild);
    }
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        ls.push_back(temp);
    }
    sort(ls.begin(), ls.end());

    create(0);
    BFS(0);
    return 0;
}
