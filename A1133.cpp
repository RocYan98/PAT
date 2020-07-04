#include <iostream>
#include <vector>

using namespace std;
struct Node {
    int data, next;
} nodes[100000];
vector<int> temp, ans;

int main() {
    int root, n, k;
    scanf("%d%d%d", &root, &n, &k);
    for (int i = 0; i < n; ++i) {
        int addr, data, next;
        scanf("%d%d%d", &addr, &data, &next);
        nodes[addr] = {data, next};
    }
    while (root != -1) {
        temp.push_back(root);
        root = nodes[root].next;
    }
    for (int i = 0; i < temp.size(); ++i) {
        if (nodes[temp[i]].data < 0) ans.push_back(temp[i]);
    }
    for (int i = 0; i < temp.size(); ++i) {
        if (nodes[temp[i]].data >= 0 && nodes[temp[i]].data <= k) ans.push_back(temp[i]);
    }
    for (int i = 0; i < temp.size(); ++i) {
        if (nodes[temp[i]].data > k) ans.push_back(temp[i]);
    }
    for (int i = 0; i < ans.size() - 1; ++i) {
        printf("%05d %d %05d\n", ans[i], nodes[ans[i]].data, ans[i + 1]);
    }
    printf("%05d %d -1", ans.back(), nodes[ans.back()].data);
    return 0;
}
