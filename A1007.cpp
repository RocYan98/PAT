#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr, dp;

int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int temp;
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	
	dp.resize(k);
	dp[0] = arr[0];
	for (int i = 1; i < k; ++i) {
		dp[i] = arr[i] + dp[i - 1] > arr[i] ? dp[i - 1] + arr[i] : arr[i];
	}
	
	int ans = -1;
	int last;
	for (int i = 0; i < k; ++i) {
		if (dp[i] > ans) {
			ans = dp[i];
			last = i;
		}
	}
	
	if (ans >= 0) {
		printf("%d ", ans);
		int i;
		for (i = last; i >= 0; --i) {
			ans -= arr[i];
			if (ans == 0) break;
		}
		printf("%d %d", arr[i], arr[last]);
	}
	else printf("0 %d %d", arr[0], arr[k - 1]);
	return 0;
}
