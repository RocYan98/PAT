#include <iostream>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	long long div = 10;
	while(div / 10 <= n) {
		ans += (n / div) * (div / 10);
		if (n % div / (div / 10) > 1) ans += div / 10;
		else if (n % div / (div / 10) == 1) ans += n % div - div / 10 + 1;
		div *= 10;
	}
	printf("%d", ans);
	return 0;
}
