#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
char names[40010][4];
vector<string> courses[2510];

bool cmp(const string &a, const string &b) {
    return a < b;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", names[i]);
        int num;
        scanf("%d", &num);
        while(num--) {
            int course;
            scanf("%d", &course);
            courses[course].push_back(names[i]);
        }
    }
    
    for (int i = 1; i <= k; ++i) {
        sort(courses[i].begin(), courses[i].end(), cmp);
    }
    
    for (int i = 1; i <= k; ++i) {
        printf("%d %d\n", i, courses[i].size());
        for (auto name : courses[i]) printf("%s\n", name.c_str());
    }
    return 0;
}
