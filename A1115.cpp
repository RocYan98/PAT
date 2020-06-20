#include <iostream>

using namespace std;
struct Node {
    int data;
    Node *lchild, *rchild;
};
int level[1010];

int max_level = -1;
void create(int data, Node* &root, int depth) {
    if (root == NULL) {
        root = new Node;
        root->data = data;
        if (depth > max_level) max_level = depth;
        level[depth]++;
        root->lchild = root->rchild = NULL;
        return;
    }
    create(data, data <= root->data ? root->lchild : root->rchild, depth + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    Node* root = NULL;
    for (int i = 0; i < n; ++i) {
        int data;
        scanf("%d", &data);
        create(data, root, 1);
    }
    printf("%d + %d = %d", level[max_level], level[max_level - 1], level[max_level] + level[max_level - 1]);
    return 0;
}
