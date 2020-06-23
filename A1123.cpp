#include <iostream>
#include <queue>

using namespace std;
struct Node {
    int data, id;
    Node *lchild, *rchild;
};

int get_height(Node *root) {
    if (root == NULL) return 1;
    return max(get_height(root->lchild), get_height(root->rchild)) + 1;
}

void L(Node *&root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    root = temp;
}

void R(Node *&root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    root = temp;
}

void create(int data, Node *&root) {
    if (root == NULL) {
        root = new Node;
        root->data = data;
        root->lchild = root->rchild = NULL;
        return;
    }
    if (data < root->data) {
        create(data, root->lchild);
        if (get_height(root->lchild) - get_height(root->rchild) == 2) {
            if (get_height(root->lchild->lchild) - get_height(root->lchild->rchild) == 1) {
                R(root);
            } else {
                L(root->lchild);
                R(root);
            }
        }
    } else {
        create(data, root->rchild);
        if (get_height((root->lchild)) - get_height(root->rchild) == -2) {
            if (get_height(root->rchild->lchild) - get_height(root->rchild->rchild) == -1) {
                L(root);
            } else {
                R(root->rchild);
                L(root);
            }
        }
    }
}

int max_id = -1;
void level_order(Node* root) {
    queue<Node*> q;
    q.push(root);
    while (q.size()) {
        Node* top = q.front();
        if (top->id > max_id) max_id = top->id;
        q.pop();
        if (top->lchild != NULL) {
            top->lchild->id = top->id * 2;
            q.push(top->lchild);
        }
        if (top->rchild != NULL) {
            top->rchild->id = top->id * 2 + 1;
            q.push(top->rchild);
        }
        printf("%d", top->data);
        if (q.size()) printf(" ");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Node *root = NULL;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        create(num, root);
    }
    root->id = 1;
    level_order(root);
    printf("\n%s", max_id == n ? "YES" : "NO");
    return 0;
}
