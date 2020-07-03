#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Node {
    int data;
    Node *lchild, *rchild;
};
int in[30], post[30];
vector<int> depth[30];

Node* create(int inL, int postL, int postR) {
    if (postL > postR) return NULL;
    Node* root = new Node;
    root->data = post[postR];
    root->lchild = root->rchild = NULL;

    int i = inL;
    while (in[i] != post[postR]) i++;
    int left_num = i - inL;
    root->lchild = create(inL, postL, postL + left_num - 1);
    root->rchild = create(i + 1, postL + left_num, postR - 1);
    return root;
}

void DFS(Node* root, int d) {
    if (root == NULL) return;
    depth[d].push_back(root->data);
    DFS(root->lchild, d + 1);
    DFS(root->rchild, d + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }
    Node* root = create(0, 0, n - 1);
    DFS(root, 0);
    printf("%d", depth[0][0]);
    for (int i = 1; i < n; ++i) {
        if (i % 2 == 0) reverse(depth[i].begin(), depth[i].end());
        for (auto ite = depth[i].begin(); ite != depth[i].end(); ++ite) {
            printf(" %d", *ite);
        }
    }
    return 0;
}
