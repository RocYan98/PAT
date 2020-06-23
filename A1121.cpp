#include <iostream>
#include <set>

using namespace std;
int cp[100000];
set<int> guests, ans;

int main() {
    fill(cp, cp + 100000, -1);
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        cp[a] = b;
        cp[b] = a;
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        int id;
        scanf("%d", &id);
        guests.insert(id);
    }
    for (auto id : guests) {
        if (guests.find(cp[id]) == guests.end()) ans.insert(id);
    }
    printf("%d\n", ans.size());
    for (auto ite = ans.begin(); ite != ans.end(); ++ite) {
        if (ite != ans.begin()) printf(" ");
        printf("%05d", *ite);
    }
    return 0;
}
