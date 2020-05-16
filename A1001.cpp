#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int sum = a + b;
	if (sum < 0) {
		sum = -sum;
		printf("-");
	}
	string ans;
	int flag = 0;
	do {
		if (flag && flag % 3 == 0) ans.push_back(',');	
		ans.push_back(sum % 10 + '0');
		sum /= 10;
		flag++;
	} while (sum);
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}
