#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int n, inq[10010];
vector<int> gra[10010];
set<int> ans;

int DFS(int node, int depth) {
	int res = depth;
	inq[node] = 1;
	for (auto n : gra[node]) {
		if (!inq[n]) {
			res = max(DFS(n, depth + 1), res);	
		}
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		gra[a].push_back(b);
		gra[b].push_back(a);
	}
	
	int k = 0;
	for (int i = 1; i <= n; ++i) {
		if (!inq[i]) {
			DFS(i, 1);
			k++;
		}
	}
	
	if (k > 1) printf("Error: %d components", k);
	else {
		int max_depth = -1;
		for (int i = 1; i <= n; ++i) {
			fill(inq, inq + n + 1, 0);
			int depth = DFS(i, 1);
			if (depth > max_depth) {
				ans.clear();
				ans.insert(i);
				max_depth = depth;
			} else if (depth == max_depth) {
				ans.insert(i);
			}
		}
		for (auto n : ans) {
			printf("%d\n", n);
		}
	}
	return 0;
}
