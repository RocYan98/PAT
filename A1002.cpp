#include <iostream>

using namespace std;
double exp[1001];

int main() {
	for (int i = 0; i < 2; ++i) {
		int k;
		scanf("%d", &k);
		while (k--) {
			int e;
			double coe;
			scanf("%d%lf", &e, &coe);
			exp[e] += coe;
		}
	}
	int ans = 0;
	for (int i = 1000; i >= 0; --i) {
		if (exp[i]) ans++;
	}
	printf("%d", ans);
	for (int i = 1000; i >= 0; --i) {
		if (exp[i]) {
			printf(" %d %.1lf", i, exp[i]);
		}
	}
	return 0;
}
