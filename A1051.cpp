#include <iostream>
#include <queue>
#include <stack>

using namespace std;


int main() {
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	while(k--) {
		queue<int> que;
		stack<int> sta;
		for (int i = 0; i < n; ++i) {
			int temp;
			scanf("%d", &temp);
			que.push(temp);
		}
		
		for (int i = 1; i <= n; ++i) {
			sta.push(i);
			if (sta.size() > m) break;
			while(sta.size() && sta.top() == que.front()) {
				que.pop();
				sta.pop();
			}
		}
		printf("%s\n", que.empty() ? "YES" : "NO");
	}
	return 0;
}
