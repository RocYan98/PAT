#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct Record {
    string name, id;
    int grade;
} records[110];

bool cmp(const Record &a, const Record &b) {
    return a.grade > b.grade;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        string name, id;
        cin >> name >> id;
        scanf("%d", &records[i].grade);
        records[i].name = name;
        records[i].id = id;
    }
    int grade1, grade2;
    scanf("%d%d", &grade1, &grade2);

    sort(records, records + n, cmp);

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (records[i].grade >= grade1 && records[i].grade <= grade2) {
            printf("%s %s\n", records[i].name.c_str(), records[i].id.c_str());
            count++;
        }
    }
    if (!count) printf("NONE");
    return 0;
}
