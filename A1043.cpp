#include <iostream>
#include <vector>

using namespace std;
struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};
int pre[1010];

void create(Node* &root, int data) {
    if (root == NULL) {
        root = new Node();
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        return;
    }
    
    if (data < root->data) create(root->lchild, data); 
    else create(root->rchild, data);
}

vector<int> ans;
void preorder(Node* root, bool is_mir) {
    if (root == NULL) return;
    ans.push_back(root->data);
    is_mir ? preorder(root->rchild, is_mir) : preorder(root->lchild, is_mir);
    is_mir ? preorder(root->lchild, is_mir) : preorder(root->rchild, is_mir);
}

void postorder(Node* root, bool is_mir) {
    if (root == NULL) return;
    is_mir ? postorder(root->rchild, is_mir) : postorder(root->lchild, is_mir);
    is_mir ? postorder(root->lchild, is_mir) : postorder(root->rchild, is_mir);
    ans.push_back(root->data);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }
    
    Node* root = NULL;
    for (int i = 0; i < n; ++i) create(root, pre[i]);
    
    bool is_mir = pre[1] < pre[0] ? 0 : 1;
    
    preorder(root, is_mir);
    for (int i = 0; i < n; ++i) {
        if (ans[i] != pre[i]) {
            printf("NO");
            return 0;
        }
    }
    
    printf("YES\n");
    ans.clear();
    postorder(root, is_mir);
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}
