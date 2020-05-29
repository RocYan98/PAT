#include <iostream>

using namespace std;
struct Node {
	int data;
	Node* lchild;
	Node* rchild;
};

int get_height(Node* root) {
	if (root == NULL) return 1;
	return max(get_height(root->lchild), get_height(root->rchild)) + 1;
}

void L(Node* &root) {
	Node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	root = temp;
}

void R(Node* &root) {
	Node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	root = temp;
}

void create(Node* &root, int data) {
	if (root == NULL) {
		root = new Node;
		root->data = data;
		root->lchild = NULL;
		root->rchild = NULL;
		return;
	}
	
	if (data < root->data) {
		create(root->lchild, data);
		if (get_height(root->lchild) - get_height(root->rchild) == 2) {
			if (get_height(root->lchild->lchild) - get_height(root->lchild->rchild) == 1) {
				R(root);
			} else {
				L(root->lchild);
				R(root);
			}
		}
	} else {
		create(root->rchild, data);
		if (get_height(root->lchild) - get_height(root->rchild) == -2) {
			if (get_height(root->rchild->lchild) - get_height(root->rchild->rchild) == -1) {
				L(root);
			} else {
				R(root->rchild);
				L(root);
			}
		}
	}
}

int main() {
	int n;
	Node* root = NULL;
	scanf("%d", &n);
	while (n--) {
		int temp;
		scanf("%d", &temp);
		create(root, temp);
	}
	printf("%d", root->data);
	return 0; 
}
