#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};
int n, times;

Node* create() {
    if (times == 2 * n) return NULL;
    string opt;
    cin >> opt;
    times++;
    Node* root = NULL;
    if (opt == "Push") {
        int data;
        scanf("%d", &data);
        root = new Node;
        root->data = data;
        root->lchild = root->rchild = NULL;
        root->lchild = create();
        root->rchild = create();
    }
    return root;
}

Node* root;
void postorder(Node* node) {
    if (node == NULL) return;
    postorder(node->lchild);
    postorder(node->rchild);
    printf("%d", node->data);
    if (node != root) printf(" ");
}

int main() {
    scanf("%d", &n);
    root = create();
    postorder(root);
    return 0;
}
