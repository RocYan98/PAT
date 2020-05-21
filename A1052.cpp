#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Node {
	int addr, key, next;
} nodes[100010];
vector<Node> arr;

bool cmp(const Node &a, const Node &b) {
	return a.key < b.key;
}

void DFS(int addr) {
	if (addr == -1) return;
	arr.push_back(nodes[addr]);
	DFS(nodes[addr].next);
}

int main() {
	int n, head;
	scanf("%d%d", &n, &head);
	for (int i = 0; i < n; ++i) {
		int addr, key, next;
		scanf("%d%d%d", &addr, &key, &next);
		nodes[addr].addr = addr;
		nodes[addr].key = key;
		nodes[addr].next = next;
	}
	
	DFS(head);
	
	sort(arr.begin(), arr.end(), cmp);
	if (arr.empty()) {
		printf("0 -1");
		return 0;
	}
	printf("%d %05d\n", arr.size(), arr[0].addr);
	for (int i = 0; i < arr.size(); ++i) {
		printf("%05d %d ", arr[i].addr, arr[i].key);
		i == arr.size() - 1 ? printf("-1\n") : printf("%05d\n", arr[i + 1].addr);
	}
	return 0;
}
