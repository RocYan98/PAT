#include <iostream>
#include <cstring>
#include <map>
#include <set>

using namespace std;
map<int, set<int> > ans;

int s2i(char ch[]) {
    int res = 0;
    for (int i = 0; i < 3; ++i) {
        res = res * 36 + ch[i] - 'A';
    }
    res = res * 36 + ch[3] - '0';
    return res;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    while(k--) {
        int id, m;
        scanf("%d%d", &id, &m);
        for (int i = 0; i < m; ++i) {
            char name[4];
            scanf("%s", name);
            ans[s2i(name)].insert(id);
        }
    }
    
    while(n--) {
        char query[4];
        scanf("%s", query);
        printf("%s %d", query, ans[s2i(query)].size());
        for (auto id : ans[s2i(query)]) {
            printf(" %d", id);
        }
        printf("\n");
    }
    return 0;
}
