#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Student {
    int id, ge, gi, final;
    vector<int> prefer;
} students[40010];
int quota[110];
vector<Student*> admission[110];

bool cmp(const Student &a, const Student &b) {
    if (a.final != b.final) return a.final > b.final;
    else if (a.ge != b.ge) return a.ge > b.ge;
    else return a.id < b.id;
}

bool cmp2(const Student* a, const Student* b) {
    return a->id < b->id;
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &quota[i]);
    }
    for (int i = 0; i < n; ++i) {
        students[i].id = i;
        scanf("%d%d", &students[i].ge, &students[i].gi);
        students[i].final = students[i].ge + students[i].gi;
        for (int j = 0; j < k; ++j) {
            int temp;
            scanf("%d", &temp);
            students[i].prefer.push_back(temp);
        }
    }
    sort(students, students + n, cmp);

    for (int i = 0; i < n; ++i) {
        for (auto sch : students[i].prefer) {
            if (quota[sch]) {
                admission[sch].push_back(&students[i]);
                quota[sch]--;
                break;
            } else if (students[i].final == admission[sch].back()->final && students[i].ge == admission[sch].back()->ge) {
                admission[sch].push_back(&students[i]);
                break;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        sort(admission[i].begin(), admission[i].end(), cmp2);
        for (int j = 0; j < admission[i].size(); ++j) {
            if (j) printf(" ");
            printf("%d", admission[i][j]->id);
        }
        printf("\n");
    }
    return 0;
}


