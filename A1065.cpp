#include <iostream>

#define LL long long
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		LL a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		LL res = a + b;
		printf("Case #%d: ", i);
		if (a > 0 && b > 0) {
			printf("%s\n", res <= 0 || res > c ? "true" : "false");
		} else if (a < 0 && b < 0) {
			printf("%s\n", res >= 0 || res < c ? "false" : "true");
		} else {
			printf("%s\n", res > c ? "true" : "false");
		}
	}
	return 0; 
}
