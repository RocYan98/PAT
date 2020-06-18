#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
struct Person {
    string name;
    int height;
} people[10010];

bool cmp(const Person &a, const Person &b) {
    if (a.height != b.height) return a.height > b.height;
    else return a.name < b.name;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        scanf("%d", &people[i].height);
        people[i].name = name;
    }
    sort(people, people + n, cmp);
    int idx = 0;
    for (int i = 0; i < k; ++i) {
        int num = n / k;
        if (!i) num = n - (k - 1) * num;
        vector<string> row(num);
        int tallest = num / 2;
        row[tallest] = people[idx++].name;
        int step = 1;
        while (tallest - step >= 0 || tallest + step < num) {
            if (tallest - step >= 0) row[tallest - step] = people[idx++].name;
            if (tallest + step < num) row[tallest + step] = people[idx++].name;
            step++;
        }
        for (int j = 0; j < num; ++j) {
            if (j) printf(" ");
            printf("%s", row[j].c_str());
        }
        printf("\n");
    }
    return 0;
}
