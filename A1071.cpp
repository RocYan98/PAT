#include <iostream>
#include <map>

using namespace std;
map<string, int> words;

int main() {
	string str;
	while (1) {
		char ch =getchar();
		if (!isalpha(ch) && !isdigit(ch)) {
			if (str.size()) words[str]++;
			if (ch == '\n') break;
			str.clear();
		} else {
			ch = tolower(ch);
			str.push_back(ch);
		}
	}
	
	string ans;
	int times = -1;
	for (auto pair : words) {
		if (pair.second > times) {
			ans = pair.first;
			times = pair.second;
		} else if (pair.second == times && pair.first < ans) {
			ans = pair.first;
		}
	}
	printf("%s %d", ans.c_str(), times);
	return 0;
}
