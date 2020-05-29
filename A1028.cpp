#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct Record {
    string id, name;
    int grade;
} records[100010];
int n, c;

bool cmp(const Record &a, const Record &b) {
    if (c == 1) {
        return a.id < b.id;
    } else if (c == 2) {
        if (a.name != b.name) return a.name < b.name;
        else return a.id < b.id;
    } else {
        if (a.grade != b.grade) return a.grade < b.grade;
        else return a.id < b.id;
    }
}

int main() {
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i) {
        string id, name;
        cin >> id >> name;
        records[i].id = id;
        records[i].name = name;
        scanf("%d", &records[i].grade);
    }
    
    sort(records, records + n, cmp);
    for (int i = 0; i < n; ++i) {
        printf("%s %s %d\n", records[i].id.c_str(), records[i].name.c_str(), records[i].grade);
    }
    return 0;
}
