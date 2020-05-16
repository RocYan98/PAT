#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
struct Gang {
	string head;
	int num, total_time;
};
map<string, vector<string> > gra;
map<string, int> weight;
set<string> inq;
vector<Gang> ans;

Gang temp;
void DFS(string s) {
	inq.insert(s);
	if (weight[s] > weight[temp.head]) {
		temp.head = s;
	}
	temp.num++;
	temp.total_time += weight[s];
	
	for (auto mem : gra[s]) {
		if (inq.find(mem) == inq.end())	DFS(mem);
	}
}

bool cmp(const Gang &a, const Gang &b) {
	return a.head < b.head;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		string a, b;
		int time;
		cin >> a >> b >> time;
		gra[a].push_back(b);
		gra[b].push_back(a);
		weight[a] += time;
		weight[b] += time;
	}
	
	for (auto pair : gra) {
		if (inq.find(pair.first) == inq.end()) {
			temp = Gang();
			temp.head = pair.first;
			DFS(pair.first);
			if (temp.num > 2 && temp.total_time / 2 > k) ans.push_back(temp);
		}
	}
	
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for (auto gang : ans) {
		printf("%s %d\n", gang.head.c_str(), gang.num);
	}
	return 0;
}
