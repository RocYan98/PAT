#include <iostream>
#include <set>
#include <vector>

using namespace std;
set<int> nodes;
vector<int> pre;

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
        int data;
        scanf("%d", &data);
        nodes.insert(data);
        pre.push_back(data);
    }
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (!nodes.count(a) && !nodes.count(b)) printf("ERROR: %d and %d are not found.\n", a, b);
        else if (!nodes.count(a) || !nodes.count(b)) {
            printf("ERROR: %d is not found.\n", !nodes.count(a) ? a : b);
        } else {
            for (auto node : pre) {
                if ((node > a && node < b) || (node > b && node < a)) {
                    printf("LCA of %d and %d is %d.\n", a, b, node);
                    break;
                } else if (node == a || node == b) {
                    node == a ? printf("%d is an ancestor of %d.\n", a, b) : printf("%d is an ancestor of %d.\n", b, a);
                    break;
                }
            }
        }
    }
    return 0;
}
