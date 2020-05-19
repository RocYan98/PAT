#include <iostream>
#include <string>

using namespace std;
int dp[1010][1010];

int main() {
	string str;
	getline(cin, str);
	
	int ans = 1;
	for (int i = 0; i < str.size(); ++i) {
		dp[i][i] = 1;
		if (i + 1 < str.size() && str[i] == str[i + 1]) {
			ans = 2;
			dp[i][i + 1] = 1;
		}
	}
	
	for (int step = 2; step < str.size(); ++step) {
		for (int j = 0; j + step < str.size(); ++j) {
			if (str[j] == str[j + step] && dp[j + 1][j + step - 1]) {
				dp[j][j + step] = 1;
				ans = step + 1;
			}
		}
	} 
	
	printf("%d", ans);
	return 0;
}
