#include <iostream>
#include <vector>

using namespace std;
struct Node {
    int data;
    Node *lchild, *rchild;
};

void create(Node* &root, int data) {
    if (root == NULL) {
        root = new Node;
        root->data = data;
        root->lchild = root->rchild = NULL;
        return;
    }
    if (abs(data) <= abs(root->data)) create(root->lchild, data);
    else create(root->rchild, data);
}

int flag, num;
vector<Node*> ans;
void DFS(Node* root) {
    if (!flag) return;
    if (root == NULL) {
        int temp = 0;
        for (auto node : ans) {
            if (node->data > 0) temp++;
        }
        if (num) {
            if (temp != num) flag = 0;
        } else num = temp;
        return;
    }
    if (root->data < 0) {
        if (root->lchild != NULL && root->lchild->data < 0) flag = 0;
        if (root->rchild != NULL && root->rchild->data < 0) flag = 0;
    }
    ans.push_back(root);
    DFS(root->lchild);
    DFS(root->rchild);
    ans.pop_back();
}

int main() {
    int k, n;
    scanf("%d", &k);
    while (k--) {
        flag = 1, num = 0;
        scanf("%d", &n);
        Node *root = NULL;
        for (int i = 0; i < n; ++i) {
            int data;
            scanf("%d", &data);
            create(root, data);
        }
        if (root->data < 0) flag = 0;
        else DFS(root);
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}
