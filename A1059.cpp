#include <iostream>
#include <cmath>
#include <map>

using namespace std;
map<int, int> factors;

bool is_prime(int x) {
	if (x < 2) return false;
	for (int i = 2; i <= sqrt(x); ++i) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d=", n);
	if (n == 1) printf("1");
	for (int i = 2; i <= sqrt(n); ++i) {
		while(is_prime(i) && n % i == 0) {
			factors[i]++;
			n /= i;
		}
	}
	if (n > 1) factors[n]++;
	
	for (auto ite = factors.begin(); ite != factors.end(); ++ite) {
		if (ite != factors.begin()) printf("*");
		printf("%d", ite->first);
		if (ite->second > 1) printf("^%d", ite->second);
	}
	return 0; 
}
