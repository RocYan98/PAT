#include <iostream>

using namespace std;
struct Node {
    int data;
    Node *lchild, *rchild;
};
int pre[40], post[40];

int unique = 1;
Node* create(int preL, int preR, int postL, int postR) {
    if (preL > preR) return NULL;
    Node* root = new Node;
    root->data = pre[preL];
    root->lchild = root->rchild = NULL;
    if (preR - preL == 1) unique = 0;

    int i = preL + 1;
    while (i <= preR && pre[i] != post[postR - 1]) i++;

    int left_num = i - preL - 1;
    root->lchild = create(preL + 1, i - 1, postL, postL + left_num - 1);
    root->rchild = create(i, preR, postL + left_num, postR - 1);

    return root;
}

int num = 0;
void in_order(Node* root) {
    if (root == NULL) return;
    in_order(root->lchild);
    if (num) printf(" ");
    printf("%d", root->data);
    num++;
    in_order(root->rchild);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }
    Node *root = create(0, n - 1, 0, n - 1);
    printf("%s\n", unique ? "Yes" : "No");
    in_order(root);
    printf("\n");
    return 0;
}
