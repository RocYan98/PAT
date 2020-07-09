#include <iostream>
#include <set>
#include <vector>

using namespace std;
set<int> incompatible[100000];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        incompatible[a].insert(b);
        incompatible[b].insert(a);
    }
    while (m--) {
        int k;
        scanf("%d", &k);
        vector<int> list(k);
        for (int i = 0; i < k; ++i) {
            scanf("%d", &list[i]);
        }
        int flag = 1;
        for (int i = 0; i < k; ++i) {
            if (flag)
                for (int j = i + 1; j < k; ++j) {
                    if (incompatible[list[i]].count(list[j])) {
                        flag = 0;
                        break;
                    }
                }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}
