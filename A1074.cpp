#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Node {
    int id, data, next;
} nodes[100010];
vector<Node> list;

int main() {
    int root, n, k;
    scanf("%d%d%d", &root, &n, &k);
    for (int i = 0; i < n; ++i) {
        int id, data, next;
        scanf("%d%d%d", &id, &data, &next);
        nodes[id].id = id;
        nodes[id].data = data;
        nodes[id].next = next;
    }
    while (root != -1) {
        list.push_back(nodes[root]);
        root = nodes[root].next;
    }
    for (int i = 0; i + k <= list.size(); i += k) {
        reverse(list.begin() + i, list.begin() + i + k);
    }
    for (auto ite = list.begin(); ite != list.end(); ++ite) {
        printf("%05d %d ", ite->id, ite->data);
        ite + 1 == list.end() ? printf("-1\n") : printf("%05d\n", (ite + 1)->id);
    }
    return 0;
}
