#include <iostream>
#include <string>
#include <vector>

using namespace std;
char type[] = {'S', 'H', 'C', 'D'};
string num[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
vector<string> start, ed;
int shuffling[55];

int main() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			string str;
			str.push_back(type[i]);
			str += num[j];
			start.push_back(str);
		}
	}
	start.push_back("J1");
	start.push_back("J2");
	
	int k;
	scanf("%d", &k);
	for (int i = 0; i < 54; ++i) {
		scanf("%d", &shuffling[i]);
	}
	
	ed.resize(54);
	while(k--) {
		for (int i = 0; i < 54; ++i) {
			ed[shuffling[i] - 1] = start[i];
		}
		start = ed;
	}
	
	for (int i = 0; i < 54; ++i) {
		if (i) printf(" ");
		printf("%s", start[i].c_str());
	}
	return 0;
}
