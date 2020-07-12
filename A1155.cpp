#include <iostream>
#include <vector>
#include <set>

using namespace std;
int n, nodes[1001];

vector<int> temp;
int maxn = 1, minn = 1;
void DFS(int root) {
    if (root > n) {
        printf("%d", temp[0]);
        for (int i = 1; i < temp.size(); ++i) {
            if (temp[i] > temp[i - 1]) maxn = 0;
            else minn = 0;
            printf(" %d", temp[i]);
        }
        printf("\n");
        return;
    }
    temp.push_back(nodes[root]);
    if (root * 2 + 1 > n && root * 2 <= n) DFS(root * 2);
    else {
        DFS(root * 2 + 1);
        if (root * 2 + 1 <= n) DFS(root * 2);
    }
    temp.pop_back();
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nodes[i]);
    }
    DFS(1);
    if (maxn) printf("Max Heap");
    else if (minn) printf("Min Heap");
    else printf("Not Heap");
}
