#include <iostream>
#include <map>

using namespace std;
map<int, int> color;

int main() {
	int n, m;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m * n; ++i) {
		int temp;
		scanf("%d", &temp);
		if (++color[temp] > m * n / 2) {
			printf("%d", temp);
			return 0;
		}
	}
	return 0;
}
