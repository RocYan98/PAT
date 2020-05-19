#include <iostream>
#include <map>
#include <vector>

using namespace std;
int times[10010];
vector<int> bets;

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		int temp;
		scanf("%d", &temp);
		times[temp]++;
		bets.push_back(temp);
	}
	
	for (auto num : bets) {
		if (times[num] == 1) {
			printf("%d", num);
			return 0;
		}
	}
	printf("None");
	return 0;
}
