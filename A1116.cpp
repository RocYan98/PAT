#include <iostream>
#include <set>
#include <cmath>

using namespace std;
set<int> checked;
int seq[10010];

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int id;
        scanf("%d", &id);
        seq[id] = i;
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        int query;
        scanf("%d", &query);
        printf("%04d: ", query);
        if (seq[query] == 0) printf("Are you kidding?\n");
        else if (checked.find(seq[query]) != checked.end()) printf("Checked\n");
        else if (seq[query] == 1) printf("Mystery Award\n");
        else if (is_prime(seq[query])) printf("Minion\n");
        else printf("Chocolate\n");
        checked.insert(seq[query]);
    }
    return 0;
}
