#include <iostream>
#include <set>
#include <vector>

using namespace std;
struct Node {
    int data, next;
} nodes[100000];
set<int> inq;
vector<int> list, removed;

void print(const vector<int> &a) {
    for (int i = 0; i < a.size(); ++i) {
        printf("%05d %d ", a[i], nodes[a[i]].data);
        i + 1 == a.size() ? printf("-1\n") : printf("%05d\n", a[i + 1]);
    }
}

int main() {
    int root, n;
    scanf("%d%d", &root, &n);
    for (int i = 0; i < n; ++i) {
        int addr, key, next;
        scanf("%d%d%d", &addr, &key, &next);
        nodes[addr].data = key;
        nodes[addr].next = next;
    }

    while (root != -1) {
        int key = abs(nodes[root].data);
        inq.find(key) == inq.end() ? list.push_back(root) : removed.push_back(root);
        inq.insert(key);
        root = nodes[root].next;
    }

    print(list);
    print(removed);
    return 0;
}
