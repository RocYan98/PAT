#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;
int in[10000], pre[10000];
set<int> nodes;
unordered_map<int, int> hash_table;

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
        hash_table[in[i]] = i;
        nodes.insert(in[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (!nodes.count(a) && !nodes.count(b)) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if (!nodes.count(a) || !nodes.count(b)) {
            printf("ERROR: %d is not found.\n", !nodes.count(a) ? a : b);
        } else {
            for (int i = 0; i < n; ++i) {
                if ((hash_table[pre[i]] > hash_table[a] && hash_table[pre[i]] < hash_table[b]) ||
                    (hash_table[pre[i]] < hash_table[a] && hash_table[pre[i]] > hash_table[b])) {
                    printf("LCA of %d and %d is %d.\n", a, b, pre[i]);
                    break;
                } else if (pre[i] == a || pre[i] == b) {
                    printf("%d is an ancestor of %d.\n", pre[i], a == pre[i] ? b : a);
                    break;
                }
            }
        }
    }
    return 0;
}
