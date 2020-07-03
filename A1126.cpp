#include <iostream>
#include <vector>

using namespace std;
vector<int> gra[510];
int inq[510];

void DFS(int s) {
    inq[s] = 1;
    for (auto i : gra[s]) {
        if (!inq[i]) DFS(i);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        gra[a].push_back(b);
        gra[b].push_back(a);
    }
    int num = 0, part = 0;
    for (int i = 1; i <= n; ++i) {
        if (i > 1) printf(" ");
        printf("%d", gra[i].size());
        if (!inq[i]) {
            DFS(i);
            part++;
        }
        if (gra[i].size() % 2 != 0) num++;
    }
    if (part > 1) printf("\nNon-Eulerian");
    else if (num == 0) printf("\nEulerian");
    else if (num == 2) printf("\nSemi-Eulerian");
    else printf("\nNon-Eulerian");
    return 0;
}
