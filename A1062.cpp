#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Person {
	int id, vir, tal, ttl;
} temp;
vector<Person> people[4];

bool cmp(const Person &a, const Person &b) {
	if (a.ttl != b.ttl) return a.ttl > b.ttl;
	else if (a.vir != b.vir) return a.vir > b.vir;
	else return a.id < b.id;
}

int main() {
	int n, l, h;
	scanf("%d%d%d", &n, &l, &h);
	int count = 0;
	for (int i = 0; i < n; ++i) {
		int id, vir, tal;
		scanf("%d%d%d", &temp.id, &temp.vir, &temp.tal);
		if (temp.vir >= l && temp.tal >= l) {
			count++;
			temp.ttl = temp.vir + temp.tal;
			if (temp.vir >= h && temp.tal >= h) people[0].push_back(temp);
			else if (temp.vir >= h) people[1].push_back(temp);
			else if (temp.vir >= temp.tal) people[2].push_back(temp);
			else people[3].push_back(temp);
		}
	}
	
	for (int i = 0; i < 4; ++i) sort(people[i].begin(), people[i].end(), cmp);
	
	printf("%d\n", count);
	for (int i = 0; i < 4; ++i) {
		for (auto p : people[i]) printf("%d %d %d\n", p.id, p.vir, p.tal);
	}
	
	return 0; 
}
