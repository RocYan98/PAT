#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 1010;
int n, m, k;
vector<int> gra[MAX];
int inq[MAX];
int city;

void DFS(int i) {
	inq[i] = 1;
	for (auto cy : gra[i]) {
    if (cy == city) continue;
		if (inq[cy] == 0) DFS(cy);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		gra[a].push_back(b);
		gra[b].push_back(a);
	}
	
	while (k--) {
		scanf("%d", &city);
		fill(inq, inq + n + 1, 0);
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (i == city) continue;
			if (inq[i] == 0) {
				ans++;
				DFS(i);
			}
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}
