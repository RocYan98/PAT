#include <iostream>
#include <vector>

using namespace std;
struct Node {
    vector<int> child;
} node[110];
int count[110];

void DFS(int root, int depth) {
    count[depth]++;
    for (int i = 0; i < node[root].child.size(); ++i) {
        DFS(node[root].child[i], depth + 1);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int id, k;
        scanf("%d%d", &id, &k);
        while (k--) {
            int temp;
            scanf("%d", &temp);
            node[id].child.push_back(temp);
        }
    }
    DFS(1, 1);
    
    int max = 0, ans, i = 1;
    while (count[i]) {
        if (count[i] > max) {
            max = count[i];
            ans = i;
        }
        i++;
    }
    printf("%d %d", max, ans);
    return 0;
}
