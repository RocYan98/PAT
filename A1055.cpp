#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct Person {
	string name;
	int age, worth;
} people[100010];

bool cmp(const Person &a, const Person &b) {
	if (a.worth != b.worth) return a.worth > b.worth;
	else if (a.age != b.age) return a.age < b.age;
	else return a.name < b.name;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		string name;
		cin >> name;
		people[i].name = name;
		scanf("%d%d", &people[i].age, &people[i].worth);
	}
	sort(people, people + n, cmp);
	
	for (int i = 1; i <= k; ++i) {
		int m, amin, amax;
		scanf("%d%d%d", &m, &amin, &amax);
		printf("Case #%d:\n", i);
		int j = 0, rest = m;
		while (rest && j < n) {
			if (people[j].age <= amax && people[j].age >= amin) {
				printf("%s %d %d\n", people[j].name.c_str(), people[j].age, people[j].worth);
				rest--;
			}
			j++;
		}
		if (rest == m) printf("None\n");
	}
	return 0;
}
