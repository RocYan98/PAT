#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct Record {
	string name, gender, id;
	int grade;
} records[1000];

bool cmp(const Record &a, const Record &b) {
	if (a.gender != b.gender) return a.gender < b.gender;
	else return a.grade > b.grade;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		string name, gender, id;
		int grade;
		cin >> name >> gender >> id >> grade;
		records[i].name = name;
		records[i].gender = gender;
		records[i].id = id;
		records[i].grade = grade;
	}
	
	sort(records, records + n, cmp);
	
	if (records[0].gender == records[n - 1].gender) {
		records[0].gender == "F" ? printf("%s %s\n", records[0].name.c_str(), records[0].id.c_str()) : printf("Absent\n");
		records[n - 1].gender == "M" ? printf("%s %s\n", records[0].name.c_str(), records[0].id.c_str()) : printf("Absent\n");
		printf("NA");
	} else {
		printf("%s %s\n", records[0].name.c_str(), records[0].id.c_str());
		printf("%s %s\n", records[n - 1].name.c_str(), records[n - 1].id.c_str());
		printf("%d", records[0].grade - records[n - 1].grade);
	}
	return 0;
}
