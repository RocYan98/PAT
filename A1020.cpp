#include <iostream>
#include <queue>

using namespace std;
struct Node {
	int data;
	Node* lchild;
	Node* rchild;
};
int n, post[40], in[40];

Node* create(int postL, int postR, int inL, int inR) {
	if (postL > postR) return NULL;
	Node* root = new Node;
	root->data = post[postR];
	root->lchild = root->rchild = NULL;

	int i = 0;
	while (in[i] != post[postR]) i++;
	
	int left_num = i - inL;
	root->lchild = create(postL, postL + left_num - 1, inL, i - 1);
	root->rchild = create(postL + left_num, postR - 1, i + 1, inR);
	
	return root;
}

void BFS(Node* root) {
	queue<Node*> q;
	q.push(root);
	while (q.size()) {
		Node* top = q.front();
		q.pop();
		if (top->lchild != NULL) q.push(top->lchild);
		if (top->rchild != NULL) q.push(top->rchild);
		printf("%d", top->data);
		if (q.size()) printf(" ");
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &in[i]);
	}
	
	Node* root = create(0, n - 1, 0, n - 1);
	BFS(root);
	return 0;
}
