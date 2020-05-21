#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Node {
	int weight;
	vector<int> child;
} nodes[110];
int n, m, s;

bool cmp(int a, int b) {
	return nodes[a].weight > nodes[b].weight;
}

vector<int> ans;
void DFS(int id, int sum) {
	ans.push_back(id);
	sum += nodes[id].weight;
	if (nodes[id].child.empty() && sum == s) {
		for (int i = 0; i < ans.size(); ++i) {
			if(i) printf(" ");
			printf("%d", nodes[ans[i]].weight);
		}
		printf("\n");
	}
	for (auto a : nodes[id].child) {
		DFS(a, sum);
	}
	ans.pop_back();
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &nodes[i].weight);
	}
	for (int i = 0; i < m; ++i) {
		int id, k;
		scanf("%d%d", &id, &k);
		while(k--) {
			int temp;
			scanf("%d", &temp);
			nodes[id].child.push_back(temp);
		}
		sort(nodes[id].child.begin(), nodes[id].child.end(), cmp);
	}
	
	DFS(0, 0);
	return 0;
}
