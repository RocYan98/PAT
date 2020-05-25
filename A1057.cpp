#include <iostream>
#include <stack>

using namespace std;
const int sqr = 316;
stack<int> sta;
int num[100010], block[sqr];

int get_media(int k) {
	int bk = 0, sum = 0;
	while(sum + block[bk] < k) {
		sum += block[bk++];
	}
	
	int ans = bk * sqr;
	while (sum + num[ans] < k) {
		sum += num[ans++];
	}
	return ans;
}

int main() {
	int n;
	char str[15];
	scanf("%d", &n);
	while(n--) {
		scanf("%s", str);
		if (str[1] == 'o') {
			if (sta.empty()) printf("Invalid\n");
			else {
				printf("%d\n", sta.top());
				num[sta.top()]--;
				block[sta.top() / sqr]--;
				sta.pop();
			}
		} else if (str[1] == 'u') {
			int temp;
			scanf("%d", &temp);
			sta.push(temp);
			num[temp]++;
			block[temp / sqr]++;
		} else {
			if (sta.empty()) printf("Invalid\n");
			else printf("%d\n", get_media((sta.size() + 1) / 2));
		}
	}
	return 0; 
}
