#include <iostream>
#include <set>
#include <vector>

using namespace std;
int n, m;
int gra[210][210];

bool is_Hamilton(const vector<int> &path) {
    if (path.size() != n + 1 || path.front() != path.back()) return false;
    set<int> vis;
    vis.insert(path[0]);
    for (int i = 1; i < path.size(); ++i) {
        if (!gra[path[i - 1]][path[i]]) return false;
        vis.insert(path[i]);
    }
    return vis.size() == n;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        gra[a][b] = gra[b][a] = 1;
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        int x;
        scanf("%d", &x);
        vector<int> path(x);
        for (int i = 0; i < x; ++i) {
            scanf("%d", &path[i]);
        }
        printf("%s\n", is_Hamilton(path) ? "YES" : "NO");
    }
    return 0;
}
