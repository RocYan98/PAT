#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Node {
	vector<int> child;
	int depth;
} node[110];
int ans[110], max_depth = 1;

void BFS() {
	queue<int> q;
	q.push(1);
	while (q.size()) {
		int top = q.front();
		q.pop();
		if (node[top].child.size() == 0) ans[node[top].depth]++;
		for (auto nd : node[top].child) {
			node[nd].depth = node[top].depth + 1;
			if (node[nd].depth > max_depth) max_depth = node[nd].depth;
			q.push(nd);
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int id, k;
		scanf("%d%d", &id, &k);
		while (k--) {
			int temp;
			scanf("%d", &temp);
			node[id].child.push_back(temp);
		}
	}
	node[1].depth = 1;
	BFS();
	for (int i = 1; i <= max_depth; ++i) {
		if (i != 1) printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}
